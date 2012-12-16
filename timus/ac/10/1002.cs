using System;
using System.Collections.Generic;
namespace Timus
{
	class PhoneNumbersDP	//1002. Phone numbers
	{
		struct Record
		{
			public int dp;
			public int pr;
			public string re;
		}
		static string ToNumber(ref string word)
		{
			string res = "";
			for (int i = 0; i < word.Length; i++)
			{
				switch (word[i])
				{
					case 'i':
					case 'j': res += '1'; break;
					case 'a':
					case 'b':
					case 'c': res += '2'; break;
					case 'd':
					case 'e':
					case 'f': res += '3'; break;
					case 'g':
					case 'h': res += '4'; break;
					case 'k':
					case 'l': res += '5'; break;
					case 'm':
					case 'n': res += '6'; break;
					case 'p':
					case 'r':
					case 's': res += '7'; break;
					case 't':
					case 'u':
					case 'v': res += '8'; break;
					case 'w':
					case 'x':
					case 'y': res += '9'; break;
					case 'o':
					case 'q':
					case 'z': res += '0'; break;
				}
			}
			return res;
		}
		static void WriteAns(ref Record[] ans, int i)
		{
			if (ans[i].pr == 0)
			{
				Console.Write(ans[i].re);
			}
			else
			{
				WriteAns(ref ans, ans[i].pr);
				Console.Write(" " + ans[i].re);
			}
		}
		static void Main()
		{
			for (string input = Console.ReadLine(); input != "-1"; input = Console.ReadLine())
			{
				int n = int.Parse(Console.ReadLine());
				Dictionary<string, string> st = new Dictionary<string, string>();
				while (n-- != 0)
				{
					string cur = Console.ReadLine();
					string tmp = ToNumber(ref cur);
					if (!st.ContainsKey(tmp)) st.Add(tmp, cur);
				}
				Record[] dp = new Record[input.Length + 1];
				dp[0].dp = 0;
				dp[0].pr = -1;
				for (int i = 1; i <= input.Length; i++)
				{
					dp[i].dp = -1;
					for (int j = 0; j < i; j++)
					{
						if (dp[j].dp == -1) continue;
						if ((dp[i].dp == -1 || dp[j].dp + 1 < dp[i].dp) && st.ContainsKey(input.Substring(j, i - j)))
						{
							dp[i].dp = dp[j].dp + 1;
							dp[i].pr = j;
							dp[i].re = st[input.Substring(j, i - j)];
						}
					}
				}
				if (dp[input.Length].dp == -1)
				{
					Console.WriteLine("No solution.");
				}
				else
				{
					WriteAns(ref dp, input.Length);
					Console.WriteLine();
				}
			}
		}
	}
}
//ID Date Author Problem Language Judgement result Test # Execution time Memory used 
//1893921 14:53:44 3 Dec 2007 watashi 1002 C# Accepted  0.14 9 009 KB 
/*
id => 4677337
date => 18:01:2115 Dec 2012
user => watashi
pname => Phone Numbers
lang => C#
status => Accepted
testid => 
time => 0.14
mem => 7 820 KB
pid => 1002
*/
