/* //is it a tree */
/* //There will be at most one channel between two endpoints, and there is no channel connects an endpoint to itself. */
#include <stdio.h>
#include <string.h>
int n, m;
char mk[1001];
char mp[1001][1001];
void dfs(int t)
{
    int i;
    mk[t] = 1;
    for(i = 1; i <= n; i++)
        if(mp[t][i] && !mk[i])
            dfs(i);
}
int main()
{
    int i, j;

    while(scanf("%d%d", &n, &m) != EOF && n) {
        if(m != n - 1){
            while(m--)
                scanf("%d%d", &i, &j);
            puts("No");
            continue;
        }
        memset(mp, 0, sizeof(mp));
        while(m--){
            scanf("%d%d", &i, &j);
            mp[i][j] = mp[j][i] = 1;
        }
        memset(mk, 0, sizeof(mk));
        dfs(1);
        for(i = 1; i <= n; i++)
            if(!mk[i]) break;
        if(i > n) puts("Yes");
        else puts("No");
    }

    return 0;   /* NZEC */
}

/* //Run ID     Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name */
/* //2709334    2007-12-22 14:59:01     Accepted    2740    C   00:00.03    1372K   ¤ï¤¿¤· */

// 2012-09-07 03:12:36 | Accepted | 2740 | C | 0 | 1140 | watashi | Source
