// TAG : Hungary
// TAG : Bipartite
// TAG : Minimum Path Cover

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
// TAG : LED MASK
    static int[] mask = new int[]{
        0x3f,   // 0
        0x06,   // 1
        0x5b,   // 2
        0x4f,   // 3
        0x66,   // 4
        0x6d,   // 5
        0x7d,   // 6
        0x07,   // 7
        0x7f,   // 8
        0x6f,   // 9
    };

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNextInt()) {
            int n = in.nextInt();
            int[] a = new int[n];
            ArrayList<ArrayList<Integer> > e = new ArrayList<ArrayList<Integer> >(n);
            for (int i = 0; i < n; ++i) {
                a[i] = in.nextInt();
                e.add(new ArrayList<Integer>());
                for (int j = 0; j < i; ++j) {
                    if (a[i] != a[j] && (mask[a[i]] & mask[a[j]]) == mask[a[i]]) {
                        e.get(j).add(i);
                    }
                }
            }
            System.out.println(n - Matching.hungary(n, n, e, new int[n], new int[n]));
        }
    }
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1802292   2009-03-24 19:24:27     Accepted    2521    Java    0   2784    watashi@Zodiac

// 2012-09-07 01:26:33 | Accepted | 2521 | Java | 340 | 9589 | watashi | Source
