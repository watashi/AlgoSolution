#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 512;
const int MAXM = 12800;
const int INF = 1000000007;

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

    int diff[MAXN];      //*

    void init(int n, int source, int sink) {   // if no source & sink, then source = sink = -1
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
    int c[MAXN];      //*
    int d[MAXN];      //*
    int done[MAXN];      //*
    int path[MAXN];      //*
    int len;         //*

    void _bfs() {
        queue<int> q;
        fill(c, c + n, 0);
        fill(d, d + n, n);   // n->inf
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
                done[v] = i;   // ~
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
        while (d[source] != n/* && len >= 0*/) {   // n->inf
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
                        break;   // return;
                    } else {
                        _retreat(back);
                        if (back != source) {   // !!
                            --len;   // pop
                        }
                    }
                } else {
                    path[++len] = edge[e[back][done[back]]].v;   // push
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
            } else/* if (diff[i] <= 0)*/ {   // an edge is added even if diff[i] == 0 for [@1]
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
            e[i].pop_back();   // assert(...) :[@1]
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

    int flow() {
        int ret = 0;
        return ret;
    }
} efn;

int a[MAXM], b[MAXM], c[MAXM];

int gao(int n, int m, int s, int t, int lo, int up) {
    int ret = 0;
    efn.init(n, s, t);
    for (int i = 0; i < m; ++i) {
        if (lo > c[i]) {
            throw NoSuchFlowException();
        }
        efn.addEdge(a[i], b[i], lo, min(c[i], up));
        if (a[i] == s) {
            ret += lo;
        }
        if (b[i] == s) {
            ret -= lo;
        }
    }
    for (vector<int>::const_iterator i = efn.e[s].begin(); i != efn.e[s].end(); ++i) {
        ret -= efn.edge[RE(*i)].c;
    }
    efn.maxFlow();
    for (vector<int>::const_iterator i = efn.e[s].begin(); i != efn.e[s].end(); ++i) {
        ret += efn.edge[RE(*i)].c;
    }
    return ret;
}

int main() {
    int re, n, m, s, t, p, q, l, r;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d%d%d%d%d", &n, &m, &s, &t, &p);
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &a[i], &b[i], &c[i]);
        }
        q = gao(n, m, s, t, 0, INF);

        l = 0;
        r = q;
        while (l < r) {
            if (gao(n, m, s, t, 0, (l + r) / 2) != q) {
                l = (l + r) / 2 + 1;
            } else {
                r = (l + r) / 2;
            }
        }
        printf("%lld ", 1LL * r * p);

        l = 0;
        r = q + 1;
        while (l < r) {
            try {
                if (gao(n, m, s, t, (l + r) / 2, INF) == q) {
                    l = (l + r) / 2 + 1;
                } else {
                    r = (l + r) / 2;
                }
            } catch (...) {
                r = (l + r) / 2;
            }
        }
        printf("%lld\n", 1LL * (r - 1) * p);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//2498394   2011-04-16 23:42:52     Accepted    3496    C++     240     676     watashi@ArcOfDream  Source

// 2012-09-07 16:02:05 | Accepted | 3496 | C++ | 250 | 676 | watashi | Source
