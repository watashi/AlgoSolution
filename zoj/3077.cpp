#include <cstdio>
#include <algorithm>

using namespace std;

struct baggage
{
    int v, a, b, c;
    bool operator<(const baggage& rhs) const
    {
        return b > rhs.b;
    }
};

int dp[1024];
baggage bag[128];

int main(void)
{
    int re;
    int s, n;

    scanf("%d", &re);
    while (re--) {
        scanf("%d%d", &s, &n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d", &bag[i].v, &bag[i].a, &bag[i].b);
            bag[i].c = bag[i].a - bag[i].b;
        }
        sort(bag, bag + n);
        fill(dp, dp + s + 1, 0);
        for (int i = 0; i < n; i++) {
            for (int j = bag[i].a; j <= s; j++) {
                dp[j - bag[i].c] = max(dp[j - bag[i].c], dp[j] + bag[i].v);
            }
        }
        printf("%d\n", *max_element(dp, dp + s + 1));
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1801446   2009-03-24 04:56:24     Accepted    3077    C++     0   184     watashi@Zodiac

// 2012-09-07 02:00:30 | Accepted | 3077 | C++ | 0 | 184 | watashi | Source
