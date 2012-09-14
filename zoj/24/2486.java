import java.math.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNextInt()) {
            int n = in.nextInt();
            double p = in.nextDouble();
            System.out.printf("%.0f\n", Math.pow(p, 1. / n));
        }
    }
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1759853   2009-02-07 01:30:52     Accepted    2486    Java    0   327     watashi@Zodiac

// 2012-09-07 01:24:37 | Accepted | 2486 | Java | 40 | 428 | watashi | Source
