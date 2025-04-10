using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _10_04_cs
{
    public enum Rarity
    {
        Common, Rare, Epic, Legendary
    }

    abstract public class Artifact
    {
        public Artifact(int id, string name, int powerLevel, Rarity rarity)
        {
            Id = id;
            Name = name;
            PowerLevel = powerLevel;
            Rarity = rarity;
        }

        public int Id { get; set; }
        public string Name { get; set; }
        public int PowerLevel { get; set; }
        public Rarity Rarity { get; set; }

        public abstract string Serialize();
    }
}
