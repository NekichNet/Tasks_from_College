namespace _12_02
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string highest = "0";
            while (highest != "")
            {
                Console.Write("Enter a number: ");
                string input = Console.ReadLine();
                highest = int.Parse(input) > int.Parse(highest) ? input : highest;
            }
            Console.WriteLine("Highest: " + highest);
        }
    }
}
