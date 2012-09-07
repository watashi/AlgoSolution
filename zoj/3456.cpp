#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

const int MAXN = 256;
const int MAXM = 10086;

const int HOURS_PER_DAY = 24;
const int HOURS_PER_YEAR = 365 * HOURS_PER_DAY;
const int HOURS_PER_LEAP_YEAR = 366 * HOURS_PER_DAY;

inline bool isleap(int y) {
    return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0);
}

struct DisjointSet {
    int p[MAXN];

    void init(int n) {
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
    }

    int root(int i) {
        return i == p[i] ? i : (p[i] = root(p[i]));
    }

    bool setp(int i, int j) {
        i = root(i);
        j = root(j);
        if (i != j) {
            p[i] = j;
            return true;
        } else {
            return false;
        }
    }
} ds;

typedef pair<int, pair<int, int> > Edge;

int main() {
    int n, m, t, a, b, c, ans;
    bool todo;
    int v[MAXN];
    Edge p;
    vector<Edge> e;

    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &v[i]);
            v[i] *= HOURS_PER_DAY;
        }

        ds.init(n);
        e.clear();
        t = n - 1;
        ans = HOURS_PER_LEAP_YEAR + 1;
        todo = false;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &a, &b, &c);
            p = make_pair(c + c + v[a] + v[b], make_pair(a, b));

            if (t > 0) {
                e.push_back(p);
                if (ds.setp(a, b)) {
                    if (--t == 0) {
                        sort(e.begin(), e.end());
                        todo = true;
                    }
                }
            } else if (p.first < e.back().first) {
                e.insert(find_if(e.begin(), e.end(), bind2nd(greater<Edge>(), p)), p);
                todo = true;
            }
            if (todo) {
                ds.init(n);
                ans = 0;
                for (vector<Edge>::iterator it = e.begin(); it != e.end(); ) {
                    if (!ds.setp(it->second.first, it->second.second)) {
                        it = e.erase(it);
                    } else {
                        ans += it->first;
                        ++it;
                    }
                }
                todo = false;
            }

            if (ans <= (isleap(1000 + i) ? HOURS_PER_LEAP_YEAR : HOURS_PER_YEAR)) {
                printf("%.2lf\n", (double)ans / HOURS_PER_DAY);
            } else {
                puts("-1");
            }
        }
        puts("");
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//622   2010-12-23 21:48:46     Accepted    L   C++     150     180     watashi@Zodiac  Source

// 2012-09-07 15:57:55 | Accepted | 3456 | C++ | 150 | 180 | watashi | Source
