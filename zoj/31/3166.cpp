#include <cstdio>
#include <algorithm>

using namespace std;

const int inf = 123456789;

int mp[128][128];
int h[128];

int main(void)
{
    int n, c, m, f, t;

    while (scanf("%d%d", &n, &c) != EOF) {
        for (int i = 0; i < c; i++) {
            scanf("%d", &h[i]);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                mp[i][j] = 2 * inf;
            }
  //          mp[i][i] = 0;
        }
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &f, &t);
            scanf("%d", &mp[f][t]);
        }
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
//                    if (k == n)printf(" %d", mp[i][j]);
                }
//                if (k == n)      printf("\n");
            }
        }

        int ans = -1, mind = inf;

        for (int i = 0; i < c; i++) {
        /*    int tmp = 0;
            for (int j = 1; j <= n; j++) {
//                if (mp[h[i]][j] < inf) {
//                    tmp = max(tmp, mp[j][h[i]] + mp[h[i]][j]);
//                }
                tmp = max(tmp, mp[h[i]][j] + mp[j][h[i]]);
            }
//            printf("%d\n", tmp);
            if (tmp < mind) {
                mind = tmp;
                ans = h[i];
            }
            else if (tmp == mind) {
                ans = min(ans, h[i]);
            }*/
            int p = h[i];
            if (mp[p][p] < mind) {
                mind = mp[p][p];
                ans = p;
            }
            else {
                ans = min(ans, p);
            }
        }

        if (ans == -1) {
            puts("I will nerver go to that city!");
        }
        else {
            printf("%d\n", ans);
        }
    }

    return 0;
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1801111   2009-03-23 21:10:49     Accepted    3166    C++     270     240     watashi@Zodiac

// 2012-09-07 02:05:18 | Accepted | 3166 | C++ | 210 | 244 | watashi | Source
