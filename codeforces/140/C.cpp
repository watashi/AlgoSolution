#include <map>
#include <cstdio>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    int n, l, r, m, s;
    map<int, int> mp;
    vector<vector<int> > ans;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &r);
        ++mp[r];
    }
    l = 0;
    r = n / 3 + 1;
    while (l < r) {
        m = (l + r) / 2;
        s = 0;
        for (const auto& p: mp) {
            s += min(m, p.second);
        }
        if (s >= 3 * m) {
            l = m + 1;
        } else {
            r = m;
        }
    }

    m = r - 1;
    s = 0;
    ans.resize(m);
    for (const auto& p: mp) {
        for (int i = 0; i < min(m, p.second); ++i) {
            if (s < 3 * m) {
                ans[s % m].push_back(p.first);
                ++s;
            }
        }
    }

    printf("%d\n", (int)ans.size());
    for (const auto& v: ans) {
        printf("%d %d %d\n", v[2], v[1], v[0]);
    }

    return 0;
}


