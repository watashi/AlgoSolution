#include <cstdio>
#include <cstdlib>
#include <numeric>
#include <algorithm>

using namespace std;

long long dom[13];
long long sdom[13];
long long doy[13];
long long sdoy[13];

void init() {
    for (int i = 1; i <= 12; ++i) {
        dom[i] = i * i * i;
    }
    partial_sum(dom, dom + 13, sdom);
    copy(sdom, sdom + 13, doy);
    partial_sum(doy, doy + 13, sdoy);
}

bool isleap(long long y) {
    return y % 11 == 0;
}

// <y
long long leapnum(long long y) {
    return (y + 10) / 11;
}

// <m-d-y
long long ymd2i(long long y, long long m, long long d) {
    long long ret = 0;
    // if (y > 1) 是错的，测试数据基本都是随机的，所以混过了……
    if (y > 0) {
        ret += (y - 1) / 12 * sdoy[12];
        ret += sdoy[(y - 1) % 12 + 1];
    }
    // printf("(%lld)", ret);
    ret += leapnum(y);
    ret += sdom[m - 1];
    ret += d - 1;
    if (isleap(y) && m > 1) {
        ++ret;
    }
    return ret;
}

int main() {
    long long y, m, d, a, b;

    init();
    while (scanf("%lld-%lld-%lld", &m, &d, &y) != EOF) {
        a = ymd2i(y, m, d);
        scanf("%lld-%lld-%lld", &m, &d, &y);
        b = ymd2i(y, m, d);
        // printf("%lld %lld\n", a, b);
        printf("%lld\n", llabs(a - b) + 1);
    }

    return 0;
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//1287  2010-08-01 18:52:28     Accepted    1159    C++     40  180     anotherpeg  Source

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//273   2010-08-30 17:32:42     Accepted    H   C++     30  176     watashi@Zodiac  Source

// 2012-09-07 17:07:29 | Accepted | 3403 | C++ | 20 | 180 | watashi | Source
