import java.math.*;
import java.util.*;

public class Main {
    private BigInteger[] dp;

    public Main(int n) {
        dp = new BigInteger[n + 1];
        dp[0] = BigInteger.ZERO;
        for (int i = 1; i < dp.length; ++i) {
            dp[i] = dp[i - 1].add(BigInteger.ONE);  // *< & >..>V
            for (int j = 1; j < i ; ++j) {
                dp[i] = dp[i].add(dp[j]);   // *>..>V, j=len(*)
            }
        }
    }

    public BigInteger get(int i) {
        return dp[i];
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Main solution = new Main(100);
        while (in.hasNextInt()) {
            System.out.println(solution.get(in.nextInt()));
        }
    }
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1759443   2009-02-06 19:23:50     Accepted    1512    Java    0   663     watashi@Zodiac

// 2012-09-07 00:51:47 | Accepted | 1512 | Java | 60 | 633 | watashi | Source
