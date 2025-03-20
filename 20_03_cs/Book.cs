using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20_03_cs
{
    public class Book : Media
    {
        public uint Pages { get; set; }
        public string Genre { get; set; }

        public Book(uint pages, string genre,
            string title, string author, ushort yearPublished, bool isAvailable)
            : base(title, author, yearPublished, isAvailable)
        {
            Pages = pages;
            Genre = genre;
        }

        override public string GetInfo()
        {
            return Title + ": author " + Author + "; year " + YearPublished + "; available " + IsAvailable +
                "; pages " + Pages + "; genre " + Genre + ";";
        }
    }
}
