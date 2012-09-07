#include <queue>
#include <cstdio>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

const int MAXN = 365 + 1000 + 10;
const int MAXM = 100000;
inline int RE(int i) { return i ^ 1; }

struct Edge {
    int v;
    int c;
};

struct NoSuchFlowException {
};

struct ExtFlowNetwork {
    int n, m, source, sink;
    vector<int> e[MAXN];
    Edge edge[MAXM * 2];

    int diff[MAXN];     //*

    void init(int n, int source, int sink) {    // if no source & sink, then source = sink = -1
        this->n = n;
        this->m = 0;
        this->source = source;
        this->sink = sink;
        for (int i = 0; i < n; ++i) {
            e[i].clear();
        }
        fill(diff, diff + n, 0);
    }

    void _addEdge(int a, int b, int c) {
        edge[m].v = b;
        edge[m].c = c;
        e[a].push_back(m);
        edge[m + 1].v = a;
        edge[m + 1].c = 0;
        e[b].push_back(m + 1);
        m += 2;
    }

    void addEdge(int a, int b, int l, int u) {
        diff[a] += l;
        diff[b] -= l;
        _addEdge(a, b, u - l);
    }

    // shortest augmenting path
    int c[MAXN];        //*
    int d[MAXN];        //*
    int done[MAXN];     //*
    int path[MAXN];     //*
    int len;            //*

    void _bfs() {
        queue<int> q;
        fill(c, c + n, 0);
        fill(d, d + n, n);  // n->inf
        d[sink] = 0;
        q.push(sink);
        while (!q.empty()) {
            int cur = q.front();
            ++c[d[cur]];
            for (size_t i = 0; i < e[cur].size(); ++i) {
                int id = e[cur][i];
                if (d[edge[id].v] == n && edge[RE(id)].c > 0) {
                    d[edge[id].v] = d[cur] + 1;
                    q.push(edge[id].v);
                }
            }
            q.pop();
        }
    }

    void _retreat(int v) {
        --c[d[v]];
        d[v] = n;   // n->inf
        for (size_t i = 0; i < e[v].size(); ++i) {
            Edge &arc = edge[e[v][i]];
            if (d[v] > d[arc.v] + 1 && arc.c > 0) {
                d[v] = d[arc.v] + 1;
                done[v] = i;    // ~
            }
        }
        ++c[d[v]];
    }

    int _augment() {
        int todo = -1;
        int flow = 0x7fffff;
        for (int i = 0; i < len; ++i) {
            Edge &arc = edge[e[path[i]][done[path[i]]]];
            if (arc.c < flow) {
                flow = arc.c;
                todo = i;
            }
        }
        for (int i = 0; i < len; ++i) {
            int id = e[path[i]][done[path[i]]];
            edge[id].c -= flow;
            edge[RE(id)].c += flow;
        }
        len = todo;
        return flow;
    }

    int sap() {
        int flow = 0;
        _bfs();
        fill(done, done + n, 0);
        len = 0;
        path[0] = source;
        while (d[source] != n/* && len >= 0*/) {    // n->inf
            int back = path[len];
            if (back == sink) {
                flow += _augment();
            } else {
                while (done[back] < (int)e[back].size()) {
                    Edge &arc = edge[e[back][done[back]]];
                    if (d[arc.v] == d[back] - 1 && arc.c > 0) {
                        break;
                    } else {
                        ++done[back];
                    }
                }
                if (done[back] == (int)e[back].size()) {
                    if (c[d[back]] == 1) {
                        break;  // return;
                    } else {
                        _retreat(back);
                        if (back != source) {   // !!
                            --len;  // pop
                        }
                    }
                } else {
                    path[++len] = edge[e[back][done[back]]].v;  // push
                }
            }
        }
        return flow;
    }
    // end of sap

    void feasibleFlow() {   // throws NoSuchFlowException
        int N = n + 2;
        int M = m;
        int SOURCE = n;
        int SINK = n + 1;
        int flow = 0;
        e[SOURCE].clear();
        e[SINK].clear();
        if (source != sink/* != -1*/) {
            _addEdge(sink, source, 0x7f7f7f7f);
        }
        for (int i = 0; i < n; ++i) {
            if (diff[i] > 0) {
                _addEdge(i, SINK, diff[i]);
                flow += diff[i];
            } else/* if (diff[i] <= 0)*/ {  // an edge is added even if diff[i] == 0 for [@1]
                _addEdge(SOURCE, i, -diff[i]);
            }
        }
        swap(n, N);
        swap(source, SOURCE);
        swap(sink, SINK);
        int aflow = sap();
        swap(n, N);
        swap(source, SOURCE);
        swap(sink, SINK);
        for (int i = 0; i < n; ++i) {
            e[i].pop_back();    // assert(...) :[@1]
        }
        if (source != sink/* != -1*/) {
            e[source].pop_back();
            e[sink].pop_back();
        }
        // e[SOURCE].clear();
        // e[SINK].clear();
        m = M;
        if (aflow != flow) {
            throw NoSuchFlowException();
        }
    }

    void minFlow() {
        feasibleFlow();
        swap(source, sink);
        sap();
        swap(source, sink);
    }

    void maxFlow() {
        feasibleFlow();
        sap();
    }
};

#define N() (n + m + 2) // number
#define S() (n + m)     // source
#define T() (n + m + 1) // sink
#define D(i) (i)        // input layer: day i
#define G(j) (n + j)    // output layer: girl j

const int INF = 1000000000;

int main() {
    int n, m, p, c, t, l;
    int d[365], g[1000], r[365 * 100];
    ExtFlowNetwork efn;

    while (scanf("%d%d", &n, &m) != EOF) {
        assert(1 <= n && n <= 365);             /// @param  n   1 <= n <= 365
        assert(1 <= m && m <= 1000);            /// @param  m1 <= m <= 1000
        efn.init(N(), S(), T());
        for (int i = 0; i < m; ++i) {
            assert(scanf("%d", &g[i]) == 1);
            assert(0 <= g[i] && g[i] <= 10000); /// @param  gG in range [0, 10000]
        }
        p = 0;
        for (int i = 0; i < n; ++i) {
            assert(scanf("%d%d", &c, &d[i]) == 2);
            assert(1 <= c && c <= 100);         /// @param  c   1 <= C <= 100
            assert(0 <= d[i] && d[i] <= 30000); /// @param  d0 <= D <= 30000
            for (int j = 0; j < c; ++j) {
                assert(scanf("%d%d%d", &t, &l, &r[p]) == 3);
                assert(0 <= t && t < m);        /// @param  0 <= T < m
                assert(0 <= l && l <= r[p] && r[p] <= 100); /// 0 <= T < m, 0 <= L <= R <= 100.
                efn.addEdge(D(i), G(t), l, r[p]);
                ++p;
            }
        }
        for (int i = 0; i < n; ++i) {
            efn.addEdge(S(), D(i), 0, d[i]);
        }
        for (int i = 0; i < m; ++i) {
            efn.addEdge(G(i), T(), g[i], INF);
        }
        try {
            efn.maxFlow();
            int ans = 0;
            for (int i = 0; i < p; ++i) {
                ans += r[i] - efn.edge[i << 1].c;
            }
            printf("%d\n", ans);
            //
            for (vector<int>::const_iterator it = efn.e[S()].begin(); it != efn.e[S()].end(); ++it) {
                ans -= efn.edge[*it ^ 1].c;
            }
            assert(ans == 0);
            //
            for (int i = 0; i < p; ++i) {
                printf("%d\n", r[i] - efn.edge[i << 1].c);
            }
        } catch (NoSuchFlowException e) {
            puts("-1");
        }
        puts("");   /// Output a blank line after each case.
    }

    return 0;
}

// vim: ft=cpp.doxygen sw=4 ts=4

// 2012-09-07 15:45:54 | Accepted | 3229 | C++ | 140 | 840 | watashi | Source
