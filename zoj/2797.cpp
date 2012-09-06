#include <cstdio>

bool mark[128];
double mp[128][128], maxp[128];

int main(void)
{
    int n, m, a, b;
    double p;

    while (scanf("%d%d", &n, &m) != EOF && n > 0) {
        for (int i = 1; i <= n; i++) {
            mark[i] = false;
            maxp[i] = 0;
            for (int j = 1; j <= n; j++) {
                mp[i][j] = 0;
            }
        }
        while (m--) {
            scanf("%d%d%lf", &a, &b, &p);
            mp[a][b] = mp[b][a] = p / 100.0;
        }
        maxp[1] = 1;
        for (int i = 1; i <= n; i++) {
            int k = -1;
            for (int j = 1; j <= n; j++) {
                if (!mark[j] && (k == -1 || maxp[j] > maxp[k])) {
                    k = j;
                }
            }
            mark[k] = true;
            for (int j = 1; j <= n; j++) {
                if (!mark[j] && maxp[k] * mp[k][j] > maxp[j]) {
                    maxp[j] = maxp[k] * mp[k][j];
                }
            }
        }
        printf("%.6lf percent\n", 100 * maxp[n]);
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//3022747 2008-08-05 14:38:30 Accepted 2797 C++ 00:00.11 524K Re:ReJudge
//

// 2012-09-07 01:40:21 | Accepted | 2797 | C++ | 30 | 308 | watashi | Source
