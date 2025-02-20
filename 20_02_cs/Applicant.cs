using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20_02_cs
{
	internal class Applicant
	{
		private string fullname, date;
		private double average, extra;

		public Applicant(string fullname, string date, double average, double extra)
		{
			this.fullname = fullname;
			this.date = date;
			this.average = average;
			this.extra = extra;
		}

		public static bool operator >(Applicant left, Applicant right) {
			return left.average == right.average ? left.extra > right.extra : left.average > right.average;
		}

        public static bool operator <(Applicant left, Applicant right)
        {
            return left.average == right.average ? left.extra < right.extra : left.average < right.average;
        }

        public static bool operator >(Applicant left, double num)
        {
            return left.average > num;
        }

        public static bool operator <(Applicant left, double num)
        {
            return left.average < num;
        }
    }
}
 