// dp

import java.math.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        while (in.hasNextInt()) {
            int n = in.nextInt();
            int k = in.nextInt();
            boolean[][] b = new boolean[n + 2][n + 2];
            for (int i = 0; i < n; ++i) {
                String s = in.next();
                for (int j = 0; j < n; ++j) {
                    if (s.charAt(j) == '0') {
                        b[i + 1][j + 1] = true;
                    }
                }
            }

            BigInteger[][] prev, next; // if int|long then WA;
            prev = new BigInteger[n + 2][n + 2];
            for (BigInteger[] ar : prev) {
                Arrays.fill(ar, BigInteger.ZERO);
            }
            prev[1][1] = BigInteger.ONE;
            while (k-- > 0) {
                next = new BigInteger[n + 2][n + 2];
                for (BigInteger[] ar : next) {
                    Arrays.fill(ar, BigInteger.ZERO);
                }
                for (int i = 1; i <= n; ++i) {
                    for (int j = 1; j <= n; ++j) {
                        if (b[i][j]) {
                            next[i][j] = next[i][j].add(prev[i - 1][j]);
                            next[i][j] = next[i][j].add(prev[i + 1][j]);
                            next[i][j] = next[i][j].add(prev[i][j - 1]);
                            next[i][j] = next[i][j].add(prev[i][j + 1]);
                        }
                    }
                }
                prev = next;
            }
            System.out.println(prev[n][n]);
        }
    }
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1755327   2009-02-03 22:42:41     Accepted    1536    Java    0   1554    watashi@Zodiac

/*
##BUG##
Submit Time     Language    Run Time(ms)    Run Memory(KB)      User Name
2006-04-04 07:40:31     C++     0   816     SHOIT
2009-02-03 22:42:41     Java    0   1554    watashi@Zodiac
2008-08-07 03:30:03     FPC     10  424     IwfWcf@LZOI
2005-09-13 16:01:34     C   10  428     Leave me alone
2008-08-07 11:51:46     FPC     10  432     IwfWcf@LZOI
2006-04-05 23:48:09     C++     10  812     hello
2006-02-15 22:53:21     C++     10  1108    lucky boy
2006-04-04 07:37:37     C++     10  1820    SHOIT
2008-08-07 03:31:38     FPC     20  428     IwfWcf
*/

// 2012-09-07 00:52:42 | Accepted | 1536 | Java | 170 | 4221 | watashi | Source
