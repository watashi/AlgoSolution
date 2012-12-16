using System;

public class Relation
{
	public static void Main(String[] args)
	{
		int[, ] c = new int[11, 11];
		int[] dp = new int[11];
		int n;

		for (int i = 0; i <= 10; i++) {
			c[i, 0] = c[i, i] = 1;
			for (int j = 1; j < i; j++) {
				c[i, j] = c[i - 1, j - 1] + c[i - 1, j];
			}
		}
		dp[0] = 1;
		for (int i = 1; i <= 10; i++) {
			dp[i] = 0;
			for (int j = 1; j <= i; j++) {
				dp[i] += c[i, j] * dp[i - j];
			}
		}

		while ((n = Int32.Parse(Console.ReadLine())) != -1) {
			Console.WriteLine(dp[n]);
		}
	}
}
/*
id => 4678066
date => 03:44:4716 Dec 2012
user => watashi
pname => Relations
lang => C#
status => Accepted
testid => 
time => 0.125
mem => 2 096 KB
pid => 1142
*/
