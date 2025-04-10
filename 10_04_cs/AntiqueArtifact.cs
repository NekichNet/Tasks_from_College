using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace _10_04_cs
{
    public class AntiqueArtifact : Artifact
    {
        public AntiqueArtifact(int id, string name, int powerLevel,
            Rarity rarity, int age, string originRealm) : base(id, name, powerLevel, rarity)
        {
            Age = age;
            OriginRealm = originRealm;
        }

        public int Age { get; set; }
        public string OriginRealm { get; set; }

        public override string Serialize()
        {
            return "Id: " + Id + " Name: " + Name + " PowerLevel: "
                + PowerLevel + " Rarity: " + Rarity + " Age: "
                + Age + " Origin Realm: " + OriginRealm;
        }
    }
}
