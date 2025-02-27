using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _26_02
{
	internal class Person
	{
		private string _name;
		private int _age;

		public Person(string name, int age) {
			_name = name;
			_age = age;
		}

		public virtual string Info()
		{
			return $"Имя: {_name}, возраст: {_age}";
		}
	}
}
