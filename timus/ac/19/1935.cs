using System;
using System.Collections.Generic;

public class E {
  public static void Main(string[] args) {
    Console.ReadLine();
    int[] a = Array.ConvertAll(Console.ReadLine().Split(), Int32.Parse);
    Array.Sort(a);
    int s = a[a.Length - 1];
    foreach (int i in a) {
      s += i;
    }
    Console.WriteLine(s);
  }
}

// ID	Time	Author	Problem	Language	Judgement result	Test #	Execution time	Memory used
// 4610507	2:02:02	watashi	E. Tears of Drowned	C#	Accepted	0.14	2 172 KB

