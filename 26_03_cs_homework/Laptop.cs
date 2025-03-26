using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _26_03_cs_homework
{
    public class Laptop
    {
        private string model_;
        private int frequency_, ram_, hdd_, weight_;

        public Laptop(string model, int frequency, int ram, int hdd, int weight)
        {
            model_ = model;
            frequency_ = frequency;
            ram_ = ram;
            hdd_ = hdd;
            weight_ = weight;
        }

        public void Info()
        {
            Console.WriteLine(model_ + " " + frequency_ + " " + ram_ + " " + hdd_ + " " + weight_);
        }
    }
}
