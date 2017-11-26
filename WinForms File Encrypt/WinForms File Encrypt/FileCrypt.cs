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

        public FileCrypt()
        {
            _key = "Samir";
        }

        public byte[] Decrypt(string filepath)
        {
            FileStream f = new FileStream(filepath, FileMode.Open);
            byte[] file = new byte[f.Length];
            f.Read(file, 0, (int)f.Length);
            int k = 0;
            for (int i = 0; i < file.Length; i++)
            {
                file[i] = (byte)(file[i] | (file.Length / _key.Length));
                file[i] = (byte)(file[i] << (_key.Length % 4));
                file[i] -= (byte)file.Length;
                file[i] += (byte)_key.Length;
                file[i] -= (byte)_key[k];
                if (k == _key.Length - 1)
                    k = 0;
            }
            f.Close();
            return file;
        }
        public byte[] Encrypt(string filepath)
        {
            FileStream f = new FileStream(filepath, FileMode.Open);
            byte[] file = new byte[f.Length];
            f.Read(file, 0, (int)f.Length);
            int k = 0;
            for (int i = 0; i < file.Length; i++)
            {
                file[i] = (byte)(file[i] | (file.Length / _key.Length));
                file[i] = (byte)(file[i] >> (_key.Length % 4));
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
