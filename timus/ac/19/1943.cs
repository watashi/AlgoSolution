using System;
using System.Collections.Generic;

public class C {
  static IEnumerable<int[]> Permutations(int[] a, int[] b, int k, int m) {
    if (k == a.Length) {
      yield return (int[])b.Clone();
    } else {
      for (int i = 0; i < a.Length; ++i) {
        if ((m & (1 << i)) == 0) {
          b[k] = a[i];
          foreach (int[] j in Permutations(a, b, k + 1, m | (1 << i))) {
            yield return j;
          }
        }
      }
    }
  }

  static IEnumerable<int[]> Permutations(int[] a) {
    return Permutations(a, new int[a.Length], 0, 0);
  }

  static bool Win(int[] x, int[] y) {
    LinkedList<int> a = new LinkedList<int>(x), b = new LinkedList<int>(y);
    while (a.Count > 0 && b.Count > 0) {
      if (a.First.Value > b.First.Value) {
        a.AddLast(b.First.Value);
        a.AddLast(a.First.Value);
      } else if (a.First.Value < b.First.Value) {
        b.AddLast(a.First.Value);
        b.AddLast(b.First.Value);
      }
      a.RemoveFirst();
      b.RemoveFirst();
    }
    return a.Count > 0;
  }

  public static void Main(string[] args) {
    Console.ReadLine();
    int[] a = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
    int m = Math.Min(5, a.Length);
    int[] b = new int[m];
    Array.Copy(a, b, m);

    int[] c = null;
    foreach (int[] i in Permutations(b)) {
      if (Win(i, b)) {
        c = i;
        break;
      }
    }

    if (c == null) {
      Console.WriteLine("NO");
    } else {
      Console.WriteLine("YES");
      for (int i = 0; i < m; ++i) {
        a[i] = c[i];
      }
      Console.WriteLine(String.Join(" ", Array.ConvertAll(a, i => i.ToString())));
    }
  }
}

/*
id => 4706654
date => 20:47:425 Jan 2013
user => watashi
pname => Space Rummy
lang => C#
status => Accepted
testid => 
time => 0.14
mem => 2 500 KB
pid => 1943
*/
