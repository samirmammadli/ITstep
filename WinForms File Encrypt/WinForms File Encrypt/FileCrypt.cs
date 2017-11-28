using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WinForms_File_Encrypt
{
    class FileCrypt
    {
        private string _key;
        private string _cryptorStamp;
        public string posmotrim;
        FileStream file;
        public FileCrypt()
        {
            _key = "Samir";
            _cryptorStamp = "Crypted by Samir";
        }

        //public byte[] DecryptBytes(string filepath)
        //{
        //    file = new FileStream(filepath, FileMode.Open);
        //    byte[] Bytes = new byte[file.Length];
        //    file.Read(Bytes, 0, (int)file.Length);
        //    int k = 0;
        //    for (int i = 0; i < Bytes.Length; i++)
        //    {
        //        Bytes[i] -= (byte)Bytes.Length;
        //        Bytes[i] += (byte)_key.Length;
        //        Bytes[i] -= (byte)_key[k];
        //        Bytes[i] = (byte)~Bytes[i];
        //        Bytes[i] -= (byte)(_key[k] | Bytes.Length / _key.Length);
        //        Bytes[i] += (byte)(_key[k] & Math.Abs(Bytes.Length - _key.Length));
        //        if (k == _key.Length - 1)
        //            k = 0;
        //    }
        //    file.Close();
        //    if (_cryptorStamp != Encoding.ASCII.GetString(Bytes, (int)file.Length - _cryptorStamp.Length, _cryptorStamp.Length))
        //        throw new ArgumentException("Incorrect Key or File is not crypted!", nameof(file));

        //    return Bytes;
        //}
        //public byte[] EncryptBytes(string filepath)
        //{
        //    file = new FileStream(filepath, FileMode.Open);
        //    byte[] Bytes = new byte[file.Length + _cryptorStamp.Length];
        //    file.Read(Bytes, 0, (int)file.Length);
        //    Buffer.BlockCopy(Encoding.ASCII.GetBytes(_cryptorStamp), 0, Bytes, (int)file.Length, _cryptorStamp.Length);
        //    int k = 0;
        //    for (int i = 0; i < Bytes.Length; i++)
        //    {

        //        Bytes[i] -= (byte)(_key[k] & Math.Abs(Bytes.Length - _key.Length));
        //        Bytes[i] += (byte)(_key[k] | Bytes.Length / _key.Length);
        //        Bytes[i] = (byte)~Bytes[i];
        //        Bytes[i] += (byte)Bytes.Length;
        //        Bytes[i] -= (byte)_key.Length;
        //        Bytes[i] += (byte)_key[k];
        //        if (k == _key.Length - 1)
        //            k = 0;
        //    }
        //    file.Close();
        //    return Bytes;
        //}
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
           file = new FileStream(filepath, FileMode.Open);
            if (IsCrypted(filepath))
            {
                file.Close();
                throw new ArgumentException("File is alrady Crypted!");
            }
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
            file = new FileStream(filepath, FileMode.Open);
            if (!file.CanWrite)
            {
                file.Close();
                throw new ArgumentException("Cannot write to file!");
            }
            byte[] bytes = new byte[file.Length];
            file.Read(bytes, 0, bytes.Length);
            file.Seek(0, SeekOrigin.Begin);
            file.Write(DecryptBytes(bytes, keyword), 0, bytes.Length);
            file.Close();
        }
    }
}
