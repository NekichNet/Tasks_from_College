using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _26_03_cs_homework
{
    public class Circle
    {
        private int x_, y_, radius_;

        public Circle(int x, int y, int radius)
        {
            x_ = x;
            y_ = y;
            radius_ = radius;
        }

        public double Length() { return 6.283 * radius_; }

        public double Square() { return 3.1415 * radius_ * radius_; }
    }
}
