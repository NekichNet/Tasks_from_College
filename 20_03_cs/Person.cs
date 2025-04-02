using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace _20_03_cs
{
    [Serializable]
    public class Person
    {
        public string Name { get; set; }
        public string Surname { get; set; }
        public string Lastname { get; set; }

        public int Age { get; set; }

        public Person() { }

        public Person(string name, string surname, string lastname, int age)
        {
            Name = name;
            Surname = surname;
            Lastname = lastname;
            Age = age;
        }

        public void Fullname()
        {
            Console.WriteLine(Name + " " + Surname + " " + Lastname);
        }
    }
}
