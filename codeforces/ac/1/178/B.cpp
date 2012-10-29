#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXB = 17;
const int MAXN = 100100;

struct LCA {
    vector<int> e[MAXN];
    int d[MAXN];
    int p[MAXN][MAXB];

    void dfs(int u, int v) {
        // printf("%d => %d\n", u, v);
        for (int i = 1; i < MAXB; ++i) {
            p[u][i] = p[p[u][i - 1]][i - 1];
        }
        for (auto w: e[u]) {
            if (w == v) {
                continue;
            }
            d[w] = d[u] + 1;
            p[w][0] = u;
            dfs(w, u);
        }
    }

    int up(int u, int n) {
        for (int i = 0; n > 0; ++i) {
            if (n % 2 != 0) {
                u = p[u][i];
            }
            n >>= 1;
        }
        return u;
    }

    int gao(int u, int v) {
        int l = 0, r = min(d[u], d[v]) + 1, m;
        while (l < r) {
            m = (l + r) / 2;
            if (up(u, d[u] - m) == up(v, d[v] - m)) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        m = l - 1;
        return (d[u] - m) + (d[v] - m);
    }
} lca;

int id[MAXN];
bool cut[MAXN];
vector<pair<int, int> > e[MAXN];

int low[MAXN], dfn[MAXN], st[MAXN], top;

void tarjan(int v, int cnt){
    st[top++] = v;
    dfn[v] = low[v] = cnt;
    for (auto w: e[v]) {
        if (dfn[w.first] == 0){
            tarjan(w.first, cnt + 1);
            low[v] = min(low[v], low[w.first]);
            if (low[w.first] > dfn[v]) {
                cut[w.second] = true;
            }
        } else if (dfn[w.first] != dfn[v] - 1) {
            low[v] = min(low[v], dfn[w.first]);
        }
    }
}

void dfs(int v, int tag) {
    id[v] = tag;
    for (auto w: e[v]) {
        if (!cut[w.second] && id[w.first] == -1) {
            dfs(w.first, tag);
        } else if (cut[w.second] && id[w.first] != -1) {
            lca.e[tag].push_back(id[w.first]);
            lca.e[id[w.first]].push_back(tag);
        }
    }
}

int main() {
    int n, m, a, b;

    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &a, &b);
        --a;
        --b;
        e[a].push_back({b, i});
        e[b].push_back({a, i});
    }

    fill(cut, cut + n, false);
    for (int i = 0; i < n; ++i) {
        if (dfn[i] == 0) {
            tarjan(i, 1);
        }
    }

    m = 0;
    fill(id, id + n, -1);
    for (int i = 0; i < n; ++i) {
        if (id[i] == -1) {
            dfs(i, m++);
        }
    }
    for (int i = 0; i < m; ++i) {
        sort(lca.e[i].begin(), lca.e[i].end());
        lca.e[i].erase(unique(lca.e[i].begin(), lca.e[i].end()), lca.e[i].end());
    }
    lca.dfs(0, -1);

    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &a, &b);
        --a;
        --b;
        printf("%d\n", lca.gao(id[a], id[b]));
    }

    return 0;
}
