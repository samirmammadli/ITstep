using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Mime;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace CSharp_Lesson1
{
    internal struct User
    {
        private string Name;
        private string Surname;
        private string Password;
        private string Phone;
        private int Age;
    }

    class Program
    { 
        private int[] u;
        private static string Name;
        private static string Surname;
        private static int Age;
        private static int Choose = 0;

        static void ProgramMenu()
        {
            Console.WriteLine("1. Sign Up");
            Console.WriteLine("2. Log In");
            Console.WriteLine("3. Exit");
        }

        static void GetKey()
        {
            int.TryParse(Console.ReadLine(), out Choose);
        }
        static string GeneratePassword(int length)
        {
            return "Password";
        }

        static void SetName()
        {
            Console.WriteLine("Input Name:");
            Name = Console.ReadLine();
        }

        public static void SetSurname()
        {
            Console.WriteLine("Input Surname:");
            Surname = Console.ReadLine();
        }
        static void SetAge()
        {
            Console.WriteLine("Input Age:");
            int.TryParse(Console.ReadLine(),out Age);
        }
        static void Main(string[] args)
        {
            var u = new List<int>();

           var g = u.LongCount();
            while (true)
            {
                ProgramMenu();
                GetKey();
                if (Choose == 1)
                {
                    Console.Clear();
                    SetName();
                    SetSurname();
                    SetAge();
                    Console.Clear();
                }
                else if (Choose == 3)
                    Environment.Exit(0);
            }


           





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
