using System;
using System.Numerics;

public class H {
  static long MAX = 1000000000L * 1000000000L;

  static BigInteger Gao(BigInteger n) {
    if (n % 2 == 0) {
      n /= 2;
      return n * (8 * n * n - 2) / 3;
    } else {
      n /= 2;
      return 4 * n * (n + 1) * (2 * n + 1) / 3;
    }
  }

  public static void Main(string[] args) {
    int re = int.Parse(Console.ReadLine());
    for (int ri = 1; ri <= re; ++ri) {
      long[] f = Array.ConvertAll(Console.ReadLine().Split(), long.Parse);
      long a = f[0];
      long b = f[1];
      long c = f[2];
      long aa = a * a;
      long dd = b * b - 4 * a * c;

      BigInteger l = 0, r = MAX + 1;
      while (l < r) {
        BigInteger m = (l + r) / 2;
        if (Gao(m) * aa <= m * dd) {
          l = m + 1;
        } else {
          r = m;
        }
      }
      Console.WriteLine(r <= MAX ? r.ToString() : "Infinity");
    }
  }
}

/*
id => 4706660
date => 20:49:085 Jan 2013
user => watashi
pname => The Robot on the Line
lang => C#
status => Accepted
testid => 
time => 0.25
mem => 2 700 KB
pid => 1948
*/
