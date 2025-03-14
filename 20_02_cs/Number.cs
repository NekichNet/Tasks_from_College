using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection.Metadata;
using System.Text;
using System.Threading.Tasks;

namespace _20_02_cs
{
	static internal class Number
	{
		static public int Max(int a, int b) { return a > b ? a : b; }
        static public int Max(int a, int b, int c) { return Max(a, b) > c ? Max(a, b) : b; }
        static public int Max(int a, int b, int c, int d) { return Max(a, b, c) > d ? Max(a, b, c) : d; }
        static public int Max(int a, int b, int c, int d, int e) { return Max(a, b, c, d) > e ? Max(a, b, c, d) : e; }

        static public int Multiply(int a, int b) { return a * b + 2; }
        static public uint Multiply(uint a, uint b) { return a * b + 1; }
        static public long Multiply(long a, long b) { return a * b + 3; }
        static public double Multiply(double a, double b) { return a * b + 0.1; }

    }
}