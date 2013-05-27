import java.io.*;
import java.util.*;

public class B {
  static Scanner in;
  static PrintWriter out;

  static {
    String file = "beloved";
    try {
      in = new Scanner(new File(file + ".in"));
      out = new PrintWriter(new FileOutputStream(file + ".out"));
    } catch (IOException ex) {
    }
  }

  // [algo] hungary BipartiteMaximumMatching
  // [module] hungary
  public static int hungary(int nu, int nv, int[][] e, int[] mu, int[] mv) {
    Arrays.fill(mu, -1);
    Arrays.fill(mv, -1);
    int[] q = new int[nu];
    int[] p = new int[nv];
    int ret = 0;
    for (int i = 0; i < nu; ++i) {
      Arrays.fill(p, -1);
      q[0] = i;
BFS:
      for (int begin = 0, end = 1; begin < end; ++begin) {
        int u = q[begin];
        for (int v : e[u]) {
          if (p[v] == -1) {
            p[v] = u;
            if (mv[v] == -1) {
              int t = v;
              while (t != -1) {
                u = p[t];
                v = t;
                t = mu[u];
                mu[u] = v;
                mv[v] = u;
              }
              ++ret;
              break BFS;
            } else {
              q[end++] = mv[v];
            }
          }
        }
      }
    }
    return ret;
  }

  public static void main(String[] args) {
    int n = in.nextInt();
    int[] a = new int[n];
    for (int i = 0; i < n; ++i) {
      a[i] = in.nextInt();
      a[i] = (a[i] << 10) ^ i;
    }
    int[] o = new int[n];
    Arrays.sort(a);
    for (int i = 0; i < n; ++i) {
      o[a[n - 1 - i] & 1023] = i;
    }
    int[][] e = new int[n][];
    for (int i : o) {
      int k = in.nextInt();
      e[i] = new int[k];
      for (int j = 0; j < k; ++j) {
        e[i][j] = in.nextInt() - 1;
      }
    }
    int[] mu = new int[n];
    hungary(n, n, e, mu, new int[n]);
    for (int i = 0; i < n; ++i) {
      out.print(mu[o[i]] + 1);
      out.print(i == n - 1 ? '\n' : ' ');
    }
    out.flush();
  }
}

