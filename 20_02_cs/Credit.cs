using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20_02_cs
{
    internal class Credit
    {
        private static double percent = 0.05;

        private string fullname;
        private double pay;

        public static Credit operator -(Deposit deposit, Credit credit)
        {
            deposit -= credit.pay; return credit;
        }

        public static double GetPercent() { return percent; }
    }
}