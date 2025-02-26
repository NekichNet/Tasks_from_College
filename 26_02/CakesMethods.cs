using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Reflection.Metadata;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace _26_02
{
	internal class CakesMethods
	{
		private string _name, _content;
		private int _weight, _price, _calorie;

		public void SetName(string name) { _name = name; }
		public void SetPrice(int price) { _price = price; }

		public string GetName() { return _name; }
		public int GetPrice() { return _price; }
		public int GetCalorie() { return _calorie; }
        public void SetContent(string content) { _content = content; }
        public string GetContent() { return _content; }
        public string GetInfo() { return $"Название: {_name}, Цена: {_price}, " +
				$"Вес: {_weight}, Калорийность: {_calorie}, Состав: {_content}"; }
        public CakesMethods(string name, string content, int weight, int price, int calorie)
        {
            _name = name;
            _content = content;
			_weight = weight;
			_price = price;
			_calorie = calorie;
		}
	}
}
