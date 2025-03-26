using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _26_03_cs_homework
{
    public class Square
    {
        private int x, y, side;

        public Square(int x, int y, int side)
        {
            this.x = x;
            this.y = y;
            this.side = side;
        }

        public int GetSquare() { return side * side; }

        public int GetPerimetr() { return side * 4; }
    }
}
