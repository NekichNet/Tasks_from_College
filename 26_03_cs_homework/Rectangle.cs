using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _26_03_cs_homework
{
    public class Rectangle
    {
        private int x1_, y1_, x2_, y2_;

        public Rectangle(int x1, int y1, int x2, int y2)
        {
            this.x1_ = x1;
            this.y1_ = y1;
            this.x2_ = x2;
            this.y2_ = y2;
        }

        public int Perimetr() { return (x2_ - x1_ + y2_ - y1_) * 2; }

        public int Square() { return (x2_ - x1_) * (y2_ - y1_); }
    }
}
