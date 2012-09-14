import java.util.*;
import java.math.*;

public class Main {
    static final int MAXN = 50;
    static BigInteger[] y;
    static BigInteger[][] x;

    static {
        y = new BigInteger[MAXN + 1];
        x = new BigInteger[MAXN + 1][];
        y[0] = BigInteger.ONE;
        x[0] = new BigInteger[]{BigInteger.ONE};
        for (int i = 1; i <= MAXN; ++i) {
            y[i] = y[i - 1].multiply(BigInteger.valueOf(i));
            x[i] = new BigInteger[i + 1];
            x[i][0] = BigInteger.ZERO;
            x[i][i] = BigInteger.ONE;
            for (int j = 1; j < i; ++j) {
                x[i][j] = x[i - 1][j - 1].add(x[i - 1][j].multiply(BigInteger.valueOf(i - 1)));
            }
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNextInt()) {
            int n = in.nextInt();
            int k = in.nextInt();
            BigInteger sum = BigInteger.ZERO;
            for (int i = 1; i <= k; i += 2) {
                sum = sum.add(x[n][i]);
            }
            BigInteger gcd = sum.gcd(y[n]);
            System.out.println(sum.divide(gcd) + "/" + y[n].divide(gcd));
        }
    }
}

// 2012-09-07 15:47:07 | Accepted | 3344 | Java | 480 | 1232 | watashi | Source
