using System;
using System.Collections.Generic;

namespace Timus
{
	class Spammer	//1496. Spammer
	{
		static void Main()
		{
			int n = Int32.Parse(Console.ReadLine());

			Dictionary<String, Boolean> st = new Dictionary<String, Boolean>();
			Dictionary<String, Boolean> ans = new Dictionary<String, Boolean>();

			while (n-- != 0)
			{
				String cur = Console.ReadLine();
				try
				{
					st.Add(cur, false);
				}
				catch
				{
					if (st[cur] == false)
					{
						st[cur] = true;
						ans.Add(cur, false);
					}
				}
			}

			foreach (string cur in ans.Keys)
				Console.WriteLine(cur);
		}
	}
}
//1893879 13:58:31 3 Dec 2007 watashi 1496 C# Accepted  0.062 2 345 KB 
/*
id => 4678354
date => 12:21:3016 Dec 2012
user => watashi
pname => Spammer
lang => C#
status => Accepted
testid => 
time => 0.14
mem => 2 296 KB
pid => 1496
*/
