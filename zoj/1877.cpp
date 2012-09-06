#include <cstdio>
#include <algorithm>
using namespace std;

int a[1001];

int main(void)
{
    int n, x, t;

    while(scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        if(n == 0)
            printf("0\n");
        else if(n == 1)
            printf("%d\n%d\n", a[0], a[0]);
        else {
            x = a[1] + a[1] - a[0];
            x = upper_bound(a, a + n, x) - a;
            if((n - x) & 1) ++x;
            if(n & 1) {
                t = a[0] + a[1] + a[2];
                t += (x - 3) * a[0];
                for (int i = 3; i < x; ++i)
                    t += a[i];
                t += (n - x) / 2 * (a[0] + a[1] + a[1]);
                for (int i = x; i < n; i += 2)
                    t += a[i + 1];
                printf("%d\n", t);
                for (int i = n; i > x; i -= 2)
                    printf("%d %d\n%d\n%d %d\n%d\n", a[0], a[1], a[0], a[i - 1], a[i - 2], a[1]);
                for (int i = x; i > 3; --i)
                    printf("%d %d\n%d\n", a[0], a[i - 1], a[0]);
                printf("%d %d\n%d\n%d %d\n", a[1], a[0], a[0], a[0], a[2]);
            }
            else {
                t = a[1];
                t += (x - 2) * a[0];
                for (int i = 2; i < x; ++i)
                    t += a[i];
                t += (n - x) / 2 * (a[0] + a[1] + a[1]);
                for (int i = x; i < n; i += 2)
                    t += a[i + 1];
                printf("%d\n", t);
                for (int i = n; i > x; i -= 2)
                    printf("%d %d\n%d\n%d %d\n%d\n", a[0], a[1], a[0], a[i - 1], a[i - 2], a[1]);
                for (int i = x; i > 2; --i)
                    printf("%d %d\n%d\n", a[0], a[i - 1], a[0]);
                printf("%d %d\n", a[0], a[1]);
            }
        }
    }

    return 0;
}

//2796810 2008-03-22 15:42:31 Accepted 1877 C++ 00:00.01 440K ¤ï¤¿¤·

// 2012-09-07 01:03:59 | Accepted | 1877 | C++ | 0 | 184 | watashi | Source
