#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1 << 16;

int d[MAXN];
vector<int> e[MAXN];

void gao(int v, int p) {
    d[v] = -2;
    for (int w: e[v]) {
        if (w == p) {
            continue;
        } else if (d[w] == -2) {
            d[w] = 0;
            throw w;
        } else {
            try {
                gao(w, v);
            } catch (int q) {
                if (q != -1) {
                    d[w] = 0;
                    if (v == q) {
                        q = -1;
                    }
                }
                throw q;
            }
        }
    }
}

void dfs(int v) {
    for (int w: e[v]) {
        if (d[w] < 0) {
            d[w] = d[v] + 1;
            dfs(w);
        }
    }
}

int main() {
    int n, a, b;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a, &b);
        --a;
        --b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    fill(d, d + n, -1);
    try {
        gao(0, -1);
    } catch (...) {
    }
    for (int i = 0; i < n; ++i) {
        if (d[i] == 0) {
            dfs(i);
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ", d[i]);
    }

    return 0;
}

