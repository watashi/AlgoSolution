using System;

public class Knight
{
	private static int[] dx = new int[]{2, 1, -1, -2, -2, -1, 1, 2};
	private static int[] dy = new int[]{1, 2, 2, 1, -1, -2, -2, -1};

	private static bool valid(int x, int y)
	{
		return x >= 0 && x < 8 && y >= 0 && y < 8;
	}

	private static int count(int x, int y)
	{
		int ret = 0;

		for (int i = 0; i < 8; i++)
		{
			if (valid(x + dx[i], y + dy[i]))
			{
				++ret;
			}
		}

		return ret;
	}

	public static void Main(String[] args)
	{
		int re = int.Parse(Console.ReadLine());

		for (int ri = 1; ri <= re; ri++)
		{
			string pos = Console.ReadLine();

			Console.WriteLine(count(pos[0] - 'a', pos[1] - '1'));
		}
	}
}
/*
id => 4678069
date => 03:45:4016 Dec 2012
user => watashi
pname => Lonesome Knight
lang => C#
status => Accepted
testid => 
time => 0.093
mem => 2 020 KB
pid => 1197
*/
