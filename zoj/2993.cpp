// @@
// 怎么可能都看不懂题目

#include <cmath>
#include <cstdio>

const double PI = acos(-1.0);

int main(void)
{
    int re;
    double D, L, HA, HB, ERR;
    double a1, a2, a3, a4;
    double ha, hb;

    scanf("%d", &re);
    scanf("%lf%lf%lf%lf%lf", &D, &L, &HA, &HB, &ERR);
    for (int ri = 1; ri <= re; ri++) {
        scanf("%lf%lf%lf%lf", &a1, &a2, &a3, &a4);
        printf("%d ", ri);
        a4 = 180 - a4;
        if (a1 <= 0 || a1 >= 90 || a2 <= 0 || a2 >= 90 || a3 <= 0 || a3 >= 90 || a4 <= 0 || a4 >= 90) {
            printf("DISQUALIFIED\n");
        }
        else {
            a1 *= PI / 180;
            a2 *= PI / 180;
            a3 *= PI / 180;
            a4 *= PI / 180;
            ha = HA + D * sin(a4) / sin(PI - a3 - a4) * tan(a1);
            hb = HB + D * sin(a3) / sin(PI - a3 - a4) * tan(a2);
            if (fabs(ha - hb) > ERR) {
                printf("ERROR\n");
            }
            else {
                printf("%.0lf\n", (ha + hb) / 2.0);
            }
        }
    }

    return 0;
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2950517   2008-06-15 22:45:17     Accepted    2993    C++     00:00.00    404K    Re:ReJudge

// 2012-09-07 01:53:10 | Accepted | 2993 | C++ | 0 | 180 | watashi | Source
