using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _26_02
{
    internal class CakesFeatures
    {
        private string _name;
        private int _weight, _price, _calorie;

        public string Name { get { return _name; } set { _name = value; } }
        public int Price { get { return _price; } set { _price = value; } }
        public int Calorie { get { return _calorie; } }

        public string Content { get; }

        public string Info { get { return $"Название: {Name}, Цена: {Price}," +
                    $" Вес: {_weight}, Калорийность: {Calorie}, Состав: {Content}"; } }

        public CakesFeatures(string name, int weight, int price, int calorie, string content)
        {
            _name = name;
            _weight = weight;
            _price = price;
            _calorie = calorie;
            Content = content;
        }
    }
}
