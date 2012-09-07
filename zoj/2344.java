// TAG: Polya

import java.math.*;
import java.util.*;

public class Main {
    private static BigInteger TWO = BigInteger.valueOf(2);
    private static boolean[] mark = new boolean[512];
    public static int cyclic(int[] p) {
        int ret = 0;
        Arrays.fill(mark, 0, p.length, false);
        for (int i = 0; i < p.length; ++i) {
            if (!mark[i]) {
                ++ret;
                for (int j = i; !mark[j]; j = p[j]) {
                    mark[j] = true;
                }
            }
        }
        return ret;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNextInt()) {
            int n = in.nextInt();
            int m = in.nextInt();
            int nm = n * m;
            int[][] p;
            if (n == m) {
                p = new int[4][nm];
            } else {
                p = new int[2][nm];
            }
            BigInteger num = BigInteger.ZERO;
            int den = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    for (int k = 0; k < nm; ++k) {
                        int x = ((k / m) + i) % n;
                        int y = ((k % m) + j) % m;
                        p[0][k] = x * m + y;
                        p[1][k] = (n - 1 - x) * m + (m - 1 - y); // nm - 1 - p[0][k];
                        if (n == m) {
                            p[2][k] = y * m + (m - 1 - x);
                            p[3][k] = (n - 1 - y) * m + x;
                        }
                    }
                    for (int[] pp : p) {
                        num = num.add(TWO.pow(cyclic(pp)));
                        ++den;
                    }
                }
            }
            // System.err.println(num);
            // System.err.println(den);
            num = num.divide(BigInteger.valueOf(den));
            System.out.println(num);
        }
    }
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1787937   2009-03-13 21:07:45     Accepted    2344    Java    0   2074    watashi@Zodiac

// 2012-09-07 15:38:52 | Accepted | 2344 | Java | 340 | 4910 | watashi | Source
