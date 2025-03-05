using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _26_02
{
    internal class Transport
    {
        private string _num;
        private int _capacity, _speed;

        public Transport(string num, int capacity, int speed) {
            _num = num;
            _capacity = capacity;
            _speed = speed;
        }

        public virtual string Info()
        {
            return $"Гос. номер: {_num}, Вместимость: {_capacity}, Скорость: {_speed}";
        }
    }
}
