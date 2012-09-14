import java.math.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int re = in.nextInt();
        for (int ri = 1; ri <= re; ++ri) {
            double y1 = in.nextDouble();
            double x1 = in.nextDouble();
            double d1 = in.nextDouble() * Math.PI / 180;
            double y2 = in.nextDouble();
            double x2 = in.nextDouble();
            double d2 = in.nextDouble() * Math.PI / 180;

            double a1 = Math.sin(d1);
            double b1 = -Math.cos(d1);
            double c1 = x1 * a1 + y1 * b1;
            double a2 = Math.sin(d2);
            double b2 = -Math.cos(d2);
            double c2 = x2 * a2 + y2 * b2;

            double d = a1 * b2 - a2 * b1;
            double x = (c1 * b2 - c2 * b1) / d;
            double y = (a1 * c2 - a2 * c1) / d;

            System.out.printf("%.4f %.4f\n", y, x);
        }
    }
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1755835   2009-02-04 14:37:00     Accepted    1560    Java    0   813     watashi@Zodiac

// 2012-09-07 00:53:55 | Accepted | 1560 | Java | 70 | 1062 | watashi | Source
