using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Security.AccessControl;
using System.Text;
using System.Threading.Tasks;

namespace WinForms_File_Encrypt
{
    class FileCrypt
    {
        private const string _cryptorStamp = "Crypted by Samir";
        public string posmotrim;
        private FileStream file;

        private byte[] EncryptBytes(byte[] bytes, string keyword)
        {
            var k = 0;
            for (int i = 0; i < bytes.Length; i++)
            {
                bytes[i] -= (byte)(keyword[k] & Math.Abs(bytes.Length - keyword.Length));
                bytes[i] += (byte)(keyword[k] | bytes.Length / keyword.Length);
                bytes[i] = (byte)~bytes[i];
                bytes[i] += (byte)bytes.Length;
                bytes[i] -= (byte)keyword.Length;
                bytes[i] += (byte)keyword[k];
                if (k == keyword.Length - 1)
                    k = 0;
            }
            return bytes;
        }

        private static byte[] DecryptBytes(byte[] bytes, string keyword)
        {
            var k = 0;
            for (int i = 0; i < bytes.Length; i++)
            {
                bytes[i] -= (byte)bytes.Length;
                bytes[i] += (byte)keyword.Length;
                bytes[i] -= (byte)keyword[k];
                bytes[i] = (byte)~bytes[i];
                bytes[i] -= (byte)(keyword[k] | bytes.Length / keyword.Length);
                bytes[i] += (byte)(keyword[k] & Math.Abs(bytes.Length - keyword.Length));
                if (k == keyword.Length - 1)
                    k = 0;
            }
            return bytes;
        }

        private bool IsCrypted(string filepath)
        {
            byte[] temp = new byte[_cryptorStamp.Length];
            file = new FileStream(filepath, FileMode.Open);
            if (file.Length < _cryptorStamp.Length)
            {
                file.Close();
                return false;
            }
            file.Seek((int)file.Length - _cryptorStamp.Length, SeekOrigin.Begin);
            file.Read(temp,0 , _cryptorStamp.Length);
            file.Close();
            temp = DecryptBytes(temp, _cryptorStamp);
            posmotrim = Encoding.ASCII.GetString(temp, 0, temp.Length);
            if (_cryptorStamp == Encoding.ASCII.GetString(temp, 0, temp.Length))
                return true;

            return false;
        }

        public void CryptFile(string filepath, string keyword)
        {
            if (IsCrypted(filepath))
                throw new ArgumentException("File is alrady Crypted!");
           file = new FileStream(filepath, FileMode.Open);
            if (!file.CanWrite)
            {
                file.Close();
                throw new ArgumentException("Cannot write to file!");
            }
           byte[] bytes = new byte[file.Length + _cryptorStamp.Length];
           file.Read(bytes, 0, (int)file.Length);
           EncryptBytes(bytes, keyword);
           Buffer.BlockCopy(EncryptBytes(Encoding.ASCII.GetBytes(_cryptorStamp), _cryptorStamp), 0, bytes, (int)file.Length, _cryptorStamp.Length);
           file.Seek(0, SeekOrigin.Begin);
           file.Write(bytes, 0, bytes.Length);
           file.Close();
        }

        public void DecryptFile(string filepath, string keyword)
        {
            if (!IsCrypted(filepath))
                throw new ArgumentException("File is not Crypted!");
            file = new FileStream(filepath, FileMode.OpenOrCreate);
            if (!file.CanWrite)
            {
                file.Close();
                throw new ArgumentException("Cannot write to file!");
            }
            byte[] bytes = new byte[file.Length];
            file.Read(bytes, 0, bytes.Length);
            file.SetLength(file.Length - _cryptorStamp.Length);
            file.Seek(0, SeekOrigin.Begin);
            file.Write(DecryptBytes(bytes, keyword), 0, (int)file.Length);
            file.Close();
        }
    }
}
