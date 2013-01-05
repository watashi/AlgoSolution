using System;

public class D {
  static void minmax(int[] a, out int min, out int max) {
    min = max = 0;
    foreach (int i in a) {
      min = Math.Min(i, min);
      max = Math.Max(i, max);
    }
  }

  public static void Main(string[] args) {
    int n = int.Parse(Console.ReadLine());
    int[] x = new int[n];
    int[] y = new int[n];
    for (int i = 0; i < n; ++i) {
      string[] p = Console.ReadLine().Split();
      x[i] = int.Parse(p[0]);
      y[i] = -int.Parse(p[1]);
    }

    int xmin, xmax, ymin, ymax;
    minmax(x, out xmin, out xmax);
    minmax(y, out ymin, out ymax);

    char[][] buf = new char[ymax - ymin + 1][];
    for (int i = 0; i < buf.Length; ++i) {
      buf[i] = new char[xmax - xmin + 1];
      for (int j = 0; j < buf[i].Length; ++j) {
        buf[i][j] = '.';
      }
    }

    for (int i = xmin; i <= xmax; ++i) {
      buf[0 - ymin][i - xmin] = '-';
    }
    for (int i = ymin; i <= ymax; ++i) {
      buf[i - ymin][0 - xmin] = '|';
    }
    buf[0 - ymin][0 - xmin] = '+';
    for (int i = 0; i < n; ++i) {
      buf[y[i] - ymin][x[i] - xmin] = '*';
    }

    for (int i = 0; i < buf.Length; ++i) {
      Console.WriteLine(new string(buf[i]));
    }
  }
}
/*
id => 4706656
date => 20:48:085 Jan 2013
user => watashi
pname => Record of the Attack at the Orbit
lang => C#
status => Accepted
testid => 
time => 0.156
mem => 2 040 KB
pid => 1944
*/
