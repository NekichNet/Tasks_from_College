using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20_03_cs
{
    public class Movie : Media
    {
        public uint Duration { get; set; }
        public string Director { get; set; }

        public Movie(uint duration, string director,
            string title, string author, ushort yearPublished, bool isAvailable)
            : base(title, author, yearPublished, isAvailable)
        {
            Duration = duration;
            Director = director;
        }

        override public string GetInfo()
        {
            return Title + ": author " + Author + "; year " + YearPublished + "; available " + IsAvailable +
                "; duration " + Duration + "; director " + Director + ";";
        }
    }
}
