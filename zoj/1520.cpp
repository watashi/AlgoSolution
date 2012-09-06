#include <cstdio>

int a[1000];
int dp[1001][2];

int main(void)
{
    int m, l, s, n;

    while(scanf("%d%d", &m, &l) != EOF && (m > 0 || l > 0)) {
        scanf("%d", &n);
        s = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            s += a[i];
        }
        s -= l;
        if (s <= 0) {
            printf("0\n");
            continue;
        }
        if (s > m) {
            printf("Impossible to distribute\n");
            continue;
        }
        for (int i = 1; i <= m; ++i)
            dp[i][0] = -1;
        dp[0][0] = 0;
        l = -1;
        for (int i = n - 1; i >= 0 && l == -1; --i)
            for (int j = m; j >= a[i]; --j)
                if(dp[j][0] == -1 && dp[j - a[i]][0] != -1) {
                    dp[j][0] = dp[j - a[i]][0] + 1;
                    dp[j][1] = i;
                    if (j >= s) {
                        l = j;
                        break;
                    }
                }
        if(l == -1)
            printf("Impossible to distribute\n");
        else {
            printf("%d", dp[l][0]);
            // in ascending order
            while(l > 0) {
                printf(" %d", dp[l][1] + 1);
                l -= a[dp[l][1]];
            }
            printf("\n");
        }
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2797103 2008-03-22 17:01:20 Accepted 1520 C++ 00:00.00 404K ¤ï¤¿¤·

// 2012-09-07 00:52:17 | Accepted | 1520 | C++ | 0 | 192 | watashi | Source
