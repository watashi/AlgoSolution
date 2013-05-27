import java.io.*;
import java.util.*;

public class E {
  static InputStream in;
  static PrintWriter out;

  static {
    String file = "defence";
    try {
      in = new BufferedInputStream(new FileInputStream(file + ".in"));
      out = new PrintWriter(new FileOutputStream(file + ".out"));
    } catch (IOException ex) {
    }
  }

  static int nextInt() throws IOException {
    int ch = -1;
    do {
      ch = in.read();
    } while (!Character.isDigit(ch));
    int ret = 0;
    while (Character.isDigit(ch)) {
      ret *= 10;
      ret += Character.digit(ch, 10);
      ch = in.read();
    }
    return ret;
  }

  public static void main(String[] args) throws IOException {
    int n = nextInt();
    int m = nextInt();
    int s = nextInt() - 1;
    int t = nextInt() - 1;
    int[][] e = new int[n][n];
    for (int i = 0; i < m; ++i) {
      int a = nextInt() - 1;
      int b = nextInt() - 1;
      e[a][b] = e[b][a] = i + 1;
    }
    int[] d = new int[n];
    Arrays.fill(d, -1);
    int[] q = new int[n];
    q[0] = s;
    d[s] = 0;
    for (int begin = 0, end = 1; begin < end; ++begin) {
      int i = q[begin];
      for (int j = 0; j < n; ++j) {
        if (d[j] == -1 && e[i][j] > 0) {
          d[j] = d[i] + 1;
          q[end++] = j;
        }
      }
    }
    ArrayList<ArrayList<Integer> > ans = new ArrayList<ArrayList<Integer> >(d[t]);
    for (int i = 0; i < d[t]; ++i) {
      ans.add(new ArrayList<Integer>());
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (e[i][j] > 0 && d[i] < d[t] && d[j] == d[i] + 1) {
          ans.get(d[i]).add(e[i][j]);
        }
      }
    }
    out.println(ans.size());
    for (ArrayList<Integer> i : ans) {
      out.print(i.size());
      for (int j : i) {
        out.print(" " + j);
      }
      out.println();
    }
    out.flush();
  }
}
