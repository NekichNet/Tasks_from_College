namespace _19_03_cs
{
	internal class Program
	{

		static void Main(string[] args)
		{
            /*
			Button button = new Button();

			button.Click += (sender, args) => { Console.WriteLine("Button is clicked"); };
			button.OnClick();
			
			var students = new List<Student>()
			{
				new Student("Bob", "Computer Science", 20),
                new Student("Alice", "Computer Science", 23),
                new Student("Andrew", "Biology", 19),
                new Student("Victoria", "Computer Science", 23),
                new Student("Jean", "Biology", 22),
                new Student("Peter", "Biology", 21)
            };

			var result = students.Where(x => x.Age > 20)
				.GroupBy(x => x.Fac)
				.Select(group => new
				{
					Faculty = group.Key,
					Count = group.Count()
				});
			foreach (var item in result)
			{
				Console.WriteLine(item.Faculty + " " + item.Count);
			}
			*/

            Library lib = new Library(new List<Book>{
                new Book("Voina i voina", "Tolstoy Tolstoy"),
                new Book("Nakazanie i nakazanie i nakazanie", "Cheburashka"),
                new Book("1945", "No name"),
                new Book("Vedma", "Vedma")
			});

            lib.BookAvailable += (name, author) => { Console.WriteLine($"Book is available!"); };

            List<Book> booksFound = lib.getByAuthor("Cheburashka");
		}
	}
}
