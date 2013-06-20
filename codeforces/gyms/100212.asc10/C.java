import java.io.*;
import java.util.*;

public class C {
  // [length][begin]
  static long[][] dp;
  static int[][] pre;
  static int len;
  static char[] buf;

  static void print(int l, int b) {
    if (l == 1) {
      System.out.println(new String(buf, 0, len));
    } else {
      ++len;
      buf[len - 1] = '0';
      print(pre[l][b], b);
      buf[len - 1] = '1';
      print(l - pre[l][b], b + pre[l][b]);
      --len;
    }
  }

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    while (in.hasNextInt()) {
      int n = in.nextInt();
      int[] a = new int[n];
      long[] s = new long[n + 1];
      s[0] = 0;
      for (int i = 0; i < a.length; ++i) {
        a[i] = in.nextInt();
        s[i + 1] = s[i] + a[i];
      }
      dp = new long[a.length + 1][];
      pre = new int[a.length + 1][];
      for (int i = 1; i <= a.length; ++i) {
        dp[i] = new long[a.length + 1 - i];
        pre[i] = new int[a.length + 1 - i];
        if (i == 1) {
        } else if (i == 2) {
          for (int j = 0; j < dp[i].length; ++j) {
            dp[i][j] = s[i + j] - s[j];
            pre[i][j] = 1;
          }
        } else {
          for (int j = 0; j < dp[i].length; ++j) {
            dp[i][j] = Long.MAX_VALUE;
            for (int k = pre[i - 1][j]; k <= pre[i - 1][j + 1] + 1; ++k) {
              if (dp[i][j] > dp[k][j] + dp[i - k][j + k]) {
                dp[i][j] = dp[k][j] + dp[i - k][j + k];
                pre[i][j] = k;
              }
            }
            dp[i][j] += s[i + j] - s[j];
          }
        }
      }
      len = 0;
      buf = new char[n];
      System.err.println(dp[a.length][0]);
      print(a.length, 0);
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
        String file = "codes";
        in = new BufferedInputStream(new FileInputStream(file + ".in"));
        out = new PrintStream(new FileOutputStream(file + ".out"));
      } catch (IOException ex) {
      }
    }
  }
}

