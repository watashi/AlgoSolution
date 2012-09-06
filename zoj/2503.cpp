// 考虑dt移动了dt，而两点距离变化矢量的投影为...
// draw a pic, then ...

#include <cmath>
#include <cstdio>

const double pi = acos(-1.0);

int main(void)
{
    int re, n;

    scanf("%d", &re);
    while(re--) {
        scanf("%d", &n);
        printf("%.3lf\n", 1.0 / (1.0 - cos(2.0 * pi / n)));
    }

    return 0;
}
//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2874954   2008-04-27 19:31:32     Accepted    2503    C++     00:00.05    400K    Re:ReJudge

// 2012-09-07 01:25:13 | Accepted | 2503 | C++ | 10 | 180 | watashi | Source
