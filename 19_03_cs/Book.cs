﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _19_03_cs
{
    public class Book
    {
        public string Name { get; set; }
        public string Author { get; set; }

        public Book(string name, string author)
        {
            Name = name;
            Author = author;
        }
    }
}
