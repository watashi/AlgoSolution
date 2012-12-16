using System;
using System.Globalization;
using System.Threading;

public class Election
{
	public static void Main(String[] args)
	{
		// Thread.CurrentThread.CurrentCulture = new CultureInfo("ru-ru");
		Thread.CurrentThread.CurrentCulture = new CultureInfo("en-us");
		
		string[] input = Console.ReadLine().Split(' ');
		int n = int.Parse(input[0]), m = int.Parse(input[1]);
		int[] c = new int[n + 1];

		for (int i = 1; i <= n; i++) {
			c[i] = 0;
		}
		for (int j = 1; j <= m; j++) {
			++c[int.Parse(Console.ReadLine())];
		}
		if (m == 0) {
			m = 1;
		}
		for (int i = 1; i <= n; i++) {
			Console.WriteLine("{0:0.00%}", (double) c[i] / (double) m);
		}
	}
}
/*
id => 4678076
date => 03:47:4416 Dec 2012
user => watashi
pname => Elections
lang => C#
status => Accepted
testid => 
time => 0.14
mem => 2 464 KB
pid => 1263
*/
