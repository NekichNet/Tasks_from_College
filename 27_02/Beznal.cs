using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _27_02
{
    internal class Beznal : IPayment
    {
        public long CardId { get; }
        public short CVC { get; }
        public string GotDate { get; }
        public string Fullname { get; }
        public double Sum { get; set; }
    }
}