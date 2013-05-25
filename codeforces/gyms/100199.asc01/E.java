import java.io.*;
import java.math.*;
import java.util.*;

public class E {
  static Scanner in;
  static PrintWriter out;

  static {
    String file = "nice";
    try {
      in = new Scanner(new File(file + ".in"));
      out = new PrintWriter(new FileOutputStream(file + ".out"));
    } catch (IOException ex) {
    }
  }

  static int[][] mul(int n, int m, int[][] a, int[][] b) {
    int[][] ret = new int[n][n];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        long s = 0;
        for (int k = 0; k < n; ++k) {
          s += a[i][k] * b[k][j];
        }
        ret[i][j] = (int)(s % m);
      }
    }
    return ret;
  }

  public static void main(String[] args) {
    BigInteger n = in.nextBigInteger().subtract(BigInteger.ONE);
    int m = in.nextInt();
    int p = in.nextInt();
    int mm = 1 << m;
    int[][] a = new int[mm][mm];
    for (int i = 0; i < mm; ++i) {
      for (int j = i; j < mm; ++j) {
        int mask = (i ^ (i >> 1)) | (j ^ (j >> 1)) | (i ^ j);
        if ((mask & ((mm >> 1) - 1)) == ((mm >> 1) - 1)) {
          a[i][j] = a[j][i] = 1;
        }
      }
    }
    int[][] c = new int[mm][mm];
    for (int i = 0; i < mm; ++i) {
      c[i][i] = 1;
    }
    for (int i = 0; i < n.bitLength(); ++i) {
      if (n.testBit(i)) {
        c = mul(mm, p, c, a);
      }
      a = mul(mm, p, a, a);
    }
    long ans = 0;
    for (int i = 0; i < mm; ++i) {
      for (int j = 0; j < mm; ++j) {
        ans += c[i][j];
      }
    }
    out.println(ans % p);
    out.flush();
  }
}
