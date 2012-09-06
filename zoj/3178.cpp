#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 64;
const int MAXM = 1024;
const double EPS = 1e-8;
const double INF = 1e99;

struct Edge {
    int v;
    double c;
};

struct FlowNextwork {   // Dinic
    int m;
    Edge edge[MAXM * 2];

    int n, source, sink;
    int d[MAXN];
    vector<int> e[MAXN];

    void init(int n, int source, int sink) {
        this->n = n;
        this->source = source;
        this->sink = sink;
        for (int i = 0; i < n; ++i) {
            e[i].clear();
        }
        m = 0;
    }

    void addEdge(int a, int b, double c) {
        edge[m].v = b;
        edge[m].c = c;
        e[a].push_back(m);
        edge[m + 1].v = a;
        edge[m + 1].c = 0;
        e[b].push_back(m + 1);
        m += 2;
    }

    void _bfs() {
        static int q[MAXN];
        fill(d, d + n, -1);
        d[source] = 0;
        q[0] = source;
        for (int begin = 0, end = 1; begin < end; ++begin) {
            int front = q[begin];
            for (vector<int>::const_iterator it = e[front].begin(); it != e[front].end(); ++it) {
                if (edge[*it].c > /*EPS*/0 && d[edge[*it].v] == -1) {
                    d[edge[*it].v] = d[front] + 1;
                    q[end++] = edge[*it].v;
                }
            }
        }
    }

    void _augment() {
        static int done[MAXN];
        static int path[MAXN];
        static int todo[MAXN];
        static double flow[MAXN];
        fill(done, done + n, 0);
        int len = 0;
        path[0] = source;
        todo[0] = -1;
        flow[0] = INF;
        while (len >= 0) {
            int back = path[len];
            if (back == sink) {
                for (int i = 0; i < len; ++i) {
                    int id = e[path[i]][done[path[i]]];
                    edge[id].c -= flow[len];
                    edge[id ^ 1].c += flow[len];
                    flow[i] -= flow[len];   // !!
                }
                len = todo[len];
            } else {
                while (done[back] < e[back].size()) {
                    int id = e[back][done[back]];
                    if (d[edge[id].v] == d[back] + 1 && edge[id].c > /*EPS*/0) {
                        break;
                    } else {
                        ++done[back];
                    }
                }
                if (done[back] == e[back].size()) {
                    --len;
                    d[back] = -1;
                } else {
                    ++len;
                    int id = e[back][done[back]];
                    path[len] = edge[id].v;
                    if (edge[id].c < flow[len - 1] - EPS) {
                        todo[len] = len - 1;
                        flow[len] = edge[id].c;
                    } else {
                        todo[len] = todo[len - 1];
                        flow[len] = flow[len - 1];
                    }
                }
            }
        }
    }

    double solve() {
        while (true) {
            _bfs();
            if (d[sink] == -1) {
                break;
            } else {
                _augment();
            }
        }
        double ret = 0;
        // (BUG)
        for (vector<int>::const_iterator it = e[source].begin(); it != e[source].end(); ++it) {
            ret += edge[*it ^ 1].c;
        }
        return ret;
    }

    void undo() {
        for (int i = 0; i < m; i += 2) {
            edge[i].c += edge[i ^ 1].c;
            edge[i ^ 1].c = 0;
        }
    }

    void remove(int v) {
        for (vector<int>::const_iterator it = e[v].begin(); it != e[v].end(); ++it) {
            edge[*it].c = 0;
            edge[*it ^ 1].c = 0;
        }
    }
/*
    void show() {
        for (int i = 0; i < n; ++i) {
            printf("@%d:", i);
            for (vector<int>::const_iterator it = e[i].begin(); it != e[i].end(); ++it) {
                printf(" (%d,%le)", edge[*it].v, edge[*it].c);
            }
            printf("\n");
        }
    }
*/
};

#define B(i) (i)
#define F(i) (n + i)
#define S() (n + m)
#define T() (n + m + 1)

int main() {
    int re;
    FlowNextwork fn;
    int n, m, k, t;
    double a[MAXN], b, s;
    double l, r, mid;
    bool mark[MAXN], flag;
    vector<int> bf[MAXN];

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d%d", &n, &m);
        fn.init(n + m + 2, S(), T());
        s = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%lf", &a[i]);
            fn.addEdge(B(i), T(), 0);
            s += a[i];
            bf[i].clear();
        }
        for (int i = 0; i < m; ++i) {
            scanf("%lf", &b);
            fn.addEdge(S(), F(i), b);
        }
        fill(mark, mark + n, false);
        flag = true;
        for (int i = 0; i < m; ++i) {
            scanf("%d", &k);
            if (k == 0) {
                flag = false;
            }
            while (k-- > 0) {
                scanf("%d", &t);
                --t;
                fn.addEdge(F(i), B(t), INF);
                mark[t] = true;
                bf[t].push_back(i);
            }
        }
        if (find(mark, mark + n, false) != mark + n) {
            flag = false;
        }
        if (!flag) {
            puts("Impossible");
            continue;
        }

        fill(mark, mark + n, false);
        while (s > EPS) {
            l = 0;
            r = 1e7;
            for (int k = 0; k < 100; ++k) {
                fn.undo();
                mid = (l + r) / 2;
                for (int i = 0; i < n; ++i) {
                    if (!mark[i]) {
                        fn.edge[i << 1].c = a[i] * mid; // ~
                    }
                }
                // fn.show();
                // printf("%lf <=> %lf\n", mid, fn.solve());
                // fn.show();
                if (fn.solve() < s * mid - EPS) {
                    r = mid;
                } else {
                    l = mid;
                }
            }
            mid = (l + r) / 2;
            // printf("%lf %lf %lf\n", mid, fn.solve(), s);
            for (int i = 0; i < n; ++i) {
                if (!mark[i] && fn.d[B(i)] == -1) { // ~
                    mark[i] = true;
                    fn.remove(B(i));    // ~
                    s -= a[i];
                    a[i] = mid;
                    for (vector<int>::const_iterator it = bf[i].begin(); it != bf[i].end(); ++it) {
                        fn.remove(F(*it));
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            printf("%.6lf%c", a[i], (i == n - 1) ? '\n' : ' ');
        }
    }
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1804578   2009-03-26 02:21:47     Accepted    3178    C++     80  180     watashi@Zodiac

/*
 * BUG
Submit Time     Language    Run Time(ms)    Run Memory(KB)      User Name
2009-03-26 02:23:18     C++     50  180     watashi@Zodiac
2009-03-26 02:22:47     C++     70  180     watashi@Zodiac
2009-03-26 02:22:57     C++     70  180     watashi@Zodiac
2009-03-26 02:21:47     C++     80  180     watashi@Zodiac
2009-03-22 18:19:52     C++     190     252     11
2009-03-22 21:45:01     C++     410     244     hhanger@Zodiac
*/

// 2012-09-07 02:06:25 | Accepted | 3178 | C++ | 90 | 180 | watashi | Source
