#include <cstdio>
#include <cstring>

char buf[16];
long long p[16][16], e[16][16];

bool match(int src, int tar, char ch)
{
    for (int i = 1; i < tar; i++) {
        if (buf[src - tar + i] != buf[i - 1]) {
            return false;
        }
    }
    return tar == 0 || ch == buf[tar - 1];
}

int main(void)
{
    int re, n, l;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ri++) {
        scanf("%d%s", &n, buf);
        l = (int)strlen(buf);

        memset(p, 0, sizeof(p));
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = i + 1; k >= 0; k--) {
                    if (match(i, k, 'A' + j)) {
                        ++p[i][k];
                        break;
                    }
                }
            }
        }
        for (int i = 1; i <= l; i++) {
            e[i - 1][i] = n;
            for (int j = 0; j < i - 1; j++) {
                e[i - 1][i] += e[j][i - 1] * p[i - 1][j];
            }
            for (int j = 0; j < i - 1; j++) {
                e[j][i] = e[j][i - 1] + e[i - 1][i];
            }
        }

        printf("Case %d:\n%lld\n", ri, e[0][l]);
        if (ri < re) {
            putchar('\n');
        }
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//3019573 2008-08-03 15:26:19 Accepted 2619 C++ 00:00.00 392K Re:ReJudge
//

// 2012-09-07 01:32:30 | Accepted | 2619 | C++ | 0 | 184 | watashi | Source
