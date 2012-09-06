#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 200;
const double INF = 1e100;
double x[MAXN];
inline double calcdiff(int i, int j, int k)
{
    return fabs(x[i] + (x[j] - x[i]) * (k - i) / (j - i) - x[k]);
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int h, c;
        scanf("%d%d", &h, &c);
        double dp[MAXN][MAXN];
        double cost[MAXN][MAXN];
        for (int i = 0; i < h; i++){
            scanf("%lf", &x[i]);
            dp[0][i] = INF;
        }
        for (int i = 0; i < h; i++)
            for (int j = i + 1; j < h; j++){
                cost[i][j] = 0;
                for (int k = i + 1; k < j; k++)
                    cost[i][j] += calcdiff(i, j, k);
            }
        dp[0][0] = 0;
        for (int l = 1; l < c; l++)
            for (int j = l; j < h; j++){
                dp[l][j] = INF;
                for (int i = 0; i < j; i++)
                    dp[l][j] = min(dp[l][j], dp[l - 1][i] + cost[i][j]);
            }
        printf("%.4lf\n", dp[c - 1][h - 1] / h);
    }
    return 0;
}
//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2708378   2007-12-21 17:14:24     Accepted    2884    C++     00:01.42    1024K   ¤ï¤¿¤·

// 2012-09-07 01:44:37 | Accepted | 2884 | C++ | 710 | 180 | watashi | Source
