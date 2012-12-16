namespace Timus
{
	class DiagonalSquare	//1319. The Hotel
	{
		static void Main()
		{
			int n = System.Int32.Parse(System.Console.ReadLine());
			int[,] a = new int[n, n];
			int k = 0;
			for (int i = n - 1; i >= 1 - n; i--)
				for (int j = System.Math.Max(0, i); j < i + n && j < n; j++)
					a[j - i, j] = ++k;
			for (int i = 0; i < n; i++)
			{
				System.Console.Write(a[i, 0]);
				for (int j = 1; j < n; j++)
					System.Console.Write(" " + a[i, j]);
				System.Console.WriteLine();
			}
		}
	}
}
//ID Date Author Problem Language Judgement result Test # Execution time Memory used 
//1893066 19:14:33 2 Dec 2007 watashi 1319 C# Accepted  0.078 2 085 KB 
/*
id => 4678339
date => 12:17:2316 Dec 2012
user => watashi
pname => Hotel
lang => C#
status => Accepted
testid => 
time => 0.109
mem => 2 096 KB
pid => 1319
*/
