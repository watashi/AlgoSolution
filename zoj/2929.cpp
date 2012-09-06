//Èç¹ûÈ«0¡­¡­

#include <cstdio>
#include <algorithm>
using namespace std;

const double eps = 1e-8;

double pa[11], pb[11];
struct prob{
    double win, lose, draw;
}first, second, total, res;

void dpit(double p[5], double dp[6][6])
{
    fill(dp[0], dp[6], 0);
    dp[0][0] = 1;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j <= i; j++) {
            dp[i + 1][j + 1] += dp[i][j] * p[i];
            dp[i + 1][j] += dp[i][j] * (1 - p[i]);
        }
    }
}

prob tryit(double pa[5], double pb[5])
{
    double dpa[6][6], dpb[6][6];
    prob res;

    dpit(pa, dpa);
    dpit(pb, dpb);
    res.win = res.lose = res.draw = 0;
    for (int i = 0; i <= 5; i++) {
        for (int j = 0; j < i; j++)
            res.win += dpa[5][i] * dpb[5][j];
        res.draw += dpa[5][i] * dpb[5][i];
        for (int j = i + 1; j <= 5; j++)
            res.lose += dpa[5][i] * dpb[5][j];
    }
    return res;
}

prob doit(int n, double pa[], double pb[])
{
    prob res;

    res.win = res.lose = 0;
    res.draw = 1;
    for (int i = 0; i < n; i++) {
        res.win += res.draw * pa[i] * (1 - pb[i]);
        res.lose += res.draw * (1 - pa[i]) * pb[i];
        res.draw *= pa[i] * pb[i] + (1 - pa[i]) * (1 - pb[i]);
    }
    return res;
}

int main(void)
{
    while(true) {
        for (int i = 0; i < 11; i++) {
            if(scanf("%lf", &pa[i]) == EOF) return 0;
            pa[i] /= 100;
        }
        sort(pa, pa + 11);
        reverse(pa, pa + 11);
        scanf("%lf", &pb[0]);
        pb[0] /= 100;
        for (int i = 1; i < 11; i++)
            pb[i] = pb[0];
        first = tryit(pa, pb);
        second = doit(11 - 5, pa + 5, pb + 5);
        total = doit(11, pa, pb);
        res.win = first.win + second.win * first.draw;
        res.lose = first.lose + second.lose * first.draw;
        res.draw = first.draw * second.draw;
        if(total.win + total.lose < eps) printf("%.4lf\n", 0);
        else {
            res.win += total.win / (1 - total.draw) * res.draw;
            printf("%.4lf\n", 100 * res.win);
        }
    }
    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2762877 2008-02-27 17:28:47 Accepted 2929 C++ 00:00.00 428K ¤ï¤¿¤·

// 2012-09-07 01:48:06 | Accepted | 2929 | C++ | 0 | 180 | watashi | Source
