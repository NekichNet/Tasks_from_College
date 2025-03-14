using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _12_02
{
    internal class Smartphone
    {
        private string model, OS;
        private int frequency, RAM, memory, weight;

        public Smartphone(string model, string OS, int frequency, int RAM, int memory, int weight)
        {
            this.model = model;
            this.OS = OS;
            this.frequency = frequency;
            this.RAM = RAM;
            this.memory = memory;
            this.weight = weight;
        }

        public void Info()
        {
            Console.WriteLine($"Model: {model}\nOS: {OS}\nFreq: {frequency}\n" +
                $"RAM: {RAM}\nMemory: {memory}\nWeight: {weight}");
        }
    }
}
