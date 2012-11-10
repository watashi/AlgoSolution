using System;
using System.Collections.Generic;

class Edge {
  public int v;
  public double p;

  public Edge(int v, double p) {
    this.v = v;
    this.p = p;
  }
}

public class D {
  public static int[] ReadArray() {
    return Array.ConvertAll(Console.ReadLine().Split(), Int32.Parse);
  }

  public static void Main(string[] args) {
    int[] a;
    a = ReadArray();
    int n = a[0];
    int m = a[1];
    a = ReadArray();
    int s = a[0] - 1;
    int t = a[1] - 1;

    List<Edge>[] e = new List<Edge>[n];
    for (int i = 0; i < n; ++i) {
      e[i] = new List<Edge>();
    }
    for (int i = 0; i < m; ++i) {
      a = ReadArray();
      --a[0];
      --a[1];
      e[a[0]].Add(new Edge(a[1], 1 - a[2] / 100.0));
      e[a[1]].Add(new Edge(a[0], 1 - a[2] / 100.0));
    }

    int[] d = new int[n];
    double[] p = new double[n];
    int[] pre = new int[n];
    for (int i = 0; i < n; ++i) {
      d[i] = -1;
      p[i] = 0;
      pre[i] = -1;
    }

    Queue<int> q = new Queue<int>();
    d[s] = 1;
    p[s] = 1;
    q.Enqueue(s);
    while (q.Count > 0) {
      int v = q.Dequeue();
      foreach (var i in e[v]) {
        if (d[i.v] == -1 || (d[i.v] == d[v] + 1 && p[i.v] < p[v] * i.p)) {
          if (d[i.v] == -1) {
            q.Enqueue(i.v);
          }
          d[i.v] = d[v] + 1;
          p[i.v] = p[v] * i.p;
          pre[i.v] = v;
        }
      }
    }

    Console.WriteLine(d[t] + " " + (1 - p[t]));
    List<int> path = new List<int>();
    for (int i = t; i != s; i = pre[i]) {
      path.Add(i);
    }
    path.Add(s);
    path.Reverse();
    Console.WriteLine(String.Join(" ", path.ConvertAll(i => (i + 1).ToString()).ToArray()));
  }
}

//ID	Time	Author	Problem	Language	Judgement result	Test #	Execution time	Memory used
//4611557	3:44:13	watashi	D. Black Spot	C#	Accepted		0.562	21 668 KB

