namespace _27_02
{
	internal class Program
	{
		static void Main(string[] args)
		{
			Dictionary<string, string> engToRus = new Dictionary<string, string>();
			Dictionary<string, string> rusToEng = new Dictionary<string, string>();
			engToRus.Add("Russia", "Россия");
            engToRus.Add("USA", "США");
            engToRus.Add("UK", "Великобритания");
            engToRus.Add("China", "Китай");

			foreach (string key in engToRus.Keys) {
				rusToEng.Add(engToRus[key], key);
			}

			string choice = "";
			Console.Write("С какого языка перевод: ");
			choice = Console.ReadLine();
			string country = "";
            Console.Write("Введите название страны: ");
            country = Console.ReadLine();

            switch (choice)
			{
				case "ru":
					Console.WriteLine(rusToEng[country]);
					break;
				case "eng":
                    Console.WriteLine(engToRus[country]);
					break;
                default:
					Console.WriteLine("Ошибка");
					break;
			}
        }
	}
}