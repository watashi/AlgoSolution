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

// 2012-09-07 15:38:33 | Accepted | 2341 | Java | 1610 | 3326 | watashi | Source
