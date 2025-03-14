using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _27_02
{
    internal interface ITransport
    {
        string Type { get; }
        int Number { get; set; }
        double TravelTime { get; set; }

        string GetDetails();
    }
}
