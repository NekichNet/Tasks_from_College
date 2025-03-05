using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _27_02
{
    internal class Purchase<T> where T : IPayment
    {
        public string PhoneNumber { get; }
        T PayType { get; }
        public double Sum { get; }

        Purchase(T payType, double sum) {
            PayType = payType;
            Sum = sum;
            PayType.Sum = sum;
        }

        public string Info()
        {
            return $"Сумма: {Sum}, Тип оплаты: {PayType.Type}, Номер тел.: {PhoneNumber}, ";
        }
    }
}
