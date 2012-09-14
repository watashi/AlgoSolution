#include <map>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXT = 10086;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int dp[MAXT];

void gao(int n, vector<pair<int, pair<int, int> > >& v) {
    int t = 0, w = 0;
    sort(v.begin(), v.end());
    for (vector<pair<int, pair<int, int> > >::iterator it = v.begin(); it != v.end(); ++it) {
        t += it->second.first;
        w += it->second.second;
        it->second.first = t;
        it->second.second = w;
    //  printf("%d %d\n", t, w);
    }
    for (int i = n; i >= 0; --i) {
        int tmp = dp[i];
        for (vector<pair<int, pair<int, int> > >::const_iterator it = v.begin(); it != v.end(); ++it) {
            if (i < it->second.first) {
                break;
            } else {
                tmp = max(tmp, dp[i - it->second.first] + it->second.second);
            }
        }
        dp[i] = tmp;
    }
}

int main() {
    int x0, y0, x, y, z, t, w, n, m;

    while (scanf("%d%d%d%d", &x0, &y0, &n, &m) != EOF) {
        map<pair<int, int>, vector<pair<int, pair<int, int> > > > mp;

        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d%d", &x, &y, &t, &w);
            x -= x0;
            y -= y0;
            z = gcd(abs(x), abs(y));
            x /= z;
            y /= z;
            mp[make_pair(x, y)].push_back(make_pair(z, make_pair(t, w)));
        }
        fill(dp, dp + m + 1, 0);
        for (map<pair<int, int>, vector<pair<int, pair<int, int> > > >::iterator it = mp.begin(); it != mp.end(); ++it) {
        //  printf("gao (%d, %d)\n", it->first.first, it->first.second);
            gao(m, it->second);
        }
        printf("%d\n", *max_element(dp, dp + m + 1));
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//631   2010-12-24 00:08:20     Accepted    F   C++     340     220     watashi@Zodiac  Source

// 2012-09-07 16:50:29 | Accepted | 3450 | C++ | 330 | 220 | watashi | Source
