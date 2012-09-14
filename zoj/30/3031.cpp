#include <set>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <utility>

using namespace std;

typedef long long integer;

const int MAXN = 100001;

integer D[MAXN], d[MAXN], w[MAXN], dp[MAXN];
int x[MAXN], y[MAXN];

int main()
{
    int re, n, c;

    scanf("%d", &re);
    while (re--) {
        scanf("%d%d", &c, &n);
        w[0] = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d%d%lld", &x[i], &y[i], &w[i]);
            D[i] = abs(x[i]) + abs(y[i]);
            if (i == 1) {
                d[i] = 0;
            }
            else {
                d[i] = d[i - 1] + abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]);
            }
            w[i] += w[i - 1];
        }

        deque<pair<integer, int> > q;
        int p;

        p = 0;
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            q.push_front(make_pair(dp[i - 1] - d[i] + D[i], w[i - 1]));
            while (q.back().second < w[i] - c) {
                q.pop_back();
            }
            while (q.size() > 1 && q.front().first <= (q.begin() + 1)->first) {
                q.erase(q.begin() + 1);
            }
            dp[i] = q.back().first + d[i] + D[i];
        }

        printf("%lld\n", dp[n]);
    }

    return 0;
}

// if integer=int; then WA elif integer=long\ long; then AC fi

// set
// Run ID   Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
// 3048790  2008-08-24 13:54:08     Accepted    3031    C++     00:00.56    6764K   watashi@Zodiac

// deque
// 3048782      2008-08-24 13:52:03     Accepted    3031    C++     00:00.49    4752K   watashi@Zodiac

// 2012-09-07 01:56:43 | Accepted | 3031 | C++ | 120 | 4088 | watashi | Source
