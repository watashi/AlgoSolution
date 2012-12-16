using System;

public class CityBlocks
{
	public static void Main(String[] args)
	{
		string[] input = Console.ReadLine().Split(' ');
		int n = int.Parse(input[0]), m = int.Parse(input[1]);
		int ans = 0;

		--n;
		--m;
		for (int i = 1; i <= m; i++) {
			ans += (i * n + m - 1) / m - ((i - 1) * n) / m;
		}
		Console.WriteLine(ans);
	}
}
/*
id => 4678065
date => 03:44:2616 Dec 2012
user => watashi
pname => City Blocks
lang => C#
status => Accepted
testid => 
time => 0.125
mem => 2 012 KB
pid => 1139
*/
