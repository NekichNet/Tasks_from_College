using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _26_02
{
    internal class BookMethods
    {
        private string _title, _author, _publisher;
        private int _year, _pages;

        public void SetTitle(string title) => _title = title;
        public string GetTitle() => _title;
        public string GetPublisher() => _publisher;
        public string Info() => $"Название: {_title}, Автор: {_author}," +
            $" Год издания: {_year}, Кол-во страниц: {_pages}, Издатель: {_publisher}";

        public BookMethods(string title, string author, string publisher, int year, int pages)
        {
            _title = title;
            _author = author;
            _publisher = publisher;
            _year = year;
            _pages = pages;
        }
    }
}
