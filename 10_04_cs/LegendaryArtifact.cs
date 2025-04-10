using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _10_04_cs
{
    public class LegendaryArtifact : Artifact
    {
        public LegendaryArtifact() : base(0, "", 0, Rarity.Common)
        {
            CurseDescription = "";
            IsCursed = false;
        }

        public LegendaryArtifact(int id, string name, int powerLevel,
            Rarity rarity, string curseDescription, bool isCursed)
            : base(id, name, powerLevel, rarity)
        {
            CurseDescription = curseDescription;
            IsCursed = isCursed;
        }

        public string CurseDescription { get; set; }
        public bool IsCursed { get; set; }

        public override string Serialize()
        {
            return "Id: " + Id + " Name: " + Name + " PowerLevel: "
                + PowerLevel + " Rarity: " + Rarity + " Curse Description: "
                + CurseDescription + " Is Cursed: " + IsCursed;
        }
    }
}
