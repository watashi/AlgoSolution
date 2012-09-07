#include <cmath> // auto fix CE
#include <queue>
#include <cmath> // auto fix CE
#include <cstdio>
#include <cmath> // auto fix CE
#include <numeric>
#include <cmath> // auto fix CE
#include <utility>
#include <cmath> // auto fix CE
#include <algorithm>
#include <cmath> // auto fix CE
#include <functional>
#include <cmath> // auto fix CE
#include <ext/numeric>

using namespace std;
using namespace __gnu_cxx;

const int MAXN = 10086;
const int MAXM = 218;
const long long INF = 12345678987654321LL;

struct AscendingQueue {
    deque<pair<int, long long> > dq;    // <index (asc), value (asc)>

    void insert(int i, long long v) {
        while (!dq.empty() && dq.back().second >= v) {
            dq.pop_back();
        }
        dq.push_back(make_pair(i, v));
    }

    long long top(int i) {
        while (!dq.empty() && dq.front().first < i) {
            dq.pop_front();
        }
        return dq.empty() ? INF : dq.front().second;
    }
};

long long x[MAXN], g[MAXM];
long long mem[2][MAXN], *pre = mem[0], *cur = mem[1];

int main() {
    int n, m, a, b;
    long long ans;
    int ansk = -1, anst = -1;

    while (scanf("%d%d%d%d", &n, &m, &a, &b) != EOF) {
        for (int i = 1; i <= n; ++i) {
            scanf("%lld", &x[i]);
        }
        transform(x + 1, x + 1 + n, x + 1, compose1(
                bind2nd(ptr_fun<long long, int, long long>(power<long long, int>), 2),
                bind2nd(minus<long long>(), accumulate(x + 1, x + 1 + n, 0LL) / n)));
        x[0] = 0;
        partial_sum(x, x + 1 + n, x);
        for (int i = 0; i < m; ++i) {
            scanf("%lld", &g[i]);
        }

        fill(cur, cur + n + 1, INF);
        cur[0] = 0;
        ans = INF;
        for (int i = 0; i < m; ++i) {
            AscendingQueue aq;
            swap(pre, cur);
            fill(cur, cur + n + 1, INF);
            for (int j = a; j <= n; ++j) {
                aq.insert(j - a, pre[j - a] - g[i] * x[j - a]);
                cur[j] = aq.top(j - b) + g[i] * x[j];
            }
            if (ans > cur[n]) {
                ans = cur[n];
                ansk = i + 1;
                anst = n - aq.dq.front().first;
            }
        }

        if (ans < INF / 2) {
            printf("%lld %d %d\n", ans, ansk, anst);
        } else {
            puts("No solution.");
        }
    }

    return 0;
}

//ptr_fun(power<long long, int>)    =>  CE
//ptr_fun<long long, int, long long>(power<long long, int>) =>  AC

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//983   2010-07-23 20:49:18     Accepted    1100    C++     880     416     anotherpeg  Source

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//282   2010-08-30 17:47:00     Accepted    D   C++     800     416     watashi@Zodiac  Source

// 2012-09-07 15:51:46 | Accepted | 3399 | C++ | 810 | 416 | watashi | Source
