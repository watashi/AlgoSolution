#include <cstdlib> // auto fix CE
#include <algorithm> // auto fix CE
#include <cstdlib> // auto fix CE
#include <cmath>
#include <cstdlib> // auto fix CE
#include <algorithm> // auto fix CE
#include <cstdlib> // auto fix CE
#include <cstdio>

const double EPS = 1e-4;
const int MAXN = 512;

inline bool lt(double a, double b) {
    return a < b - EPS;
}

inline bool gt(double a, double b) {
    return a > b + EPS;
}

inline bool eq(double a, double b) {
    return fabs(a - b) < EPS;
}

int main() {
    int ri = 0, n, p, q;
    bool flag;
    double t, r, dr, tr, alpha, beta, gamma;
    double x[MAXN], y[MAXN];

    while (scanf("%d%lf", &n, &r) != EOF && r > 0) {
        x[0] = y[0] = 0;
        p = 0;
        alpha = -M_PI;
        for (int i = 1; i <= n; ++i) {
            scanf("%lf%lf", &x[i], &y[i]);
        }

        t = 0;
        while (true) {
            // printf("@%d: %lf %lf (%lf)\n", p, alpha, r, t);
            q = -1;
            for (int i = 1; i <= n; ++i) {
                if (i == p) {
                    continue;
                }
                tr = hypot(y[i] - y[p], x[i] - x[p]);
                gamma = atan2(y[i] - y[p], x[i] - x[p]);
                if (!lt(tr, r)) {
                    continue;
                }
                flag = false;
                if (q == -1) {
                    flag = true;    // !eq(gamma, alpha);
                } else if (eq(gamma, beta)) {
                    flag = gt(tr, dr);
                } else if (lt(gamma, alpha)) {
                    flag = lt(beta, alpha) && lt(gamma, beta);
                } else if (gt(gamma, alpha)) {
                    flag = lt(beta, alpha) || lt(gamma, beta);
                }
                if (flag) {
                    q = i;
                    dr = tr;
                    beta = gamma;
                }
            }

            // valid beta?
            flag = false;
            if (gt(y[p] + r, 0)) {  // y[q] < 0
                gamma = asin(-y[p] / r);
                // printf("-> %lf+%lf>0: %lf %lf %lf\n", y[p], r, alpha, beta, gamma);
                if (q == -1 ||
                    (lt(alpha, gamma) && lt(gamma, beta)) ||
                    (gt(alpha, beta) && (gt(gamma, alpha) || lt(gamma, beta)))) {
                    q = -1;
                    beta = gamma;
                    flag = true;
                }
            }
            if (q != -1 || flag) {
                if (lt(alpha, beta)) {
                    t += r * (beta - alpha);
                } else if (lt(beta, alpha)) {   // !!
                    t += r * (beta - alpha + 2 * M_PI);
                } else {
                    // t += 0;
                }
            }
            if (q != -1) {
                p = q;
                r -= dr;
                alpha = beta;
                continue;
            }

            printf("Pendulum #%d\nLength of periodic orbit = ", ++ri);
            printf("%.2lf\n\n", flag ? 2 * t : 2 * M_PI * r);
            break;
        }
    }

    return 0;
}

// ONLY WA TEST CASE #27 @ 1st try
// 3 27.0
// 0 -12
// 3 -8
// 6 -4

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//368   2010-07-06 13:12:03     Accepted    1023    C++     0   180     anotherpeg  Source

// 2012-09-30 23:39:36 | Accepted | 1299 | C++ | 0 | 180 | watashi | Source
