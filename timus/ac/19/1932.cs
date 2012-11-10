using System;
using System.Globalization;
using System.Collections.Generic;

public class B {
  static int[] mask;
  static int[] count;
  static int[,] choose;

  static B() {
    mask = new int[16];
    count = new int[16];
    for (int i = 0; i < 16; ++i) {
      mask[i] = 0;
      count[i] = 0;
      for (int j = 0; j < 4; ++j) {
        if ((i & (1 << j)) != 0) {
          mask[i] |= 0xf << (j * 4);
          ++count[i];
        }
      }
    }

    choose = new int[16,16];
    for (int i = 0; i < 16; ++i) {
      choose[i,0] = 1;
      for (int j = 1; j <= i; ++j) {
        choose[i,j] = choose[i-1,j-1] + choose[i-1,j];
      }
    }
  }

  public static void Main(string[] args) {
    int n = Int32.Parse(Console.ReadLine());
    Dictionary<int, int> d = new Dictionary<int, int>();
    for (int i = 0; i < n; ++i) {
      int x = Int32.Parse(Console.ReadLine(), NumberStyles.HexNumber);
      for (int j = 0; j < 16; ++j) {
        int y = (x & mask[j]) | (j << 16);
        d[y] = (d.ContainsKey(y) ? d[y] : 0) + 1;
      }
    }

    long[] ans = new long[5];
    foreach (var i in d) {
      ans[count[i.Key >> 16]] += (long)i.Value * (i.Value - 1) / 2;
    }
    for (int i = 4; i >= 0; --i) {
      for (int j = 4; j > i; --j) {
        ans[i] -= ans[j] * choose[j,i];
      }
    }
    Console.WriteLine(ans[3] + " " + ans[2] + " " + ans[1] + " " + ans[0]);
  }
}

//ID	Time	Author	Problem	Language	Judgement result	Test #	Execution time	Memory used
//4611924	4:31:00	watashi	B. The Secret of Identifier	C#	Accepted		0.265	6 988 KB

