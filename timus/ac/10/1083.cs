using System;
class Factorials	//1083. Factorials!!!
{
	static void Main(string[] args)
	{
		string[] str = Console.ReadLine().Split(' ');
		int n = Int32.Parse(str[0]);
		int k = str[1].Length;
		int ans = 1;
		for (int i = n; i > 0; i -= k)
		{
			ans *= i;
		}
		Console.WriteLine(ans);
	}
}
//ID Date Author Problem Language Judgement result Test # Execution time Memory used 
//1873189 14:02:24 16 Nov 2007 watashi 1083 C# Accepted  0.062 1 997 KB 
/*
id => 4677350
date => 18:04:1115 Dec 2012
user => watashi
pname => Factorials!!!
lang => C#
status => Accepted
testid => 
time => 0.125
mem => 1 992 KB
pid => 1083
*/
