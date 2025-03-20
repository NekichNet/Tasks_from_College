using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20_03_cs
{
    public interface IMediaManager<T> where T : Media
    {
        public void Add(T item);
        public bool Remove(string item);
        public T FindByTitle(string title);
        public IEnumerable<T> FilterByYear(ushort year);
        public IEnumerable<T> GetAllAvailable();
    }
}
