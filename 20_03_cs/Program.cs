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

			XmlDocument doc = new XmlDocument();
			XmlElement company = doc.CreateElement("Company");
			XmlElement employee = doc.CreateElement("Employee");
			employee.SetAttribute("Id", "1");
			employee.AppendChild(doc.CreateElement("Name", "John"));
            employee.AppendChild(doc.CreateElement("Age", "20"));
            company.AppendChild(employee);
            company.AppendChild(employee);
            company.AppendChild(employee);
            doc.AppendChild(company);
            doc.Save("document.xml");
        }
	}
}
