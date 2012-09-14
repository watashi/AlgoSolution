/*
import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    private static int N = 50;

    public static void main(String[] args) throws IOException {
        BigInteger[][] tree = new BigInteger[N + 1][N + 1]; // not necessary
        BigInteger[][] forest = new BigInteger[N + 1][N + 1];

        for (int i = 0; i <= N; i++) {
            forest[0][i] = tree[0][i] = BigInteger.ONE;
        }
        for (int i = 1; i <= N; i++) {
            tree[i][0] = BigInteger.ZERO;
            for (int j = 1; j < i; j++) {
                tree[i][j] = forest[i - 1][j - 1];
            }
            tree[i][i] = tree[i][i - 1].add(BigInteger.ONE);
            for (int j = i + 1; j <= N; j++) {
                tree[i][j] = tree[i][i];
            }

            for (int j = 0; j <= N; j++) {
                forest[i][j] = BigInteger.ZERO;
                for (int k = 1; k <= i; k++) {
                    forest[i][j] = forest[i][j].add(tree[k][j].multiply(forest[i - k][j]));
                }
            }
        }

        Scanner in = new Scanner(System.in);

        for (int ri = 1; ; ri++) {
            int n = in.nextInt();
            int k = in.nextInt();
            if (n == 0 && k == 0) {
                break;
            }
            if (ri > 1) {
                System.out.println();
            }
            System.out.println("Case " + ri + ": "
                    + forest[n][k].subtract(forest[n][k - 1]));
        }
    }
}
*/

import java.math.*;
import java.util.*;

public class Main {
    static final int N = 52;

    public static void main(String[] args) {
        BigInteger[][] tree = new BigInteger[N + 1][N + 1]; // not necessary
        BigInteger[][] forest = new BigInteger[N + 1][N + 1];

        for (int i = 0; i <= N; i++) {
            forest[0][i] = tree[0][i] = BigInteger.ONE;
        }
        for (int i = 1; i <= N; i++) {
            tree[i][0] = BigInteger.ZERO;
            for (int j = 1; j < i; j++) {
                tree[i][j] = forest[i - 1][j - 1];
            }
            tree[i][i] = tree[i][i - 1].add(BigInteger.ONE);
            for (int j = i + 1; j <= N; j++) {
                tree[i][j] = tree[i][i];
            }

            for (int j = 0; j <= N; j++) {
                forest[i][j] = BigInteger.ZERO;
                for (int k = 1; k <= i; k++) {
                    forest[i][j] = forest[i][j].add(tree[k][j].multiply(forest[i - k][j]));
                }
            }
        }

        Scanner in = new Scanner(System.in);

        for (int ri = 1; ; ri++) {
            int n = in.nextInt();
            int k = in.nextInt();
            if (n == 0 && k == 0) {
                break;
            }
            if (ri > 1) {
                System.out.println();
            }
            System.out.println("Case " + ri + ": "
                    + forest[n][k].subtract(forest[n][k - 1]));
        }
    }
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1721999   2008-12-09 00:14:19     Accepted    2604    Java    0   329     watashi@Zodiac

// 2012-09-07 01:31:42 | Accepted | 2604 | Java | 380 | 2032 | watashi | Source
