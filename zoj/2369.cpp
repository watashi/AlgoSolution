#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

const long double H = 5e-5;

struct F {
    long double rr1, rr2;
    F(long double r1, long double r2) : rr1(r1 * r1), rr2(r2 * r2) {
    }
    long double operator()(long double x) const {
        x = x * x;
        return sqrt((rr2 - x) * (rr1 - x));
    }
};

int main() {
    int re;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        long double r1, r2;
        scanf("%Lf%Lf", &r1, &r2);
        if (r1 > r2) {
            swap(r1, r2);
        }
        int n = int(r1 / H);
        // int n = 1000000;
        long double h = r1 / n / 2;
        F f(r1, r2);
        long double s = 0;
        s += f(0) + f(r1);
        for (int i = 1; i < 2 * n; ++i) {
            if (i & 1) {
                s += 4 * f(i * h);
            } else {
                s += 2 * f(i * h);
            }
        }
        s /= 6 * n;
        s *= 8 * r1;
        printf("%.6Lf\n", s);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1807544   2009-03-28 06:09:08     Accepted    2369    C++     410     176     watashi@Zodiac

// 2012-09-07 01:21:20 | Accepted | 2369 | C++ | 310 | 180 | watashi | Source
