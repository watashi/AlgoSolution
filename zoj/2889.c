/* //dp||关键在于倒过来dp！！ */
#include <stdio.h>
#define inf 123456789
char str[100][26];
int dp[101][26], ans[101][26];
int main()
{
    int kase;
    int ri;
    int i, j, k, f, t, n, m;

    scanf("%d", &kase);
    while(kase--) {
        ri = 0;
        while(scanf("%d%d", &n, &m) != EOF && (n || m)) {
            if(ri) putchar('\n');
            for (i = 0; i < n; i++)
                scanf("%s", str[i]);
            scanf("%d%d", &f, &t);
            f--;
            t--;
            for (j = 0; j < m; j++) {
                dp[t - 1][j] = (str[t - 1][j] == 'X') ? inf : 0;
                ans[t - 1][j] = -1;
            }
            for (i = t - 2; i >= f; i--)
                for (j = 0; j < m; j++) {
                    dp[i][j] = inf;
                    if(str[i][j] == 'X') continue;
                    for (k = 0; k < m; k++) {
                        if(dp[i + 1][k] + (k != j) < dp[i][j]) {
                            dp[i][j] = dp[i + 1][k] + (k != j);
                            ans[i][j] = k;
                        }
                    }
                }
            k = 0;
            for (i = 0; i < m; i++)
                if(dp[f][i] < dp[f][k]) k = i;
            printf("Case %d:\n\n", ++ri);
            if(dp[f][k] == inf) printf("Not available\n");
            else {
                i = f;
                do {
                    j = i;
                    while(ans[j][k] == k) j++;
                    printf("%c: %d-%d\n", 'A' + k, i + 1, j + 2);
                    k = ans[j][k];
                    i = j + 1;
                } while(k != -1);
            }
        }
        if(kase) putchar('\n');
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2717867 2008-01-01 21:33:40 Accepted 2889 C 00:00.05 416K わたし */

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //81 2007-12-26 22:41:05 Accepted 1014 C 00:00:06 420K わたし */

// 2012-09-07 01:45:07 | Accepted | 2889 | C | 10 | 180 | watashi | Source
