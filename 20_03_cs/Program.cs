namespace _20_03_cs
{
	internal class Program
	{
		static void Main(string[] args)
		{
			Library<Media> lib = new Library<Media>();
			lib.Add(new Book(14, "meme", "MyMeme123", "me", 1954, true));
            lib.Add(new MusicAlbum(50, "my cousin", "Trash", "my cousin", 2001, false));
			lib.PrintAll();
			Console.WriteLine(((List<Media>)lib.FilterByYear(1954))[0].GetInfo());
        }
	}
}
