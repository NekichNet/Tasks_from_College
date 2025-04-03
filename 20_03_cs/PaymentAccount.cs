using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Runtime.Serialization;
using System.Text;
using System.Threading.Tasks;
using System.Xml;
using System.Xml.Linq;
using System.Xml.Serialization;

namespace ConsoleApp3
{
    [Serializable]
    public class PaymentAccount : ISerializable
    {
        // Поля
        public decimal DailyPayment { get; set; }
        public int NumberOfDays { get; set; }
        public decimal PenaltyPerDay { get; set; }
        public int DelayDays { get; set; }

        // Вычисляемые поля
        [XmlIgnore]
        public decimal TotalWithoutPenalty => DailyPayment * NumberOfDays;
        [XmlIgnore]
        public decimal Penalty => PenaltyPerDay * DelayDays;
        [XmlIgnore]
        public decimal TotalWithPenalty => TotalWithoutPenalty + Penalty;

        // Статическое свойство для управления сериализацией
        [XmlIgnore]
        public static bool SerializeComputedFields { get; set; } = true;

        // Конструктор для создания объекта
        public PaymentAccount(decimal dailyPayment, int numberOfDays, decimal penaltyPerDay, int delayDays)
        {
            DailyPayment = dailyPayment;
            NumberOfDays = numberOfDays;
            PenaltyPerDay = penaltyPerDay;
            DelayDays = delayDays;
        }

        // Метод для сериализации
        public void GetObjectData(SerializationInfo info, StreamingContext context)
        {
            info.AddValue("DailyPayment", DailyPayment);
            info.AddValue("NumberOfDays", NumberOfDays);
            info.AddValue("PenaltyPerDay", PenaltyPerDay);
            info.AddValue("DelayDays", DelayDays);

            if (SerializeComputedFields)
            {
                info.AddValue("TotalWithoutPenalty", TotalWithoutPenalty);
                info.AddValue("Penalty", Penalty);
                info.AddValue("TotalWithPenalty", TotalWithPenalty);
            }
        }

        // Переопределение ToString для удобного вывода
        public override string ToString()
        {
            return $"Daily Payment: {DailyPayment}\n" +
                   $"Number of Days: {NumberOfDays}\n" +
                   $"Penalty Per Day: {PenaltyPerDay}\n" +
                   $"Delay Days: {DelayDays}\n" +
                   $"Total Without Penalty: {TotalWithoutPenalty}\n" +
                   $"Penalty: {Penalty}\n" +
                   $"Total With Penalty: {TotalWithPenalty}";
        }

        public void ToXmlFile(string filepath)
        {
            XmlDocument doc = new XmlDocument();

            XmlElement dailyPaymentEl = doc.CreateElement("DailyPayment");
            dailyPaymentEl.InnerText = DailyPayment.ToString(CultureInfo.InvariantCulture);

            XmlElement numberOfDaysEl = doc.CreateElement("NumberOfDays");
            numberOfDaysEl.InnerText = DailyPayment.ToString();

            XmlElement penaltyPerDayEl = doc.CreateElement("PenaltyPerDay");
            penaltyPerDayEl.InnerText = PenaltyPerDay.ToString(CultureInfo.InvariantCulture);

            XmlElement delayDaysEl = doc.CreateElement("DelayDays");
            delayDaysEl.InnerText = DelayDays.ToString();

            doc.AppendChild(dailyPaymentEl);
            doc.AppendChild(numberOfDaysEl);
            doc.AppendChild(penaltyPerDayEl);
            doc.AppendChild(delayDaysEl);

            doc.Save(filepath);
        }

        public void ToJson(string filepath)
        {
            try
            {
                string json = JsonConvert.SerializeObject(this, Newtonsoft.Json.Formatting.Indented);
                File.WriteAllText(filepath, json);
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }

        public static PaymentAccount FromJson(string filepath)
        {
            try
            {
                string json = File.ReadAllText(filepath);
                return JsonConvert.DeserializeObject<PaymentAccount>(json);
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
                return null;
            }
        }
    }
}
