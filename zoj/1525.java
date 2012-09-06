import java.io.*;
import java.util.*;

// 最小路径覆盖
// 二分图最大匹配

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

    public static void main(String[] args) throws IOException {
        // Scanner in = new Scanner(System.in); // TLE
        int re = nextInt();

        for (int ri = 1; ri <= re; ++ri) {
            int n = nextInt();
            ArrayList<ArrayList<Integer> > e = new ArrayList<ArrayList<Integer> >(n);
            for (int i = 0; i < n; ++i) {
                e.add(new ArrayList<Integer>());
            }
            int m = nextInt();
            for (int i = 0; i < m; ++i) {
                int a = nextInt() - 1;
                int b = nextInt() - 1;
                e.get(a).add(b);
            }
            System.out.println(n - hungary(n, n, e, null, null));
        }
    }
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1755257   2009-02-03 21:43:26     Accepted    1525    Java    0   1154    watashi@Zodiac

/*
##BUG##
Submit Time     Language    Run Time(ms)    Run Memory(KB)      User Name
2009-02-03 21:43:26     Java    0   1154    watashi@Zodiac
2008-11-27 12:52:27     C   10  160     hglem
2009-01-19 10:32:27     C++     10  180     code-breaker
2008-10-23 13:50:58     C++     10  192     Fandywang
2008-10-23 14:36:20     C++     10  192     manniuniu
2008-10-23 14:37:18     C++     10  192     manniuniu
2008-10-23 14:39:29     C++     10  192     manniuniu
2008-10-23 14:40:41     C++     10  192     manniuniu
2008-10-23 14:10:26     C++     10  196     manniuniu
2008-12-26 16:32:34     C++     10  196     xgy
2009-01-02 18:54:48     C++     10  216     hglem
2009-01-13 10:16:43     FPC     20  44  Myth5
*/

// 2012-09-07 00:52:30 | Accepted | 1525 | Java | 100 | 1268 | watashi | Source
