// 最小环 min circle

using System;

public class Trip
{
	private const int inf = 1000000000;
	private int n;
	private int[, ] e, d, p;

	private string gao(int i, int j)
	{
		if (p[i, j] == -1)
		{
			return " " + (i + 1);
		}
		else
		{
			return gao(i, p[i, j]) + gao(p[i, j], j);
		}
	}

	public void Gao()
	{
		int a, b, t = inf;
		string s = "No solution.";

		for (int k = 0; k < n; k++)
		{
			a = b = -1;
			for (int i = 0; i < k; i++)
			{
				for (int j = i + 1; j < k; j++)
				{
					if (e[k, i] < inf && e[j, k] < inf && e[k, i] + d[i, j] + e[j, k] < t)
					{
						t = e[k, i] + d[i, j] + e[j, k];
						a = i;
						b = j;
					}
				}
			}
			if (a != -1)
			{
				s = (k + 1) + gao(a, b) + " " + (b + 1);
			}
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (d[i, k] + d[k, j] < d[i, j])
					{
						d[i, j] = d[i, k] + d[k, j];
						p[i, j] = k;
					}
				}
			}
		}
		Console.WriteLine(s);
	}

	public void AddEdge(int a, int b, int c)
	{
		e[a, b] = e[b, a] = d[a, b] = d[b, a] = Math.Min(d[a, b], c);
	}

	public Trip(int n)
	{
		this.n = n;
		e = new int[n, n];
		d = new int[n, n];
		p = new int[n, n];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				e[i, j] = inf;
				d[i, j] = inf;
				p[i, j] = -1;
			}
		}
	}

	public static void Main(string[] args)
	{
		string s;

		while ((s = Console.ReadLine()) != "-1")
		{
			string[] ss = s.Split(' ');
			Trip trip = new Trip(int.Parse(ss[0]));
			int m = int.Parse(ss[1]);
			
			while (m-- > 0)
			{
				string[] input = Console.ReadLine().Split(' ');

				trip.AddEdge(int.Parse(input[0]) - 1, int.Parse(input[1]) - 1, int.Parse(input[2]));
			}
			trip.Gao();
		}
	}
}
/*
id => 4677341
date => 18:01:5515 Dec 2012
user => watashi
pname => Sightseeing Trip
lang => C#
status => Accepted
testid => 
time => 0.171
mem => 3 300 KB
pid => 1004
*/
