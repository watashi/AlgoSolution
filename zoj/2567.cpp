#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 2 * 303 + 2;
const int MAXM = 303 * 303 + 303;
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

#define N() (m + n + 2) // number
#define S() (m + n) // source
#define T() (m + n + 1) // sink
#define A(i) (i)    // input layer
#define B(j) (m + j)    // output layer

int main() {
    int m, n, p, a, b;
    ExtFlowNetwork efn;

    while (scanf("%d%d%d", &m, &n, &p) != EOF) {
        efn.init(N(), S(), T());
        for (int k = 0; k < p; ++k) {
            scanf("%d%d", &a, &b);
            --a;
            --b;
            efn.addEdge(A(a), B(b), 0, 1);
        }
        for (int i = 0; i < m; ++i) {
            efn.addEdge(S(), A(i), 2, n);
        }
        for (int j = 0; j < n; ++j) {
            efn.addEdge(B(j), T(), 2, m);
        }
        try {
            efn.minFlow();
            vector<int> ans;
            for (int i = 0; i < p; ++i) {
                if (efn.edge[i << 1].c == 0) {
                    ans.push_back(i + 1);
                }
            }
            printf("%d\n", (int)ans.size());
            for (size_t i = 0; i < ans.size(); ++i) {
                printf("%d%c", ans[i], (i == ans.size() - 1) ? '\n' : ' ');
            }
        } catch (NoSuchFlowException e) {
            puts("-1");
        }
    }

    return 0;
}

//  ExtFlowNetwork::sap()
//      ZOJ1364
//      ZOJ1882
//  ExtFlowNetwork::feasibleFlow()
//      ZOJ2314
//  ExtFlowNetwork::minFlow()
//      ZOJ2567

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1817452   2009-04-03 20:42:49     Accepted    2567    C++     60  1496    watashi@Zodiac

/*
Submit Time     Language    Run Time(ms)    Run Memory(KB)      User Name
2009-04-03 20:42:49     C++     60  1496    watashi@Zodiac
2008-11-03 16:09:48     C++     70  3536    呆滞的慢板
2008-11-03 16:02:30     C++     70  4120    Rainco_test
2008-11-03 16:03:38     C++     70  4120    Rainco
2008-12-06 16:12:24     C++     70  4384    rendezvous_hello_world
2008-12-29 14:55:38     C++     80  2752    o(∩_∩)o...
2009-02-16 16:06:52     FPC     80  5724    woo_50
2009-02-14 22:40:31     FPC     80  10668   321
2008-12-29 14:44:09     C++     90  4880    Sweety_xt
2009-02-16 15:57:35     FPC     90  5724    woo_50
2008-10-31 22:12:15     C++     90  8004    skoier
2008-11-26 15:48:28     FPC     100     2964    ddjdhx
*/

// 2012-09-07 15:40:46 | Accepted | 2567 | C++ | 60 | 1500 | watashi | Source
