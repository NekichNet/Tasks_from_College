using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _10_04_cs
{
    public class ShopManager
    {
        public List<Artifact> Artifacts { get; set; }
        public void LoadAllData(string filename)
        {
            XmlProcessor xml_processor = new XmlProcessor();
            JsonProcessor json_processor = new JsonProcessor();
            LegendaryProcessor legendary_processor = new LegendaryProcessor();

            Artifacts.Clear();
            Artifacts.Concat(xml_processor.LoadData(filename + ".xml"));
            Artifacts.Concat(json_processor.LoadData(filename + ".json"));
            Artifacts.Concat(legendary_processor.LoadData(filename + ".txt"));
        }
    }
}
