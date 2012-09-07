#include <queue>
#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 32768;

pair<int, int> et[MAXN];

int main() {
    int n, m, t, ans;

    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &et[i].second, &et[i].first);
        }
        sort(et, et + n);
        t = 0;
        ans = 0;

        priority_queue<int> pq;
        for (int i = 0; i < n; ++i) {
            t += et[i].second;
            pq.push(et[i].second);
            while (t > et[i].first) {
                t -= pq.top();
                pq.pop();
                ++ans;
            }
        }

        printf("%d\n", ans < m ? ans : -1);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//929   2010-07-22 20:39:41     Accepted    1107    C++     330     692     anotherpeg  Source

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//318   2010-10-05 22:26:19     Accepted    E   C++     230     692     watashi@Zodiac  Source

// 2012-09-07 15:53:00 | Accepted | 3410 | C++ | 290 | 692 | watashi | Source
