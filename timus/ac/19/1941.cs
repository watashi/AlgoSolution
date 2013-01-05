using System;
using System.Collections.Generic;

public class A {
  static int get(Dictionary<string, int> h, string k) {
    int v;
    h.TryGetValue(k, out v);
    return v;
  }

  static int inc(Dictionary<string, int> h, string k, int d = 1) {
    int v = get(h, k) + d;
    h[k] = v;
    return v;
  }

  public static void Main(string[] args) {
    string[] a = Console.ReadLine().Split();
    Dictionary<string, int> x = new Dictionary<string, int>();
    foreach (string i in a) {
      inc(x, i);
    }

    string[] b = Console.ReadLine().Split();
    Dictionary<string, int> y = new Dictionary<string, int>();
    int off = x.Count, ans = 0;
    for (int i = 0; i < b.Length; ++i) {
      if (i >= a.Length) {
        switch (inc(y, b[i - a.Length], -1) - get(x, b[i - a.Length])) {
          case 0: --off; break;
          case -1: ++off; break;
        }
      }
      switch (inc(y, b[i]) - get(x, b[i])) {
        case 0: --off; break;
        case 1: ++off; break;
      }
      if (off == 0) {
        ++ans;
      }
    }
    Console.WriteLine(ans);
  }
}
/*
id => 4706650
date => 20:46:425 Jan 2013
user => watashi
pname => Scary Martian Word
lang => C#
status => Accepted
testid => 
time => 0.468
mem => 39 124 KB
pid => 1941
*/
