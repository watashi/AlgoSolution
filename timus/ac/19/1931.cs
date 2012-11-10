using System;

public class A {
  public static void Main(string[] args) {
    Console.ReadLine();
    int[] a = Array.ConvertAll(Console.ReadLine().Split(), Int32.Parse);
    int ans = 0, cnt = 0;
    for (int i = 1, j = 0, k = 0; i < a.Length; ++i) {
      if (a[i] < a[k]) {
        k = i;
        j = 1;
      } else {
        ++j;
      }
      if (j > cnt) {
        cnt = j;
        ans = k;
      }
    }
    Console.WriteLine(ans + 1);
  }
}

//ID	Time	Author	Problem	Language	Judgement result	Test #	Execution time	Memory used
//4610577	2:08:48	watashi	A. Excellent Team	C#	Accepted		0.171	6 676 KB

