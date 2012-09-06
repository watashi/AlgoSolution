#include <cstdio>

const double g = 9.81;
const double Ekmin = 0.00;

int main(void)
{
    double k, l, s, w;
    while(scanf("%lf%lf%lf%lf", &k, &l, &s, &w) != EOF && (k > 0 || l > 0 || s > 0 || w > 0)) {
        double Epg, Epk, Ek, Ekmax;
        Epg = g * w * s;
        Epk = (l < s) ? (k * (s - l) * (s - l) / 2.0) : 0;
        Ek = Epg - Epk;
        Ekmax = w * 10.0 * 10.0 / 2.0;
        if(Ek < Ekmin) puts("Stuck in the air.");
        else if(Ek > Ekmax) puts("Killed by the impact.");
        else puts("James Bond survives.");
    }
    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2748823 2008-02-11 22:15:49 Accepted 2557 C++ 00:00.00 392K ¤ï¤¿¤·

// 2012-09-07 01:28:17 | Accepted | 2557 | C++ | 0 | 180 | watashi | Source
