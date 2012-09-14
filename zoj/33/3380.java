import java.math.*;
import java.util.*;

public class Main {
    static final int MAXN = 128;
    static BigInteger[] f;
    static BigInteger[][] c;

    static {
        f = new BigInteger[MAXN];
        c = new BigInteger[MAXN][];
        for (int i = 0; i < MAXN; ++i) {
            f[i] = i == 0 ? BigInteger.ONE : f[i - 1].multiply(BigInteger.valueOf(i));
            c[i] = new BigInteger[i + 1];
            c[i][0] = c[i][i] = BigInteger.ONE;
            for (int j = 1; j < i; ++j) {
                c[i][j] = c[i - 1][j - 1].add(c[i - 1][j]);
            }
        }
    }

    static void print(BigInteger num, BigInteger den) {
        BigInteger gcd = num.gcd(den);
        System.out.println(num.divide(gcd) + "/" + den.divide(gcd));
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNextInt()) {
            int m = in.nextInt();
            int n = in.nextInt();
            int l = in.nextInt();

            // optional optimization
            if (m < l) {
                System.out.println("mukyu~");
                continue;
            } else if (l > m / 2) {
                BigInteger ans = BigInteger.ZERO;
                for (int i = l; i <= m; ++i) {
                    ans = ans.add(c[m][i].multiply(BigInteger.valueOf(n - 1).pow(m - i)));
                }
                ans = ans.multiply(BigInteger.valueOf(n));
                print(ans, BigInteger.valueOf(n).pow(m));
                continue;
            }

            BigInteger[][] dp = new BigInteger[m + 1][m + 1];
            for (int i = 0; i < dp.length; ++i) {
                Arrays.fill(dp[i], BigInteger.ZERO);
            }
            dp[0][0] = BigInteger.ONE;
            for (int i = 0; i < m && i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (dp[i][j].signum() == 0) {
                        continue;
                    }
                    for (int k = 1; k < l && j + k <= m; ++k) {
                        // dp[i + 1][j + k] = dp[i + 1][j + k].add(dp[i][j].multiply(c[m - j][k].multiply(BigInteger.valueOf(n - i))));
                        dp[i + 1][j + k] = dp[i + 1][j + k].add(dp[i][j].multiply(c[m - j - 1][k - 1].multiply(BigInteger.valueOf(n - i))));
                    }
                }
            }

            BigInteger ans = BigInteger.ZERO;
            for (int i = 1; i <= m; ++i) {
            //  ans = ans.add(dp[i][m].divide(f[i]));
                ans = ans.add(dp[i][m]);
            }
            BigInteger sum = BigInteger.valueOf(n).pow(m);
            ans = sum.subtract(ans);
            print(ans, sum);
        }
    }
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//574   2010-07-16 19:35:53     Accepted    1062    Java    1130    3053    anotherpeg  Source

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//222   2010-08-12 15:15:17     Accepted    pache   Java    940     13428   watashi@Zodiac  Source

// 2012-09-07 15:50:51 | Accepted | 3380 | Java | 970 | 9679 | watashi | Source
