import java.util.*;

public class Main {
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
        Scanner in = new Scanner(System.in);
        int re = in.nextInt();
        for (int ri = 1; ri <= re; ++ri) {
            if (ri > 1) {
                System.out.println();
            }
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
            System.out.println(dp[0][0]);
            int q = 0;
            for (int i = 0; i < n; ++i) {
                if (i > 0) {
                    System.out.print(' ');
                }
                System.out.print(pd[i][q]);
                q = pd[i][q] & mask;
            }
            System.out.println();
        }
    }
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1787167   2009-03-13 02:00:25     Accepted    2341    Java    0   3463    watashi@Zodiac

/*
 * ZOJ BUG
Submit Time     Language    Run Time(ms)    Run Memory(KB)      User Name
2009-03-13 02:00:25     Java    0   3463    watashi@Zodiac
2008-10-03 09:40:25     C++     290     748     QiZiChao
2008-10-20 16:07:30     C++     310     1784    Sweety_xt
2008-10-13 09:48:07     C++     340     1352    Lostmonkey
2008-10-21 12:04:51     C++     350     1352    skoier
2008-09-19 20:12:21     C++     410     1836    CaiMa
2008-11-29 18:37:21     C++     480     1252    gnocuil
2008-10-06 15:16:43     C++     500     1752    FAndy
2008-12-04 21:33:07     C++     650     2056    zkw
2008-10-19 17:21:00     C++     680     1280    rendezvous_hello_world
2006-05-10 00:12:22     C++     810     1544    11
*/

// 2012-09-07 01:19:48 | Accepted | 2341 | Java | 1580 | 8369 | watashi | Source
