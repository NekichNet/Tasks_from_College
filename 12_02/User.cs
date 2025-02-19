using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _12_02
{
    internal class User
    {
        public string surname, name, lastname;
        public int age;

        public User(string surname, string name,
            string lastname, int age) {
            this.surname = surname;
            this.name = name;
            this.lastname = lastname;
            this.age = age;
        }

        public void Fullname()
        {
            Console.WriteLine($"{surname} {name} {lastname}");
        }
    }
}
