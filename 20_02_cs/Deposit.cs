using System;
using System.Collections.Generic;
using System.Data.SqlTypes;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20_02_cs
{
	internal class Deposit
	{
		private static double percent = 0.05;

        private string fullname;
        private double money;

		public static Deposit operator ++(Deposit deposit) {
			deposit.money += deposit.money * percent; return deposit;
		}

		public static Deposit operator -(Deposit deposit, double num) { deposit.money -= num; return deposit; }

		public static double GetPercent() { return percent; }
	}
}
