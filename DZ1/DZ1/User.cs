using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Remoting.Messaging;
using System.Text;
using System.Threading.Tasks;

namespace DZ1
{
    class User
    {
        private string _name;
        private string _surname;
        private string _username;
        private StringBuilder _password;
        private int _age;
        private int _key;

        public User()
        {
            _username = "";
            _password = new StringBuilder(10);
            _name = "";
            _surname = "";
            _age = 0;
            _key = 0;
        }
        public string Name
        {
            set => _name = value;
            get => _name;
        }
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
        }
    }
}
