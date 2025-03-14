using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _12_02
{
    internal class Point
    {
        private double x, y, z;

        public Point()
        {
            x = 0; y = 0; z = 0;
        }

        public Point(double x, double y, double z)
        {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        public void MoveBy(double x, double y, double z)
        {
            this.x += x;
            this.y += y;
            this.z += z;
        }
    }
}
