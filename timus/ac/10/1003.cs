// Friend-Enemy DisjointSet

using System;
using System.Collections;

public class Parity
{
	private Hashtable h;
	private int[] p;

	private int root(int i)
	{
		if (p[i] > 0)
		{
			return p[i] == i ? p[i] : (p[i] = root(p[i]));
		}
		else
		{
			return p[-p[i]] == -p[i] ? p[i] : (p[i] = -root(-p[i]));
		}
	}

	private void setFriend(int i, int j)
	{
		i = root(i);
		j = root(j);
		if (i == -j)
		{
			throw new Exception();
		}
		if (i > 0)
		{
			p[i] = j;
		}
		else
		{
			p[-i] = -j;
		}
	}

	private void setEnemy(int i, int j)
	{
		i = root(i);
		j = root(j);
		if (i == j)
		{
			throw new Exception();
		}
		if (i > 0)
		{
			p[i] = -j;
		}
		else
		{
			p[-i] = j;
		}
	}

	public Parity()
	{
		h = new Hashtable();
		p = new int[10001];
		for (int i = 1; i <= 10000; i++)
		{
			p[i] = i;
		}
	}

	private int hash(int i)
	{
		if (h.Contains(i))
		{
			return (int)h[i];
		}
		else
		{
			h.Add(i, h.Count + 1);
			return h.Count;
		}
	}

	public void Run()
	{
		int m = int.Parse(Console.ReadLine());

		for (int i = 0; i < m; i++) {
			string[] input = Console.ReadLine().Split(' ');
			int a = hash(int.Parse(input[0])), b = hash(int.Parse(input[1]) + 1);

			try
			{
				switch (input[2])
				{
					case "even": setFriend(a, b); break;
					case "odd": setEnemy(a, b); break;
				}
			}
			catch (Exception)
			{
				Console.WriteLine(i);
				while (++i < m)
				{
					Console.ReadLine();
				}
				return;
			}
		}
		Console.WriteLine(m);
	}

	public static void Main()
	{
		while (int.Parse(Console.ReadLine()) != -1) {
			Parity p = new Parity();

			p.Run();
		}
	}
}
/*
id => 4677338
date => 18:01:3815 Dec 2012
user => watashi
pname => Parity
lang => C#
status => Accepted
testid => 
time => 0.14
mem => 4 416 KB
pid => 1003
*/
