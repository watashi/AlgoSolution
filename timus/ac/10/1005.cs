using System;

class KnapsackProblem	//1005. Stone pile
{
	static void Main(string[] args)
	{
		string input = "";
		string cur;
		while ((cur = Console.ReadLine()) != null)
		{
			if (input != "") input += " ";
			input += cur;
		}
		string[] data = input.Split(' ');
		int n = Int32.Parse(data[0]);
		int[] w = new int[n];
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			w[i] = Int32.Parse(data[i+1]);
			sum += w[i];
		}
		int m = sum / 2;
		bool[] dp = new bool[m+1];
		dp[0]=true;
		for (int i = 0; i < n; i++)
		{
			for (int j = m; j >= w[i]; j--)
			{
				if (dp[j - w[i]]) dp[j] = true;
			}
		}
		int ans = m;
		while (dp[ans] == false) ans--;
		Console.WriteLine(sum - ans - ans);
	}
}

//输入数据不规范

//ID Date Author Problem Language Judgement result Test # Execution time Memory used 
//1873126 13:21:44 16 Nov 2007 watashi 1005 C# Accepted  0.125 2 013 KB 
/*
id => 4677342
date => 18:02:1215 Dec 2012
user => watashi
pname => Stone Pile
lang => C#
status => Accepted
testid => 
time => 0.14
mem => 2 040 KB
pid => 1005
*/
