import java.io.*;
import java.util.*;

public class F {
  static Scanner in;
  static PrintWriter out;

  static {
    String file = "roads";
    try {
      in = new Scanner(new File(file + ".in"));
      out = new PrintWriter(new FileOutputStream(file + ".out"));
    } catch (IOException ex) {
    }
  }

  static final int INF = Integer.MAX_VALUE / 2;
  static int t, d;
  static int[] c, q;
  static int[][] ab, w;
  static boolean[] mark;
  static ArrayList<ArrayList<Integer> > e;

  static void dfs(int p) {
    mark[p] = true;
    q[t++] = p;
    if (t >= 3 && ab[q[0]][q[t - 1]] != -1) {
      int y = ab[q[0]][q[t - 1]];
      for (int i = 1; i < t; ++i) {
        int x = ab[q[i - 1]][q[i]];
        w[x][y] = Math.max(w[x][y], c[x] - c[y + d]);
      }
    }
    for (int v : e.get(p)) {
      if (!mark[v]) {
        dfs(v);
      }
    }
    --t;
  }

  public static void main(String[] args) {
    int n = in.nextInt();
    int m = in.nextInt();
    d = n - 1;
    e = new ArrayList<ArrayList<Integer> >(n);
    for (int i = 0; i < n; ++i) {
      e.add(new ArrayList<Integer>());
    }
    ab = new int[n][n];
    for (int[] ar : ab) {
      Arrays.fill(ar, -1);
    }
    c = new int[m];
    for (int i = 0; i < m; ++i) {
      int a = in.nextInt() - 1;
      int b = in.nextInt() - 1;
      ab[a][b] = ab[b][a] = (i < d) ? i : (i - d);
      c[i] = in.nextInt();
      if (i < d) {
        e.get(a).add(b);
        e.get(b).add(a);
      }
    }

    q = new int[n];
    w = new int[n - 1][m - d];
    for (int[] ar : w) {
      Arrays.fill(ar, 0);
    }
    mark = new boolean[n];
    for (int i = 0; i < n; ++i) {
      Arrays.fill(mark, false);
      t = 0;
      dfs(i);
    }

    if (m - d < d) {
      int[][] ww = w;
      w = new int[m - d][d];
      for (int i = 0; i < w.length; ++i) {
        for (int j = 0; j < w[i].length; ++j) {
          w[i][j] = ww[j][i];
        }
      }
    }
    int[] u = new int[w.length];
    int[] v = new int[m - w.length]; // w[0].length -> RE
    Matching.kuhnMunkres(u.length, v.length, w, u, v, new int[u.length], new int[v.length]);
    if (m - d < d) {
      int[] swap;
      swap = u;
      u = v;
      v = swap;
    }
    for (int i = 0; i < u.length; ++i) {
      out.println(c[i] - u[i]);
    }
    for (int i = 0; i < v.length; ++i) {
      out.println(c[i + d] + v[i]);
    }
    out.flush();
  }
}

class Matching {
  // nu <= nv
  public static int kuhnMunkres(int nu, int nv, int[][] w, int[] u, int[] v, int[] mu, int[] mv) {
    for (int i = 0; i < nu; ++i) {
      u[i] = Integer.MIN_VALUE;
      for (int uu : w[i]) {
        u[i] = Math.max(u[i], uu);
      }
    }
    for (int j = 0; j < nv; ++j) {
      v[j] = 0;
    }
    mu = new int[nu];	// null
    Arrays.fill(mu, -1);
    mv = new int[nv];	// null
    Arrays.fill(mv, -1);

    int[] q = new int[nu];
    int[] p = new int[nv];

    for (int i = 0; i < nu; ++i) {
      Arrays.fill(p, -1);
      q[0] = i;
      int t = 1;
BFS:
      for (int s = 0; s < t; ++s) {
        int k = q[s];
        for (int j = 0; j < nv; ++j) {
          if (p[j] == -1 && u[k] + v[j] == w[k][j]) {
            if (mv[j] == -1) {
              int x = k, y = j, z;
              while(true) {
                z = mu[x];
                mu[x] = y;
                mv[y] = x;
                if (z == -1) {
                  break;
                } else {
                  x = p[z];
                  y = z;
                }
              }
              break BFS;
            } else {
              q[t++] = mv[j];
              p[j] = k;
            }
          }
        }
      }
      if (mu[i] != -1) {
        continue;
      } else {
        --i; // !
      }
      int e = Integer.MAX_VALUE;
      for (int j = 0; j < nv; ++j) {
        if (p[j] != -1) {	// Y - T
          continue;
        }
        for (int s = 0; s < t; ++s) {	// S
          e = Math.min(e, u[q[s]] + v[j] - w[q[s]][j]);
        }
      }
      for (int j = 0; j < nv; ++j) {
        if (p[j] != -1) {
          v[j] += e;
        }
      }
      for (int s = 0; s < t; ++s) {
        u[q[s]] -= e;
      }
    }
    int ret = 0;
    for (int i : u) {
      ret += i;
    }
    for (int i : v) {
      ret += i;
    }
    return ret;
  }
}

