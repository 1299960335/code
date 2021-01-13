using System;
using System.Collections.Generic;

namespace TEST5
{
    class Program
    {
        public class Book
        {
            public Book(int ID, int Price, string Name)
            {
                V1 = ID;
                V2 = Price;
                V3 = Name;
            }
            public int V1 { get; }
            public int V2 { get; }
            public string V3 { get; }
        }
        static void Main(string[] args)
        {
            //构造数据
            List<Book> books = new List<Book>();
            books.Add(new Book(01, 59, "编程之美"));
            books.Add(new Book(09, 50, "剑指OFEER"));
            books.Add(new Book(17, 99, "C程序设计"));
            books.Add(new Book(36, 40, "编译原理教程"));
            Console.WriteLine("\n排序之前:");
            foreach (Book a in books)
            {
                Console.WriteLine(a.V1 + " " + a.V2 + " " + a.V3);
            }

            //按照序号进行排序
            books.Sort(delegate (Book a1, Book a2)
            {
                if (a1.V1.CompareTo(a2.V1) != 0)
                    return a1.V1.CompareTo(a2.V1);
                else if (a1.V2.CompareTo(a2.V2) != 0)
                    return a1.V2.CompareTo(a2.V2);
                else
                    return a1.V3.CompareTo(a2.V3);
            });
            Console.WriteLine("\n按照序号排序:");
            foreach (Book a in books)
            {
                Console.WriteLine(a.V1 + " " + a.V2 + " " + a.V3);
            }

            //按照名字排序
            books.Sort(delegate (Book x, Book y)
            {
                if (x.V3 == null && y.V3 == null) return 0;
                else if (x.V3 == null) return -1;
                else if (y.V3 == null) return 1;
                else return x.V3.CompareTo(y.V3);
            });

            Console.WriteLine("\n按照名字排序:");
            foreach (Book a in books)
            {
                Console.WriteLine(a.V1 + " " + a.V2 + " " + a.V3);
            }

        }
    }
}
