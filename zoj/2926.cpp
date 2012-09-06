#include <cstdio>
#include <limits>
#include <algorithm>
#include <functional>

int zju[1000];
int rate[5000];
int range[30][2];
int dp[30];

inline int rating(int x, int l, int r)
{
    if(x >= l) return x - l + 1;
    else if(x <= r) return r - x + 1;
    else return 0;
}

int main(void)
{
    int n, m, cnt;

    while(scanf("%d%d", &n, &m) != EOF) {
        for (int i = 0; i < n; i++)
            scanf("%d", &zju[i]);
        for (int i = 0; i < m; i++)
            scanf("%d", &rate[i]);
        if(m == 0) {
            printf("%d\n", 0);
            continue;
        }
        cnt = (m + 24) / 25;
        std::sort(zju, zju + n, std::greater<int>());
        std::sort(rate, rate + m, std::greater<int>());

        int ans = std::numeric_limits<int>::max() / 2;


        for (int i = 0; i <= cnt; i++) {
            int t = i, c = 0;
            while(t < m) {  // 对于最后一组有两种方案，一般不选最后一个人(m + c + 24) / 25 == cnt而(m + c + 1 + 24) / 25 == cnt + 1 时除外，没有这个测试数据
                dp[c + 1] = std::numeric_limits<int>::max() / 2;
                if(t == 0) range[c][0] = std::numeric_limits<int>::max() / 2;
                else range[c][0] = rate[t - 1];
                range[c][1] = rate[t];
                t += cnt;
                ++c;
            }
            if(t == m && (m + c + 24) / 25 == cnt && (m + c + 24 + 1) / 25 == cnt + 1) {
                range[c][0] = rate[t - 1];
                range[c][1] = std::numeric_limits<int>::min() / 2;
                ++c;
            }
            if(c > n || (m + c + 24) / 25 == cnt) continue;
            for (int j = 0; j < n; j++)
                for (int k = c - 1; k >= 0; k--)
                    dp[k + 1] = std::min(dp[k + 1], dp[k] + rating(zju[j], range[k][0], range[k][1]));
            ans = std::min(ans, dp[c]);
        }
        if(ans == std::numeric_limits<int>::max() / 2) printf("Impossible\n");
        else printf("%d\n", ans);
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2765125 2008-02-29 16:43:05 Accepted 2926 C++ 00:00.21 460K わたし

/*
Rank Submit time Run time Run memory Language User
1 2008-02-29 16:43:05 00:00.21 460K C++ わたし
2 2008-02-24 08:18:11 00:00.22 580K C++ mj
3 2008-02-23 18:19:53 00:00.31 612K C++ Lunarmony@Amethyst
4 2008-02-26 09:02:57 00:00.35 596K C++ 11
5 2008-02-26 11:30:51 00:00.43 600K C++ Z.C.S
6 2008-02-25 17:02:47 00:00.49 576K C++ yali
7 2008-02-23 17:27:40 00:00.73 4396K C++ Fire
8 2008-02-24 15:26:23 00:01.36 692K C++ Wishmaster
9 2008-02-27 00:46:32 00:01.37 1060K C++ Hadi Moshayedi
*/

// 2012-09-07 01:47:54 | Accepted | 2926 | C++ | 70 | 204 | watashi | Source
