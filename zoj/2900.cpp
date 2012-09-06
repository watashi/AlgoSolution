//状态为 MARK * LEN 而不是 N * LEN(TLE)
//状态转移为 (min(mark + p, MARK) - max(mark - p, 0) ) * LEN
//可以通过数状数组或线段树快速求出 SUM(min(mark + p, MARK) - max(mark - p, 0)) (由于只有 100, 体现不出太多优势)

#include <cstdio>
#include <algorithm>
using namespace std;

const int SIZE = 101;
int dp[2002][SIZE];
int it[2002][SIZE];//Indexed Tree //Binary Indexed Tree //
int n, k, p, m;

inline int lowbit(int x)
{
    return x & (x ^ (x - 1));
}

inline void modify(int k, int i, int v)
{
    v -= dp[k][i];
    dp[k][i] += v;
    if(v >= m) v -= m;
    else if(v < 0) v += m;
    for (i = i + 1; i <= SIZE; i += lowbit(i)) {
        it[k][i - 1] += v;
        if(it[k][i - 1] >= m) it[k][i - 1] -= m;
    }
}

inline int query(int k, int i)
{
    int sum = 0;
    while(i) {
        sum += it[k][i - 1];
        if(sum >= m) sum -= m;
        i ^= lowbit(i);
    }
    return sum;
}

int main(void)
{
    while(scanf("%d%d%d%d", &n, &k, &p, &m) != EOF) {
        fill(dp[0], dp[n], 0);
        fill(it[0], it[n], 0);
        for (int i = 0; i < n; i++) {
            int a;
            scanf("%d", &a);
            int f = max(a - p, 0), t = min(a + p + 1, SIZE);
            for (int j = i; j; j--) {
                int v = dp[j][a] + query(j - 1, t) - query(j - 1, f);
                if(v >= m) v -= m;
                else if(v < 0) v += m;
                modify(j, a, v);
            }
            if (dp[0][a] != m - 1) modify(0, a, dp[0][a] + 1);
            else modify(0, a, 0);
        }
        int ans = 0;
        for (int i = k - 1; i < n; i++) {
            ans += query(i, SIZE);
            if(ans >= m) ans -= m;
        }
        printf("%d\n", ans);
    }
    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2742076 2008-02-02 19:00:53 Accepted 2900 C++ 00:03.24 2016K わたし

// 2012-09-07 01:45:51 | Accepted | 2900 | C++ | 950 | 1760 | watashi | Source
