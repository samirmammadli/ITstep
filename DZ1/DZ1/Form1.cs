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
        private int _usernumber;
        private List<User> _users;

        public Form1()
        {
            _usernumber = -1;
            _users = new List<User>();
            InitializeComponent();
            if (File.Exists("data.dat"))
            LoadFile();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void ClearRegLine()
        {
            tbName.Text = "";
            tbSurname.Text = "";
            tbAge.Text = "";
        }

        private void LogOutPanelVisible(bool state)
        {
            this.LogOutPanel.Visible = state;
        }

        private void RegWindowVisible(bool state)
        {
            this.regPanel.Visible = state;
        }

        private void MainLinesVisible(bool state)
        {
            this.loginPanel.Visible = state;
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

        private void UserLogged(int i)
        {
            MainLinesVisible(false);
            lbLoggedName.Text = "Welcome, " + _users[i].Name + "  " + _users[i].Surname + "!";
            LogOutPanelVisible(true);
            tbLogin.Text = "";
            tbPassword.Text = "";
            ChatBox.Enabled = true;
        }
        private void btLogin_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < _users.Count; i++)
                if (_users[i].Username == tbLogin.Text && _users[i].Pass == tbPassword.Text)
                {
                    _usernumber = i;
                    UserLogged(i);
                    return;
                }
            MessageBox.Show("Incorrect Username or Password!");
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
                DisplayMessagesBox.Text += _users[_usernumber].Name + ":" + ChatBox.Text;
                DisplayMessagesBox.Text += Environment.NewLine;
                ChatBox.Text = "";
            }
        }

        private void tbName_TextChanged(object sender, EventArgs e)
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
            bool linesFilled = (tbName.Text.Length > 0);

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
        }

        private void btLogOut_Click(object sender, EventArgs e)
        {
            this._usernumber = -1;
            LogOutPanelVisible(false);
            MainLinesVisible(true);
            ChatBox.Enabled = false;
        }

        private void lbLoggedName_Click_1(object sender, EventArgs e)
        {

        }
    }
}
