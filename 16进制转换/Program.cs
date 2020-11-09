using System;

namespace _16进制转化
{
	class Program
	{
		static void Main(string[] args)
		{
			Console.WriteLine("请输入一个数：");
			int a = Convert.ToInt32(Console.ReadLine());
			Console.WriteLine("十六进制为：");
			while (true)
			{
				if (a < 10)
				{
					Console.Write("{0}", a);
					break;
				}
				else if (16 > a && a >= 10)
				{
					a = a % 16;
					switch (a)
					{
						case 10:
							Console.Write("A");
							break;
						case 11:
							Console.Write("B");
							break;
						case 12:
							Console.Write("C");
							break;
						case 13:
							Console.Write("D");
							break;
						case 14:
							Console.Write("E");
							break;
						case 15:
							Console.Write("F");
							break;
					}
					break;
				}
				else if (a >= 16)
				{
					Console.Write("{0}", a / 16);
					if (a % 16 == 0)
					{
						a = 0;
					}
					a = a % 16;
				}
			}
		}
	}
}
