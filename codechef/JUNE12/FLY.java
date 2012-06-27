import java.math.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int re = in.nextInt();
        for (int ri = 1; ri <= re; ++ri) {
            long n = in.nextLong();
            BigDecimal c = in.nextBigDecimal();
            int m = in.nextInt();
            HashSet<Integer> hs = new HashSet<Integer>();
            for (int i = 0; i < 2 * m; ++i) {
                hs.add(in.nextInt());
            }
            BigDecimal x = c.multiply(BigDecimal.valueOf(n * (n - 1) / 2 - m)).add(BigDecimal.valueOf(n * (n - 1)));
            BigDecimal y = c.multiply(BigDecimal.valueOf(n - 1 - m)).add(BigDecimal.valueOf((n - 1) * (n - 1) * 2));
            if (hs.size() == 4) {
                y = y.add(BigDecimal.valueOf(2 * (n - 3))).min(
                            y.add(c).subtract(BigDecimal.valueOf(2)));
            }
            x = x.min(y);
            System.out.printf("%.9f\n", x);
        }
    }
}

