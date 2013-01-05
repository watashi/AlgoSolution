using System;

public class B {
  const int N = 1000;

  static int Normalize(string s) {
    decimal d = decimal.Parse(s) * 1000;
    int i = decimal.ToInt32(d);
    return (i % N + N) % N;
  }

  static int Square(int x) {
    return x * x;
  }

  public static void Main(string[] args) {
    int n = int.Parse(Console.ReadLine());
    int[, ] c = new int[N, N];
    for (int i = 0; i < n; ++i) {
      string[] p = Console.ReadLine().Split();
      ++c[Normalize(p[0]), Normalize(p[1])];
    }

    int ans = -1;
    int dis = -1;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (c[i, j] > ans) {
          ans = c[i, j];
          dis = Square(Math.Min(i, N - i)) + Square(Math.Min(j, N - j));
        } else if (c[i, j] == ans) {
          dis = Math.Min(dis, Square(Math.Min(i, N - i)) + Square(Math.Min(j, N - j)));
        }
      }
    }
    Console.WriteLine("{0} {1}", ans, Math.Sqrt((double)dis / N / N));
  }
}
/*
id => 4706652
date => 20:47:065 Jan 2013
user => watashi
pname => Attack at the Orbit
lang => C#
status => Accepted
testid => 
time => 0.187
mem => 6 468 KB
pid => 1942
*/
