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
        private int _time_in_seconds;

        public Time() : this(0, 0, 0) {}

        public Time(int hour, int minute, int second)
        {
            _hours = hour;
            _minutes = minute;
            _seconds = second;
            _time_in_seconds = _hours * 3600 + _minutes * 60 + _seconds;
        }

        private int ConvertToSeconds(int hours, int minutes, int seconds)
        {
            return hours * 3600 + minutes * 60 + seconds;
             
        }

        private void ConvertToSeconds()
        {
            _time_in_seconds = _hours * 3600 + _minutes * 60 + _seconds;

        }

        private void ConvertToTime()
        {
            int sec = _time_in_seconds;
            _hours = sec / 3600;
            sec -= _hours * 3600;
            _minutes = sec / 60;
            sec -= _minutes * 60;
            _seconds = sec;
        }

        private void ConvertToTime(int hours, int minutes, int seconds)
        {
            int sec = _time_in_seconds;
            hours = sec / 3600;
            sec -= hours * 3600;
            minutes = sec / 60;
            sec -= minutes * 60;
            seconds = sec;
        }

        private string appendNull(int value)
        {
            if (value < 10)
                return "0" + value.ToString();
            return value.ToString();
        }

        static public Time operator - (Time t1, Time t2)
        {
            Time t = new Time();
            t1.ConvertToSeconds();
            t2.ConvertToSeconds();
            t._time_in_seconds = t1._time_in_seconds - t2._time_in_seconds;
            t.ConvertToTime();
            return t;
        }

        static public bool operator == (Time t1, Time t2)
        {
            if (t1._hours == t2._hours && t1._minutes == t2._minutes && t1._seconds == t2._seconds)
                return true;
            else
                return false;
        }

        static public bool operator !=(Time obj1, Time obj2)
        {
            return !(obj1 == obj2);
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
            Time t1 = new Time(16, 24, 18);

            Console.WriteLine(t1);
            Console.WriteLine(t);
            Console.WriteLine(t - t1);



            
        }
    }
}
