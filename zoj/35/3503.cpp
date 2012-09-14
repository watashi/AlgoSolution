#include <cstdlib> // auto fix CE
#include <cmath>
#include <cstdlib> // auto fix CE
#include <cstdio>
#include <cstdlib> // auto fix CE
#include <vector>
#include <cstdlib> // auto fix CE
#include <cassert>
#include <cstdlib> // auto fix CE
#include <numeric>
#include <cstdlib> // auto fix CE
#include <algorithm>

using namespace std;

const double EPS = 1e-6;

struct Matrix {
    int n;
    double a[5][5];
    double* operator[](int i) { return a[i]; }
} e, E;

int rank(Matrix a, double& d) {
    d = 1;
    for (int k = 0; k < a.n; ++k) {
        int ii = k, jj = k;
        for (int i = k; i < a.n; ++i) {
            for (int j = k; j < a.n; ++j) {
                if (fabs(a[i][j]) > fabs(a[ii][jj])) {
                    ii = i;
                    jj = j;
                }
            }
        }

        if (ii != k) {
            d = -d;
            for (int j = 0; j < a.n; ++j) {
                swap(a[k][j], a[ii][j]);
            }
        }
        if (jj != k) {
            d = -d;
            for (int i = 0; i < a.n; ++i) {
                swap(a[i][k], a[i][jj]);
            }
        }
/*
for (int i = 0; i < a.n; ++i) {
    for (int j = 0; j < a.n; ++j) {
        printf("%f ", a[i][j]);
    }
    puts("");
}
puts("");
*/
        if (fabs(a[k][k]) < EPS) {
            d = 0;
            return k;
        } else {
            d *= a[k][k];
        }
        for (int i = k + 1; i < a.n; ++i) {
            a[i][k] /= a[k][k];
            for (int j = k + 1; j < a.n; ++j) {
                a[i][j] -= a[i][k] * a[k][j];
            }
        }
    }
    return a.n;
}

inline double eval(int n, double c[], double x) {
    double y = c[0];
    for (int i = 1; i < n; ++i) {
        y = y * x + c[i];
    }
    return y;
}

bool gao(int n, double c[]) {
    double l = -1, r = 1, m;
    while (eval(n, c, l) > 0) {
        l *= 2;
    }
    while (eval(n, c, r) < 0) {
        r *= 2;
    }
    for (int loop = 0; loop < 64; ++loop) {
//  while (r - l > EPS) {
        m = (l + r) / 2;
        if (eval(n, c, m) < 0) {
            l = m;
        } else {
            r = m;
        }
    }
    m = (l + r) / 2;

    for (int i = 1; i < n; ++i) {
        c[i] += c[i - 1] * m;
    }
    assert(c[0] == 1);
    assert(fabs(c[n - 1]) < EPS);

    if (fabs(c[2]) < EPS) {
        return fabs(m) < EPS || fabs(c[1]) < EPS || m * c[1] < 0;
    } else {
        return c[2] > 0 && (fabs(m) < EPS || m * c[1] < 0);
    }
}

int main() {
    int re, rho3, rho4;
    double c[10], a[4], delta;
    Matrix m;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        for (int i = 0; i < 10; ++i) {
            assert(scanf("%lf", &c[i]) == 1);
            assert(fabs(c[i]) <= 1000);
        }
        assert(fabs(c[0]) + fabs(c[1]) + fabs(c[2]) > 1e-4);

        m.n = 3;
        m[0][0] = c[0];
        m[1][1] = c[1];
        m[2][2] = c[2];
        m[0][1] = m[1][0] = c[5];
        m[0][2] = m[2][0] = c[4];
        m[1][2] = m[2][1] = c[3];
        rho3 = rank(m, delta);

        m.n = 4;
        m[3][3] = c[9];
        m[0][3] = m[3][0] = c[6];
        m[1][3] = m[3][1] = c[7];
        m[2][3] = m[3][2] = c[8];
        rho4 = rank(m, delta);

        a[0] = 1;
        a[1] = c[0] + c[1] + c[2];
        a[2] = c[0] * c[1] + c[1] * c[2] + c[2] * c[0]
            - c[3] * c[3] - c[4] * c[4] - c[5] * c[5];
        a[3] = c[0] * c[1] * c[2] + 2 * c[3] * c[4] * c[5]
            - c[0] * c[3] * c[3] - c[1] * c[4] * c[4] - c[2] * c[5] * c[5];

//      printf("%d %d %lf\n", rho3, rho4, delta);
        switch (rho3) {
            case 1:
                switch (rho4) {
                    case 1:
                        puts("coincident planes");
                        break;
                    case 2:
                        puts("parallel planes (imaginary or real)");
                        break;
                    case 3:
                        puts("parabolic cylinder");
                        break;
                    default:
                        assert(false);
                }
                break;
            case 2:
                switch (rho4) {
                    case 2:
                        printf("intersecting planes (%s)\n", gao(4, a) ? "imaginary" : "real");
                        break;
                    case 3:
                        if (gao(4, a)) {
                            puts("elliptic cylinder (imaginary or real)");
                        } else {
                            puts("hyperbolic cylinder");
                        }
                        break;
                    case 4:
                        puts(delta > 0 ? "hyperbolic paraboloid" : "elliptic paraboloid");
                        break;
                    default:
                        assert(false);
                }
                break;
            case 3:
                switch (rho4) {
                    case 3:
                        printf("elliptic cone (%s)\n", gao(4, a) ? "imaginary" : "real");
                        break;
                    case 4:
                        if (gao(4, a)) {
                            printf("ellipsoid (%s)\n", delta > 0 ? "imaginary" : "real");
                        } else {
                            puts(delta > 0 ? "hyperboloid of one sheet" : "hyperboloid of two sheets");
                        }
                        break;
                    default:
                        assert(false);
                }
                break;
            default:
                assert(false);
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//728   2011-04-22 17:02:29     Accepted    D   C++     100     180     watashi@ArcOfDream  Source

// 2012-09-07 16:02:48 | Accepted | 3503 | C++ | 80 | 180 | watashi | Source
