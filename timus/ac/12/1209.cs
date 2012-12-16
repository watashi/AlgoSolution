using System;

public class Digit
{
	private static bool judge(long x)
	{
		long i = (long)Math.Sqrt(2 * x);

		return i * (i + 1) == 2 * x;
	}

	public static void Main(String[] args)
	{
		int re = int.Parse(Console.ReadLine());
		
		while (re-- > 0)
		{
			Console.Write(judge(long.Parse(Console.ReadLine()) - 1) ? '1' : '0');
			Console.Write(re == 0 ? '\n' : ' ');
		}
	}
}
/*
id => 4678071
date => 03:46:1916 Dec 2012
user => watashi
pname => 1, 10, 100, 1000...
lang => C#
status => Accepted
testid => 
time => 0.25
mem => 2 200 KB
pid => 1209
*/
