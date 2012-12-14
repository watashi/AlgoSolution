#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

const double EPS = 1e-8;
const double INF = 1e8;
const int MAXN = 128;

inline double sqr(double x) {
    return x * x;
}

inline double solve(double a, double b, double c) {
    // printf("a=%lf b=%lf c=%lf\n", a, b, c);
    double d = b * b - 4 * a * c;
    if (d < 0) {
        return INF;
    }
    d = sqrt(d);
    double t;
    // printf("t = %lf %lf\n", (-b - d) / a / 2, (-b + d) / a / 2);
    t = (-b - d) / a / 2;
    if (t > 0) {
        return t;
    }
    t = (-b + d) / a / 2;
    if (t > 0) {
        return t;
    }
    return INF;
}

double x[MAXN], y[MAXN], z[MAXN], r[MAXN];

int main() {
    int n, k, kk;
    double x0, y0, z0, dx, dy, dz, t, tt;
    
    // freopen("E.in", "r", stdin);
    while (scanf("%d", &n) != EOF && n > 0) {
        x0 = y0 = z0 = 0;
        scanf("%lf%lf%lf", &dx, &dy, &dz);
        for (int i = 0; i < n; ++i) {
            scanf("%lf%lf%lf%lf", &x[i], &y[i], &z[i], &r[i]);
        }
        kk = -1;
        while (true) {
            k = -1;
            tt = INF;
            for (int i = 0; i < n; ++i) {
                if (i == kk) {
                    continue;
                } 
                t = solve(
                        sqr(dx) + sqr(dy) + sqr(dz),
                        2 * ((x0 - x[i]) * dx + (y0 - y[i]) * dy + (z0 - z[i]) * dz),
                        sqr(x0 - x[i]) + sqr(y0 - y[i]) + sqr(z0 - z[i]) - sqr(r[i])
                        );
                if (t < tt) {
                    tt = t;
                    k = i;
                }
            }
            if (k == -1) {
                break;
            }
            kk = k;
       //     printf("k=%d tt=%lf\n", k, tt);
       //     printf("(%lf, %lf, %lf)->(%lf, %lf, %lf)\n", x0, y0, z0, dx, dy, dz);
            x0 += dx * tt;
            y0 += dy * tt;
            z0 += dz * tt;
            t = -2 * ((x0 - x[k]) * dx + (y0 - y[k]) * dy + (z0 - z[k]) * dz) / r[k] / r[k];
       //     printf("t=%lf\n", t);
            dx += t * (x0 - x[k]);
            dy += t * (y0 - y[k]);
            dz += t * (z0 - z[k]);
       //     printf("=> (%lf, %lf, %lf)->(%lf, %lf, %lf)\n", x0, y0, z0, dx, dy, dz);
        }
        printf("%.4lf %.4lf %.4lf\n", x0, y0, z0);
    }
    
    return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//727370  	2011-01-29 12:30:51 	Accepted	0.008	Minimum	26909	C++	4161 - Spherical Mirrors

/*
id => 1174235
pid => 4161
pname => Spherical Mirrors
status => Accepted
lang => C++
time => 0.012
date => 2012-12-14 17:42:56
*/
