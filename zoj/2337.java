import java.math.*;
import java.util.*;

class DFA {
    private int z, k, s;
    private int[] t;
    private int[][] e;

    private int dfs(int p, int[] e, int[] f, boolean[] g) {
        if (e[p] == -1) {
        } else if (g[p]) {
            e[p] = f[p];
        } else {
            e[p] = -1;
            e[p] = dfs(f[p], e, f, g);
        }
        return e[p];
    }

    public DFA(char[] z, int k, int s, int[] t, int[][] f, boolean[][] g) {
        this.z = z.length;
        this.k = k;
        this.s = s;
        this.t = t.clone();
        e = new int[z.length][k];
        for (int i = 0; i < z.length; ++i) {
            Arrays.fill(e[i], -2);
            for (int j = 0; j < k; ++j) {
                if (e[i][j] == -2) {
                    dfs(j, e[i], f[i], g[i]);
                }
            }
        }
    }

    public BigInteger count(int n) {
        BigInteger[] prev = new BigInteger[k];
        Arrays.fill(prev, BigInteger.ZERO);
        prev[s] = BigInteger.ONE;
        while (n-- > 0) {
            BigInteger[] next = new BigInteger[k];
            Arrays.fill(next, BigInteger.ZERO);
            for (int i = 0; i < k; ++i) {
                if (prev[i].signum() <= 0) {
                    continue;
                }
                for (int j = 0; j < z; ++j) {
                    if (e[j][i] < 0) {
                        continue;
                    }
                    next[e[j][i]] = next[e[j][i]].add(prev[i]);
                }
            }
            prev = next;
        }
        BigInteger ans = BigInteger.ZERO;
        for (int term : t) {
            ans = ans.add(prev[term]);
        }
        return ans;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int re = in.nextInt();
        for (int ri = 1; ri <= re; ++ri) {
            if (ri > 1) {
                System.out.println();
            }
            String z = in.next();
            int k = in.nextInt();
            int s = in.nextInt() - 1;
            int l = in.nextInt();
            int[] t = new int[l];
            for (int i = 0; i < l; ++i) {
                t[i] = in.nextInt() - 1;
            }
            int[][] f = new int[z.length()][k];
            for (int i = 0; i < k; ++i) {
                for (int j = 0; j < z.length(); ++j) {
                    f[j][i] = in.nextInt() - 1;
                }
            }
            boolean[][] g = new boolean[z.length()][k];
            for (int i = 0; i < k; ++i) {
                for (int j = 0; j < z.length(); ++j) {
                    g[j][i] = (in.nextInt() == 0);
                }
            }
            DFA dfa = new DFA(z.toCharArray(), k, s, t, f, g);
            int n = in.nextInt();
            System.out.println(dfa.count(n));
        }
    }
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1784603   2009-03-10 22:56:24     Accepted    2337    Java    0   4434    watashi@Zodiac

// 2012-09-07 01:19:23 | Accepted | 2337 | Java | 2000 | 13214 | watashi | Source
