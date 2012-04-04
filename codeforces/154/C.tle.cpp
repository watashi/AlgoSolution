#include <map>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 1 << 20;
const long long BASE1 = 1000037LL;
const long long BASE2 = 1000039LL;
const long long MOD1 = 1000000007LL;
const long long MOD2 = 1000000009LL;
const long long INV1 = 596247943LL;
const long long INV2 = 44292273LL;


vector<int> e[MAXN];
long long b1[MAXN], b2[MAXN];
vector<long long> h1[MAXN], h2[MAXN];
int x[MAXN], y[MAXN], sz[MAXN];

inline
pair<int, long long> gao(vector<int>& v, int& sz, vector<long long>& h1, vector<long long>& h2) {
    sort(v.begin(), v.end());
    sz = v.size();
    h1.push_back(0);
    h2.push_back(0);
    for (int i = 0; i < sz; ++i) {
        h1.push_back((h1.back() + v[i] * b1[i]) % MOD1);
        h2.push_back((h2.back() + v[i] * b2[i]) % MOD2);
    }
    return make_pair(sz, (h1.back() << 32) ^ h2.back());
}

inline
pair<int, long long> gao(int u, int v) {
    long long lo1, hi1, lo2, hi2;
    int m = lower_bound(e[u].begin(), e[u].end(), v) - e[u].begin();
    lo1 = h1[u][m];
    hi1 = (h1[u].back() - lo1 - v * b1[m]) % MOD1 * INV1 % MOD1;
    hi1 = (lo1 + hi1 + MOD1) % MOD1;
    lo2 = h2[u][m];
    hi2 = (h2[u].back() - lo2 - v * b2[m]) % MOD2 * INV2 % MOD2;
    hi2 = (lo2 + hi2 + MOD2) % MOD2;
    return make_pair(sz[u], (hi1 << 32) ^ hi2);
}

long long one[MAXN];

int main() {
    int n, m;
    long long zero, ans;
    map<pair<int, long long>, int> mp;

    b1[0] = 1;
    b2[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        b1[i] = b1[i - 1] * BASE1 % MOD1;
        b2[i] = b2[i - 1] * BASE2 % MOD2;
    }

    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &x[i], &y[i]);
        --x[i];
        --y[i];
        e[x[i]].push_back(y[i]);
        e[y[i]].push_back(x[i]);
    }
    zero = 0;
    ans = 0;
    for (int i = 0; i < n; ++i) {
        sz[i] = e[i].size();
        if (sz[i] == 0) {
            ++zero;
        } else if (sz[i] == 1) {
            ++one[e[i].back()];
        } else {
            ++mp[gao(e[i], sz[i], h1[i], h2[i])];
        }
    }
    for (int i = 0; i < m; ++i) {
        if (sz[x[i]] == sz[y[i]]) {
            if (sz[x[i]] == 1) {
                if (e[x[i]].back() == y[i] && e[y[i]].back() == x[i]) {
                    ++ans;
                }
            } else if (gao(x[i], y[i]) == gao(y[i], x[i])) {
                ++ans;
            }
        }
    }
    ans += zero * (zero - 1) / 2;
    for (int i = 0; i < n; ++i) {
        ans += one[i] * (one[i] - 1) / 2;
    }
    for (const auto& p: mp) {
        ans += p.second * (p.second - 1LL) / 2;
    }
    printf("%I64d\n", ans);

    return 0;
}

