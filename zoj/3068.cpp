#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    double l, r, mid, s;
    static int a[1024], b[1024];
    static double v[1024];

    while (scanf("%d%d", &n, &k) != EOF && n > 0) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
        }
        l = 0;
        r = 1;
        while (r - l > 1e-8) {
            mid = (l + r) / 2;
            for (int i = 0; i < n; i++) {
                v[i] = a[i] - mid * b[i];
            }
            s = 0;
            sort(v, v + n);
            for (int i = k; i < n; i++) {
                s += v[i];
            }
            if (s >= 0) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        printf("%.0lf\n", 100 * l);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1750214   2009-01-28 15:39:23     Accepted    3068    C++     80  192     watashi@Zodiac

// 2012-09-07 01:59:47 | Accepted | 3068 | C++ | 70 | 196 | watashi | Source
