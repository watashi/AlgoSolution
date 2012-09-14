// vertices are 1~n

#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 10001;
int dp[MAXN], c[MAXN];
vector<int> e[MAXN];

int ans;

void dfs(int p)
{
    dp[p] = c[p];
    for (size_t i = 0; i < e[p].size(); i++) {
        dfs(e[p][i]);
        dp[p] += dp[e[p][i]];
    }
    --dp[p];
    ans += (dp[p] >= 0) ? dp[p] : -dp[p];
}

int main(void)
{
    int n, m, v, d;

    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; i++) {
            dp[i] = -1;
            e[i].clear();
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &v);
            scanf("%d", &c[v]);
            scanf("%d", &m);
            while (m--) {
                scanf("%d", &d);
                e[v].push_back(d);
                dp[d] = 0;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (dp[i] == -1) {
                ans = 0;
                dfs(i);
                printf("%d\n", ans);
                break;
            }
        }
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//3020620 2008-08-04 11:51:44 Accepted 2374 C++ 00:00.03 1104K Re:ReJudge

// 2012-09-07 01:21:39 | Accepted | 2374 | C++ | 10 | 376 | watashi | Source
