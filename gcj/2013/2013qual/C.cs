using System;
using System.Collections.Generic;

public class C {
  private static bool IsPalindrome(long x) {
    string s = x.ToString();
    char[] a = s.ToCharArray();
    Array.Reverse(a);
    return s == new string(a);
  }

  private static int LowerBound(List<long> a, long x) {
    int i = a.BinarySearch(x);
    return i >= 0 ? i : ~i;
  }

  public static void Main(string[] Args) {
    List<long> a = new List<long>();
    for (long i = 1; i <= 10000000; ++i) {
      if (IsPalindrome(i) && IsPalindrome(i * i)) {
        Console.Error.WriteLine(i + " " + i * i);
        a.Add(i * i);
      }
    }
    Console.Error.WriteLine(a.Count);

    int re = int.Parse(Console.ReadLine());
    for (int ri = 1; ri <= re; ++ri) {
      string[] input = Console.ReadLine().Split();
      long l = long.Parse(input[0]);
      long r = long.Parse(input[1]);
      Console.WriteLine("Case #{0}: {1}", ri, LowerBound(a, r + 1) - LowerBound(a, l));
    }
  }
}

