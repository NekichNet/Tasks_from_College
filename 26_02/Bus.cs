using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _26_02
{
    internal class Bus : Transport
    {
        private int _tankMax;

        public Bus(string num, int capacity, int speed, int tankMax) : base(num, capacity, speed) {
            _tankMax = tankMax;
        }

        public int maxRange()
        {
            return _tankMax * 25 / 20;
        }

        public override string Info()
        {
            return $"{base.Info()}, Вместимость бака: {_tankMax}";
        }
    }
}
