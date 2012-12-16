//ORZ
//for n = 0 solution is 10
//This is a stupid trick, since q = 0 is not considered positive. Hope it saves a few minutes of your life. 

using System;

class TheProductOfDigits	//1014. The Product of Digits
{
	static void Main(string[] args)
	{
		int[] a=new int[33];
		int n=0;
		int t = Int32.Parse(Console.ReadLine());
		if (t == 0)
		{
			Console.WriteLine(10);
			return;
		}
		else if (t == 1)
		{
			Console.WriteLine(1);
			return;
		}
		for (int i = 9; i > 1; i--)
		{
			while (t % i == 0)
			{
				a[n++] = i;
				t /= i;
			}
		}
		if (t >= 10)
		{
			Console.WriteLine(-1);
			return;
		}
		for (int i = --n; i > 0; i--)
		{
			Console.Write(a[i]);
		}
		Console.WriteLine(a[0]);
	}
}
//ID Date Author Problem Language Judgement result Test # Execution time Memory used 
//1873166 13:44:52 16 Nov 2007 watashi 1014 C# Accepted  0.078 1 941 KB 


//TEST #3 : 1 // 1	// -1
//TEST #4 : 0 // 10	// -1 || 0
//啊~好题>.<
/*
id => 4677343
date => 18:02:2815 Dec 2012
user => watashi
pname => Product of Digits
lang => C#
status => Accepted
testid => 
time => 0.125
mem => 2 016 KB
pid => 1014
*/
