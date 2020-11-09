using System;

namespace ConsoleApp4
{
    class Program
    {
        static void Main(string[] args)
        {
            char[] a = Console.ReadLine().ToCharArray();//逐个输入，使输入的数据类型有string变成char[]
            int[] d = new int[100];
            int b = 0, c = 0;
            for (int i = 0; i < a.Length; i++)
            {
                if (a[i] >= 48 && a[i] <= 57)//判断当前第一个是否为数字
                {
                    b = a[i] - 48;//由于数组存储的是ascall值，所以减
                    while (true)
                    {
                        if (i < a.Length - 1) //防止下面越界
                        {
                            if (a[i + 1] >= 48 && a[i + 1] <= 57)//判断下一位是否为数字
                            {
                                if (a[i] + 1 == a[i + 1])//判断下一位是否连续
                                {

                                    b = b * 10 + a[i + 1] - 48;
                                    i++;

                                }
                                else
                                    break;
                            }
                            else
                                break;
                        }
                        else
                            break;
                    }

                    d[c] = b;//将符合的值存入d[]
                    c++;//记录数组长度

                }

            }
            int[] h = new int[100];
            int l = 0;
            for (int i = 0; i < c; i++)//将单个数字的整数剔除
            {

                if (d[i] > 9)
                {
                    h[l] = d[i];
                    l++;
                }
            }
            Console.WriteLine("共有{0}个整数", l);
            for (int i = 0; i < l; i++)
                Console.WriteLine(h[i]);
        }
    }
}
