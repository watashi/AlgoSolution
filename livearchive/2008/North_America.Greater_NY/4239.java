import java.math.*;
import java.util.*;

public class Main {
    static final int N = 21, TP = 64, FP = 25, XP = 64;
    static final BigInteger TWO = BigInteger.valueOf(2);
    static final BigInteger FIV = BigInteger.valueOf(5);

    static BigInteger pow(BigInteger[] a, BigInteger b, BigInteger m) {
        BigInteger c = BigInteger.ONE;
        for (int i = 0; i < b.bitLength(); ++i) {
            if (b.testBit(i)) {
                c = c.multiply(a[i]).mod(m);
            }
        }
        return c;
    }

    static boolean chk(BigInteger b, int r) {
        String s = b.toString();
        if (s.length() != r) {
            return false;
        }
        for (int i = 0; i < r; ++i) {
            if (s.charAt(i) != '1' && s.charAt(i) != '2') {
                return false;
            }
        }
        return true;
    }

    public static void main(String args[]) {
        BigInteger[] ans = new BigInteger[N + 1];
        BigInteger[] a = new BigInteger[XP];
        ans[1] = BigInteger.ONE;
        for (int i = 2; i <= N; ++i) {
            BigInteger mod = BigInteger.ONE;
            for (int j = 0; j < i; ++j) {
                mod = mod.multiply(BigInteger.TEN);
            }
            a[0] = TWO;
            for (int j = 1; j < XP; ++j) {
                a[j] = a[j - 1].multiply(a[j - 1]).mod(mod);
            }
            if (chk(pow(a, ans[i - 1], mod), i)) {
                ans[i] = ans[i - 1];
                continue;
            }
            for (int tp = 0; tp < TP; ++tp) {
                for (int fp = 0; fp < FP; ++fp) {
                    BigInteger p = TWO.pow(tp).multiply(FIV.pow(fp)).add(ans[i - 1]);
                    if (ans[i] != null && p.compareTo(ans[i]) >= 0) {
                        continue;
                    }
                    if (chk(pow(a, p, mod), i)) {
                        ans[i] = p;
                    }
                }
            }
        }
        
        Scanner in = new Scanner(System.in);
        int re = in.nextInt();
        for (int ri = 1; ri <= re; ++ri) {
            int n = in.nextInt();
            System.out.println(ri + " " + n + " " + ans[n]);
        }
    }
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//805858 	4239 	The Two Note Rag 	Accepted 	JAVA 	0.896 	2011-05-23 13:52:43
/*
id => 1174208
pid => 4239
pname => The Two Note Rag
status => Accepted
lang => JAVA
time => 0.839
date => 2012-12-14 17:38:39
*/
