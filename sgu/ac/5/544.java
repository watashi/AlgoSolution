// SGU544. Chess Championship
import java.io.*;
import java.util.*;

public class Solution {
  static final int MAXN = 512;
  static final int MOD = 1000000009;
  static int fact[] = new int[MAXN];
  static int choose[][] = new int[MAXN][MAXN];

  static {
    for (int i = 0; i < MAXN; ++i) {
      fact[i] = i == 0 ? 1 : mul(fact[i - 1], i);
      choose[i][0] = 1;
      for (int j = 1; j <= i; ++j) {
        choose[i][j] = add(choose[i - 1][j - 1], choose[i - 1][j]);
      }
    }
  }

  static int add(int a, int b) {
    a += b;
    if (a >= MOD) {
      a -= MOD;
    }
    return a;
  }

  static int sub(int a, int b) {
    return a >= b ? a - b : a - b + MOD;
  }

  static int mul(int a, int b) {
    return (int)(1L * a * b % MOD);
  }

  public static void main(String[] args) throws IOException {
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();
    int m = in.nextInt();
    int[] a = new int[n];
    for (int i = 0; i < n; ++i) {
      a[i] = in.nextInt();
    }
    int[] b = new int[n];
    for (int j = 0; j < n; ++j) {
      b[j] = in.nextInt();
    }
    int[] c = new int[n];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (a[i] > b[j]) {
          ++c[i];
        }
      }
    }
    Arrays.sort(c);
    for (int i = n - 1; i > 0; --i) {
      c[i] -= c[i - 1];
    }

    int[][] cur = new int[1][n + 1];
    cur[0][0] = 1;
    for (int k = 0; k < n; ++k) {
      int[][] pre = cur;
      cur = new int[k + 2][n + 1];
      for (int i = 0; i < pre.length; ++i) {
        for (int j = 0; j < pre[i].length; ++j) {
          if (pre[i][j] == 0) {
            continue;
          }
          // System.out.printf("[%d][%d][%d] = %d\n", k, i, j, pre[i][j]);
          cur[i][j + c[k]] = add(cur[i][j + c[k]], pre[i][j]);
          if (j + c[k] > 0) {
            cur[i + 1][j + c[k] - 1] = add(cur[i + 1][j + c[k] - 1], mul(pre[i][j], j + c[k]));
          }
        }
      }
    }
    /*
    for (int i = 0; i < cur.length; ++i) {
      for (int j = 0; j < cur[i].length; ++j) {
        if (cur[i][j] != 0) {
          System.out.printf("[%d][%d][%d] = %d\n", n, i, j, cur[i][j]);
        }
      }
    }
    */

    int[] cnt = new int[n + 1];
    for (int i = n; i >= 0; --i) {
      for (int j = 0; j <= n; ++j) {
        cnt[i] = add(cnt[i], cur[i][j]);
      }
      cnt[i] = mul(cnt[i], fact[n - i]);
      for (int j = i + 1; j <= n; ++j) {
        cnt[i] = sub(cnt[i], mul(cnt[j], choose[j][i]));
      }
      // System.err.printf("cnt[%d] = %d\n", i, cnt[i]);
    }

    int ans = 0;
    for (int i = 0; i <= n; ++i) {
      if (i - (n - i) == m) {
        ans = add(ans, cnt[i]);
      }
    }
    System.out.println(ans);
  }
}

// ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
// 1379867	22.10.12 21:24	watashi	544 	.JAVA	Accepted 	239 ms	8660 kb
// 1375919	22.10.12 16:00	* watashi	C 	.JAVA	Accepted 	246 ms	8660 kb
