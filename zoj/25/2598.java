import java.math.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNextBigInteger()) {
            BigInteger r = in.nextBigInteger();
            if (r.signum() < 0) {
                break;
            }
            int c = 0;
            BigInteger x = BigInteger.ONE, y = BigInteger.ZERO;
            for (int i = 0; i < r.bitLength(); ++i) {
                if (r.testBit(i)) {
                    BigInteger xx = x.add(y);
                    BigInteger yy = x.multiply(BigInteger.valueOf(c)).add(y.multiply(BigInteger.valueOf(c + 1)));
                    x = xx;
                    y = yy;
                    c = 0;
                } else {
                    ++c;
                }
            }
            System.out.println(x.add(y));
        }
    }
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//2248981   2010-08-02 14:20:41     Accepted    2598    Java    50  684     watashi@Zodiac  Source

// 2012-09-07 15:42:12 | Accepted | 2598 | Java | 50 | 633 | watashi | Source
