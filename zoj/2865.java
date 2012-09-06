/*
二项式展开 + 矩阵乘法
*/

import java.math.*;
import java.util.*;

class BMatrix {
    private int n;
    private BigInteger[][] a;

    protected BMatrix(int k) {
        n = k;
        a = new BigInteger[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = BigInteger.ZERO;
            }
        }
    }

    static public BMatrix O(int k) {
        return new BMatrix(k);
    }

    static public BMatrix E(int k) {
        BMatrix ret = new BMatrix(k);

        for (int i = 0; i < ret.n; i++) {
            ret.a[i][i] = BigInteger.ONE;
        }

        return ret;
    }

    static public BMatrix A(int k) {
        BMatrix ret = new BMatrix(k + 2);

        ret.a[k + 1][k] = BigInteger.ONE;
        ret.a[k + 1][k + 1] = BigInteger.ONE;
        for (int i = 0; i <= k; i++) {
            ret.a[i][0] = ret.a[i][i] = BigInteger.ONE;
            for (int j = 1; j < i; j++) {
                ret.a[i][j] = ret.a[i - 1][j - 1].add(ret.a[i - 1][j]);
            }
        }

        return ret;
    }

    public BMatrix multiply(BMatrix m) {
        BMatrix ret = BMatrix.O(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    ret.a[i][j] = ret.a[i][j].add(a[i][k].multiply(m.a[k][j]));
                }
            }
        }

        return ret;
    }

    public BMatrix pow(BigInteger k) {
        BMatrix ret = this;

        for (int b = k.bitLength() - 2; b >= 0; b--) {
            ret = ret.multiply(ret);
            if (k.testBit(b)) {
                ret = ret.multiply(this);
            }
        }

        return ret;
    }

    public BigInteger sum() {
        BigInteger ret = BigInteger.ZERO;

        for (int i = 0; i < n - 1; i++) {
            ret = ret.add(a[n - 1][i]);
        }

        return ret;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        try {
            while (true) {
                BigInteger n = scan.nextBigInteger();
                int k = scan.nextInt();

                if (n.signum() == 0) {
                    System.out.println("0");
                }
                else {
                    System.out.println(BMatrix.A(k).pow(n).sum());
                }
            }
        }
        catch (Exception e) {
        }
    }
}

/*
Submit Time     Language    Run Time(ms)    Run Memory(KB)      User Name
2008-11-26 22:32:55     Java    0   4346    watashi@Zodiac
2008-09-27 09:53:08     C++     20  516     11
2007-10-12 05:31:16     C++     20  1236    Prinse
2007-10-12 05:32:20     C++     30  1240    Prinse
2007-10-12 05:07:17     C++     30  1244    Prinse
2008-09-27 10:45:44     C++     40  9136    饭饭的角
2007-09-16 19:14:29     C++     50  888     Etrnls
2007-10-12 22:06:53     C++     60  892     Etrnls
2007-10-14 17:03:24     C++     60  892     Etrnls
2007-06-19 15:18:17     C++     60  5484    zhousc
2007-06-18 02:42:23     C++     60  6420    mj
2007-06-17 14:21:32     C++     70  888     wubin_s1
*/

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1711281   2008-11-26 22:50:04     Accepted    2865    Java    0   5951    watashi@Zodiac

// 2012-09-07 01:43:48 | Accepted | 2865 | Java | 3660 | 25547 | watashi | Source
