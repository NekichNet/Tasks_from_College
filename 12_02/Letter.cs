using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _12_02
{
    internal class Letter
    {
        public string mailIndex, city, street, house, body, flat, text;

        public Letter(string mailIndex, string city, string street, string house, string body, string flat, string text)
        {
            this.mailIndex = mailIndex;
            this.city = city;
            this.street = street;
            this.house = house;
            this.body = body;
            this.flat = flat;
            this.text = text;
        }

        public void Print()
        {
            Console.WriteLine(mailIndex, city, street, house, body, flat);
        }
    }
}
