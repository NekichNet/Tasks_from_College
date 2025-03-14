using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _27_02
{
    internal interface IPayment
    {
        private static readonly string _type;
        public string Type => _type;
        public double Sum { get; set; }
    }
}
