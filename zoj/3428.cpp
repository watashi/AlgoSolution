#include <cstdio>
#include <vector>
#include <utility>
#include <cassert>
#include <algorithm>

using namespace std;

const int LIMIT = 1000001;
const int RLIMIT = 1600;

template<typename T>
inline T gcd(T a, T b) {
    return b == 0 ? a : gcd(b, a % b);
}

struct BigInt {
    static const long long MOD = 1000000000000000000LL;
    long long h, l;

    BigInt() : h(0), l(0) {
    }

    void add(long long x) {
        l += x;
        while (l >= MOD) {
            l -= MOD;
            ++h;
        }
    }

    void print(long long x) {
        if (x == 0) {
            printf("NaN");
            return;
        }
        long long g = gcd((h % x) * (MOD % x) + l, x);
        long long hh = h / g;
        long long ll = (h % g) * (MOD / g) + ((h % g) * (MOD % g) + l) / g;
        if (hh > 0) {
            printf("%lld%018lld/%lld", hh, ll, x / g);
        } else {
            printf("%lld/%lld", ll, x / g);
        }
    }
};

// r=first; s=second
// x=r^2-s^2; y=2rs; z=r^2+s^2
// vector<pair<int, int> > pythagoras;
// static BigInt a[LIMIT];
// static BigInt b[LIMIT];
// static long long c[LIMIT];

static struct ABC {
    BigInt a, b;
    long long c;
} abc[LIMIT];


inline long long sum2(long long n) {    // \sum_{i=0}^n{i^2}
    return n * (n + 1) / 2 * (n + n + 1) / 3;
}

inline void gao(long long x, long long y) {
    long long l = max(1LL, x - y);
    long long r = x / 2 + 1;
    if (l < r) {
        abc[y].a.add((x * x + y * y) * (r - l));
        abc[y].b.add(sum2(r - 1) - sum2(l - 1));
        abc[y].b.add(sum2(x - l) - sum2(x - r));
        abc[y].b.add((y * y) * (r - l));
        abc[y].c += r - l;
    }
}

void init() {
    // pythagoras
    for (int r = 1; r < RLIMIT; ++r) {
        for (int s = r % 2 + 1; s < r; s += 2) {
            if (gcd(r, s) == 1) {
                int x = r * r - s * s;
                int y = 2 * r * s;
                if (x > y) {
                    swap(x, y);
                }
                for (long long i = x, j = y; i < LIMIT; i += x, j += y) {
                //  pythagoras.push_back(make_pair(i, j));
                    if (j < LIMIT) {
                        gao(i, j);
                    }
                    gao(j, i);
                }
            }
        }
    }
    // printf("%d\n", pythagoras.size());   // 2388959
}

int main() {
    int n = 0;

    init();
    while (scanf("%d", &n) != EOF) {
        assert(1 <= n && n <= 1000000);
        abc[n].a.print(abc[n].c);
        putchar(' ');
        abc[n].b.print(abc[n].c);
        puts("");
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//404   2010-11-11 23:17:38     Accepted    B   C++     2520    39244   watashi@Zodiac  Source

// 2012-09-07 15:54:07 | Accepted | 3428 | C++ | 2470 | 39244 | watashi | Source
