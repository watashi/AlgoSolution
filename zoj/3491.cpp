#include <queue>
#include <cstdio>
#include <vector>
#include <cassert>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

const int MAXN = 2048;
const int MAXM = 200200;

inline int mod(int a, int b) {
    a %= b;
    return a >= 0 ? a : a + b;
}

int main() {
    int re, n, z, w, t, m;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d%d%d", &n, &z, &w);
        m = 2 * (n - 1);

        vector<pair<int, int> > p(z);
        for (int i = 0; i < z; ++i) {
            scanf("%d%d", &p[i].first, &p[i].second);
            --p[i].second;
        }
        sort(p.begin(), p.end());

        priority_queue<int, vector<int>, greater<int> > q[m + n];
        for (int i = 0; i < w; ++i) {
            scanf("%d", &t);
            q[m + t - 1].push(i);
        }

        int lastx = -1;
        vector<pair<int, int> > r;
        for (vector<pair<int, int> >::const_iterator i = p.begin(); i != p.end(); ++i) {
            int x = i->first, y = i->second;
            if (x > lastx) {
                lastx = x;
                for (vector<pair<int, int> >::const_iterator k = r.begin(); k != r.end(); ++k) {
                    q[k->first].push(k->second);
                }
                r.clear();
            }

            int j = -1;
            if (!q[t = mod(y - x, m)].empty() && (j == -1 || q[t].top() < q[j].top())) {
                j = t;
            }
            if (!q[t = mod(m - y - x, m)].empty() && (j == -1 || q[t].top() < q[j].top())) {
                j = t;
            }
            if (!q[t = m + y].empty() && (j == -1 || q[t].top() < q[j].top())) {
                j = t;
            }

            if (j == -1) {
                --z;
                continue;
            }
            t = q[j].top();
            q[j].pop();
            if (j < m) {
                r.push_back(make_pair(mod(m - j - x - x, m), t));
            } else {
                j -= m;
                if (j < n / 2) {
                    r.push_back(make_pair(mod(j - x, m), t));
                } else {
                    r.push_back(make_pair(mod(m - j - x, m), t));
                }
            }
        }
        printf("%d\n", z);
    }
    assert(scanf("%d", &re) == EOF);

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//470   2011-04-15 01:45:43     Accepted    E   C++     1570    2404    watashi     Source

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//1     2011-04-15 23:02:53     Accepted    E   C++     890     2404    watashi@ArcOfDream  Source

// 2012-09-07 16:01:35 | Accepted | 3491 | C++ | 820 | 2404 | watashi | Source
