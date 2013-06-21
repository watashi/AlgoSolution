import java.io.*;
import java.math.*;
import java.util.*;

public class D {
  private static int buffer = -1;

  public static int nextInt() throws IOException {
    int ret = 0;

    do {
      buffer = System.in.read();
    } while (Character.isWhitespace(buffer));
    if (buffer == -1) {
      return -1;
    }
    do {
      ret *= 10;
      ret += Character.digit(buffer, 10);
      buffer = System.in.read();
    } while (Character.isDigit(buffer));

    return ret;
  }

  static BigInteger[][] c;

  static {
    c = new BigInteger[101][101];
    for (int i = 0; i < c.length; ++i) {
      // Arrays.fill(c[i], BigInteger.ZERO);
      c[i][0] = c[i][i] = BigInteger.ONE;
      for (int j = 1; j < i; ++j) {
        c[i][j] = c[i - 1][j - 1].add(c[i - 1][j]);
      }
    }
  }

  public static void main(String[] args) throws IOException {
    int n = nextInt();
    int m = nextInt();
    int v = nextInt();
    boolean[][] w = new boolean[n][n];
    for (int i = 0; i < m; ++i) {
      int a = nextInt();
      int b = nextInt();
      w[a - 1][b - 1] = true;
    }
    // floyd
    for (int k = 0; k < n; ++k) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          w[i][j] |= w[i][k] && w[k][j];
        }
      }
    }

    int[] id = new int[n], sz = new int[n];
    ArrayList<Integer> x = new ArrayList<Integer>();
    int y = 0;
    // relabel
    for (int i = 0; i < n; ++i) {
      id[i] = i;
      for (int j = 0; j < i; ++j) {
        if (w[i][j] && w[j][i]) {
          id[i] = id[j];
          break;
        }
      }
      ++sz[id[i]];
    }
    //
    for (int i = 0; i < n; ++i) {
      boolean hasIn = false, hasOut = false;
      if (id[i] < i) {
        continue;
      }
      for (int j = 0; j < n; ++j) {
        if (id[i] != id[j]) {
          if (w[i][j]) {
            hasOut = true;
          }
          if (w[j][i]) {
            hasIn = true;
          }
        }
      }
      if (hasIn && hasOut) {
        y += sz[id[i]];
      } else {
        x.add(sz[id[i]]);
      }
    }

    // dp
    BigInteger[] dp = new BigInteger[v + 1];
    Arrays.fill(dp, BigInteger.ZERO);
    dp[0] = BigInteger.ONE;
    for (int xi : x) {
      BigInteger[] pd = new BigInteger[v + 1];
      Arrays.fill(pd, BigInteger.ZERO);
      for (int j = 1; j <= xi; ++j) {
        for (int k = j; k <= v; ++k) {
          pd[k] = pd[k].add(dp[k - j].multiply(c[xi][j]));
        }
      }
      dp = pd;
    }

    BigInteger ans = BigInteger.ZERO;
    for (int j = 0; j <= y && j <= v; ++j) {
      ans = ans.add(dp[v - j].multiply(c[y][j]));
    }
    System.out.println(ans);
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
        String file = "police";
        in = new BufferedInputStream(new FileInputStream(file + ".in"));
        out = new PrintStream(new FileOutputStream(file + ".out"));
      } catch (IOException ex) {
      }
    }
  }
}

