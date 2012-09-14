#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 444;
const int MAXM = 4444;
const int INF = 1000000007;

inline int RE(int i) { return i ^ 1; }

struct Edge {
    int v;
    int c;
};

struct FlowNetwork {
    int n, m, source, sink;
    vector<int> e[MAXN];
    Edge edge[MAXM * 2];

    void init(int n, int source, int sink) {
        this->n = n;
        this->m = 0;
        this->source = source;
        this->sink = sink;
        for (int i = 0; i < n; ++i) {
            e[i].clear();
        }
    }

    void addEdge(int a, int b, int c) {
        edge[m].v = b;
        edge[m].c = c;
        e[a].push_back(m);
        edge[m + 1].v = a;
        edge[m + 1].c = c;
        e[b].push_back(m + 1);
        m += 2;
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
        int flow = INF;
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
} fn, _fn;

#define ID(i, j) ((i) * c + (j))
#define S() (r * c)
#define T() (r * c + 1)

int main() {
    int n, r, c, f, ans;
    int x[10], y[10], z[10];

    while (scanf("%d%d", &r, &c) != EOF) {
        _fn.init(r * c + 2, S(), T());
        for (int i = 0; i <= r; ++i) {
            for (int j = 0; j < c; ++j) {
                scanf("%d", &f);
                _fn.addEdge(i == 0 ? T() : ID(i - 1, j), i == r ? T() : ID(i, j), f);
            }
            if (i == r) {
                break;
            }
            for (int j = 0; j <= c; ++j) {
                scanf("%d", &f);
                _fn.addEdge(j == 0 ? T() : ID(i, j - 1), j == c ? T() : ID(i, j), f);
            }
        }

        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d", &z[i], &x[i], &y[i]);
            if (z[i] == 0) {
                swap(x[i], x[0]);
                swap(y[i], y[0]);
                swap(z[i], z[0]);
            } else if (z[i] < 0) {
                _fn.addEdge(ID(x[i], y[i]), T(), INF);
                --i;
                --n;
            }
        }

        ans = INF;
        for (int i = 1; i < (1 << n); i += 2) {
            fn = _fn;
            f = 0;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    f -= z[j];
                    fn.addEdge(S(), ID(x[j], y[j]), INF);
                }
            }
            f += fn.sap();
            ans = min(ans, f);
        }
        printf("%d\n", ans);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//711   2011-02-09 22:22:22     Accepted    I   C++     40  344     watashi@ArcOfDream  Source

// 2012-09-07 15:59:51 | Accepted | 3475 | C++ | 50 | 344 | watashi | Source
