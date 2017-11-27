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
        private string _cryptorName;
        public FileCrypt()
        {
            _key = "Samir";
            _cryptorName = "Crypted by Samir";
        }

        public byte[] Decrypt(string filepath)
        {
            FileStream f = new FileStream(filepath, FileMode.Open);
            byte[] file = new byte[f.Length];
            f.Read(file, 0, (int)f.Length);
            int k = 0;
            for (int i = 0; i < file.Length; i++)
            {
                file[i] -= (byte)file.Length;
                file[i] += (byte)_key.Length;
                file[i] -= (byte)_key[k];
                file[i] = (byte)~file[i];
                file[i] -= (byte)(_key[k] | file.Length / _key.Length);
                file[i] += (byte)(_key[k] & Math.Abs(file.Length - _key.Length));
                if (k == _key.Length - 1)
                    k = 0;
            }
            f.Close();
            if (_cryptorName != Encoding.ASCII.GetString(file, (int)f.Length - _cryptorName.Length, _cryptorName.Length))
                throw new ArgumentException("Incorrect Key or File is not crypted!", nameof(f));

            return file;
        }
        public byte[] Encrypt(string filepath)
        {
            FileStream f = new FileStream(filepath, FileMode.Open);
            byte[] file = new byte[f.Length + _cryptorName.Length];
            f.Read(file, 0, (int)f.Length);
            System.Buffer.BlockCopy(Encoding.ASCII.GetBytes(_cryptorName), 0, file, (int)f.Length, _cryptorName.Length);
            int k = 0;
            for (int i = 0; i < file.Length; i++)
            {

                file[i] -= (byte)(_key[k] & Math.Abs(file.Length - _key.Length));
                file[i] += (byte)(_key[k] | file.Length / _key.Length);
                file[i] = (byte)~file[i];
                file[i] += (byte)file.Length;
                file[i] -= (byte)_key.Length;
                file[i] += (byte)_key[k];
                if (k == _key.Length - 1)
                    k = 0;
            }
            f.Close();
            return file;
        }
    }
}
