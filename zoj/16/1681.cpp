#include <cstdio>
#include <algorithm>
using namespace std;

static int a[60] = {};
static int b[110] = {};

int main(void)
{
    int n, ans;

    for (int i = 0; i < 60; i++)
        a[i] = i * i * i;
    for (int i = 0; i < 110; i++)
        b[i] = i * (i + 1) * (i + 2) / 6;
    while(scanf("%d", &n) != EOF && n > 0) {
        ans = 0;
        for (int i = 0; a[i] <= n; i++)
            ans = max(ans, a[i] + *(upper_bound(b, b + 110, n - a[i]) - 1));
        printf("%d\n", ans);
    }

    return 0;
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2840686   2008-04-12 20:40:58     Accepted    1681    C++     00:00.00    440K    Re:ReJudge

// 2012-09-07 00:57:47 | Accepted | 1681 | C++ | 0 | 180 | watashi | Source
