import java.io.*;
import java.math.*;
import java.util.*;

public class H {
  static Scanner in;
  static PrintWriter out;

  static {
    String file = "tickets";
    try {
      in = new Scanner(new File(file + ".in"));
      out = new PrintWriter(new FileOutputStream(file + ".out"));
    } catch (IOException ex) {
    }
  }

  private static BigInteger TWO = BigInteger.valueOf(2);
  private static boolean[] mark = new boolean[512];
  public static int cyclic(int[] p) {
    int ret = 0;
    Arrays.fill(mark, 0, p.length, false);
    for (int i = 0; i < p.length; ++i) {
      if (!mark[i]) {
        ++ret;
        for (int j = i; !mark[j]; j = p[j]) {
          mark[j] = true;
        }
      }
    }
    return ret;
  }

  public static void main(String[] args) {
    int n = in.nextInt();
    int m = in.nextInt();
    int nm = n * m;
    int[][] p;
    if (n == m) {
      p = new int[4][nm];
    } else {
      p = new int[2][nm];
    }
    BigInteger num = BigInteger.ZERO;
    int den = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        for (int k = 0; k < nm; ++k) {
          int x = ((k / m) + i) % n;
          int y = ((k % m) + j) % m;
          p[0][k] = x * m + y;
          p[1][k] = (n - 1 - x) * m + (m - 1 - y);
          if (n == m) {
            p[2][k] = y * m + (m - 1 - x);
            p[3][k] = (n - 1 - y) * m + x;
          }
        }
        for (int[] pp : p) {
          num = num.add(TWO.pow(cyclic(pp)));
          ++den;
        }
      }
    }
    num = num.divide(BigInteger.valueOf(den));
    out.println(num);
    out.flush();
  }
}


