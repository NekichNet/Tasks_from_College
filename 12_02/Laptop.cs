using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _12_02
{
    internal class Laptop
    {
        private string model;
        private int frequency, RAM, HDD, weight;

        public Laptop(string model, int frequency, int RAM, int HDD, int weight)
        {
            this.model = model;
            this.frequency = frequency;
            this.RAM = RAM;
            this.HDD = HDD;
            this.weight = weight;
        }

        public void Info()
        {
            Console.WriteLine($"Model: {model}\nFreq: {frequency}\n" +
                $"RAM: {RAM}\nHDD: {HDD}\nWeight: {weight}");
        }
    }
}
