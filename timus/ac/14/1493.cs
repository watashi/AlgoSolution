namespace Timus
{
	class OneStepFromHappiness	//1493. One Step from Happiness
	{
		static bool IsLucky(int number)
		{
			int tmp = 0;
			for (int i = 0; i < 3; i++)
			{
				tmp += number % 10;
				number /= 10;
			}
			for (int i = 0; i < 3; i++)
			{
				tmp -= number % 10;
				number /= 10;
			}
			return tmp == 0;
		}
		static void Main()
		{
			int number = int.Parse(System.Console.ReadLine());
			System.Console.WriteLine((IsLucky(number - 1) || IsLucky(number + 1)) ? "Yes" : "No");
		}
	}
}
//ID Date Author Problem Language Judgement result Test # Execution time Memory used 
//1893893 14:08:07 3 Dec 2007 watashi 1493 C# Accepted  0.078 1 913 KB 
/*
id => 4678353
date => 12:21:0716 Dec 2012
user => watashi
pname => One Step from Happiness
lang => C#
status => Accepted
testid => 
time => 0.14
mem => 1 992 KB
pid => 1493
*/
