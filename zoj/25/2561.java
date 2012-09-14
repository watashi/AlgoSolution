// ZOJ 2860

import java.util.*;

public class Main {
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
                    // for (int j = 0; j < dp[i].length; ++j) {
                    //  dp[i][j] = 0;
                    // }
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

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1814336   2009-04-02 04:04:10     Accepted    2561    Java    0   33833   watashi@Zodiac

// 2012-09-07 15:40:08 | Accepted | 2561 | Java | 2000 | 36017 | watashi | Source
