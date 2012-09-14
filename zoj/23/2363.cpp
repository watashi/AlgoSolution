#include <set>
#include <cstdio>
#include <vector>

using namespace std;

int bitLength(int m) {
    int ret = 0;
    while (m > 0) {
        m >>= 1;
        ++ret;
    }
    return ret;
}

#define CHANGE(p, d) \
    do {\
        if (v[p] == 0) {\
            zero.erase(p);\
        } else if (v[p] == 2) {\
            two.erase(p);\
        }\
        v[p] += d;\
        printf(" %d %d", p, v[p]);\
        if (v[p] == 0) {\
            zero.insert(p);\
        } else if (v[p] == 2) {\
            two.insert(p);\
        }\
    } while(false)

int main() {
    int re;
    int n, m, p;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        if (ri > 1) {
            puts("");
        }
        scanf("%d%d", &n, &m);
        vector<int> v(n + bitLength(m), 0);
        set<int> zero;
        set<int> two;
        set<int>::iterator iz, it;
        for (int i = 0; i < (int)v.size(); ++i) {
            zero.insert(i);
        }
        two.insert((int)v.size());
        for (int i = 0; i < m; ++i) {
            scanf("%d", &p);
            it = two.upper_bound(p);
            iz = zero.upper_bound(*it);
            --iz;
            if (p >= *iz) {
                putchar('3');
                CHANGE(p, +1);
                CHANGE(*it, -2);
                CHANGE(*it + 1, +1);
            } else if (v[p] > 0) {
                putchar('2');
                CHANGE(p, -1);
                CHANGE(p + 1, +1);
            } else {
                putchar('1');
                CHANGE(p, +1);
            }
            putchar('\n');
        }
    }

    return 0;
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1828490   2009-04-11 03:59:33     Accepted    2363    C++     210     176     watashi@Zodiac

// 2012-09-07 15:39:10 | Accepted | 2363 | C++ | 160 | 180 | watashi | Source
