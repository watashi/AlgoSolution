using System;

public class Hieroglyphs
{
	public static void Main(String[] args)
	{
		int n = int.Parse(Console.ReadLine());
		string[] s = new string[n];

		for (int i = 0; i < n; i++) {
			s[i] = Console.ReadLine();
		}

		char c = (char)Console.Read();

		foreach (string str in s)
		{
			if (str[0] == c)
			{
				Console.WriteLine(str);
			}
		}
	}
}
/*
id => 4678646
date => 15:36:5916 Dec 2012
user => watashi
pname => Hieroglyphs
lang => C#
status => Accepted
testid => 
time => 0.14
mem => 1 996 KB
pid => 1545
*/
