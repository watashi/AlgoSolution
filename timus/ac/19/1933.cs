using System;
using System.Collections.Generic;

public class C {
  public static void Main(string[] args) {
    int n = Int32.Parse(Console.ReadLine());
    int m = n + n + 1;
    int[][] a = new int[m][];
    for (int i = 0; i < m; ++i) {
      a[i] = new int[m];
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < m; ++j) {
        if (i != j) {
          a[i][j] = (i + j) % m + 1;
        }
      }
    }
    for (int i = 0; i < m; ++i) {
      Console.WriteLine(String.Join(" ",
            Array.ConvertAll<int, string>(a[i], j => j.ToString())));
    }
  }
}

//ID	Time	Author	Problem	Language	Judgement result	Test #	Execution time	Memory used
//4610768	2:28:23	watashi	C. Guns for Battle!	C#	Accepted	  0.14	2 272 KB

