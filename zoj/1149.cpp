#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 6;

int c[MAXN];
int dp[MAXN - 1][100000];

int main(void)
{
    int ri = 0;
    int pre, tmp, sum;
    bool flag;

    while (scanf("%d%d%d%d%d%d", &c[0], &c[1], &c[2], &c[3], &c[4], &c[5]) != EOF && (c[0] + c[1] + c[2] + c[3] + c[4] + c[5]) > 0) {
        printf("Collection #%d:\n", ++ri);
        sum = 0;
        for (int i = 1; i <= MAXN; i++) {
            sum += i * c[i - 1];
        }
        if (sum % 2 != 0) {
            printf("Can't be divided.\n\n");
            continue;
        }
        sum /= 2;
        tmp = min(c[0], sum);
        for (int k = 0; k <= tmp; k++) {
            dp[0][k] = 1;
        }
        for (int i = 1; i < MAXN - 1; i++) {
            pre = tmp;
            tmp = min(tmp + (i + 1) * c[i], sum);
            for (int j = tmp; j > pre; j--) {
                dp[i][j] = 0;
            }
            for (int j = pre; j >= 0; j--) {
                dp[i][j] = 0;
                if (dp[i - 1][j]) {
                    for (int k = 0, t = j; k <= c[i] && t <= tmp; k++, t += i + 1) {
                        if (dp[i][t]) {
                            break;
                        }
                        else {
                            dp[i][t] = 1;
                        }
                    }
                }
            }

        }
        flag = false;
        for (int i = (sum - tmp + MAXN - 1) / MAXN, j = sum - (sum - tmp + MAXN - 1) / MAXN * MAXN; i <= c[MAXN - 1] && j >= 0; i++, j -= MAXN) {
            if (dp[MAXN - 2][j]) {
                flag = true;
                break;
            }
        }
        puts(flag ? "Can be divided.\n" : "Can't be divided.\n");
    }

    return 0;
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2958251   2008-06-29 03:11:03     Accepted    1149    C++     00:00.01    2344K   Re:ReJudge

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2958252   2008-06-29 03:11:29     Accepted    1149    C++     00:00.00    2344K   Re:ReJudge

// 2012-09-07 00:38:59 | Accepted | 1149 | C++ | 0 | 2132 | watashi | Source
