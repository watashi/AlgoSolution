#include <queue>
#include <deque>
#include <limits>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 2048;
const int MAXM = 1024 * 1024 / 2;

struct Edge {
    short c, v;
    int w, b;
    Edge() { }
    Edge(int c, int v, int w, int b) : c(c), v(v), w(w), b(b) { }
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
            for (Edge& i: e[cur]) {
                if (i.c == 0) {
                    continue;
                }
                int v = i.v;
                int w = minw[cur] + i.w;
                if (minw[v] > w) {
                    minw[v] = w;
                    pre[v] = &i;
                    if (!mark[v]) {
                        mark[v] = true;
                        q.push_back(v);
                    }
                }
            }
        }
    }

    bool gao() {
        _spfa();
        if (minw[sink] == numeric_limits<int>::max()) {
            return false;
        } else {
            int cur = sink;
            while (cur != source) {
                Edge* x = pre[cur];
                --x->c;
                Edge* y = &e[x->v][x->b];
                ++y->c;
                cur = y->v;
            }
        }
        return true;
    }
};

MinCostMaxFlow mcmf;

inline int IN(int i) { return i << 1; }
inline int OUT(int i) { return IN(i) ^ 1; }

int s[MAXN], t[MAXN], c[MAXN];

int main() {
    int n, m;

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", &s[i], &t[i], &c[i]);
        t[i] += s[i];
    }

    mcmf.init(OUT(n + 1), IN(n), IN(n + 1));
    mcmf.addEdge(IN(n), OUT(n), 1, 0);
    for (int i = 0; i < n; ++i) {
        mcmf.addEdge(OUT(n), IN(i), 1, 0);
        mcmf.addEdge(IN(i), OUT(i), 1, -c[i]);
        mcmf.addEdge(OUT(i), IN(n + 1), 1, 0);
        for (int j = 0; j < n; ++j) {
            if (t[i] <= s[j]) {
                mcmf.addEdge(OUT(i), IN(j), 1, 0);
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        mcmf.e[IN(n)][0].c = 1;
        mcmf.e[OUT(n)][0].c = 0;
        if (!mcmf.gao()) {
            break;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (const Edge& e: mcmf.e[IN(i)]) {
            if (e.v != OUT(i)) {
                continue;
            }
            printf("%d%c", 1 - e.c, i == n - 1 ? '\n' : ' ');
        }
    }

    return 0;
}
