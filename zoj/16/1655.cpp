#include <cstdio>

double mp[101][101];
double maxr[101];
double weight[101];

void Dijkstra(const int n)
{
    static bool mark[101];

    for (int i = 1; i <= n; i++) {
        mark[i] = false;
        maxr[i] = 0.0;
    }
    maxr[n] = 1.0;
    for (int i = 1; i <= n; i++) {
        int k = 0;
        for (int j = 1; j <= n; j++)
            if(!mark[j] && (k == 0 || maxr[j] > maxr[k]))
                k = j;
        mark[k] = true;
        for (int j = 1; j <= n; j++)
            if(!mark[j] && maxr[j] < maxr[k] * mp[k][j])
                maxr[j] = maxr[k] * mp[k][j];
    }
}

int main(void)
{
    int a, b, n, m;
    double ans;

    while(scanf("%d%d", &n, &m) != EOF) {
        for (int i = 1; i <= n; i++) {
            if(i < n) scanf("%lf", &weight[i]);
            else weight[i] = 0;
            for (int j = 1; j <= n; j++)
                mp[i][j] = 0.0;
        }
        while(m--) {
            scanf("%d%d%lf", &a, &b, &ans);
            if(mp[a][b] < 1.0 - ans) // 555 tooold is also not old 555
                mp[a][b] = mp[b][a] = 1.0 - ans;
        }
        Dijkstra(n);
        ans = 0.0;
        for (int i = 1; i < n; i++)
            ans += weight[i] * maxr[i];
        printf("%.2lf\n", ans);
    }
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2840636   2008-04-12 20:24:23     Accepted    1655    C++     00:00.04    480K    Re:ReJudge

// 2012-09-07 00:57:17 | Accepted | 1655 | C++ | 10 | 260 | watashi | Source
