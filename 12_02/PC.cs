using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _12_02
{
    internal class PC
    {
        private string model;
        private int frequency, RAM, HDD;

        public PC(string model, int frequency, int RAM, int HDD)
        {
            this.model = model;
            this.frequency = frequency;
            this.RAM = RAM;
            this.HDD = HDD;
        }

        public void Info()
        {
            Console.WriteLine($"Model: {model}\nFreq: {frequency}\n" +
                $"RAM: {RAM}\nHDD: {HDD}");
        }
    }
}
