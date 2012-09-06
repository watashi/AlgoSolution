#include <queue>
#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    int n, l, p, t, s;
    pair<int, int> a[10000];
    priority_queue<int> pq;

    while (scanf("%d%d", &n, &l) != EOF) {
        // !Runtime Error
        if (n == 0) {
            puts("0");
            continue;
        }

        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &a[i].second, &a[i].first);
        }
        sort(a, a + n);
        p = n - 1;
        t = a[p].first;
        s = 0;
        pq = priority_queue<int>();
        while (t >= 0) {
            while (p >= 0 && a[p].first >= t) {
                pq.push(a[p--].second);
            }
            for (int i = 0; !pq.empty() && i < l; ++i) {
                s += pq.top();
                pq.pop();
            }
            --t;
        }
        printf("%d\n", s);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1749871   2009-01-27 23:51:45     Accepted    3116    C++     20  176     watashi@Zodiac

// 2012-09-07 02:02:08 | Accepted | 3116 | C++ | 10 | 180 | watashi | Source
