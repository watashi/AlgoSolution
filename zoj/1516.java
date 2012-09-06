// ¶þ·ÖÍ¼Æ¥Åä

import java.io.*;
import java.util.*;

public class Main {
    private static int ch = 0;

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

    private static int hungary(int na, int nb, ArrayList<ArrayList<Integer> > e,
            int[] ma, int[] mb) {
        int p, t, ret = 0;
        int[] q = new int[na], pre = new int[na];

        if (ma == null) {
            ma = new int[na];
        }
        Arrays.fill(ma, -1);
        if (mb == null) {
            mb = new int[nb];
        }
        Arrays.fill(mb, -1);
        for (int i = 0; i < na; ++i) {
            p = t = 0;
            q[t++] = i;
            Arrays.fill(pre, -1);
BFS:
            while (p < t) {
                for (int v : e.get(q[p])) {
                    if (mb[v] == -1) {
                        int u = q[p], w;
                        do {
                            w = ma[u];
                            ma[u] = v;
                            mb[v] = u;
                            u = pre[u];
                            v = w;
                        } while (u != -1);
                        ++ret;
                        break BFS;
                    } else if (pre[mb[v]] == -1) {
                        q[t++] = mb[v];
                        pre[mb[v]] = q[p];
                    }
                }
                ++p;
            }
        }

        return ret;
    }

    private static int[] dx = new int[]{1, 0, -1, 0};
    private static int[] dy = new int[]{0, 1, 0, -1};

    public static void main(String[] args) throws IOException {
        while (true) {
            int n = nextInt();
            int m = nextInt();
            if (n == 0 && m == 0) {
                break;
            }
            int k = nextInt();
            int[][] id = new int[n][m];
            for (int i = 0; i < k; ++i) {
                int x = nextInt() - 1;
                int y = nextInt() - 1;
                id[x][y] = -1;
            }
            int na = 0, nb = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (id[i][j] != -1) {
                        if ((i + j) % 2 == 0) {
                            id[i][j] = na++;
                        } else {
                            id[i][j] = nb++;
                        }
                    }
                }
            }
            ArrayList<ArrayList<Integer> > e = new ArrayList<ArrayList<Integer> >(na);
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (id[i][j] != -1 && (i + j) % 2 == 0) {
                        ArrayList<Integer> ai = new ArrayList<Integer>();
                        for (int d = 0; d < 4; ++d) {
                            int x = i + dx[d];
                            int y = j + dy[d];
                            try {
                                if (id[x][y] != -1) {
                                    ai.add(id[x][y]);
                                }
                            } catch (ArrayIndexOutOfBoundsException dump) {
                            }
                        }
                        e.add(ai);
                    }
                }
            }
            System.out.println(hungary(na, nb, e, null, null));
        }
    }
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1755483   2009-02-04 01:25:36     Accepted    1516    Java    0   241     watashi@Zodiac

// 2012-09-07 00:52:05 | Accepted | 1516 | Java | 80 | 422 | watashi | Source
