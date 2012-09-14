#include <cstdio>
#include <algorithm>

using namespace std;

struct Calender {
    const long long ty, tm, td, diy;

    Calender(int t1, int t2, int t3) : ty(t1), tm(t2), td(t3), diy(t1 / t3) {
    }

    static long long ceil(long long a, long long b) {
        return (a + b - 1) / b;
    }

    static long long floor(long long a, long long b) {
        return a / b;
    }

    int query(long long y, long long m) const {
        long long first_full = ceil((y - 1) * ty, tm) * tm - (y - 1) * ty;
//      bool has_month_0 = (first_full >= td);
        long long begin = (m == 0) ? 0 : floor(first_full + tm * (m - 1), td);
        long long end = floor(first_full + tm * m, td);
        if (begin >= diy) {
            return 0;
        } else {
            return min(diy, end) - begin;
        }
    }
};

int main() {
    int re;
    int t1, t2, t3, q, y, m;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d%d%d", &t1, &t2, &t3);
        Calender cal(t1, t2, t3);
        scanf("%d", &q);
        for (int p = 0; p < q; ++p) {
            scanf("%d%d", &y, &m);
            printf("%d\n", cal.query(y, m));
        }
    }

    return 0;
}

// 2012-09-07 16:49:50 | Accepted | 3350 | C++ | 0 | 180 | watashi | Source
