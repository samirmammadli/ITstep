using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.Remoting.Messaging;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DZ1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void fileSystemWatcher1_Changed(object sender, System.IO.FileSystemEventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
           
        }

        private void tabPage1_Click(object sender, EventArgs e)
        {

        }

        private void eventLog1_EntryWritten(object sender, System.Diagnostics.EntryWrittenEventArgs e)
        {

        }

        private void ChatBox_TextChanged(object sender, EventArgs e)
        {
            
            
        }

        private void DisplayMessagesBox_TextChanged(object sender, EventArgs e)
        {

        }

        private void ChatBox_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Return)
            DisplayMessagesBox.Text += ChatBox.Text;
        }
    }
}
