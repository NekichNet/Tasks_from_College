using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20_03_cs
{
	public class Library<T> : IMediaManager<T> where T : Media
	{
		private Dictionary<string, T> media_ = new Dictionary<string, T>();
		public Dictionary<string, T> Media { get { return media_; } }

		public void Add(T item) {
			media_.Add(item.Title, item);
		}
		public bool Remove(string item) {
			if (media_.ContainsKey(item))
			{
				media_.Remove(item);
				return true;
			}
			else return false;
		}
		public T FindByTitle(string title) {
			if (media_.ContainsKey(title))
				return media_[title];
			return null;
		}
		public IEnumerable<T> FilterByYear(ushort year) {
			return (IEnumerable<T>)media_.Values.Where(media => media.YearPublished == year).ToList();
		}
		public IEnumerable<T> GetAllAvailable() {
			return (IEnumerable<T>)media_.Values.Where(media => media.IsAvailable).ToList();
		}
		public IEnumerable<T> GetAllUnavailable()
		{
			return (IEnumerable<T>)media_.Values.Where(media => !media.IsAvailable).ToList();
		}
		public bool SetAvailable(string title, bool isAvailable = true)
		{
			if (media_.ContainsKey(title))
			{
				media_[title].IsAvailable = isAvailable;
				return true;
			}
			else return false;
		}
		public void PrintAll()
		{
			foreach (T item in media_.Values)
			{
				Console.WriteLine(item.GetInfo());
			}
		}
	}

	static public class ExtendedLibrary
	{
		static public IEnumerable<Book> GetBooksNewerThan(ushort afterYear, ref Library<Book> lib)
		{
			return (IEnumerable<Book>)lib.Media.Values.Where(media => media.YearPublished > afterYear).ToList();
		}
		static public IEnumerable<Movie> SortMoviesByDuration(ushort afterYear, ref Library<Movie> lib)
		{
			return lib.Media.Values.OrderBy(media => media.Duration).ToList();
		}
	}
}
