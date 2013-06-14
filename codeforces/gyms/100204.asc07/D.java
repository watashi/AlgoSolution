import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Hashtable;
import java.util.Scanner;
import java.util.Map;
import java.io.*;

public class D {
  static int[] one;
  static BigInteger[] ans = new BigInteger[12];

  static {
    one = new int[65536];
    for (int i = 1; i < one.length; ++i) {
      one[i] = one[i >> 1] + (i & 1);
    }
  }

  static boolean ok(int i, int j, int k) {
    boolean flg = false;
    while (--i > 0) {
      if ((k & 1) == 0) {
        if ((j & 1) != 0) {
          if (flg || (j & 2) != 0) {
            return false;
          }
          flg = true;
          j >>= 1;
        }
      } else if (flg) {
        flg = false;
        j <<= 1;
      }
      j >>= 1;
      k >>= 1;
    }
    return true;
  }

  static BigInteger gao(int n) {
    if (ans[n] != null) {
      return ans[n];
    }
    Hashtable<Integer, BigInteger> h = new Hashtable<Integer, BigInteger>();
    h.put(0, BigInteger.ONE);
    for (int i = n + 1; i <= n + n; ++i) {
      Hashtable<Integer, BigInteger> hh = new Hashtable<Integer, BigInteger>();
      for (int j = 0; j < (1 << i); ++j) {
        if (one[j] != i - n) {
          continue;
        }
        BigInteger sum = BigInteger.ZERO;
        for (Map.Entry<Integer, BigInteger> k : h.entrySet()) {
          if (ok(i, j, k.getKey())) {
            sum = sum.add(k.getValue());
          }
        }
        if (sum.signum() > 0) {
          hh.put(j, sum);
        }
      }
      h = hh;
    }
    BigInteger ret = BigInteger.ZERO;
    for (Map.Entry<Integer, BigInteger> entry : h.entrySet()) {
      ret = ret.add(entry.getValue().pow(2));
    }
    return ans[n] = ret;
  }

  public static void main(String[] args) {
    boolean blank = false;
    Scanner in = new Scanner(System.in);
    while (in.hasNextInt()) {
      if (blank) {
        System.out.println();
      } else {
        blank = true;
      }
      int n = in.nextInt();
      System.out.println(gao(n));
    }
  }
}

final class System {
  public static InputStream in = java.lang.System.in;
  public static PrintStream out = java.lang.System.out;
  public static PrintStream err = java.lang.System.err;

  public static void exit(int status) {
    java.lang.System.exit(status);
  }

  static {
    if (java.lang.System.getProperty("ONLINE_JUDGE") != null) {
      try {
        String file = "hex";
        in = new BufferedInputStream(new FileInputStream(file + ".in"));
        out = new PrintStream(new FileOutputStream(file + ".out"));
      } catch (IOException ex) {
      }
    }
  }
}

