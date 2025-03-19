using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static _19_03_cs.Button;

namespace _19_03_cs
{
    public class Library
    {
        public delegate void AvailableEventHandler(string name, string author);
        public event AvailableEventHandler BookAvailable;

        public List<Book> getBook(string name = null, string author = null)
        {
            List<Book> result = new List<Book>();
            if (name != null) {
                result = (List<Book>)result.Concat(this.Books.Where(book => book.Name == name).ToList());
            }
            if (author != null) {
                result = (List<Book>)result.Concat(this.Books.Where(book => book.Author == author).ToList());
            }
            return result;
        }

        public List<Book> Books { get; set; }

        public Library(List<Book> books) {
            Books = books;
        }

        public void setAvailable(string name, string author)
        {
            BookAvailable?.Invoke(name, author);
        }
    }
}
