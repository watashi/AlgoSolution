using System;

public class IntPercent
{
	private static int gcd(int a, int b)
	{
		return b == 0 ? a : gcd(b, a % b);
	}

	public static void Main(String[] args)
	{
		string[] input = Console.ReadLine().Split(' ');
		int n = int.Parse(input[0]), s = int.Parse(input[1]), g, ans;
		int[] dp = new int[n + 1];
		
		for (int i = 0; i <= n; i++) {
			dp[i] = 0;
		}
		if (s <= n) {
			dp[s] = 1;
		}
		ans = 0;
		for (int i = 1; i <= n; i++) {
			if (dp[i] == 0) {
				continue;
			}
			ans = Math.Max(ans, dp[i]);
			g = i / gcd(i, 100);
			for (int j = i + g; j <= n; j += g) {
				dp[j] = Math.Max(dp[j], dp[i] + 1);
			}
		}
		Console.WriteLine(ans);
	}
}

//ID	Date	Author	Problem	Language	Judgement result	Test #	Execution time	Memory used
//2330111	14:59:34
//5 Nov 2008	watashi	1138	C#	Accepted	
//	0.109	782 KB
/*
id => 4678064
date => 03:44:0816 Dec 2012
user => watashi
pname => Integer Percentage
lang => C#
status => Accepted
testid => 
time => 0.125
mem => 2 032 KB
pid => 1138
*/
