/*
import java.io.*;
import java.util.*;

// Topological Sort

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

    private static int par;

    private static int gao(ArrayList<ArrayList<Integer> > e,
            int[][] q, int[] t, int[] c, int cur) {
        // You may assume that there are no circular dependences.
        int tmp, ans = 0;
        int[] p = new int[]{0, 0};

        while (p[0] < t[0] || p[1] < t[1]) {
            ++ans;
            while (p[cur] < t[cur]) {
                for (int v : e.get(q[cur][p[cur]])) {
                    --c[v];
                    if (c[v] == 0) {
                        tmp = (v < par) ? 0 : 1;
                        q[tmp][t[tmp]++] = v;
                    }
                }
                ++p[cur];
            }
            cur = 1 - cur;
        }

        return ans;
    }

    public static void main(String[] args) throws IOException {
        while (true) {
            int n = nextInt();
            int m = nextInt();
            int d = nextInt();
            if (n == 0 && m == 0 && d == 0) {
                return;
            } else {
                par = n;
            }
            ArrayList<ArrayList<Integer> > e = new ArrayList<ArrayList<Integer> >(n + m);
            int[] c = new int[n + m];
            for (int i = 0; i < n + m; ++i) {
                e.add(new ArrayList<Integer>());
                c[i] = 0;
            }
            for (int i = 0; i < d; ++i) {
                int a = nextInt() - 1;
                int b = nextInt() - 1;
                e.get(b).add(a);
                ++c[a];
            }
            int[][] q = new int[2][];
            int[] t = new int[2];
            q[0] = new int[n];
            t[0] = 0;
            for (int i = 0; i < n; ++i) {
                if (c[i] == 0) {
                    q[0][t[0]++] = i;
                }
            }
            q[1] = new int[m];
            t[1] = 0;
            for (int i = 0; i < m; ++i) {
                if (c[n + i] == 0) {
                    q[1][t[1]++] = n + i;
                }
            }
            System.out.println(Math.min(gao(e, q, t.clone(), c.clone(), 0),
                        gao(e, q, t.clone(), c.clone(), 1)) + 1);
        }
        // main(args);
    }
}
*/

#include <queue>
#include <cctype>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

inline int nextInt() {
    static int ch = 0;
    int ret = 0;

    while (!isdigit(ch = getchar())) {
        continue;
    }
    do {
        ret *= 10;
        ret += ch - '0';
    } while (isdigit(ch = getchar()));

    return ret;
}

const int MAXN = 100001;

int n, m, d, a, b;
vector<int> e[MAXN];
int c[MAXN];

int gao(int cur) {
    // You may assume that there are no circular dependences.
    static int c[MAXN];
    int ans = 0;
    queue<int> q[2];

    copy(::c, ::c + n + m, c);
    for (int i = 0; i < n; ++i) {
        if (c[i] == 0) {
            q[0].push(i);
        }
    }
    for (int i = 0; i < m; ++i) {
        if (c[n + i] == 0) {
            q[1].push(n + i);
        }
    }
    while (!q[0].empty() || !q[1].empty()) {
        ++ans;
        while (!q[cur].empty()) {
            for (int i = 0; i < e[q[cur].front()].size(); ++i) {
                int v = e[q[cur].front()][i];
                --c[v];
                if (c[v] == 0) {
                    q[v >= n].push(v);
                }
            }
            q[cur].pop();
        }
        cur = 1 - cur;
    }

    return ans + 1;
}

int main() {
    while (true) {
        n = nextInt();
        m = nextInt();
        d = nextInt();
        if (n == 0 && m == 0 && d == 0) {
            break;
        }
        for (int i = 0; i < n + m; ++i) {
            e[i].clear();
            c[i] = 0;
        }
        for (int i = 0; i < d; ++i) {
            a = nextInt() - 1;
            b = nextInt() - 1;
            e[b].push_back(a);
            ++c[a];
        }
        printf("%d\n", min(gao(0), gao(1)));
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1754277   2009-02-02 22:00:47     Accepted    2236    C++     100     3148    watashi@Zodiac
//

// 2012-09-07 01:16:38 | Accepted | 2236 | C++ | 100 | 3148 | watashi | Source
