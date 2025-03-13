namespace _13_03
{
    internal class Program
    {
        static void Main(string[] args)
        {
            List<Student> students = new List<Student>();

            students.Add(new Student("Настя", "ГД", new List<float>() { 4f, 3f, 3f, 2f, 4f }));
            students.Add(new Student("Игорь", "РПО", new List<float>() { 5f, 3f, 2f, 2f, 4f }));
            students.Add(new Student("Игорь2", "ГД", new List<float>() { 2f, 3f, 5f, 5f, 4f }));
            students.Add(new Student("Света", "ГД", new List<float>() { 5f, 3f, 1f, 2f, 3f }));
            students.Add(new Student("Дениска", "РПО", new List<float>() { 5f, 5f, 5f, 5f, 5f }));
            students.Add(new Student("Галя", "РПО", new List<float>() { 4f, 4f, 4f, 5f, 4f }));
            students.Add(new Student("Виталий", "ГД", new List<float>() { 3f, 4f, 5f, 4f, 3f }));

            Dictionary<string, List<Student>> facs = new Dictionary<string, List<Student>>();

            foreach (Student student in students) {
                if (!facs.ContainsKey(student.Fac)) { facs.Add(student.Fac, new List<Student>()); }
                facs[student.Fac].Add(student);
            }

            foreach (string fac in facs.Keys)
            {
                Console.WriteLine("Факультет: " + fac);
                float sum = 0f;
                Student best = null;
                foreach (Student student in facs[fac]) {
                    sum += student.Marks.Average();
                    if (best == null) { best = student; }
                    else if (student.Marks.Average() >= best.Marks.Average()) { best = student; }
                }
                Console.WriteLine("Средний балл: " + (sum / facs[fac].Count));
                if (best != null)
                    Console.WriteLine("Лучший студент: " + best.Name + " " + best.Marks.Average() + "\n");
            }
        }
    }
}
