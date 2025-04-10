using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Net.Mime.MediaTypeNames;
using static System.Runtime.InteropServices.JavaScript.JSType;

namespace _10_04_cs
{
    public class LegendaryProcessor : IDataProcessor<LegendaryArtifact>
    {
        public List<LegendaryArtifact> LoadData(string filePath)
        {
            List<LegendaryArtifact> list = new List<LegendaryArtifact>();
            using (StreamReader reader = new StreamReader(filePath))
            {
                string? line;
                while ((line = reader.ReadLine()) != null)
                {
                    List<string> data = line.Split('|').ToList();
                    LegendaryArtifact art = new LegendaryArtifact();
                    art.Id = Int32.Parse(data[0]);
                    art.Name = data[1];
                    art.PowerLevel = Int32.Parse(data[2]);
                    switch (data[3])
                    {
                        case "Common":
                            art.Rarity = Rarity.Common; break;
                        case "Rare":
                            art.Rarity = Rarity.Rare; break;
                        case "Epic":
                            art.Rarity = Rarity.Epic; break;
                        case "Legendary":
                            art.Rarity = Rarity.Legendary; break;
                    }
                    art.CurseDescription = data[4];
                    art.IsCursed = bool.Parse(data[5]);
                    list.Add(art);
                }
            }
            return list;
        }

        public void SaveData(List<LegendaryArtifact> data, string filePath)
        {
            using (StreamWriter writer = new StreamWriter(filePath, false))
            {
                foreach (LegendaryArtifact art in data)
                {
                    writer.WriteLine(art.Id + "|" + art.Name + "|" + art.PowerLevel + "|" + art.Rarity +
                        "|" + art.CurseDescription + "|" + art.IsCursed);
                }
            }
        }
    }
}
