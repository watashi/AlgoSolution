#include <queue>
#include <cstdio>
#include <vector>
#include <functional>

using namespace std;

int main()
{
    int re;
    int n, p;
    long long a, b, s;

    scanf("%d", &re);
    while (re--) {
        priority_queue<long long, vector<long long>, greater<long long> > pq;

        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &p);
            pq.push(p);
        }
        s = 0;
        while (pq.size() > 1) {
            a = pq.top();
            pq.pop();
            b = pq.top();
            pq.pop();
            s += a + b;
            pq.push(a + b);
        }

        printf("%lld\n", s);
        if (re > 0) {
            puts("");
        }
    }
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1719852   2008-12-06 09:49:01     Accepted    2339    C++     630     6328    watashi@Zodiac

// 2012-09-07 01:19:36 | Accepted | 2339 | C++ | 630 | 6332 | watashi | Source
