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
        private int _richBoxLength;
        private int _usernumber;
        private readonly List<Color> _userColor;
        private List<User> _users;

        public Form1()
        {
            _usernumber = -1;
            _users = new List<User>();
            _userColor = new List<Color>();
            InitializeComponent();
            if (File.Exists("data.dat"))
                LoadFile();
            if (File.Exists("Chat.dat"))
            {
                try
                {
                    richTextBox1.LoadFile("Chat.dat");
                }
                catch (Exception e)
                {
                    MessageBox.Show("ChatBox: " + e.Message);
                }
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            richTextBox1.SelectionStart = richTextBox1.TextLength;
            richTextBox1.ScrollToCaret();
            _userColor.Add(Color.Red);
            _userColor.Add(Color.Green);
            _userColor.Add(Color.Blue);
            _userColor.Add(Color.Yellow);
            _userColor.Add(Color.RosyBrown);
            _userColor.Add(Color.Chocolate);
            _userColor.Add(Color.DarkBlue);
            _userColor.Add(Color.DarkGreen);
            _userColor.Add(Color.DarkGray);
        }

        private void ClearRegLine()
        {
            tbName.Clear();
            tbSurname.Clear();
            tbAge.Clear();
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
            tbLogin.Clear();
            tbPassword.Clear();
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


        private void DisplayText()
        {
            
            _richBoxLength = richTextBox1.TextLength;
            richTextBox1.AppendText(DateTime.Now.ToString() + "  ");
            richTextBox1.Select(_richBoxLength, DateTime.Now.ToString().Length + 1);
            richTextBox1.SelectionBackColor = Color.LightGreen;


            _richBoxLength = richTextBox1.TextLength;

            richTextBox1.AppendText(_users[_usernumber].Name + ":  " + ChatBox.Text);
            richTextBox1.Select(_richBoxLength, _users[_usernumber].Name.Length);
            richTextBox1.SelectionColor = _userColor[_usernumber % 9];



            richTextBox1.AppendText(Environment.NewLine);
            richTextBox1.SelectionStart = richTextBox1.TextLength;
            richTextBox1.ScrollToCaret();
            ChatBox.Clear();
        }

        private void ChatCommands()
        {
            if (ChatBox.Text == "/clear")
                richTextBox1.Clear();
            ChatBox.Clear();
        }

        private void ChatBox_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Return)
            {
                if (ChatBox.Text[0] == '/')
                    ChatCommands();
                else
                    DisplayText();
            }
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
            try
            {
                formatter.Serialize(stream, _users);
            }
            catch (Exception e)
            {
                MessageBox.Show("UserBase Save Error: " + e.Message);
                stream.Close();
            }
            
            stream.Close();
        }

        private void LoadFile()
        {
            FileStream stream = new FileStream("data.dat", FileMode.Open, FileAccess.Read);
            var formatter = new BinaryFormatter();
            try
            {  
                _users = (List<User>)formatter.Deserialize(stream);
            }
            catch (Exception e)
            {
                MessageBox.Show("UserBase Load Error: " + e.Message);
                stream.Close();
            }
            stream.Close();
        }
        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
           SaveFile();
            richTextBox1.SaveFile("Chat.dat");
        }

        private void btLogOut_Click(object sender, EventArgs e)
        {
            this._usernumber = -1;
            LogOutPanelVisible(false);
            MainLinesVisible(true);
            ChatBox.Enabled = false;
        }
    }
}
