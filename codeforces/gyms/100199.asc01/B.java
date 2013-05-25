import java.io.*;
import java.util.*;

public class B {
  public static void main (String[] args) throws IOException {
    Scanner in = new Scanner(new File("cooling.in"));
    PrintStream out = new PrintStream(new FileOutputStream("cooling.out"));
    int n = in.nextInt();
    int m = in.nextInt();
    int[] s = new int[m];
    int[] t = new int[m];
    int[] b = new int[m];
    int[] c = new int[m];
    for (int i = 0; i < m; ++i) {
      s[i] = in.nextInt() - 1;
      t[i] = in.nextInt() - 1;
      b[i] = in.nextInt();
      c[i] = in.nextInt();
    }
    LimitFlow lf = new LimitFlow(n, s, t, b, c);
    try {
      int[] ans = lf.solve();
      out.println("YES");
      for (int f : ans) {
        out.println(f);
      }
    } catch (NoSuchFlowException e) {
      out.println("NO");
    }
  }
}

class Edge {
  int v, c, id;
  Edge r;

  public Edge(int v, int c) {
    this.v = v;
    this.c = c;
    this.id = -1;
    this.r = null;
  }
}

class NoSuchFlowException extends Throwable {
  static final long serialVersionUID = 9;
}

class LimitFlow {
  int n, source, sink;
  int[] f;
  ArrayList<ArrayList<Edge> > edge;

  public LimitFlow(int an, int[] s, int[] t, int[] b, int[] c) {
    n = an + 2;
    source = an;
    sink = an + 1;
    f = b.clone();
    edge = new ArrayList<ArrayList<Edge> >(n);
    for (int i = 0; i < n; ++i) {
      edge.add(new ArrayList<Edge>());
    }
    int[] d = new int[an];
    for (int i = 0; i < f.length; ++i) {
      Edge x = new Edge(t[i], c[i] - b[i]);
      Edge y = new Edge(s[i], 0);
      x.r = y;
      y.r = x;
      edge.get(s[i]).add(x);
      edge.get(t[i]).add(y);
      d[s[i]] -= b[i];
      d[t[i]] += b[i];
      x.id = i;
    }
    for (int i = 0; i < d.length; ++i) {
      if (d[i] > 0) {
        Edge x = new Edge(i, d[i]);
        Edge y = new Edge(source, 0);
        x.r = y;
        y.r = x;
        edge.get(source).add(x);
        edge.get(i).add(y);
      } else if (d[i] < 0) {
        Edge x = new Edge(sink, -d[i]);
        Edge y = new Edge(i, 0);
        x.r = y;
        y.r = x;
        edge.get(i).add(x);
        edge.get(sink).add(y);
      }
    }
  }

  public int[] solve() throws NoSuchFlowException {
    int[] q = new int[n];
    int[] d = new int[n];
    int[] done = new int[n];
    int[] path = new int[n];
    while (true) {
      //
      Arrays.fill(d, -1);
      q[0] = source;
      d[source] = 0;
      int begin = 0, end = 1;
      while (begin < end) {
        int front = q[begin++];
        for (Edge e : edge.get(front)) {
          if (e.c > 0 && d[e.v] == -1) {
            d[e.v] = d[front] + 1;
            q[end++] = e.v;
          }
        }
      }
      /* String s = "";
         for (int x : d) {
         s += x;
         }
         System.err.println(s); */
      if (d[sink] == -1) {
        break;
      }
      //
      Arrays.fill(done, 0);
      int len = 0;
      path[0] = source;
      while (len >= 0) {
        int back = path[len];
        if (back == sink) {
          int flow = Integer.MAX_VALUE;
          int todo = -1;
          for (int i = 0; i < len; ++i) {
            Edge e = edge.get(path[i]).get(done[path[i]]);
            if (e.c < flow) {
              flow = e.c;
              todo = i;
            }
          }
          for (int i = 0; i < len; ++i) {
            Edge e = edge.get(path[i]).get(done[path[i]]);
            e.c -= flow;
            e.r.c += flow;
          }
          len = todo;
        } else {
          while (done[back] < edge.get(back).size()) {
            Edge e = edge.get(back).get(done[back]);
            if (d[e.v] == d[back] + 1 && e.c > 0) {
              break;
            } else {
              ++done[back];
            }
          }
          if (done[back] == edge.get(back).size()) {
            d[back] = -1; // !!
            --len;
          } else {
            path[++len] = edge.get(back).get(done[back]).v;
          }
        }
      }
    }
    for (Edge e : edge.get(source)) {
      if (e.c > 0) {
        throw new NoSuchFlowException();
      }
    }
    for (ArrayList<Edge> ae : edge) {
      for (Edge e : ae) {
        if (e.id != -1) {
          f[e.id] += e.r.c;
        }
      }
    }
    return f;
  }
}

