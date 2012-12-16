using System;
using System.Collections;

public class Bayan
{
	public static void Main(String[] args)
	{
		int n = int.Parse(Console.ReadLine()), c = 0;
		Hashtable h = new Hashtable();

		for (int i = 0; i < n; i++) {
			string s = Console.ReadLine();

			if (h.Contains(s)) {
				++c;
			}
			else {
				h.Add(s, null);
			}
		}
		Console.WriteLine(c);
	}
}
/*
id => 4678649
date => 15:37:2116 Dec 2012
user => watashi
pname => Bayan
lang => C#
status => Accepted
testid => 
time => 0.125
mem => 1 972 KB
pid => 1563
*/
