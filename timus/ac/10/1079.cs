using System;
class Maximum	//1079. Maximum
{
	static void Main(string[] args)
	{
		const int MAXN=100000;
		int[] a = new int[MAXN];
		a[0] = 0;
		a[1] = 1;
		for (int i = 2; i < MAXN; i++)
		{
			if ((i & 1) == 0)
			{
				a[i] = a[i >> 1];
			}
			else
			{
				int j = i >> 1;
				a[i] = a[j] + a[j + 1];
			}
		}
		for (int i = 1; i < MAXN; i++)
		{
			a[i] = (a[i] > a[i - 1]) ? a[i] : a[i - 1];
		}
		string cur;
		while ((cur = Console.ReadLine()) != null)
		{
			int x = Int32.Parse(cur);
			if (x == 0) break;
			else Console.WriteLine(a[x]);
		}
	}
}
//ID Date Author Problem Language Judgement result Test # Execution time Memory used 
//1873225 14:23:41 16 Nov 2007 watashi 1079 C# Accepted  0.078 2 333 KB 
/*
id => 4677348
date => 18:03:4715 Dec 2012
user => watashi
pname => Maximum
lang => C#
status => Accepted
testid => 
time => 0.14
mem => 2 408 KB
pid => 1079
*/
