using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20_02_cs
{
    internal class Passing
    {
        public static double passValue = 4.5;
        public static bool havePassed(Applicant applicant) { return applicant > passValue; }
    }
}
