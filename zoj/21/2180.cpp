#include <cstdio>
#include <algorithm>
using namespace std;

int a[1001][1001];
int u[1001], d[1001];

int main(void)
{
    int re, m, n, ans;

    scanf("%d", &re);
    while(re--) {
        scanf("%d%d", &m, &n);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                scanf(" %c", &a[i][j]);
                if(a[i][j] == 'F') {
                    if(j == 0)
                        a[i][j] = 1;
                    else
                        a[i][j] = a[i][j - 1] + 1;
                }
                else
                    a[i][j] = 0;
            }
        ans = 0;
        for (int i = 0; i < n; i++) {
            u[0] = 1;
            for (int j = 1; j < m; j++) {
                int k = j - 1;
                while(k >= 0 && a[k][i] >= a[j][i])
                    k -= u[k];
                u[j] = j - k;
            }
            d[m - 1] = 1;
            ans = max(ans, (u[m - 1] + d[m - 1] - 1) * a[m - 1][i]);
            for (int j = m - 2; j >= 0; j--) {
                int k = j + 1;
                while(k < m && a[k][i] >= a[j][i])
                    k += d[k];
                d[j] = k - j;
                ans = max(ans, (u[j] + d[j] - 1) * a[j][i]);
            }
        }
        printf("%d\n", ans * 3);
    }
}

/*
Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
2807619 2008-03-28 22:13:20 Accepted 2180 C++ 00:00.38 4316K ¤ï¤¿¤·
*/

// 2012-09-07 01:15:00 | Accepted | 2180 | C++ | 120 | 4100 | watashi | Source
