/*
[quote=Ice_Ax]
设数为a[1],a[2]…a[m]（从小到大排序），分别有k[1],k[2]…k[m]个，那么我们可以证明最优解中k[1],k[2]…k[m-1]都不会超过a[m]:
若有某个k[i]>a[m],那么我们把k[i]减去a[m],k[m]加上a[i],有k[i]*a[i]+k[m]*a[m] == (k[i]-a[m])*a[i]+(k[m]+a[i])*a[m]，就是数的和保持不变，仍为n,但是数的数量从k[i]+k[m]变成了(k[i]-a[m])+ (k[m]+a[i])，减少了，结果更优，与最优解矛盾。
所以k[1],k[2]…k[m-1]最大不会超过99，数的和最大不会超过（1+2+…+98）*99,大概是500000吧（其实远远到不了这个，不过当时嫌麻烦，懒得算精确的了），于是在1到500000用dp求出最优解，然后枚举这前m-1个数的和（设为i），用dp[i]+(n-i)/a[m]就是一个解，求个最小的就行了。
[/quote]
*/

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXANS = 1111111111;
int dp[500000];

int main(void)
{
    int re, m, n;
    int a[101], s, ans;

    scanf("%d", &re);
    while(re--) {
        scanf("%d%d", &m, &n);
        for (int i = 0; i < m; i++)
            scanf("%d", &a[i]);
        sort(a, a + m);
        // TLE
        s = 0;
        for (int i = 1; i < m; i++)
            if(a[i] != a[s])
                a[++s] = a[i];
        m = s;
        //
        s = 0;
        for (int i = 0; i < m; i++) {
            s += (a[i + 1] - 1) * a[i];
            //if(a[i] == a[i + 1])
            //  char *p = new char[123456789];
        }
        dp[0] = 0;
        fill(dp + 1, dp + s + 1, MAXANS);
        for (int i = 0; i < m; i++)
            for (int j = a[i]; j <= s && j <= n; j++)
                dp[j] = min(dp[j], dp[j - a[i]] + 1);
        ans = MAXANS;
        for (int i = n % a[m]; i <= s && i <= n; i += a[m])
            ans = min(ans, dp[i] + (n - i) / a[m]);
        printf("%d\n", (ans == MAXANS) ? -1 : ans);
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2814895 2008-03-31 22:56:26 Accepted 2955 C++ 00:00.11 2392K わたし

// 2012-09-07 01:49:58 | Accepted | 2955 | C++ | 30 | 2132 | watashi | Source
