using System;
using System.CodeDom;
using System.Collections.Generic;
using System.Linq;
using System.Net.Mime;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace CSharp_Lesson1
{
    class Time
    {
        private int _hours;
        private int _minutes;
        private int _seconds;

        public Time() : this(0, 0, 0) {}

        public Time(int hour, int minute, int second)
        {
            _hours = hour;
            _minutes = minute;
            _seconds = second;
        }


        private string appendNull(int value)
        {
            if (value < 10)
                return "0" + value.ToString();
            return value.ToString();
        }

        public override bool Equals(object obj)
        {
            return base.Equals(obj);
        }

        public override int GetHashCode()
        {
            return base.GetHashCode();
        }

        public override string ToString()
        {
            return appendNull(_hours) + ":" + appendNull(_minutes) + ":" + appendNull(_seconds);
        }
    }
    class Program
    { 
        static void Main(string[] args)
        {
            Time t = new Time(9,15,7);
            Console.WriteLine(t);
        }
    }
}
