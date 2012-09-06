#include <set>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 65536;

inline int F(int x) { return x >> 1; }
inline int L(int x) { return x << 1; }
inline int R(int x) { return (x << 1) ^ 1; }
inline int LR(int x) { return x ^ 1; }

int n, cur;
int h[MAXN], s[MAXN];
int a[MAXN * 2];

void mark(int p) {
    p += MAXN;
    a[p] = 1;
    while (p > 1) {
        if (a[p] == 1 && a[LR(p)] == 1) {
            a[F(p)] = 1;
        } else {
            a[F(p)] = -1;
        }
        p = F(p);
    }
}

bool check(int p, int l, int r, int ll, int rr) {
    if (a[p] != -1) {
        return a[p] == 1;
    } else if (l == ll && r == rr) {
        return false;
    } else {
        int m = (l + r) / 2;
        if (rr <= m) {
            return check(L(p), l, m, ll, rr);
        } else if (ll >= m) {
            return check(R(p), m, r, ll, rr);
        } else {
            return check(L(p), l, m, ll, m) && check(R(p), m, r, m, rr);
        }
    }
}

bool check(int l, int r) {
    if (l == r) {
        return true;
    } else if (l > r) {
        return check(l, n) && check(0, r);
    } else {
        return check(1, 0, MAXN, l, r);
    }
}

int main() {
    while (scanf("%d", &n) != EOF) {
        set<pair<int, int> > todo;
        vector<int> ans;
        set<int> st;
        for (int i = 0; i < n; ++i) {
            st.insert(i);
            scanf("%d", &h[i]);
            s[i] = (h[i] + 7) % n;
            if (h[i] > 0 && s[i] == i) {
                todo.insert(make_pair(h[i], i));
            }
            // printf("%d ", s[i]);
        }
        // putchar(' ');
        fill(a, a + MAXN * 2, 0);
        for (int i = n; i < MAXN; ++i) {
            mark(i);
        }
        // printf("DONE\n");
        while (!todo.empty()) {
            ans.push_back(todo.begin()->first);
            cur = todo.begin()->second;
            todo.erase(todo.begin());
            h[cur] = 0;
            mark(cur);
            st.erase(cur);
            if (st.lower_bound(cur) == st.end()) {
                cur = *st.begin();
            } else {
                cur = *st.lower_bound(cur);
            }
            // printf("1 %d\n", cur);
            if (h[cur] > 0 && check(s[cur], cur)) {
                // printf("2 %d\n", cur);
                todo.insert(make_pair(h[cur], cur));
            }
        }
        for (int i = 0; i < ans.size(); ++i) {
            printf("%d%c", ans[i], (i == ans.size() - 1) ? '\n' : ' ');
        }
    }
    return 0;
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1801337   2009-03-23 23:28:24     Accepted    3169    C++     2490    3668    watashi@Zodiac

// 2012-09-07 02:05:37 | Accepted | 3169 | C++ | 2140 | 3672 | watashi | Source
