import java.io.*;
import java.util.*;

public class C {
  static InputStream in;
  static PrintWriter out;

  static {
    String file = "grant";
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
    int[] c = new int[n];
    int[] p = new int[n];
    p[0] = 0;
    c[0] = 1;
    for (int i = 1; i < n; ++i) {
      p[i] = nextInt() - 1;
      ++c[p[i]];
    }
    int[] queue = new int[n];
    int s = 0, q = 0;
    for (int i = 0; i < n; ++i) {
      if (c[i] == 0) {
        queue[q++] = i;
      }
    }
    int[] b = new int[n];
    int ans = 0;
    while (s < q) {
      int v = queue[s++];
      if (b[v] == 0 && b[p[v]] == 0) {
        b[v] = 1;
        b[p[v]] = -1;
        ++ans;
      }
      if (--c[p[v]] == 0) {
        queue[q++] = p[v];
      }
    }
    boolean blank = false;
    out.println(ans * 1000);
    for (int i = 0; i < n; ++i) {
      if (b[i] == 1) {
        if (blank) {
          out.print(' ');
        } else {
          blank = true;
        }
        out.print(i + 1);
      }
    }
    out.println();
    out.flush();
  }
}
