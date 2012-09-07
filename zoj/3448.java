import java.math.*;
import java.util.*;

public class Main {
    static final int[] pl = new int[]{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    static final int pn = pl.length;
    static final int[][] ps = new int[33][pn];

    static {
        for (int i = 1; i < ps.length; ++i) {
            for (int j = 0; j < pl.length; ++j) {
                int k = i;
                while (k % pl[j] == 0) {
                    ++ps[i][j];
                    k /= pl[j];
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNextInt()) {
            int n = in.nextInt();
            int b = in.nextInt();
            int s = in.nextInt();
            int t = in.nextInt();

            System.out.print(BigInteger.valueOf(b).pow(t - 2).multiply(BigInteger.valueOf(b - 1)));

            BigInteger ans = BigInteger.ZERO;
            for (int i = 1; i < b; ++i) {
                int[] a = new int[pn];
                BigInteger tmp = BigInteger.ONE;

                for (int j = 0; j < pn; ++j) {
                    a[j] = ps[i][j] + ps[b][j] * (n - 1);
                    tmp = tmp.multiply(BigInteger.valueOf(a[j] + 1));
                }

                int dif = i;
                for (int k = 1; k <= i; ++k) {
                    for (int j = 0; j < pn; ++j) {
                        if (ps[k][j] > a[j]) {
                            --dif;
                            break;
                        }
                    }
                }

                ans = ans.add(tmp.subtract(BigInteger.valueOf(dif)));
            }

            System.out.println(" " + ans);
        }
    }
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//636   2010-12-24 01:24:22     Accepted    D   Java    640     3360    watashi@Zodiac  Source

// 2012-09-07 15:57:06 | Accepted | 3448 | Java | 730 | 7149 | watashi | Source
