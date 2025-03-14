using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _13_03
{
    public class Student
    {
        public string Name { get; set; }
        public string Fac { get; set; }
        public List<float> Marks { get; set; }

        public Student(string name, string fac, List<float> marks)
        {
            Name = name;
            Fac = fac;
            Marks = marks;
        }
    }
}
