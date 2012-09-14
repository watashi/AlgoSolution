import java.math.*;
import java.util.*;

public class Main {
    class Matrix implements Cloneable {
        public long[][] a;

        public Matrix() {
            a = new long[d][d];
        }

        public Matrix multiply(Matrix m) {
            Matrix ret = new Matrix();

            for (int i = 0; i < d; ++i) {
                for (int j = 0; j < d; ++j) {
                    for (int k = 0; k < d; ++k) {
                        ret.a[i][j] += a[i][k] * m.a[k][j];
                    }
                    ret.a[i][j] %= p;
                }
            }

            return ret;
        }

        public Matrix clone() {
            Matrix ret = new Matrix();

            ret.a = a.clone();

            return ret;
        }
    }

    private BigInteger n;
    private int m, d;
    private long p;

    public Main(BigInteger n, int m, long p) {
        this.n = n;
        this.m = m;
        this.d = 1 << m;
        this.p = p;
    }

    public long solve() {
        Matrix a = new Matrix();
        for (int i = 0; i < d; ++i) {
            for (int j = 0; j < d; ++j) {
                int x = i, y = j;
                for (int l = 1; l < m; ++l) {
                    if ((x & 3) == (y & 3) && ((x & 3) == 0 || (y & 3) == 3)) {
                        x = -1;
                        break;
                    } else {
                        x >>= 1;
                        y >>= 1;
                    }
                }
                a.a[i][j] = (x == -1) ? 0 : 1;
            }
        }
        Matrix s = new Matrix();
        for (int i = 0; i < d; ++i) {
            s.a[i][i] = 1;
        }
        for (int i = n.bitLength() - 1; i >= 0; --i) {
            s = s.multiply(s);
            if (n.testBit(i)) {
                s = s.multiply(a);
            }
        }
        long ret = 0;
        for (int i = 0; i < d; ++i) {
            for (int j = 0; j < d; ++j) {
                ret += s.a[i][j];
            }
        }
        return ret % p;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int re = in.nextInt();
        for (int ri = 1; ri <= re; ++ri) {
            if (ri > 1) {
                System.out.println();
            }
            BigInteger n = in.nextBigInteger();
            int m = in.nextInt();
            int p = in.nextInt();
            Main solution = new Main(n.subtract(BigInteger.ONE), m, p);
            System.out.println(solution.solve());
        }
    }
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1776580   2009-03-03 19:19:21     Accepted    2317    Java    0   2570    watashi@Zodiac

// 2012-09-07 15:37:43 | Accepted | 2317 | Java | 2640 | 7832 | watashi | Source
