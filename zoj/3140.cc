// «¯º‰Õº œ“Õº

#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int re, n, m, tmp, ans;
    static int x[5000];

    scanf("%d", &re);
    while (re--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++) {
            scanf("%d", &x[i]);
        }
        sort(x, x + n);
        tmp = ans = 1;
        for (int i = 1; i < n; i++) {
            if (tmp > 1 && x[i - 2] + m >= x[i]) {
                ++tmp;
            }
            else if (x[i - 1] + m >= x[i]) {
                tmp = 2;
            }
            else {
                tmp = 1;
            }
            // ans >?= tmp;
            ans = max(ans, tmp);
        }
        printf("%d\n", ans);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1750167   2009-01-28 15:02:45     Accepted    3140    C++     90  196     watashi@Zodiac

// 2012-09-07 02:03:03 | Accepted | 3140 | C++ | 80 | 200 | watashi | Source
