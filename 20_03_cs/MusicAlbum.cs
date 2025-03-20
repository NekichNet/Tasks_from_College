using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20_03_cs
{
    public class MusicAlbum : Media
    {
        public ushort TracksAmount { get; set; }
        public string Executor { get; set; }

        public MusicAlbum (ushort tracksAmount, string executor,
            string title, string author, ushort yearPublished, bool isAvailable)
            : base(title, author, yearPublished, isAvailable)
        {
            TracksAmount = tracksAmount;
            Executor = executor;
        }

        override public string GetInfo()
        {
            return Title + ": author " + Author + "; year " + YearPublished + "; available " + IsAvailable +
                "; tracks amount " + TracksAmount + "; executor " + Executor + ";";
        }
    }
}
