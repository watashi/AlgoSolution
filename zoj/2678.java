import java.math.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        boolean blank = false;

        while (scanner.hasNextBigInteger()) {
            if (blank) {
                System.out.println();
            }
            else {
                blank = true;
            }
            BigInteger a = scanner.nextBigInteger();
            BigInteger b = scanner.nextBigInteger();
            System.out.println(a.gcd(b));
        }
    }
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1721289   2008-12-08 04:47:02     Accepted    2678    Java    0   241     watashi@Zodiac

// 2012-09-07 15:43:38 | Accepted | 2678 | Java | 60 | 252 | watashi | Source
