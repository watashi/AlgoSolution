#include <map>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100100;

const char * ans[] = {
    "none",
    "any",
    "at least one"
};

struct Edge {
    int a, b, c, i, t;
} e[MAXN];

struct DisjointSet {
    int p[MAXN], q[MAXN];

    void init(int n) {
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            q[i] = -1;
        }
    }

    int getp(int i) {
        return p[i] == i ? i : (p[i] = getp(p[i]));
    }

    void setp(int i, int j) {
        p[getp(i)] = getp(j);
    }
} st;

struct Graph {
    map<int, int> v;
    map<int, Edge*> e[MAXN];

    void init() {
        v.clear();
    }

    int getv(int i) {
        int ret;
        if (v.count(i) > 0) {
            ret = v[i];
        } else {
            ret = (int)v.size();
            e[ret].clear();
            v[i] = ret;
        }
        return ret;
    }

    void add(int a, int b, Edge* c) {
        a = getv(a);
        b = getv(b);
        if (e[a].count(b) > 0) {
            e[a][b] = NULL;
        } else {
            e[a][b] = c;
        }
        if (e[b].count(a) > 0) {
            e[b][a] = NULL;
        } else {
            e[b][a] = c;
        }
    }

    int dfn[MAXN], low[MAXN];

    void tarjan(int v, int d) {
        dfn[v] = low[v] = d;
        for (const auto& p: e[v]){
            int w = p.first;
            if (!dfn[w]){
                tarjan(w, d + 1);
                low[v] = min(low[v], low[w]);
                if (low[w] > dfn[v] && p.second != NULL) {
                    // printf("CUT %d %d %d\n", p.second->a + 1, p.second->b + 1, p.second->i);
                    p.second->t = 1;
                }
            } else if (dfn[w] != dfn[v] - 1) {
                low[v] = min(low[v], dfn[w]);
            }
        }
    }

    void gao() {
        int n = (int)v.size();
        fill(dfn, dfn + n, 0);
        fill(low, low + n, 0);
        for (int i = 0; i < n; ++i) {
            if (!dfn[i]) {
                tarjan(i, 1);
            }
        }
    }
} g;

int main() {
    int n, m;

    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &e[i].a, &e[i].b, &e[i].c);
        --e[i].a;
        --e[i].b;
        e[i].i = i;
    }
    sort(e, e + m, [&](const Edge& lhs, const Edge& rhs){ return lhs.c < rhs.c; });

    st.init(n);
    for (int i = 0; i < m; ) {
        int j = i;
        g.init();
        do {
            e[j].a = st.getp(e[j].a);
            e[j].b = st.getp(e[j].b);
            if (e[j].a == e[j].b) {
                e[j].t = 0;
            } else {
                e[j].t = 2;
                g.add(e[j].a, e[j].b, e + j);
            }
            ++j;
        } while (j < m && e[j].c == e[i].c);
        g.gao();
        do {
            st.setp(e[i].a, e[i].b);
            ++i;
        } while (i < j);
    }
    sort(e, e + m, [&](const Edge& lhs, const Edge& rhs){ return lhs.i < rhs.i; });

    for (int i = 0; i < m; ++i) {
        puts(ans[e[i].t]);
    }

    return 0;
}

