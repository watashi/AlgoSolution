using System;
using System.Collections;

public class Standing
{
	public static void Main(string[] args)
	{
		ArrayList[] a = new ArrayList[100 + 1];
		int n = int.Parse(Console.ReadLine());
		string s;

		for (int i = 0; i <= 100; i++)
		{
			a[i] = new ArrayList();
		}
		while (n-- > 0)
		{
			s = Console.ReadLine();
			a[int.Parse(s.Split(' ')[1])].Add(s);
		}
		for (int i = 100; i >= 0; i--)
		{
			foreach (string o in a[i])
			{
				Console.WriteLine(o);
			}
		}
	}
}
/*
id => 4677352
date => 18:04:3515 Dec 2012
user => watashi
pname => Final Standings
lang => C#
status => Accepted
testid => 
time => 0.375
mem => 12 128 KB
pid => 1100
*/
