using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Remoting.Messaging;
using System.Security.AccessControl;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms.VisualStyles;

namespace WinForms_File_Encrypt
{
    class FileCrypt
    {
        private const string CryptorStamp = "Encrypted File n987NYTop;9hwBYT987gbt9";

        private static byte[] EncryptBytes(byte[] bytes, string keyword)
        {
            var k = 0;
            for (var i = 0; i < bytes.Length; i++)
            {
                bytes[i] -= (byte)(keyword[k] & Math.Abs(~keyword.Length - keyword.Length));
                bytes[i] += (byte)(keyword[k] | (keyword.Length | 84) / keyword.Length);
                bytes[i] = (byte)~bytes[i];
                bytes[i] += (byte)(keyword.Length | 0x84);
                bytes[i] -= (byte)keyword.Length;
                bytes[i] += (byte)keyword[k];
                k++;
                if (k == keyword.Length - 1)
                    k = 0;
            }
            return bytes;
        }

        private static byte[] DecryptBytes(byte[] bytes, string keyword)
        {
            var k = 0;
            for (var i = 0; i < bytes.Length; i++)
            {
                bytes[i] -= (byte)(keyword.Length | 0x84);
                bytes[i] += (byte)keyword.Length;
                bytes[i] -= (byte)keyword[k];
                bytes[i] = (byte)~bytes[i];
                bytes[i] -= (byte)(keyword[k] | (keyword.Length | 84) / keyword.Length);
                bytes[i] += (byte)(keyword[k] & Math.Abs(~keyword.Length - keyword.Length));
                k++;
                if (k == keyword.Length - 1)
                    k = 0;
            }
            return bytes;
        }

        private static bool IsCrypted(string filepath)
        {
            var file = new FileStream(filepath, FileMode.Open);
            if (file.Length < CryptorStamp.Length * 2) {file.Close(); return false;}
            var temp = new byte[CryptorStamp.Length];
            file.Read(temp, 0, temp.Length);
            file.Close();
            return Encoding.ASCII.GetString(temp, 0, temp.Length) == CryptorStamp;
        }

        private static bool IsKeyCorrect(string filepath, string keyword)
        {
            var file = new FileStream(filepath, FileMode.Open);
            var temp = new byte[CryptorStamp.Length];
            file.Seek(CryptorStamp.Length, SeekOrigin.Begin);
            file.Read(temp, 0, CryptorStamp.Length);
            file.Close();
            return Encoding.ASCII.GetString(DecryptBytes(temp, keyword), 0, (int)temp.Length) == CryptorStamp;
        }

        public static void EncryptFile(string filepath, string keyword)
        {
            if (!File.Exists(filepath)) throw new NullReferenceException();
            if (keyword.Length < 5) throw new ArgumentException("The key length can not be less than 5");
            if (IsCrypted(filepath)) throw new ArgumentException("File is Already Encrypted!");
            var file = new FileStream(filepath, FileMode.OpenOrCreate);
            var allBytes = new byte[file.Length + CryptorStamp.Length * 2];
            var fileBuffer = new byte[file.Length + CryptorStamp.Length];
            Buffer.BlockCopy(Encoding.ASCII.GetBytes(CryptorStamp), 0, allBytes, 0, CryptorStamp.Length);
            Buffer.BlockCopy(Encoding.ASCII.GetBytes(CryptorStamp), 0, fileBuffer, 0, CryptorStamp.Length);
            file.Read(fileBuffer, CryptorStamp.Length, (int)file.Length);
            Buffer.BlockCopy(EncryptBytes(fileBuffer, keyword), 0, allBytes, CryptorStamp.Length, fileBuffer.Length);
            file.Seek(0, SeekOrigin.Begin);
            file.Write(allBytes, 0, allBytes.Length);
            file.Close();
        }

        public static void DecryptFile(string filepath, string keyword)
        {
            if (!File.Exists(filepath)) throw new NullReferenceException();
            if (keyword.Length < 5) throw new ArgumentException("The key length can not be less than 5");
            if (!IsCrypted(filepath))  throw new ArgumentException("File is not Encrypted!");
            if (!IsKeyCorrect(filepath, keyword)) throw new ArgumentException("Incorrect key !"); 
            var file = new FileStream(filepath, FileMode.OpenOrCreate);


            var bytes = new byte[file.Length - CryptorStamp.Length];
            file.Seek(CryptorStamp.Length, SeekOrigin.Begin);
            file.Read(bytes, 0, bytes.Length);
            file.SetLength(bytes.Length - CryptorStamp.Length);
            file.Seek(0, SeekOrigin.Begin);
            file.Write(DecryptBytes(bytes, keyword), CryptorStamp.Length, (int)file.Length);
            file.Close();
        }
    }
}






