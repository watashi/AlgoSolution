using System;

class Addition	//1000. A+B Problem
{
    static void Main(string[] args)
    {
        string[] number = Console.ReadLine().Split(' ');        
        int sum = Int32.Parse(number[0]) + Int32.Parse(number[1]);
        Console.WriteLine(sum);
    }
}

//ID Date Author Problem Language Judgement result Test # Execution time Memory used 
//1873030 12:16:03 16 Nov 2007 watashi 1000 C# Accepted  0.093 1 981 KB
/*
id => 4677334
date => 18:00:4715 Dec 2012
user => watashi
pname => A+B Problem
lang => C#
status => Accepted
testid => 
time => 0.109
mem => 1 972 KB
pid => 1000
*/
