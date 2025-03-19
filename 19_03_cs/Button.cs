using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _19_03_cs
{
    public class Button
    {
        public delegate void ClickEventHandler(object sender, EventArgs eventArgs);
        public event ClickEventHandler Click;
        public void OnClick() {
            Click?.Invoke(this, EventArgs.Empty);
        }
    }
}
