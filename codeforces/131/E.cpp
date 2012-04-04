#include <set>
#include <map>
#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 100100;

map<pair<int, int>, int> cnt;
map<int, set<int> > mp[4];
int ans[10];

const int fx[] = {1, 0, 1, 1};
const int fy[] = {0, 1, 1, -1};
const int gx[] = {0, 1, 0, 0};
const int gy[] = {1, 0, 1, 1};

int main() {
    int n, m, x, y;

    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &x, &y);
        for (int j = 0; j < 4; ++j) {
            mp[j][fx[j] * x + fy[j] * y].insert(gx[j] * x + gy[j] * y);
        }
    }
    for (int i = 0; i < 4; ++i) {
        for (const auto& p: mp[i]) {
            const set<int>& s = p.second;
            set<int>::const_iterator it = s.begin(), jt;
            while (it != s.end()) {
                jt = it;
                ++jt;
                if (gx[i] == 1) {
                    x = *it;
                    y = p.first - fx[i] * x;
                } else {
                    y = *it;
                    x = p.first - fy[i] * y;
                }
                cnt[make_pair(x, y)] += (it == s.begin() ? 0 : 1) + (jt == s.end() ? 0 : 1);
                it = jt;
            }
        }
    }
    fill(ans, ans + 9, 0);
    for (const auto& p: cnt) {
        ++ans[p.second];
    }
    for (int i = 0; i <= 8; ++i) {
        printf("%d ", ans[i]);
    }

    return 0;
}
