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

/*
Submit Time     Language    Run Time(ms)    Run Memory(KB)      User Name
2008-12-08 04:47:02     Java    0   241     watashi@Zodiac
2006-04-30 17:01:21     C   0   388     sea
2006-03-13 19:53:51     C++     0   392     zerk
2006-05-25 19:00:48     C   0   396     intx
2007-10-18 14:28:15     C++     0   396     flowsky
2006-06-16 14:25:13     C++     0   440     041221125
2007-06-22 14:47:24     C++     0   440     Xiaolan.Lee
2006-04-13 21:05:19     C++     0   620     清风
2006-05-07 01:25:56     C++     0   840     Vovka
2006-09-17 21:51:28     C++     0   848     rxw
2008-09-27 03:34:21     C++     0   960     arena
2006-03-11 17:34:47     C   10  388     Xiaolan.Lee
*/

// 2012-09-07 01:34:27 | Accepted | 2678 | Java | 70 | 252 | watashi | Source
