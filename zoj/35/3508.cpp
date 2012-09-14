#include <set>
#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 65536;

pair<int, int> p[MAXN];

int main() {
    int n, m, t;
    multiset<int> s;
    multiset<int>::iterator it;

    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &p[i].second, &p[i].first);
        }
        s.clear();
        for (int i = 0; i < m; ++i) {
            scanf("%d", &t);
            s.insert(t);
        }
        sort(p, p + n);
        t = 0;
        for (int i = 0; i < n; ++i) {
            it = s.lower_bound(p[i].second);
            if (it != s.end() && *it <= p[i].first) {
                ++t;
                s.erase(it);
            }
        }
        printf("%d\n", t);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//745   2011-04-27 03:53:16     Accepted    I   C++     30  1484    watashi@ArcOfDream  Source

// 2012-09-07 16:03:18 | Accepted | 3508 | C++ | 30 | 1484 | watashi | Source
