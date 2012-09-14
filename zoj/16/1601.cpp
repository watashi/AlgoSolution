// 这么高的AC数估计是枚举过的-_-b

#include <cstdio>

int main(void)
{
    double a;
    int l;
    int an, ad, bn, bd, cn, cd;

    while (scanf("%lf%d", &a, &l) != EOF) {
        an = 0;
        ad = 1;
        bn = 1;
        bd = 0;
        while (true) {
            cn = an + bn;
            cd = ad + bd;
            if (cn > l || cd > l) {
                break;
            }
            else if (a <= 1.0 * cn / cd) {
                bn = cn;
                bd = cd;
            }
            else {
                an = cn;
                ad = cd;
            }
        }
        if (a - 1.0 * an / ad <= 1.0 * bn / bd - a) {
            printf("%d %d\n", an, ad);
        }
        else {
            printf("%d %d\n", bn, bd);
        }
    }

    return 0;
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2958036   2008-06-28 20:42:32     Accepted    1601    C++     00:00.00    388K    Re:ReJudge

// 2012-09-07 00:55:27 | Accepted | 1601 | C++ | 0 | 180 | watashi | Source
