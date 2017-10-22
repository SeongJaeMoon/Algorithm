using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System;
using System.Net;

namespace HttpTest
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Running as {0}", Environment.GetEnvironmentVariable("PROCESSOR_ARCHITECTURE"));
            using (HttpListener s = new HttpListener())
            {
                s.Prefixes.Add("http://localhost:49154/vshub/418f29b9cebf4d6bae64d16162f56832/");
                s.Start();
                Console.WriteLine("Server started");
            }

            Console.WriteLine("Server stopped");
        }
    }
}
