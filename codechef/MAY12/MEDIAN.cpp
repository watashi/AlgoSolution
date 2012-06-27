#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 32;

int tmp, ans;

bool test(int i, int j) {
    return ((i >> j) & 1) != 0;
}

void gao(int n, int m) {
    if (m == 0) {
        ans = tmp;
    } else if (ans > tmp + 1) {
        vector<pair<int, int> > v;
        ++tmp;
        for (int i = 0; i < n; ++i) {
            int k = -1, c = 0;
            for (int j = i + 1; j <= n; ++j) {
                if (test(m, j - 1)) {
                    ++c;
                }
                if (c <= (j - i) / 2) {
                    k = j;
                }
            }
            if (k != -1 && (v.empty() || k > v.back().second)) {
                v.push_back(make_pair(i, k));
            }
        }
        for (int i = 0; i < (int)v.size(); ++i) {
            gao(n, m & ~((1 << v[i].second) - (1 << v[i].first)));
        }
        --tmp;
    }
}

int main() {
    int re, n, m, b, a[MAXN];

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        b = *max_element(a, a + n);
        m = 0;
        for (int i = 0; i < n; ++i) {
            m <<= 1;
            if (a[i] < b) {
                m ^= 1;
            }
        }
        tmp = 0;
        ans = MAXN;
        gao(n, m);
        printf("%d\n", ans);
    }

    return 0;
}

//Correct Answer
//Execution Time: 0.02
