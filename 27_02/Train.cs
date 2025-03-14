using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _27_02
{
	internal struct Train : ITransport
	{
		private static readonly string _type = "Поезд";
		public string Type => _type;
		public int Number { get; set; }
		public double TravelTime { get; set; }
		public string DepartureStation { get; set; }
		public int SeatNum { get; set; }

		public string GetDetails() => $"Станция отправления: {DepartureStation}, номер сидения: {SeatNum}";
	}
}
