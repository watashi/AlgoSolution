#include <algorithm> // auto fix CE
#include <cstdio>

const int INF = 123456789;

int mp[1001][1001];
int mind[1001];

int Dijkstra(int n, int s)
{
    static bool mark[1001];

    for (int i = 1; i <= n; i++) {
        mark[i] = false;
        mind[i] = INF;
    }
    mind[s] = 0;
    for (int i = 1; i <= n; i++) {
        int k = -1;
        for (int j = 1; j <= n; j++)
            if(!mark[j] && (k == -1 || mind[j] < mind[k]))
                k = j;
        mark[k] = true;
        for (int j = 1; j <= n; j++)
            if(!mark[j])
                /* mind[j] <?= mind[k] + mp[k][j]; */ /* auto fix <?= */
                mind[j] = mind[j] < mind[k] + mp[k][j] ? mind[j] : mind[k] + mp[k][j];
    }

    return mind[n];
}

int main(void)
{
    int re;
    int n, m, a, b, c, l;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ri++) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                mp[i][j] = INF;
        while(m--) {
            scanf("%d%d%d", &a, &b, &c);
            if(c < mp[a][b])
                mp[a][b] = mp[b][a] = c;
        }

        scanf("%d", &m);
        if(m == 1) {
            scanf("%*d");
            printf("TEST %d %s\n", ri, (n == 1) ? "Y 0" : "N");
            continue;
        }
        scanf("%d%d", &a, &b);
        c = b;
        l = mp[a][b];
        a = b;
        m -= 2;
        while(m--) {
            scanf("%d", &b);
            if(l < INF) {
                l += mp[a][b];
                a = b;
            }
        }
        if(l >= INF) {
            printf("TEST %d N\n", ri);
            continue;
        }
        l -= mp[1][c];
        for (int i = 1; i <= n; i++)
            mp[1][i] = INF;
        l -= Dijkstra(n, c);
        if(l < 0)
            printf("TEST %d N\n", ri);
        else
            printf("TEST %d Y %d\n", ri, l);
    }

    return 0;
}
//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2843296   2008-04-14 14:00:41     Accepted    2504    C++     00:00.25    4312K   Re:ReJudge

// 2012-09-07 13:54:35 | Accepted | 2504 | C++ | 60 | 4100 | watashi | Source
