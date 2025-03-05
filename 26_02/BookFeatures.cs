using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _26_02
{
	internal class BookFeatures
	{
		private string _title, _author;
		private int _year, _pages;

		public string Title { get; set; }
		public string Author => _author;
		public string Publisher { get; }
		public string Info => $"Название: {Title}, Автор: {_author}," +
			$" Год издания: {_year}, Кол-во страниц: {_pages}, Издатель: {Publisher}";

		public BookFeatures(string title, string author, int year, int pages, string publisher)
		{
			_title = title;
			_author = author;
			_year = year;
			_pages = pages;
			Publisher = publisher;
		}
	}
}
