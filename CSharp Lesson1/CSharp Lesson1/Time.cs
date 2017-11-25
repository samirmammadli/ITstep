using System;
using System.Runtime.CompilerServices;

namespace CSharp_Lesson1
{
    class Time
    {
        private int _hours;
        private int _minutes;
        private int _seconds;
        private int _timeInSeconds;

        public Time() : this(0, 0, 0) {}

        public Time(int seconds) : this(0, 0, seconds) { }

        public Time(int hour, int minute, int second)
        {

            if (hour < 0 || hour > 23) throw new ArgumentException("Incorrect value in this case!", nameof(hour));
            if (minute < 0 || minute > 59) throw new ArgumentException("Incorrect value in this case!", nameof(minute));
            if (second < 0 || second > 59) throw new ArgumentException("Incorrect value in this case!", nameof(second));
            Hour = hour;
            Minute = minute;
            Second = second;
            ConvertToSeconds();
        }

        public int Hour
        {
            private set => _hours = value;
            get => _hours;
        }

        public int Minute
        {
            private set => _minutes = value;
            get => _minutes;
        }

        public int Second
        {
            private set => _seconds = value;
            get => _seconds;
        }

        private void ConvertToSeconds()
        {
            _timeInSeconds = _hours * 3600 + _minutes * 60 + _seconds;

        }

        private void ConvertToTime()
        {
            var sec = Math.Abs(_timeInSeconds);
            _hours = sec / 3600;
            sec -= _hours * 3600;
            _minutes = sec / 60;
            sec -= _minutes * 60;
            _seconds = sec;
        }

        private static string AppendNull(int value)
        {
            if (value < 10)
                return "0" + value.ToString();
            return value.ToString();
        }

        public static Time operator - (Time t1, Time t2)
        {
            Time t = new Time();
            t._timeInSeconds = t1._timeInSeconds - t2._timeInSeconds;
            t.ConvertToTime();
            return t;
        }

        public static Time operator -(Time t1, int sec)
        {
            Time t = new Time();
            t._timeInSeconds = t1._timeInSeconds - sec;
            t.ConvertToTime();
            return t;
        }

        public static bool operator >(Time t1, Time t2)
        {
            return t1._timeInSeconds > t2._timeInSeconds;
        }

        public static bool operator <(Time t1, Time t2)
        {
            return !(t1 > t2);
        }

        public static bool operator == (Time t1, Time t2)
        {
            return t1._timeInSeconds == t2._timeInSeconds;
        }

        public static bool operator !=(Time obj1, Time obj2)
        {
            return !(obj1 == obj2);
        }

        public override bool Equals(object obj) => this == (obj as Time);

        public override int GetHashCode() => this.ToString().GetHashCode();

        public override string ToString()
        {
            return (_timeInSeconds < 0 ? "-" : "") + AppendNull(_hours) + ":" + AppendNull(_minutes) + ":" + AppendNull(_seconds);
        }
    }
}