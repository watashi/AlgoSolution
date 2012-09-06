#include <cstdio>
#include <algorithm>

using namespace std;

int c[200];

int main(void)
{
    int re, n, f, t;

    scanf("%d", &re);
    while (re--) {
        fill(c, c + 200, 0);
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &f, &t);
            f = (f - 1) / 2;
            t = (t - 1) / 2;
            if (f > t) {
                swap(f, t);
            }
            for (int j = f; j <= t; j++) {
                ++c[j];
            }
        }
        printf("%d\n", *max_element(c, c + 200) * 10);
    }

    return 0;
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2958242   2008-06-29 02:27:29     Accepted    1029    C++     00:00.01    444K    Re:ReJudge

// 2012-09-07 00:33:25 | Accepted | 1029 | C++ | 0 | 180 | watashi | Source
