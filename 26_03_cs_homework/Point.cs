using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _26_03_cs_homework
{
    public class Point
    {
        private int x, y, z;

        public Point(int x, int y, int z)
        {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        public void MoveBy(int x, int y, int z)
        {
            this.x += x;
            this.y += y;
            this.z += z;
        }
    }
}
