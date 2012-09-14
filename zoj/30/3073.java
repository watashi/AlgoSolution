/**
 * @file    Main.java
 * @author  watashi
 */

import java.io.*;
import java.math.*;

/*
 * Fraction
 */
class Fraction {
    private BigInteger num, den;

    public Fraction(BigInteger n) {
        num = n;
        den = BigInteger.ONE;
    }

    public Fraction(BigInteger n, BigInteger d) {
        if (d.signum() > 0) {
            num = n;
            den = d;
        } else if (d.signum() < 0) {
            num = n.negate();
            den = d.negate();
        } else {
            throw new ArithmeticException();
        }
        BigInteger g = num.gcd(den);
        num.divide(g);
        den.divide(g);
    }

    public Fraction add(Fraction f) {
        BigInteger n = num.multiply(f.den).add(den.multiply(f.num));
        BigInteger d = den.multiply(f.den);
        BigInteger g = n.gcd(d);
        n = n.divide(g);
        d = d.divide(g);
        return new Fraction(n, d);
    }

    public Fraction multiply(Fraction f) {
        BigInteger n = num.multiply(f.num);
        BigInteger d = den.multiply(f.den);
        BigInteger g = n.gcd(d);
        n = n.divide(g);
        d = d.divide(g);
        return new Fraction(n, d);
    }

    public int signum() {
        return num.signum();
    }

    public String toString() {
        return num.toString() + "/" + den.toString();
    }
}

/*
 * Choose
 */
/*
class Choose {
    private BigInteger[][] C;

    // O(n^2)
    public Choose(int n) {
        C = new BigInteger[n + 1][];
        for (int i = 0; i <= n; i++) {
            C[i] = new BigInteger[i + 1];
            C[i][0] = C[i][i] = BigInteger.ONE;
            for (int j = 1; j < i; j++) {
                C[i][j] = C[i - 1][j - 1].add(C[i - 1][j]);
            }
        }
    }

    public BigInteger get(int n, int k) {
        return C[n][k];
    }
}
 */

/*
 * Stirling numbers of the second kind
 *
 * S(n,k)=S(n-1,k-1)+kS(n-1,k), with S(n,1)=S(n,n)=1
 * x^n=\sum_{k=0}^n{S(n,k)(x)_k}
 */
class Stirling2 {
    private BigInteger[][] S;

    // O(n^2)
    public Stirling2(int n) {
        S = new BigInteger[n + 1][];
        S[0] = new BigInteger[1];
        S[0][0] = BigInteger.ONE;
        for (int i = 1; i <= n; i++) {
            S[i] = new BigInteger[i + 1];
            S[i][0] = BigInteger.ZERO;
            for (int j = 1; j < i; j++) {
                S[i][j] = S[i - 1][j - 1].add(
                        S[i - 1][j].multiply(BigInteger.valueOf(j)));
            }
            S[i][i] = BigInteger.ONE;
        }
    }

    public BigInteger get(int n, int k) {
        return S[n][k];
    }
}

/*
 * Polynomial
 */
class Polynomial {
    private Fraction[] a;

    public Polynomial(BigInteger[] p) {
        a = new Fraction[p.length];
        for (int i = 0; i < p.length; i++) {
            a[i] = new Fraction(p[i]);
        }
    }

    public Polynomial(Fraction[] p) {
        a = (Fraction[]) p.clone();
    }

    public int degree() {
        return a.length - 1;
    }

    public Fraction get(int i) {
        return a[i];
    }

    public Fraction eval(Fraction f) {
        Fraction ret = new Fraction(BigInteger.ZERO);

        for (int i = degree(); i >= 0; i--) {
            ret = ret.multiply(f);
            ret = ret.add(get(i));
        }

        return ret;
    }

    public Polynomial multiply(Fraction f) {
        Polynomial ret = (Polynomial) clone();

        for (int i = 0; i < ret.a.length; i++) {
            ret.a[i] = ret.a[i].multiply(f);
        }

        return ret;
    }

    public String toString() {
        int d = degree();
        while (d > 0 && get(d).signum() == 0) {
            --d;
        }

        String ret = new Integer(d).toString();

        for (int i = d; i >= 0; i--) {
            ret += " " + get(i).toString();
        }

        return ret;
    }

    public Object clone() {
        return new Polynomial(a);
    }
}

/*
 * Bernstein polynomial
 *
 * B_n(f)=\sum_{i=0}^n{f(\frac{i}{n}){n \choose i}x^i(1-x)^{n-i}}
 * B_n(x^k)=\sum_{i=0}^k{\frac{(n)_i}{n^k}S(n,i)x^i}
 */
class Bernstein {
//  private Choose C;

    private Stirling2 S;

    public Bernstein(int n, int d) {
//      C = new Choose(n);
        S = new Stirling2(d);
    }

    // B_n(x^k)=\sum_{i=0}^k{\frac{(n)_i}{n^k}S(n,i)x^i}
    // O(d^2)
    public Polynomial get(Polynomial p, int n) {
        Fraction f;
        BigInteger b = BigInteger.ONE;
        Fraction[] ans = new Fraction[p.degree() + 1];

        for (int i = 0; i <= p.degree(); i++) {
            ans[i] = new Fraction(BigInteger.ZERO);
        }
        for (int i = 0; i <= p.degree(); i++) {
            f = new Fraction(BigInteger.ONE, b);
            for (int j = 0; j <= i; j++) {
                ans[j] = ans[j].add(p.get(i).multiply(f.multiply(
                        new Fraction(S.get(i, j), BigInteger.ONE))));
                f = f.multiply(new Fraction(BigInteger.valueOf(n - j)));
            }
            b = b.multiply(BigInteger.valueOf(n));
        }

        return new Polynomial(ans);
    }
/*
    // B_n(f)=\sum_{i=0}^n{f(\frac{i}{n}){n \choose i}x^i(1-x)^{n-i}}
    // O(n^2)
    public Polynomial get2(Polynomial p, int n) {
        Fraction[] ans = new Fraction[p.degree() + 1];
        Fraction f;

        for (int i = 0; i < ans.length; i++) {
            ans[i] = new Fraction(BigInteger.ZERO);
        }
        for (int i = 0; i <= p.degree() && i <= n; i++) {
            f = p.eval(new Fraction(BigInteger.valueOf(i),
                    BigInteger.valueOf(n)));
            f = f.multiply(new Fraction(C.get(n, i)));
            for (int j = 0; j <= p.degree() - i && j <= n - i; j++) {
                if (j % 2 == 0) {
                    ans[i + j] = ans[i + j].add(f.multiply(
                            new Fraction(C.get(n - i, j))));
                } else {
                    ans[i + j] = ans[i + j].add(f.multiply(
                            new Fraction(C.get(n - i, j).negate())));
                }
            }
        }

        return new Polynomial(ans);
    }
*/
}

public class Main {
    private static final int MAXD = 64;
    private static final int MAXC = 16;
    private static final int MAXN = 1024;

    public static void main(String[] args) throws IOException {
        Bernstein bernstein = new Bernstein(MAXN, MAXD);
        BufferedReader in = new BufferedReader(
                new InputStreamReader(System.in));
        String input;

        System.err.println("Initialazation DONE");
        while ((input = in.readLine()) != null) {
            String[] str = input.split(" ");
            int d = Integer.parseInt(str[0]);
            if (str.length != d + 2 || d < 0 || d >= MAXD) {
                System.err.println("Error in K");
            }
            BigInteger[] c = new BigInteger[d + 1];
            for (int i = 0; i <= d; i++) {
                c[d - i] = new BigInteger(str[i + 1]);
                int tmp = Integer.parseInt(str[i + 1]);
                if (tmp < -MAXC || tmp > MAXC) {
                    System.err.println("Error in C");
                }
            }
            Polynomial p = new Polynomial(c);
            input = in.readLine();
            int n = Integer.parseInt(input);
            if (n <= 0 || n >= MAXN) {
                System.err.println("Error in N");
            }

            System.out.println(bernstein.get(p, n));
/*          if (n >= MAXN) {
                System.err.println("###");
            } else {
                System.err.println(bernstein.get2(p, n));
            }
*/      }
    }
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1801442   2009-03-24 04:45:07     Accepted    3073    Java    0   3510    watashi@Zodiac

// 2012-09-07 02:00:12 | Accepted | 3073 | Java | 3550 | 10092 | watashi | Source
