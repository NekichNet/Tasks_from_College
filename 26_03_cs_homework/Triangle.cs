using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _26_03_cs_homework
{
    public class Triangle
    {
        private int side1_, side2_, side3_;

        public Triangle(int side1, int side2, int side3)
        {
            side1_ = side1;
            side2_ = side2;
            side3_ = side3;
        }

        public int Perimetr() { return side1_ + side2_ + side3_; }

        public void PrintSides() { Console.WriteLine(side1_ + " " + side2_ + " " + side3_); }

        public void PrintPerimetr() { Console.WriteLine(Perimetr()); }
    }
}
