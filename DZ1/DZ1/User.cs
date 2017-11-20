using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Remoting.Messaging;
using System.Text;
using System.Threading.Tasks;

namespace DZ1
{
    [Serializable]
    class User
    {
        private string _name;
        private string _surname;
        private string _username;
        private string _password;
        private int _age;
        private Random rnd;

        public User()
        {
            rnd = new Random();
            _username = "";
            _password = "";
            _name = "";
            _surname = "";
            _age = 0;
        }
        public string Name
        {
            set => _name = value;
            get => _name;
        }

        public string Pass { get => _password; }

        public string Username { get => _username; }

        public string Surname
        {
            set => _surname = value;
            get => _surname;
        }
        public int Age
        {
            get => _age;
            set => _age = value;
        }

        public void SetUsernameAndPassword()
        {
            if (_name.Length < 6)
                _username = _name + '_';
            else
                _username = _name.Substring(0, 5) + '_';

            if (_surname.Length > 1)
                _username += _surname.Substring(0, 2).ToLower() + '_';
            else
                _username += _surname.ToLower() + '_';

            _username += _age;

            for (int i = 0; i < 10; i++)
            {
                char temp = Convert.ToChar(rnd.Next(47, 123));
                _password += temp;
            }
        }
    }
}
