using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _26_02
{
	internal class Student : Person
	{
		private int _course, _group;

		public Student(string name, int age, int course, int group) : base(name, age)
		{
			_course = course;
			_group = group;
		}

		public override string Info()
		{
			return $"{base.Info()}, курс: {_course}, группа: {_group}";
		}
	}
}
