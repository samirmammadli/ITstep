using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Mime;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace CSharp_Lesson1
{
    public struct User
    {
        private string Name;
        private string Surname;
        private string Username;
        private StringBuilder Password;
        private string Phone;
        private int Age;
        private int Key;

        public User(int a = 0)
        {
            Username = "";
            Password = new StringBuilder(10);
            Name = "";
            Surname = "";
            Phone = "";
            Age = 0;
            Key = 0;
        }
        public void PrintFirstMenu()
        {
            Console.WriteLine("1. Sign Up");
            Console.WriteLine("2. Log In");
            Console.WriteLine("3. Exit");
        }
        public void SetName()
        {
            Console.Write("Input Name:  ");
            Name = Console.ReadLine();
        }
        public void SetPhone()
        {
            Console.Write("Input Phone:  ");
            Phone = Console.ReadLine();
        }
        public void SetSurname()
        {
            Console.Write("Input Surname:   ");
            Surname = Console.ReadLine();
        }
        public void SetAge()
        {
            Console.Write("Input Age:   ");
            int.TryParse(Console.ReadLine(), out Age);
        }

        private void SetUsernameAndPassword()
        {
            if (Name.Length < 6)
                Username = Name + '_';
            else
                Username = Name.Substring(0, 5) + '_';

            if (Surname.Length > 1)
                Username += Surname.Substring(0, 2).ToLower() + '_';
            else
                Username += Surname.ToLower() + '_';

            Username += Age;
        }

        public void MainMenu()
        {
            while (Key != 3)
            {
                Console.Clear();
                PrintFirstMenu();
                int.TryParse(Console.ReadLine(), out Key);
                if (Key == 1)
                {
                    Console.Clear();
                    SetName();
                    SetSurname();
                    SetPhone();
                    SetAge();
                    SetUsernameAndPassword();

                    Console.WriteLine(Username);
                    Console.Write("Press any key...");
                    Console.ReadKey();
                }
                else if (Key == 2)
                {
                    Environment.Exit(0);
                }
            }
            
        }


    }

    class Program
    { 
        

        //static void GetKey()
        //{
        //    int.TryParse(Console.ReadLine(), out Choose);
        //}
        //static string GeneratePassword(int length)
        //{
        //    return "Password";
        //}

       

      
        static void Main(string[] args)
        {

            User useR = new User();

            useR.MainMenu();
           





            //Console.SetCursorPosition(10,10);
            //Console.Title = "CHelovek";
            //int? x = null;
            //string hw = "Netersen?";
            //Console.WriteLine($"Salam ay{x}, {hw} brat!");
            //decimal xu = 74985792848357098275098247503m;

            //int sa = Convert.ToInt32(true);
            //Console.WriteLine("Hello World!");
            //int age;
            //int.TryParse(Console.ReadLine(), out age);
            //Console.WriteLine(age);
            //Thread.Sleep(200);
        }
    }
}
