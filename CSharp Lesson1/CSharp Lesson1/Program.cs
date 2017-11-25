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
    class Program
    { 
        static void Main(string[] args)
        {

            var t1 = new Time(16, 24, 18);

            var t = new Time(14,0,14);
            

            DateTime da = new DateTime();
            da = DateTime.Now;
            Console.WriteLine(da.TimeOfDay.TotalDays);

            Console.WriteLine("t1 = " + t1);
            Console.WriteLine("t = " + t);

            Console.WriteLine("t1 > t = " + (t1 > t));
            Console.WriteLine("t1 < t = " + (t1 < t));
            Console.WriteLine("t - t1 = " + (t - t1));
            Console.WriteLine(t);


            Console.WriteLine(t - 775231);

            Console.WriteLine(t1 == t);
        }
    }
}
