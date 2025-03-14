using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _27_02
{
    internal class ExcursionTour<T> where T : ITransport
    {
        public string TouristName { get; set; }
        public T Transport { get; set; }
        public string Hotel { get; set; }
        public string GetInfo() => $"";
    }
}
