namespace Timus
{
	class DiagonalMonitor	//1313. Some words about sport
	{
		private static int max(int a, int b)
		{
			return (a > b) ? a : b;
		}
		static void Main()
		{
			int n = System.Int32.Parse(System.Console.ReadLine());
			int[,] a = new int[n, n];
			for (int i = 0; i < n; i++)
			{
				string[] cur = System.Console.ReadLine().Split(' ');
				for (int j = 0; j < n; j++)
					a[i, j] = System.Int32.Parse(cur[j]);
			}
			int m = n + n - 2;
			for (int i = 0; i <= m; i++)
				for (int j = max(0, i - n + 1); j < n && j <= i; j++)
					System.Console.Write(a[i-j, j] + ((i == m && j == n - 1) ? "\n" : " "));
		}
	}
}
//ID Date Author Problem Language Judgement result Test # Execution time Memory used 
//1893016 18:51:33 2 Dec 2007 watashi 1313 C# Accepted  0.093 2 053 KB 

/*
id => 4678338
date => 12:16:5716 Dec 2012
user => watashi
pname => Some Words about Sport
lang => C#
status => Accepted
testid => 
time => 0.109
mem => 2 096 KB
pid => 1313
*/
