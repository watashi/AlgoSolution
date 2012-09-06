// n <= 50

import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    static final int N = 50;

    public static void main(String[] args) throws IOException {
        BigInteger[][] dp = new BigInteger[N + 1][];

        for (int i = 1; i <= N; i++) {
            dp[i] = new BigInteger[i];
            dp[i][i - 1] = BigInteger.ONE;
            for (int j = 0; j < i - 1; j++) {
                dp[i][j] = dp[i - 1][j].multiply(BigInteger.valueOf(i - 1 - j));
                if (j > 0) {
                    dp[i][j] = dp[i][j].add(dp[i - 1][j - 1]);
                }
                if (j + 1 < i - 1) {
                    dp[i][j] = dp[i][j].add(dp[i - 1][j + 1].multiply(BigInteger.valueOf(j + 1)));
                }
            }
        }

        // -_-b
        dp[1][0] = BigInteger.ZERO;

        Scanner in = new Scanner(System.in);

        while (in.hasNextInt()) {
            System.out.println(dp[in.nextInt()][0]);
        }

        in.close();
    }
}

/*
 * O(n^2)
 *
 * O(n):
 *  dp[n] = (n - 1) * dp[n - 1] + (n - 2) * dp[n - 2];
 */

// Run ID   Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
// 1721235  2008-12-08 00:51:43     Accepted    2625    Java    0   663     watashi@Zodiac

// 2012-09-07 01:32:42 | Accepted | 2625 | Java | 60 | 844 | watashi | Source
