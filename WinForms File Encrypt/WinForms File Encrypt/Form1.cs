using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WinForms_File_Encrypt
{
    public partial class FormMain : Form
    {
        private FileCrypt file;
        private byte[] b;
        string _filePath;
        public FormMain()
        {
            InitializeComponent();
            file = new FileCrypt();
        }

        private void btSelectEncrypt_Click(object sender, EventArgs e)
        {
            file.CryptFile(_filePath, "Samir");
        }

        private void btSelectDecrypt_Click(object sender, EventArgs e)
        {
            //b = file.Decrypt("nese.txt");
            //MessageBox.Show(file.haha);       
            //FileStream f = new FileStream("nese.txt", FileMode.OpenOrCreate);
            //f.Write(b, 0, b.Length);
            //f.Close();
            //MessageBox.Show("File Decrypted");
            file.DecryptFile(_filePath, "Samir");
            MessageBox.Show(file.posmotrim);
        }

        private void btOpenFile_Click(object sender, EventArgs e)
        {
            if (fdOpen.ShowDialog() == DialogResult.OK)
            {
                _filePath = fdOpen.FileName;
                tbFileName.Text = _filePath;
                tbFileName.Visible = true;
                lbFileName.Visible = true;
                plOpenFile.Visible = false;
                plMain.Visible = true;
            }
        }

        private void btCancel_Click(object sender, EventArgs e)
        {
            plMain.Visible = false;
            plOpenFile.Visible = true;
        }

        private void btExit_Click(object sender, EventArgs e)
        {
            Environment.Exit(0);
        }
    }
}
