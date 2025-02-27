using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _27_02
{
    internal struct Nal : IPayment
    {
        public double Change { get; }
        public double Sum { get; set; }
    }
}
