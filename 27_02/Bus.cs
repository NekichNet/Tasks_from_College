using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _27_02
{
	internal struct Bus
	{
		private static readonly string _type = "Автобус";
		public string Type => _type;
		public int Number { get; set; }
		public double TravelTime { get; set; }
		public int SeatCount { get; set; }

		public string GetDetails() => $"Кол-во сидений: {SeatCount}";
	}
}
