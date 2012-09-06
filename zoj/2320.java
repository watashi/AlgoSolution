import java.math.*;
import java.util.*;

public class Main {
    static int np;
    static int[] p;

    static {
        np = 0;
        p = new int[256];
        boolean[] m = new boolean[1024];
        for (int i = 2; i < m.length; ++i) {
            if (m[i]) {
                continue;
            }
            p[np++] = i;
            for (int j = i + i; j < m.length; j += i) {
                m[j] = true;
            }
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int re = in.nextInt();
        for (int ri = 1; ri <= re; ++ri) {
            if (ri > 1) {
                System.out.println();
            }
            int t = in.nextInt();
            int m = in.nextInt();
            boolean[][] a = new boolean[t][m];
            for (int j = 0; j < m; ++j) {
                int b = in.nextInt();
                for (int i = 0; i < t; ++i) {
                    int k = 0;
                    while (b % p[i] == 0) {
                        b /= p[i];
                        ++k;
                    }
                    a[i][j] = (k % 2 != 0);
                }
            }
            // elimination
            int r = 0, c = 0;
            boolean swap;
            /* for (boolean[] b : a) {
                for (boolean e : b) {
                    System.err.print(e ? "1" : "0");
                }
                System.err.println();
            } */
            while (r < t && c < m) {
                int rr = -1;
                for (int i = r; i < t; ++i) {
                    if (a[i][c]) {
                        rr = i;
                        break;
                    }
                }
                if (rr == -1) {
                    ++c;
                } else {
                    for (int j = c; j < m; ++j) {
                        swap = a[r][j];
                        a[r][j] = a[rr][j];
                        a[rr][j] = swap;
                    }
                    for (int i = r + 1; i < t; ++i) {
                        if (a[i][c]) {
                            a[i][c] = false;
                            for (int j = c + 1; j < m; ++j) {
                                if (a[r][j]) {
                                    a[i][j] = !a[i][j];
                                }
                            }
                        }
                    }
                    ++r;
                }
            }
            /* for (boolean[] b : a) {
                for (boolean e : b) {
                    System.err.print(e ? "1" : "0");
                }
                System.err.println();
            } */
            System.out.println(BigInteger.valueOf(2).pow(m - r).subtract(BigInteger.ONE));
        }
    }
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1777067   2009-03-03 23:02:43     Accepted    2320    Java    0   848     watashi@Zodiac

// 2012-09-07 01:18:53 | Accepted | 2320 | Java | 90 | 1056 | watashi | Source
