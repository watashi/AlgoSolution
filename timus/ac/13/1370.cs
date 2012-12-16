namespace Timus
{
	class Magician	//1370. Magician
	{
		static void Main()
		{
			string[] input = System.Console.ReadLine().Split(' ');
			int n = int.Parse(input[0]);
			int m = int.Parse(input[1]);
			int[] a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = int.Parse(System.Console.ReadLine());
			for (int i = 0; i < 10; i++)
				System.Console.Write(a[(m + i) % n]);
			System.Console.WriteLine();
		}
	}
}
//ID Date Author Problem Language Judgement result Test # Execution time Memory used 
//1893855 13:38:59 3 Dec 2007 watashi 1370 C# Accepted  0.062 1 997 KB 
/*
id => 4678346
date => 12:19:3816 Dec 2012
user => watashi
pname => Magician
lang => C#
status => Accepted
testid => 
time => 0.125
mem => 2 020 KB
pid => 1370
*/
