import java.io.*;
import java.util.*;

// Topological Sort

public class Main {
    private static int ch = 0;
    private static int[] empty = new int[0];

    public static int nextInt() throws IOException {
        int ret = 0;

        while (!Character.isDigit(ch = System.in.read())) {
            continue;
        }
        do {
            ret *= 10;
            ret += ch - '0';
        } while (Character.isDigit(ch = System.in.read()));

        return ret;
    }

    public static void main(String[] args) throws IOException {
        int re = nextInt();
        for (int ri = 1; ri <= re; ++ri) {
            int n = nextInt();
            int[][] ab = new int[n][], ba = new int[n][];
            int[] cab = new int[n], cba = new int[n];
            for (int i = 0; i < n; ++i) {
                ab[i] = empty;
                cab[i] = 0;
                cba[i] = 0;
            }
            int m = nextInt();
            for (int i = 0; i < m; ++i) {
                int a = nextInt() - 1;
                cab[a] = nextInt();
                ab[a] = new int[cab[a]];
                for (int j = 0; j < cab[a]; ++j) {
                    int b = nextInt() - 1;
                    ++cba[b];
                    ab[a][j] = b;
                }
            }

            for (int i = 0; i < n; ++i) {
                ba[i] = new int[cba[i]];
                cba[i] = 0;
            }
            for (int i = 0; i < n; ++i) {
                for (int v : ab[i]) {
                    ba[v][cba[v]++] = i;
                }
            }

            int t = 0;
            int[] q = new int[n];
            boolean[] d = new boolean[n];
            Arrays.fill(d, false);
            for (int i = 0; i < n; ++i) {
                if (cab[i] == 0 || cba[i] == 0) {
                    q[t++] = i;
                    d[i] = true;
                }
            }
            for (int p = 0; p < t; ++p) {
                for (int v : ba[q[p]]) {
                    if (!d[v]) {
                        q[t++] = v;
                        d[v] = true;
                    }
                }
                for (int v : ab[q[p]]) {
                    --cba[v];
                    if (!d[v] && cba[v] == 0) {
                        q[t++] = v;
                        d[v] = true;
                    }
                }
            }
            System.out.println(n - t);
        }
    }
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1754158   2009-02-02 20:32:36     Accepted    2682    Java    0   1612    watashi@Zodiac

// 2012-09-07 01:34:45 | Accepted | 2682 | Java | 140 | 1704 | watashi | Source
