namespace Timus
{
	class StaticIntervalSum	//1330. Intervals
	{
		static void Main()
		{
			int n = int.Parse(System.Console.ReadLine());
			int[] a = new int[n + 1];
			a[0] = 0;
			for (int i = 1; i <= n; i++)
				a[i] = a[i - 1] + int.Parse(System.Console.ReadLine());
			int m = int.Parse(System.Console.ReadLine());
			while (m-- != 0)
			{
				string tmp = System.Console.ReadLine();
				int pos = tmp.IndexOf(' ');
				int f = int.Parse(tmp.Substring(0, pos));
				int t = int.Parse(tmp.Substring(pos + 1));
				System.Console.WriteLine(a[t] - a[f - 1]);
			}
		}
	}
}
//ID Date Author Problem Language Judgement result Test # Execution time Memory used 
//1893103 19:33:31 2 Dec 2007 watashi 1330 C# Time limit exceeded 21 0.531 2 089 KB 
//1893108 19:34:37 2 Dec 2007 watashi 1330 C# Time limit exceeded 20 0.546 2 081 KB 
//1893119 19:38:41 2 Dec 2007 watashi 1330 C# Accepted  0.437 2 105 KB
/*
id => 4678342
date => 12:18:1216 Dec 2012
user => watashi
pname => Intervals
lang => C#
status => Accepted
testid => 
time => 0.406
mem => 2 400 KB
pid => 1330
*/
