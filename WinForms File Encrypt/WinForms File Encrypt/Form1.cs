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
        private byte[] b;
        private string _filePath;
        public FormMain()
        {
            InitializeComponent();
        }

        private void btSelectEncrypt_Click(object sender, EventArgs e)
        {
            
            try
            {
                FileCrypt.EncryptFile(_filePath, tbKey.Text);
                MessageBox.Show("File Encrypted!");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
        private void btSelectDecrypt_Click(object sender, EventArgs e)
        {
            try
            {
               
                FileCrypt.DecryptFile(_filePath, tbKey.Text);
                MessageBox.Show("File Decrypted!");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }  
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
            tbKey.Clear();
            plMain.Visible = false;
            plOpenFile.Visible = true;
        }

        private void btExit_Click(object sender, EventArgs e)
        {
            Environment.Exit(0);
        }
    }
}
