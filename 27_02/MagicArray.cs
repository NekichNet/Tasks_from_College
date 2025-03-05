using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _27_02
{
    public class MagicArray : IEnumerable
    {
        private int[] _data;

        public MagicArray(int size)
        {
            _data = new int[size];
        }

        public int this[int index]
        {
            get { return _data[index] * _data[index]; }
            set { _data[index] = Math.Abs(value); }
        }

        public IEnumerator GetEnumerator()
        {
            foreach (var item in _data)
            {
                yield return item * item;
            }
        }
    }
}
