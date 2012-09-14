import java.math.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        BigInteger[] b = new BigInteger[10];
        for (int i = 0; i < 10; ++i) {
            b[i] = BigInteger.valueOf(i);
        }

        Scanner in = new Scanner(System.in);
        while (in.hasNextBigInteger()) {
            BigInteger n = in.nextBigInteger();
            if (n.equals(BigInteger.ONE.negate())) {
                break;
            } else if (n.compareTo(BigInteger.TEN) < 0) {
                System.out.println("1" + n);
            } else {
                StringBuffer sb = new StringBuffer();
                for (int i = 9; i >= 2; --i) {
                    while (n.mod(b[i]).equals(BigInteger.ZERO)) {
                        sb.append((char)('0' + i));
                        n = n.divide(b[i]);
                    }
                }
                System.out.println(n.equals(BigInteger.ONE) ? sb.reverse() : "There is no such number.");
            }
        }
    }
}

// Run ID   Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
// 2181428  2010-04-30 20:02:53     Accepted    1923    Java    260     1738    watashi@Zodiac

// 2012-09-07 01:06:38 | Accepted | 1923 | Java | 180 | 5489 | watashi | Source
