#include <set>
#include <map>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

const int MAXN = 128;
typedef pair<int, int> PII;

pair<PII, int> v[MAXN];
int ans[MAXN];

int main() {
    int n, m;
    set<int> p;
    multimap<int, int> q;

    while (scanf("%d%d", &n, &m) != EOF && n > 0) {
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &v[i].first.first, &v[i].first.second);
            v[i].second = i;
        }
        sort(v, v + n);
        p.clear();
        for (int i = 0; i < m; ++i) {
            p.insert(i);
        }
        q.clear();
        for (int i = 0; i < n; ++i) {
            while (!q.empty() && q.begin()->first <= v[i].first.first) {
                p.insert(q.begin()->second);
                q.erase(q.begin());
            }
            if (!p.empty()) {
                ans[v[i].second] = *p.begin();
                q.insert(make_pair(v[i].first.second, *p.begin()));
                p.erase(p.begin());
            } else {
                ans[v[i].second] = -1;
            }
        }
        for (int i = 0; i < n; ++i) {
            printf("%d\n", ans[i] + 1);
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//2157596   2010-04-12 22:20:06     Accepted    3317    C++     0   180     watashi@Zodiac

// 2012-09-07 02:07:20 | Accepted | 3317 | C++ | 0 | 180 | watashi | Source
