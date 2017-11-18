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
        private List<User> _users;
        private bool _isLogged;

        public Form1()
        {
            _isLogged = false;
            InitializeComponent();
        }

        private void ClearRegLine()
        {
            tbName.Text = "";
            tbSurname.Text = "";
            tbAge.Text = "";
        }
        private void RegWindowVisible(bool state)
        {
            this.label5.Visible = state;
            this.label6.Visible = state;
            this.label7.Visible = state;
            this.label8.Visible = state;
            this.tbName.Visible = state;
            this.tbSurname.Visible = state;
            this.tbAge.Visible = state;
            this.tbCancelFill.Visible = state;
            this.btRegister.Visible = state;
        }

        private void MainLinesVisible(bool state)
        {
            this.label1.Visible = state;
            this.label2.Visible = state;
            this.label3.Visible = state;
            this.label4.Visible = state;
            this.textBox1.Visible = state;
            this.textBox2.Visible = state;
            this.button1.Visible = state;
            this.button2.Visible = state;
        }

        private void NewUserRegistratiron()
        {
            int temp;
            _users.Add(new User());
            _users.Last().Name = tbName.Text;
            _users.Last().Surname = tbSurname.Text;
            int.TryParse(tbAge.Text, out temp);
            _users.Last().Age = temp;
            _users.Last().SetUsernameAndPassword();
        }
        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            MainLinesVisible(false);
            RegWindowVisible(true);
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

        private void ChatBox_TextChanged(object sender, EventArgs e)
        {
            
        }

        private void DisplayMessagesBox_TextChanged(object sender, EventArgs e)
        {

        }

        private void ChatBox_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Return)
            {
                DisplayMessagesBox.Text += ChatBox.Text;
                ChatBox.Text = "";
            }
        }

        private void label5_Click(object sender, EventArgs e)
        {

        }

        private void tbName_TextChanged(object sender, EventArgs e)
        {

        }

        private void label8_Click(object sender, EventArgs e)
        {

        }

        private void label7_Click(object sender, EventArgs e)
        {

        }

        private void label6_Click(object sender, EventArgs e)
        {

        }

        private void tbSurname_TextChanged(object sender, EventArgs e)
        {

        }

        private void tbAge_TextChanged(object sender, EventArgs e)
        {

        }

        private void btRegister_Click(object sender, EventArgs e)
        {
            var linesFilled = true;

            if (tbName.Text.Length == 0)
                linesFilled = false;

            if (tbSurname.Text.Length == 0)
                linesFilled = false;

            if (tbAge.Text.Length == 0)
                linesFilled = false;

            if (linesFilled)
            {
                RegWindowVisible(false);
                MainLinesVisible(true);
                MessageBox.Show("Succes!");
                ClearRegLine();
            }
            else
                MessageBox.Show("Please, fill all the Lines!");

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void tbCancelFill_Click(object sender, EventArgs e)
        {
            RegWindowVisible(false);
            MainLinesVisible(true);
            ClearRegLine();
        }
    }
}
