using ConsoleApp3;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using System.Xml;
using System.Xml.Linq;
using System.Xml.Serialization;

namespace _20_03_cs
{
	internal class Program
	{
		static void Main(string[] args)
		{
			//Library<Media> lib = new Library<Media>();
			//lib.Add(new Book(14, "meme", "MyMeme123", "me", 1954, true));
			//         lib.Add(new MusicAlbum(50, "my cousin", "Trash", "my cousin", 2001, false));
			//lib.PrintAll();
			//Console.WriteLine(((List<Media>)lib.FilterByYear(1954))[0].GetInfo());

			//var per = new Person("Vova", "Kovbaskus", "Kakoytotam", 20);
			//XmlSerializer xmlSerializer = new XmlSerializer(typeof(Person));

			//using(StreamWriter sw = new StreamWriter("kovbaskus.xml"))
			//{
			//	xmlSerializer.Serialize(sw, per);
			//}

			//XDocument doc = XDocument.Load("kovbaskus.xml");
			//var persons = doc.Descendants("Person");
			//foreach (var item in persons)
			//{
			//	Console.WriteLine(item.Element("Name")?.Value);
			//             Console.WriteLine(item.Element("Surname")?.Value);
			//             Console.WriteLine(item.Element("Lastname")?.Value);
			//             Console.WriteLine(item.Element("Age")?.Value);
			//         }

			//XmlDocument doc = new XmlDocument();
			//XmlElement company = doc.CreateElement("Company");
			//XmlElement employee = doc.CreateElement("Employee");
			//employee.SetAttribute("Id", "1");
			//employee.AppendChild(doc.CreateElement("Name", "John"));
			//         employee.AppendChild(doc.CreateElement("Age", "20"));
			//         company.AppendChild(employee);
			//         company.AppendChild(employee);
			//         company.AppendChild(employee);
			//         doc.AppendChild(company);
			//         doc.Save("document.xml");

			//var pers = new Person("Nikita", "Evstropov", "Vladimirovich", 18);
			//string json = JsonConvert.SerializeObject(pers, Newtonsoft.Json.Formatting.Indented);
			//Console.WriteLine(json);

			//			string json = @"{
			//""Employees"": [
			//{""Name"": ""Peter"", ""Age"": 20},
			//{""Name"": ""Anny"", ""Age"": 18},
			//{""Name"": ""John"", ""Age"": 24},
			//]
			//}";
			//			JObject obj = JObject.Parse(json);
			//			var names = obj["Employees"].Select(e => e["Name"].ToString()).ToList();
			//			foreach (var name in names)
			//			{
			//				Console.WriteLine(name);
			//			}

			var acc = new PaymentAccount(100m, 3, 50m, 4);
			Console.WriteLine(acc.ToString());
			acc.ToJson("accTrue.json");
			PaymentAccount.SerializeComputedFields = false;
			acc.ToJson("accFalse.json");
        }
	}
}
