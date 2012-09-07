#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 128;

struct X {
    int p, r;
};

bool pry(const X& lhs, const X& rhs) {
    return lhs.p < rhs.p;
}

bool prz(const X& lhs, const X& rhs) {
    return lhs.r > rhs.r;
}

int main() {
    int re, n, s, p1, p2, p3;
    bool flag;
    X x;
    vector<X> y, z;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d%d", &n, &s);
        y.clear();
        z.clear();
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d%d", &p1, &p2, &p3, &x.r);
            x.p = INF;
            for (int a = 0; a <= 3; ++a) {
                for (int b = 0; b <= 4; ++b) {
                    for (int c = 0; c <= 8; ++c) {
                        if (3 * a + 2 * b + c >= 7) {
                            x.p = min(x.p, p1 * a + p2 * b + p3 * c);
                        }
                    }
                }
            }
            if (x.p <= x.r) {
                y.push_back(x);
            } else {
                z.push_back(x);
            }
        }

        flag = true;
        sort(y.begin(), y.end(), pry);
        for (vector<X>::const_iterator i = y.begin(); i != y.end(); ++i) {
            if (i->p >= s) {
                flag = false;
            } else {
                s -= i->p - i->r;
            }
        }
        sort(z.begin(), z.end(), prz);
        for (vector<X>::const_iterator i = z.begin(); i != z.end(); ++i) {
            if (i->p >= s) {
                flag = false;
            } else {
                s -= i->p - i->r;
            }
        }
        if (flag) {
            printf("%d\n", s);
        } else {
            puts("no");
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//588   2010-07-16 19:53:04     Accepted    1077    C++     10  180     anotherpeg  Source

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//721   2011-02-11 13:23:32     Accepted    H   C++     0   180     watashi@ArcOfDream  Source

// 2012-09-07 15:59:45 | Accepted | 3474 | C++ | 0 | 180 | watashi | Source
