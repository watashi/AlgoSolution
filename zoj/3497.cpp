#include <map>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    int re, n, m, r, c, x, y, e[32];
    map<int, int> f;
    vector<int> g;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d%d", &r, &c);
        n = r * c;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                e[i * c + j] = 0;
                for (int k = 0; k < 4; ++k) {
                    scanf(" %*[(]%d,%d%*[),]", &x, &y);
                    e[i * c + j] |= 1 << ((x - 1) * c + (y - 1));
                }
            }
        }
        e[n - 1] = 0;

        r = 1;
        f.clear();
        for (int i = 0; ; ++i) {
            if (f.count(r) == 0) {
                f[r] = i;
                c = 0;
                for (int j = 0; j < n; ++j) {
                    if (r & (1 << j)) {
                        c |= e[j];
                    }
                }
                r = c;
            } else {
                x = f[r];
                y = i;
                break;
            }
        }

        c = 0;
        g.resize(f.size());
        for (map<int, int>::const_iterator i = f.begin(); i != f.end(); ++i) {
            if (i->first & (1 << (n - 1))) {
                c += i->second < x ? 1 : 2;
            }
            g[i->second] = i->first;
        }

        scanf("%d", &m);
        for (int i = 0; i < m; ++i) {
            scanf("%d", &r);
            if (r >= x) {
                r = (r - x) % (y - x) + x;
            }
            if (g[r] & (1 << (n - 1))) {
                puts(c == 1 ? "True" : "Maybe");
            } else {
                puts("False");
            }
        }
        puts("");
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//478   2011-04-15 01:54:02     Accepted    K   C++     10  180     watashi     Source

// 2012-09-07 16:02:11 | Accepted | 3497 | C++ | 0 | 180 | watashi | Source
