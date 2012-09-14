#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, l, p, q;
int flag;
int mark[1024];
bool e[1024][1024];

void dfs(int i) {
    if (l > p) {
        p = l;
        q = i;
    }
    ++l;
    mark[i] = flag;
    for (int j = 0; j < n; ++j) {
        if (e[i][j] && mark[j] != flag) {
            dfs(j);
        }
    }
    --l;
}

int main() {
    int a, b;

    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 0; i < n; ++i) {
            mark[i] = -1;
            for (int j = 0; j < n; ++j) {
                e[i][j] = false;
            }
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &a, &b);
            e[a][b] = e[b][a] = true;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (mark[i] == -1) {
                l = 1;
                p = 1;
                q = i;
                flag = 0;
                dfs(i);
                l = 1;
                p = 1;
                q = q;
                flag = 1;
                dfs(q);
                ans = max(ans, p);
            }
        }
        if (ans <= 7) {
            puts("Impossible");
        } else {
            printf("%d\n", ans);
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1801347   2009-03-23 23:33:22     Accepted    3172    C++     30  1204    watashi@Zodiac

// 2012-09-07 02:05:55 | Accepted | 3172 | C++ | 30 | 1208 | watashi | Source
