#include <cstdio>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>

using namespace std;

struct Comp {
    const pair<int, int> *p;
    Comp(const pair<int, int> p[]) : p(p) { }
    bool operator()(int lhs, int rhs) const {
        return p[lhs].first != p[rhs].first ?  p[lhs].first > p[rhs].first : p[lhs].second < p[rhs].second;
    }
};

int main() {
    int re;
    int n, m, t, p, r;
    int tid, pid, at, rank, maxac, len, maxlen;
    double a, b;
    char pcode, status, name[128][1024];
    pair<int, int> ac[128];
    pair<int, double> s[128];
    int wa[128][26];
    vector<int> ts;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        if (ri > 1) {
            puts("");
        }
        scanf("%d", &n);
        while (getchar() != '\n');
        maxlen = 0;
        for (int i = 0; i < n; ++i) {
            fgets(name[i], sizeof(name[i]), stdin);
            len = strlen(name[i]);
            name[i][--len] = '\0';
            maxlen = max(len, maxlen);
        }
        fill(s, s + n, make_pair(0, .0));
        scanf("%d", &m);
        while (m-- > 0) {
            scanf("%d", &t);
            ts.resize(t);
            for (int i = 0; i < t; ++i) {
                scanf("%d", &ts[i]);
                --ts[i];
                ac[ts[i]] = make_pair(0, 0);
                fill(wa[ts[i]], wa[ts[i]] + 26, 0);
            }
            scanf("%d", &p);
            scanf("%d", &r);
            for (int i = 0; i < r; ++i) {
                scanf("%d %c%d %c", &tid, &pcode, &at, &status);
                --tid;
                pid = pcode - 'A';
                if (wa[tid][pid] == -1) {
                    // ACed
                } else if (status == '+') {
                    ++ac[tid].first;
                    ac[tid].second += at + 20 * wa[tid][pid];
                    wa[tid][pid] = -1;
                } else {
                    ++wa[tid][pid];
                }
            }
            sort(ts.begin(), ts.end(), Comp(ac));

            a = 2 * t - 2;
            b = t - 2;
            rank = 0;
            maxac = ac[ts[0]].first;
            for (size_t i = 0; i < ts.size(); ++i) {
                if (i == 0 || ac[ts[i]] != ac[ts[i - 1]]) {
                    rank = i + 1;
                }
                //fprintf(stderr, "%d %d %d %d\n", rank, ts[i], ac[ts[i]].first, ac[ts[i]].second);
                ++s[ts[i]].first;
                s[ts[i]].second += (maxac == 0 ? 0 : 1. * ac[ts[i]].first / maxac) * a / (rank + b);
            }
        }
        vector<pair<double, int> > st(n);
        for (int i = 0; i < n; ++i) {
            st[i] = make_pair((s[i].first == 0) ? 0 : s[i].second / s[i].first, i);
        }
        sort(st.begin(), st.end());
        reverse(st.begin(), st.end());
        for (int i = 0; i < n; ++i) {
            printf("%*s %.4lf\n", -maxlen, name[st[i].second], st[i].first);
        }
    }
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1831851   2009-04-13 03:11:05     Accepted    2593    C++     160     176     watashi@Zodiac

// 2012-09-07 15:41:41 | Accepted | 2593 | C++ | 180 | 180 | watashi | Source
