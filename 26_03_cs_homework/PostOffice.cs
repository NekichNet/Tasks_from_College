using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _26_03_cs_homework
{
    public class PostOffice
    {
        private int index_;
        private string city_, street_, house_, corpus_, flat_, content_;

        public PostOffice(int index, string city, string street,
            string house, string corpus, string flat, string content)
        {
            index_ = index;
            city_ = city;
            street_ = street;
            house_ = house;
            corpus_ = corpus;
            flat_ = flat;
            content_ = content;
        }

        public void PrintAddress()
        {
            Console.WriteLine(index_ + " " + city_ + " " + street_
                + " " + house_ + " " + corpus_ + " " + flat_);
        }
    }
}
