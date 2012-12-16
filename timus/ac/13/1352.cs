//给你一张表，要求打表
namespace Timus
{
	class ListParser	//1352. Mersenne primes
	{
		static int[] a = new int[] { 0, 2, 3, 5, 7, 13, 17, 19, 31, 61, 89,
				107, 127, 521, 607, 1279, 2203, 2281, 3217, 4253, 4423,
				9689, 9941, 11213, 19937, 21701, 23209, 44497, 86243, 110503, 132049,
				216091, 756839, 859433, 1257787, 1398269, 2976221, 3021377, 6972593 };
		static void Main()
		{
			for (int t = int.Parse(System.Console.ReadLine()); t > 0; t--)
				System.Console.WriteLine(a[int.Parse(System.Console.ReadLine())]);
		}
	}
}
//ID Date Author Problem Language Judgement result Test # Execution time Memory used 
//1893835 13:28:36 3 Dec 2007 watashi 1352 C# Accepted  0.062 1 997 KB 

//很难，因为我连sample都没过还交，WA了N次
/*
id => 4678345
date => 12:19:1816 Dec 2012
user => watashi
pname => Mersenne Primes
lang => C#
status => Accepted
testid => 
time => 0.125
mem => 1 988 KB
pid => 1352
*/
