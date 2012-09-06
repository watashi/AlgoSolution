#include <cstdio>
#include <algorithm>

using namespace std;

const int inf = 123456789;

bool mark[1024];
int n, d[1024], mp[1024][1024];
int m, v[128], e[128][128];

void floyd(int m)
{
    for (int k = 0; k < m; k++) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                e[i][j] = min(e[i][j], e[i][k] + e[k][j]);
            }
        }
    }
}

void dfs(int p)
{
    v[m++] = p;
    mark[p] = true;
    for (int i = 0; i < n; i++) {
        if (!mark[i] && mp[p][i] != -1) {
            dfs(i);
        }
    }
}

int gao(int p)
{
    m = 0;
    dfs(p);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            e[i][j] = mp[v[i]][v[j]];
            if (e[i][j] == -1) {
                e[i][j] = inf;
            }
        }
    }
    floyd(m);
    for (int i = 0; i < m; i++) {
        v[i] = *max_element(e[i], e[i] + m) + d[v[i]];
    }
    return *min_element(v, v + m);
}

int main(void)
{
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &mp[i][j]);
            }
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &d[i]);
            mark[i] = false;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!mark[i]) {
                ans = max(ans, gao(i));
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}


//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1801444   2009-03-24 04:52:42     Accepted    3080    C++     810     4344    watashi@Zodiac

// 2012-09-07 02:00:42 | Accepted | 3080 | C++ | 720 | 4344 | watashi | Source
