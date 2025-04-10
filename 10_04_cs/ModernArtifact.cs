using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.Json.Serialization;
using System.Threading.Tasks;

namespace _10_04_cs
{
    public class ModernArtifact : Artifact
    {
        public ModernArtifact(int id, string name, int powerLevel,
            Rarity rarity, double techlevel, string manufacturer) : base(id, name, powerLevel, rarity)
        {
            TechLevel = techlevel;
            Manufacturer = manufacturer;
        }

        public double TechLevel { get; set; }
        public string Manufacturer { get; set; }

        public override string Serialize()
        {
            return "Id: " + Id + " Name: " + Name + " PowerLevel: "
                + PowerLevel + " Rarity: " + Rarity + " Tech Level: "
                + TechLevel + " Manufacturer: " + Manufacturer;
        }
    }
}
