using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _12_02
{
    internal class Rectangle
    {
        private int x1, y1, x2, y2;

        public Rectangle(int x1, int y1, int x2, int y2)
        {
            this.x1 = x1;
            this.y1 = y1;
            this.x2 = x2;
            this.y2 = y2;
        }

        public int P()
        {
            return (x2 - x1 + y2 - y1) * 2;
        }

        public int Square()
        {
            return (x2 - x1) * (y2 - y1);
        }
    }
}
