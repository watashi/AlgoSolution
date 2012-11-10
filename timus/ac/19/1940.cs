using System;
using System.Collections.Generic;

public class J {
  static int[] p;

  static int Gao(int m, int n, int k) {
    if (m == n) {
      return 0;
    } else if (k == p.Length || p[k] > n) {
      return n - m;
    } else {
      return Gao(m, n, k + 1) - Gao(m / p[k], n / p[k], k + 1);
    }
  }

  public static void Main(string[] args) {
    int[] input = Array.ConvertAll(Console.ReadLine().Split(), Int32.Parse);
    List<int> p = new List<int>();
    for (int i = 2; i < 2 + input[2]; ++i) {
      bool flag = true;
      for (int j = 2; j * j <= i; ++j) {
        if (i % j == 0) {
          flag = false;
          break;
        }
      }
      if (flag) {
        p.Add(i);
      }
    }

    J.p = p.ToArray();
    int ans = Gao(input[0], input[0] + input[1], 0);
    foreach (int i in p) {
      if (i > input[0] && i - input[0] <= input[1]) {
        ++ans;
      }
    }
    Console.WriteLine(ans);
  }
}

//ID	Time	Author	Problem	Language	Judgement result	Test #	Execution time	Memory used
//4612144	4:58:05	watashi	J. Not So Simple Years	C#	Accepted		0.312	2 260 KB

