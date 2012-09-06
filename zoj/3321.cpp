#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 16;
vector<int> e[MAXN];
bool b[MAXN];

void gao(int v, int p) {
    if (!b[v] && e[v].size() == 2) {
        b[v] = true;
        gao(e[v][0] != p ? e[v][0] : e[v][1], v);
    }
}

int main() {
    int n, m, x, y;
    bool ans;

    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 0; i < n; ++i) {
            b[i] = false;
            e[i].clear();
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &x, &y);
            --x;
            --y;
            e[x].push_back(y);
            e[y].push_back(x);
        }
        ans = n == m;
        gao(0, -1);
        for (int i = 0; ans && i < n; ++i) {
            ans &= b[i];
        }
        puts(ans ? "YES" : "NO");
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//2157515   2010-04-12 21:40:19     Accepted    3321    C++     0   176     watashi@Zodiac

// 2012-09-07 02:07:45 | Accepted | 3321 | C++ | 0 | 180 | watashi | Source
