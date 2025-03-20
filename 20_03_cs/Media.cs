using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace _20_03_cs
{
	public class Media
	{
		public string Title { get; set; }
		public string Author { get; set; }
		public ushort YearPublished { get; set; }
		public bool IsAvailable { get; set; }

		public Media(string title, string author, ushort yearPublished, bool isAvailable)
		{
			Title = title;
			Author = author;
			YearPublished = yearPublished;
			IsAvailable = isAvailable;
		}

		virtual public string GetInfo()
		{
			return Title + ": author " + Author + "; year " + YearPublished + "; available " + IsAvailable + ";";
		}
	}
}
