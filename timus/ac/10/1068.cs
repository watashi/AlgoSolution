//原来天皇的题目在这里有原型-_-b
//P.S. the sample is so hd
using System;
class Sum	//1068. Sum
{
	static void Main(string[] args)
	{
		int ans = 0;
		int n = Int32.Parse(Console.ReadLine());
		if (n >= 1)
		{
			for (int i = 1; i <= n; i++)
				ans += i;
		}
		else
		{
			for (int i = 1; i >= n; i--)
				ans += i;
		}
		Console.WriteLine(ans);
	}
}
//ID Date Author Problem Language Judgement result Test # Execution time Memory used 
//1873236 14:31:58 16 Nov 2007 watashi 1068 C# Accepted  0.109 1 913 KB 
/*
id => 4677347
date => 18:03:2615 Dec 2012
user => watashi
pname => Sum
lang => C#
status => Accepted
testid => 
time => 0.125
mem => 1 968 KB
pid => 1068
*/
