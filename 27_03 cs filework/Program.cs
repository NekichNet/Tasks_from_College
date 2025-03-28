using System.Runtime.Serialization.Formatters.Binary;

namespace _27_03_cs_filework
{
    internal class Program
    {
        static void Main(string[] args)
        {
            var account = new PaymentAccount
            { DailyPayment = 100, NumberOfDays = 30, PenaltyPerDay = 10, DelayDays = 5 };
            Console.WriteLine(account.ToString());
            using(FileStream fs = new FileStream("account.dat", FileMode.OpenOrCreate))
            {
                BinaryFormatter formatter = new BinaryFormatter();
            }
        }
    }
}
