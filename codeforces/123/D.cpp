#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 100100;

// [Algorithm] [Module] [Suffix Array]
struct SuffixArray {
    pair<int, int> suffix[MAXN];
    int sa[MAXN], rank[MAXN], height[MAXN], h[MAXN];

    void init(int n, const char a[MAXN]) {
        sa[0] = 0;  // n = 1
        for (int i = 0; i < n; ++i) {
            rank[i] = a[i];
        }
        for (int m = 1; m < n; m <<= 1) {
            for (int i = 0; i < n; ++i) {
                sa[i] = i;
                suffix[i] = {rank[i], i + m < n ? rank[i + m] : -1};
            }
            sort(sa, sa + n, [&](int lhs, int rhs){ return suffix[lhs] < suffix[rhs]; });
            for (int i = 0; i < n; ++i) {
                if (i == 0 || (suffix[sa[i]] != suffix[sa[i - 1]])) {
                    rank[sa[i]] = i;
                } else {
                    rank[sa[i]] = rank[sa[i - 1]];
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (rank[i] == 0) {
                h[i] = 0;
            } else {
                int x = i, y = sa[rank[i] - 1], z = max(0, h[i - 1] - 1);
                while (x + z < n && y + z < n && a[x + z] == a[y + z]) {
                    ++z;
                }
                h[i] = z;
            }
        }
        for (int i = 0; i < n; ++i) {
            height[i] = h[sa[i]];
        }
    }
} sa;

char buf[MAXN];

long long cnt(long long n) {
    return n * (n + 1) / 2;
}

int main() {
    int n;
    long long ans;
    vector<pair<pair<int, int>, int> > v;

    scanf("%s", buf);
    n = (int)strlen(buf);
    sa.init(n, buf);
    sa.height[n] = 0;
    sa.sa[n] = n;
    ans = 0;
    for (int i = 0; i <= n; ++i) {
        while (!v.empty() && v.back().first.second > sa.height[i]) {
            auto& end = v.back();
            if (end.first.first < sa.height[i]) {
                ans += (end.first.second - sa.height[i]) * cnt(i - end.second);
                end.first.second = sa.height[i];
            } else {
                ans += (end.first.second - end.first.first) * cnt(i - end.second);
                v.pop_back();
            }
        }
        if (sa.height[i] < n - sa.sa[i]) {
            v.push_back({{sa.height[i], n - sa.sa[i]}, i});
        }
    }
    // printf("%lld\n", ans);
    printf("%I64d\n", ans);

    return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//1155911 	Feb 7, 2012 6:13:07 PM 	watashi 	123D - String 	GNU C++0x 	Accepted 	250 ms 	6200 KB
