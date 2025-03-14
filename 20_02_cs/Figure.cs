using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20_02_cs
{
    public static class Figure
    {
        public static double V(double a) { return Math.Pow(a, 3); }
        public static double V(double a, double b, double c) { return a * b * c; }
    }
}
