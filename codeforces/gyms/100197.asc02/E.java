import java.io.*;
import java.util.*;

public class E {
  static Scanner in;
  static PrintWriter out;

  static {
    String file = "quant";
    try {
      in = new Scanner(new File(file + ".in"));
      out = new PrintWriter(new FileOutputStream(file + ".out"));
    } catch (IOException ex) {
    }
  }

  public static int binarySearch(int[] a, int key) {
    int index = Arrays.binarySearch(a, key);
    if (index < 0) {
      index = -index - 1;
      if (index == a.length || (index > 0 && a[index] - key > key - a[index - 1])) {
        --index;
      }
    }
    return index;
  }

  public static void main(String[] args) {
    int n = in.nextInt();
    int[] x = new int[n];
    for (int i = 0; i < n; ++i) {
      x[i] = in.nextInt();
    }
    int m = in.nextInt();
    int s = in.nextInt();
    int mask = m - 1;
    int[][] l = new int[m][s];
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < s; ++j) {
        l[i][j] = in.nextInt();
      }
    }
    int[][] dp = new int[n][m];
    int[][] pd = new int[n][m];
    for (int[] ar : dp) {
      Arrays.fill(ar, Integer.MAX_VALUE);
    }
    for (int j = 0; j < m; ++j) {
      int index = binarySearch(l[j], x[n - 1]);
      dp[n - 1][j] = Math.abs(l[j][index] - x[n - 1]);
      pd[n - 1][j] = index;
    }
    for (int i = n - 2; i >= 0; --i) {
      for (int j = 0; j < m; ++j) {
        int p = binarySearch(l[j], x[i]);
        int f = Math.max(p - (m - 1), 0);
        int t = Math.min(p + (m - 1), s - 1);
        for (int k = f; k <= t; ++k) {
          if (dp[i][j] > dp[i + 1][k & mask] + Math.abs(l[j][k] - x[i])) {
            dp[i][j] = dp[i + 1][k & mask] + Math.abs(l[j][k] - x[i]);
            pd[i][j] = k;
          }
        }
      }
    }
    out.println(dp[0][0]);
    int q = 0;
    for (int i = 0; i < n; ++i) {
      if (i > 0) {
        out.print(' ');
      }
      out.print(pd[i][q]);
      q = pd[i][q] & mask;
    }
    out.println();
    out.flush();
  }
}
