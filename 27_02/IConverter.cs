using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _27_02
{
    internal interface IConverter
    {
        string From { get; }
        string To { get; }
        double Convert(double value);
    }
}
