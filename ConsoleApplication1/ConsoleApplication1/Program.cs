using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using ConsoleApplication1.ServiceReference1;
using ConsoleApplication1.Time;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            ManagerClient client = new ManagerClient();

            Console.WriteLine("Server open");
            // Используйте переменную "client", чтобы вызвать операции из службы.
            Console.WriteLine("Prem = " + client.GetPremium(5));

            Console.WriteLine("Prem = " + client.GetStavka(5));

            client.Close();

            WorkTimeClient client2 = new WorkTimeClient();

            Console.WriteLine("Server open");

            Console.WriteLine("Prem = " + client2.GetTime(5));

            client2.Close();

            Console.ReadKey();
        }
    }
}
