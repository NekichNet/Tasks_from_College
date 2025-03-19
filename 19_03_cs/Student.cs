using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _19_03_cs
{
    public class Student
    {
        public string Name { get; set; }
        public string Fac { get; set; }
        public int Age { get; set; }

        public Student(string name, string fac, int age)
        {
            Name = name;
            Fac = fac;
            Age = age;
        }
    }
}
