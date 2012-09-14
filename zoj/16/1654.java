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
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int re = in.nextInt();
        for (int ri = 1; ri <= re; ++ri) {
            int m = in.nextInt();
            int n = in.nextInt();
            String[] map = new String[m];
            int[][] id = new int[m][n];
            for (int i = 0; i < m; ++i) {
                map[i] = in.next();
                Arrays.fill(id[i], -1);
            }
            int r = 0;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (map[i].charAt(j) == 'o') {
                        int k = j;
                        do {
                            if (map[i].charAt(k) == 'o') {
                                id[i][k] = r;
                            }
                            ++k;
                        } while (k < n && map[i].charAt(k) != '#');
                        ++r;
                        j = k;
                    }
                }
            }
            ArrayList<ArrayList<Integer> > e = new ArrayList<ArrayList<Integer> >(r);
            for (int k = 0; k < r; ++k) {
                e.add(new ArrayList<Integer>());
            }
            int c = 0;
            for (int j = 0; j < n; ++j) {
                for (int i = 0; i < m; ++i) {
                    if (map[i].charAt(j) == 'o') {
                        int k = i;
                        do {
                            if (map[k].charAt(j) == 'o') {
                                e.get(id[k][j]).add(c);
                            }
                            ++k;
                        } while (k < m && map[k].charAt(j) != '#');
                        ++c;
                        i = k;
                    }
                }
            }
            System.out.println("Case :" + ri);
            System.out.println(Matching.hungary(r, c, e, new int[r], new int[c]));
        }
    }
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1802490   2009-03-24 20:42:53     Accepted    1654    Java    0   948     watashi@Zodiac

// 2012-09-07 00:57:11 | Accepted | 1654 | Java | 150 | 1143 | watashi | Source
