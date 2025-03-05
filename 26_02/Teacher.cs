using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _26_02
{
	internal class Teacher : Person
	{
		private int _exp, _lvl;
		public static int MROT = 22400;

		public Teacher(string name,int age, int exp, int lvl) : base(name, age)
		{
			_exp = exp;
			_lvl = lvl;
		}

		public double GetSalary()
		{
			return MROT + (_exp * 500) + (_lvl * 900);
		}

        public override string Info()
        {
			string lvlSTR = _lvl == 1 ? "Кандидат в доктора наук" : "Доктор наук";
            return $"{base.Info()}, стаж: {_exp}, уровень квалификации: {lvlSTR}, зарплата: {GetSalary()}";
        }
    }
}
