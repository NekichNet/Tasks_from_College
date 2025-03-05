using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _26_02
{
    internal class Electrobus : Transport
    {
        private int _batteryMax;

        public Electrobus(string num, int capacity, int speed, int batteryMax) : base(num, capacity, speed)
        {
            _batteryMax = batteryMax;
        }

        public int maxRange()
        {
            return _batteryMax * 70 / 200;
        }

        public override string Info()
        {
            return $"{base.Info()}, Вместимость аккамулятора: {_batteryMax}";
        }
    }
}
