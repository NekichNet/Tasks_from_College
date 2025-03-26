using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _26_03_cs_homework
{
    public class Computer
    {
        private string model_;
        private int frequency_, ram_, hdd_;

        public Computer(string model, int frequency, int ram, int hdd)
        {
            model_ = model;
            frequency_ = frequency;
            ram_ = ram;
            hdd_ = hdd;
        }

        public void Info()
        {
            Console.WriteLine(model_ + " " + frequency_ + " " + ram_ + " " + hdd_);
        }
    }
}
