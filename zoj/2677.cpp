#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

struct DisjointSet {
    vector<int> p;

    DisjointSet(int n) : p(n, -1) {
    }

    int root(int i) {
        return p[i] == -1 ? i : (p[i] = root(p[i]));
    }

    bool setFriend(int i, int j) {
        i = root(i);
        j = root(j);
        if (i != j) {
            p[i] = j;
            return true;
        } else {
            return false;
        }
    }
};

const int MAXN = 100100;
int a[MAXN], b[MAXN], c[MAXN], d[MAXN];

bool pr(int lhs, int rhs) {
    return c[lhs] < c[rhs];
}

int main() {
    bool blank = false;
    int n, m;
    long long s;

    while (scanf("%d%d%lld", &n, &m, &s) != EOF) {
        if (blank) {
            puts("");
        } else {
            blank = true;
        }

        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &a[i], &b[i], &c[i]);
            --a[i];
            --b[i];
            d[i] = i;
        }
        sort(d, d + m, pr);

        DisjointSet ds(n);
        for (int i = m - 1; i >= 0; --i) {
            if (ds.setFriend(a[d[i]], b[d[i]])) {
                d[i] = -1;
            }
        }

        vector<int> ans;
        for (int i = 0; i < m; ++i) {
            if (d[i] != -1) {
                s -= c[d[i]];
                if (s >= 0) {
                    ans.push_back(d[i] + 1);
                } else {
                    break;
                }
            }
        }

        sort(ans.begin(), ans.end());
        printf("%d\n", ans.size());
        for (int i = 0; i < (int)ans.size(); ++i) {
            if (i > 0) {
                putchar(' ');
            }
            printf("%d", ans[i]);
        }
        puts("");
    }

    return 0;
}

/*
Run ID      Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
2125521     2010-03-24 23:29:17     Accepted    2677    C++     840     2808    watashi@Zodiac
*/

// 2012-09-07 15:43:32 | Accepted | 2677 | C++ | 730 | 2812 | watashi | Source
