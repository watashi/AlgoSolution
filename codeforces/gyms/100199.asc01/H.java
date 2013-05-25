import java.io.*;
import java.math.*;
import java.util.*;

public class H {
  static Scanner in;
  static PrintWriter out;

  static {
    String file = "rsa";
    try {
      in = new Scanner(new File(file + ".in"));
      out = new PrintWriter(new FileOutputStream(file + ".out"));
    } catch (IOException ex) {
    }
  }


  static int np;
  static int[] p;

  static {
    np = 0;
    p = new int[256];
    boolean[] m = new boolean[1024];
    for (int i = 2; i < m.length; ++i) {
      if (m[i]) {
        continue;
      }
      p[np++] = i;
      for (int j = i + i; j < m.length; j += i) {
        m[j] = true;
      }
    }
  }

  public static void main(String[] args) {
    int t = in.nextInt();
    int m = in.nextInt();
    boolean[][] a = new boolean[t][m];
    for (int j = 0; j < m; ++j) {
      int b = in.nextInt();
      for (int i = 0; i < t; ++i) {
        int k = 0;
        while (b % p[i] == 0) {
          b /= p[i];
          ++k;
        }
        a[i][j] = (k % 2 != 0);
      }
    }
    // elimination
    int r = 0, c = 0;
    boolean swap;
    while (r < t && c < m) {
      int rr = -1;
      for (int i = r; i < t; ++i) {
        if (a[i][c]) {
          rr = i;
          break;
        }
      }
      if (rr == -1) {
        ++c;
      } else {
        for (int j = c; j < m; ++j) {
          swap = a[r][j];
          a[r][j] = a[rr][j];
          a[rr][j] = swap;
        }
        for (int i = r + 1; i < t; ++i) {
          if (a[i][c]) {
            a[i][c] = false;
            for (int j = c + 1; j < m; ++j) {
              if (a[r][j]) {
                a[i][j] = !a[i][j];
              }
            }
          }
        }
        ++r;
      }
    }
    out.println(BigInteger.valueOf(2).pow(m - r).subtract(BigInteger.ONE));
    out.flush();
  }
}

