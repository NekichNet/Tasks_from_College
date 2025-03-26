using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _26_03_cs_homework
{
    public class User
    {
        private string name_, surname_, lastname_;
        private int age_;

        public User(string name, string surname, string lastname, int age)
        {
            name_ = name;
            surname_ = surname;
            lastname_ = lastname;
            age_ = age;
        }

        public void Fullname()
        {
            Console.WriteLine(name_ + " " + surname_ + " " + lastname_);
        }
    }
}
