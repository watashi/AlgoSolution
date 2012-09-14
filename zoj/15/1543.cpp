// easy
// 通过表达式可证明
// 不过要最大值则不易求了

#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

double a[1024];

int main(void)
{
    int n;

    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%lf", &a[i]);
        }
        sort (a, a + n);
        for (int i = n - 1; i > 0; --i) {
            a[i - 1] = 2 * sqrt(a[i - 1] * a[i]);
        }
        printf("%.3lf\n", a[0]);
    }

    return 0;
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2958010   2008-06-28 20:03:57     Accepted    1543    C++     00:00.00    452K    Re:ReJudge

// 2012-09-07 00:53:19 | Accepted | 1543 | C++ | 0 | 188 | watashi | Source
