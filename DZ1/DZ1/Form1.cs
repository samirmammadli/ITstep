using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Runtime.Remoting.Messaging;
using System.Runtime.Serialization.Formatters.Binary;
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
            _users = new List<User>();
            _isLogged = false;
            InitializeComponent();
            if (File.Exists("data.dat"))
            LoadFile();
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
            this.lbLogin.Visible = state;
            this.lbPassword.Visible = state;
            this.label4.Visible = state;
            this.tbLogin.Visible = state;
            this.tbPassword.Visible = state;
            this.btLogin.Visible = state;
            this.btRegistration.Visible = state;
        }

        private void NewUserRegistratiron()
        {
            int temp = 0;
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

        private void btRegistration_Click(object sender, EventArgs e)
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

        private void btLogin_Click(object sender, EventArgs e)
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
                NewUserRegistratiron();
                RegWindowVisible(false);
                MainLinesVisible(true);
                MessageBox.Show("Your Login: " + _users.Last().Username + '\n' + "Yor Password: " + _users.Last().Pass);
                ClearRegLine();
            }
            else
                MessageBox.Show("Please, fill all the Lines!");

        }

        private void lbLogin_Click(object sender, EventArgs e)
        {

        }

        private void lbPassword_Click(object sender, EventArgs e)
        {

        }

        private void tbLogin_TextChanged(object sender, EventArgs e)
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

        private void SaveFile()
        {
            FileStream stream = new FileStream("data.dat", FileMode.Create, FileAccess.Write, FileShare.ReadWrite);
            var formatter = new BinaryFormatter();
            formatter.Serialize(stream, _users);
            stream.Close();
        }

        private void LoadFile()
        {
            FileStream stream = new FileStream("data.dat", FileMode.Open, FileAccess.Read);
            var formatter = new BinaryFormatter();
            _users = (List<User>)formatter.Deserialize(stream);
            stream.Close();
        }
        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
           SaveFile();
            //string[] temp = new string[5];
            //File.WriteAllText("data.txt", "");
            //foreach (var user in _users)
            //{
            //    temp[0] = user.Name;
            //    temp[1] = user.Surname;
            //    temp[2] = user.Age.ToString();
            //    temp[3] = user.Username;
            //    temp[4] = user.Pass;
            //    File.AppendAllLines("data.txt", temp);
            //}
        }
    }
}
