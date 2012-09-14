// TAG : Hungary
// TAG : Bipartite

import java.util.*;

class Matching {
    public static int hungary(int nu, int nv, ArrayList<ArrayList<Integer> > e, int[] mu, int[] mv) {
        if (mu == null) {
            mu = new int[nu];
        }
        Arrays.fill(mu, -1);
        if (mv == null) {
            mv = new int[nv];
        }
        Arrays.fill(mv, -1);
        int[] q = new int[nu];
        int[] p = new int[nv];
        int ret = 0;
        for (int i = 0; i < nu; ++i) {
            Arrays.fill(p, -1);
            q[0] = i;
            int t = 1;
BFS:
            for (int s = 0; s < t; ++s) {
                int k = q[s];
                for (int j : e.get(k)) {
                    if (p[j] == -1) {
                        if (mv[j] == -1) {
                            int x = k, y = j, z;
                            while(true) {
                                z = mu[x];
                                mu[x] = y;
                                mv[y] = x;
                                if (z == -1) {
                                    break;
                                } else {
                                    x = p[z];
                                    y = z;
                                }
                            }
                            ++ret;
                            break BFS;
                        } else {
                            q[t++] = mv[j];
                            p[j] = k;
                        }
                    }
                }
            }
        }
        return ret;
    }
}

public class Main {
    static int ch;

    public static int nextInt() {
        int ret = 0;
        try {
            while (!Character.isDigit(ch = System.in.read())) {
                continue;
            }
            do {
                ret *= 10;
                ret += Character.digit(ch, 10);
            } while (Character.isDigit(ch = System.in.read()));
        } catch (java.io.IOException e) {
        }
        return ret;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int re = nextInt();
        for (int ri = 1; ri <= re; ++ri) {
            if (ri > 1) {
                System.out.println();
            }
            int n = nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; ++i) {
                a[i] = nextInt();
                a[i] = a[i] * 1024 + i;
            }
            Arrays.sort(a);
            int[] b = new int[n];
            for (int i = 0; i < n; ++i) {
                b[a[n - 1 - i] & 1023] = i;
            }
            ArrayList<ArrayList<Integer> > e = new ArrayList<ArrayList<Integer> >(n);
            for (int i = 0; i < n; ++i) {
                e.add(new ArrayList<Integer>());
            }
            for (int i = 0; i < n; ++i) {
                int k = nextInt();
                ArrayList<Integer> ee = new ArrayList<Integer>(k);
                for (int j = 0; j < k; ++j) {
                    ee.add(nextInt() - 1);
                }
                e.set(b[i], ee);
            }
            int[] m = new int[n];
            System.err.println(Matching.hungary(n, n, e, m, new int[n]));
            for (int i = 0; i < n; ++i) {
                if (i > 0) {
                    System.out.print(' ');
                }
                System.out.print(m[b[i]] + 1);
            }
            System.out.println();
        }
    }
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1791348   2009-03-16 23:10:22     Accepted    2362    Java    0   1812    watashi@Zodiac

// 2012-09-07 15:39:04 | Accepted | 2362 | Java | 350 | 6763 | watashi | Source
