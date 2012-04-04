#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int MAXN = 1 << 20;
const long long MOD = 1000000000039LL;
const long long BASE = 1000037LL;

vector<int> e[MAXN];
long long b[MAXN], h[MAXN];
int x[MAXN], y[MAXN], s[MAXN];

namespace std {
    template<>
    struct hash<pair<int, long long> > {
        size_t operator()(const pair<int, long long>& p) const {
            return p.first * p.second;
        }
    };
}

inline
pair<int, long long> gao(vector<int>& v, int& s, long long& h) {
    s = v.size();
    h = 0;
    for (int i: v) {
        h += b[i];
        if (h >= MOD) {
            h -= MOD;
        }
    }
    return make_pair(s, h);
}

inline
pair<int, long long> gao(int u, int v) {
    long long hh = h[u] - b[v];
    if (hh < 0) {
        hh += MOD;
    }
    if (hh >= MOD) {
        hh -= MOD;
    }
    return make_pair(s[u], hh);
}

long long one[MAXN];

int main() {
    int n, m;
    long long zero, ans;
    unordered_map<pair<int, long long>, int> mp(MAXN);

    b[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        b[i] = (b[i - 1] * BASE) % MOD;
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
        s[i] = e[i].size();
        if (s[i] == 0) {
            ++zero;
        } else if (s[i] == 1) {
            ++one[e[i].back()];
        } else {
            ++mp[gao(e[i], s[i], h[i])];
        }
    }
    for (int i = 0; i < m; ++i) {
        if (s[x[i]] == s[y[i]]) {
            if (s[x[i]] == 1) {
                if (e[x[i]][0] == y[i] && e[y[i]][0] == x[i]) {
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

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//1235481 	Feb 26, 2012 1:17:58 AM 	watashi 	154C - Double Profiles 	GNU C++0x 	Accepted 	2500 ms 	109600 KB

