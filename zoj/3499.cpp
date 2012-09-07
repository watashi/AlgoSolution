#include <cstdlib> // auto fix CE
#include <cmath>
#include <cstdlib> // auto fix CE
#include <cstdio>
#include <cstdlib> // auto fix CE
#include <cassert>
#include <cstdlib> // auto fix CE
#include <algorithm>

using namespace std;

int main() {
    int re, n;
    double a[1024];

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        assert(scanf("%d", &n) == 1);
        assert(0 < n && n < 500);
        for (int i = 0; i < n; ++i) {
            assert(scanf("%lf", &a[i]) != EOF && fabs(a[i]) < 1000000);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (a[i] > a[j]) {
                    swap(a[i], a[j]);
                }
            }
        }
        if (n % 2 == 0) {
            printf("%.3lf\n", (a[n / 2 - 1] + a[n / 2]) / 2);
        } else {
            printf("%.3lf\n", a[n / 2]);
        }
    }
    assert(scanf("%d", &re) == EOF);

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//480   2011-04-15 01:56:28     Accepted    M   C++     80  180     watashi     Source

// 2012-09-07 16:02:24 | Accepted | 3499 | C++ | 50 | 180 | watashi | Source
