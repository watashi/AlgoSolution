#include <utility> // auto fix CE
#include <queue>
#include <utility> // auto fix CE
#include <cstdio>
#include <utility> // auto fix CE
#include <vector>
#include <utility> // auto fix CE
#include <limits>
#include <utility> // auto fix CE
#include <algorithm>

using namespace std;

// [module] MinCostMaxFlow

const int MAXN = 300;
const int MAXM = 30000;

struct Edge {
        int v, c, w;
        Edge() { }
        Edge(int v, int c, int w) : v(v), c(c), w(w) { }
};

struct NegativeCostCircuitExistsException {
};

struct MinCostMaxFlow {
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

        void addEdge(int a, int b, int c, int w) {
                edge[m] = Edge(b, c, w);
                e[a].push_back(m++);
                edge[m] = Edge(a, 0, -w);
                e[b].push_back(m++);
        }

        bool mark[MAXN];
        int maxc[MAXN];
        int minw[MAXN];
        int pre[MAXN];
        int d[MAXN];

        // assert @return == true
        bool _spfa() {
                queue<int> q;

                fill(mark, mark + n, false);
                fill(maxc, maxc + n, 0);
                fill(minw, minw + n, numeric_limits<int>::max());
                fill(pre, pre + n, -1);
                fill(d, d + n, 0);
                mark[source] = true;
                maxc[source] = numeric_limits<int>::max();
                minw[source] = 0;
                // pre[source] = source;
                q.push(source);
                while (!q.empty()) {
                        int cur = q.front();
//                      fprintf(stderr, "%d %d %d\n", cur, maxc[cur], minw[cur]);
                        mark[cur] = false;
                        q.pop();
                        for (size_t i = 0; i < e[cur].size(); ++i) {
                                int id = e[cur][i];
                                int v = edge[id].v;
                                int c = min(maxc[cur], edge[id].c);
                                if (c == 0) {   // ~~
                                        continue;
                                }
                                int w = minw[cur] + edge[id].w;
                                if (minw[v] > w || (minw[v] == w && maxc[v] < c)) {
                                        maxc[v] = c;
                                        minw[v] = w;
                                        pre[v] = id;    // e not v !
                                        d[v] = d[cur] + 1;
                                        if (d[v] >= n) {
                                                return false;
                                        }
                                        if (!mark[v]) {
                                                mark[v] = true;
                                                q.push(v);
                                        }
                                }
                        }
                }

                return true;
        }

        pair<int, int> gao() {
                int sumc = 0, sumw = 0;

                while (true) {
                        if (!_spfa()) {
                                throw NegativeCostCircuitExistsException();
                        } else if (maxc[sink] == 0) {
                                break;
                        } else {
                                int c = maxc[sink];
                                sumc += c;
                                sumw += c * minw[sink];
                                int cur = sink;
                                while (cur != source) {
                                        int id = pre[cur];
                                        edge[id].c -= c;
                                        edge[id ^ 1].c += c;
                                        cur = edge[id ^ 1].v;
                                }
                        }
                }

                return make_pair(sumc, sumw);
        }
};

#define ID(i, j) ((i) * c + (j))
#define S() (r * c)
#define T() (S() + 1)
#define SX() (S() + 2)
#define N() (S() + 3)
#define VALID(i, j) ((i) >= 0 && (i) < r && (j) >= 0 && (j) < c)

const int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
const int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

MinCostMaxFlow mcmf;

int main() {
        int r, c, n, k;
        int t, x, y;
        int p[16][16];

        while (scanf("%d%d%d%d", &r, &c, &n, &k) != EOF) {
                mcmf.init(N(), S(), T());
                mcmf.addEdge(S(), SX(), k, 0);
                for (int i = 0; i < r; ++i) {
                        for (int j = 0; j < c; ++j) {
                                scanf("%d", &p[i][j]);
                                if ((i + j) % 2 != 0) {
                                        mcmf.addEdge(ID(i, j), T(), 1, 0);
                                }
                        }
                }
                for (int i = 0; i < n; ++i) {
                        scanf("%d%d%d", &t, &x, &y);
                        --x;
                        --y;
                        mcmf.addEdge(SX(), ID(x, y), 1, 0);
                        for (int k = 0; k < 8; ++k) {
                                int xx = x + dx[k], yy = y + dy[k];
                                int cost = 0;
                                switch (t) {
                                        case 1: cost = p[x][y] * p[xx][yy]; break;
                                        case 2: cost = p[x][y] + p[xx][yy]; break;
                                        case 3: cost = max(p[x][y], p[xx][yy]); break;
                                }
                                if (VALID(xx, yy)) {
                                        mcmf.addEdge(ID(x, y), ID(xx, yy), 1, cost);
                                }
                        }
                }
                pair<int, int> cw = mcmf.gao();
                fprintf(stderr, "%d %d\n", cw.first, cw.second);
                if (cw.first != k) {
                        puts("-1");
                } else {
                        printf("%d\n", cw.second);
                }
        }

        return 0;
}

// 2012-09-07 15:46:24 | Accepted | 3308 | C++ | 40 | 892 | watashi | Source
