#include <map>
#include <queue>
#include <cstdio>
#include <vector>
#include <string>
#include <cassert>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 10086;
const int MAXM = 55555;

inline int RE(int i) { return i ^ 1; }

struct Edge {
    int v;
    int c;
};

struct ExtFlowNetwork {
    int n, m, source, sink;
    vector<int> e[MAXN];
    Edge edge[MAXM * 2];

    void init(int n, int source, int sink) {    // if no source & sink, then source = sink = -1
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
        edge[m + 1].c = 0;
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
};

map<string, int> mp;

int getId(const string& str) {
    int ret;
    if (mp.count(str) > 0) {
        ret = mp[str];
    } else {
        ret = mp.size();
        mp[str] = ret;
    }
    return ret;
}

int main() {
    int n, m, p, a, b;
    int d[55], t[55][55];
    char buf[1024];
    ExtFlowNetwork efn;

    while (scanf("%d%d", &n, &m) != EOF) {
        fill(d, d + n, 0);
        fill(t[0], t[n], 0);
        mp.clear();
        (void)getId("DD");  // ~
        for (int i = 0; i < m; ++i) {
            scanf("%s", buf);
            a = getId(buf);
            scanf("%s", buf);
            b = getId(buf);
            scanf("%s", buf);
            assert(buf[0] == 'w' || buf[0] == 'l'); // ~
            if (buf[0] == 'w') {
                ++d[a];
            } else {
                ++d[b];
            }
        }
        scanf("%d", &p);
        vector<pair<int, int> > v;
        for (int i = 0; i < p; ++i) {
            scanf("%s", buf);
            a = getId(buf);
            scanf("%s", buf);
            b = getId(buf);
            if (a > b) {
                swap(a, b);
            }
            ++d[a];
            ++t[a][b];
        }
        if (d[0] == 0) {
            puts(n == 1 ? "Yes" : "No");
            continue;
        }
        efn.init(n + 1, 0, n);
        m = 0;
        for (int i = 1; i < n; ++i) {
            m += d[i];
            efn.addEdge(0, i, d[i]);
            efn.addEdge(i, n, d[0] - 1);
            for (int j = i + 1; j < n; ++j) {
                if (t[i][j] > 0) {
                    efn.addEdge(i, j, t[i][j]);
                }
            }
        }
        puts(efn.sap() == m ? "Yes" : "No");
    }

    return 0;
}

// TODO: add case `2 0 0`

// 2012-09-07 15:47:26 | Accepted | 3348 | C++ | 160 | 180 | watashi | Source
