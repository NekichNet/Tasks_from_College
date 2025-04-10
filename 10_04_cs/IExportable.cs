using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _10_04_cs
{
    public interface IExportable
    {
        string ExportToJson();
        string ExportToXML();
    }
}
