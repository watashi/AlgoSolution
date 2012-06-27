#include <queue>
#include <deque>
#include <limits>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 256;
const int MAXM = 1024;

struct Edge {
    short c, v;
    int w, b;
    Edge() { }
    Edge(int c, int v, int w, int b) : c(c), v(v), w(w), b(b) { }
};

struct NegativeCostCircuitExistsException {
};

struct MinCostMaxFlow {
    int n, m, source, sink;
    vector<Edge> e[MAXN];

    void init(int n, int source, int sink) {
        this->n = n;
        this->m = 0;
        this->source = source;
        this->sink = sink;
        for (int i = 0; i < n; ++i) {
            e[i].clear();
        }
    }

    void addEdge(int a, int b, int c, int w) {
        e[a].push_back(Edge(c, b, w, e[b].size()));
        e[b].push_back(Edge(0, a, -w, e[a].size() - 1));
    }

    bool mark[MAXN];
    int minw[MAXN];
    Edge* pre[MAXN];

    void _spfa() {
        deque<int> q;

        fill(mark, mark + n, false);
        fill(minw, minw + n, numeric_limits<int>::max());
        fill(pre, pre + n, (Edge*)NULL);
        mark[source] = true;
        minw[source] = 0;
        q.push_back(source);
        while (!q.empty()) {
            int cur = q.front();
            mark[cur] = false;
            q.pop_front();
            for (vector<Edge>::iterator it = e[cur].begin(); it != e[cur].end(); ++it) {
                if (it->c == 0) {
                    continue;
                }
                int v = it->v;
                int w = minw[cur] + it->w;
                if (minw[v] > w) {
                    minw[v] = w;
                    pre[v] = &*it;
                    if (!mark[v]) {
                        mark[v] = true;
                        q.push_back(v);
                    }
                }
            }
        }
    }

    pair<int, int> gao() {
        int sumc = 0, sumw = 0;

        while (true) {
            _spfa();
            if (minw[sink] == numeric_limits<int>::max()) {
                break;
            } else {
                int cur = sink;
                while (cur != source) {
                    Edge* x = pre[cur];
                    --x->c;
                    Edge* y = &e[x->v][x->b];
                    ++y->c;
                    cur = y->v;
                }
                ++sumc;
                sumw += minw[sink];
            }
        }

        return make_pair(sumc, sumw);
    }
} mcmf, mcmf2;

int d[MAXN][MAXN], c[MAXN];

int main() {
    int re, n, m, a, b;
    pair<int, int> p;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d%d", &n, &m);
        mcmf.init(n + 2, 0, n + 1);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                d[i][j] = m;
            }
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &a, &b);
            mcmf.addEdge(a, b, 1, 1);
            mcmf.addEdge(b, a, 1, 1);
            d[a][b] = 1;
        }
        mcmf2 = mcmf;

        for (int k = 1; k <= n; ++k) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }

        for (int i = 1; i <= n; ++i) {
            c[i] = m;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                mcmf = mcmf2;
                mcmf.addEdge(0, i, 2, 0);
                mcmf.addEdge(j, n + 1, 2, 0);
                p = mcmf.gao();
                if (p.first == 2) {
                    c[i] = min(c[i], p.second);
                    c[j] = min(c[j], p.second);
                }
            }
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                mcmf = mcmf2;
                mcmf.addEdge(0, i, 3, 0);
                mcmf.addEdge(j, n + 1, 3, 0);
                p = mcmf.gao();
                if (p.first == 3 && p.second <= m) {
                    m = min(m, p.second - 1);
                }
            }
        }

        printf("%d\n", m);
    }

    return 0;
}
