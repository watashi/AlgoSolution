// answer := harmonic number

#include <cmath>
#include <cstdio>

// Concrete Mathematics
// http://mathworld.wolfram.com/HarmonicNumber.html
double H(int n)
{
    static const double gamma=0.577215664901532860606512090082402431042;    // Euler-Mascheroni Constant
    // Hn = gamma + phi0(n + 1) // Digamma Function

    // Euler-Maclaurin Integration Formulas
    return gamma + log(n)
        + 1 / (2.0 * n)
        - 1 / (12.0 * n * n)
        + 1 / (120.0 * n * n * n * n)
        - 1 / (252.0 * n * n * n * n * n * n);
    // http://www.research.att.com/~njas/sequences/A006953
    // Denominator of Bernoulli(2n)/2n.      12, 120, 252, 240, 132, 32760, 12, 8160, 14364, 6600, 276, 65520, 12, 3480, 85932, 16320, 12, 69090840, 12, 541200, 75852, 2760, 564, 2227680, 132, 6360, 43092, 6960, 708, 3407203800, 12, 32640, 388332, 120, 9372, 10087262640
    // delta = epsilon / (240 * n ^ 8)
}

double h[1024];

int main(void)
{
    int n;

    h[0] = 0;
    for (int i = 1; i < 1024; i++) {
        h[i] = h[i - 1] + 1.0 / i;
    }
    while (scanf("%d", &n) != EOF) {
        printf("%.8lf\n", (n < 1024) ? h[n] : H(n));
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//3021711 2008-08-04 21:10:47 Accepted 2766 C++ 00:00.09 408K Re:ReJudge
//

// 2012-09-07 01:38:37 | Accepted | 2766 | C++ | 30 | 188 | watashi | Source
