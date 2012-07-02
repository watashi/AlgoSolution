#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

const double EPS = 1e-8;

double yy(double x, double y, double d, double xx, bool flag) {
    double dx = cos(d);
    double dy = sin(d);
    if (fabs(dx) > EPS && (xx - x) / dx > EPS) {
        return y + (xx - x) / dx * dy;
    } else {
        return y;
    }
}

double rr() {
    return 0.8 * rand() / RAND_MAX - 0.4;
}

void adjust(double d1, double d2, double e1, double e2, double& d, double& e) {
    if (d1 > d2) {
        swap(d1, d2);
    }
    if (d2 > d1 + M_PI) {
        d2 -= 2 * M_PI;
        swap(d1, d2);
    }
    double l = max(d1 - e1, d2 - e2);
    double r = min(d1 + e1, d2 + e2);
    d = (l + r) / 2;
    e = (r - l) / 2;
}

int main() {
    double w, h, ee, x, y, d, e;
    double x1, y1, x2, y2, d1, d2, dx, dy;
    int m = 200;

    scanf("%lf%lf%lf", &w, &h, &ee);
    x1 = -w;
    x2 = w;
    y1 = -h;
    y2 = h;
    ee = ee / 180 * M_PI;
    while (m > 0) {
        x = (x1 + x2) / 2.0 + rr() * (x2 - x1);
        y = (y1 + y2) / 2.0 + rr() * (y2 - y1);
        --m;
        printf("? %.12f %.12f\n", x, y);
        fflush(stdout);
        scanf("%lf", &d1);
        d1 = d1 / 180 * M_PI;
        d = d1;
        e = ee;
        while (m > 0 && e > M_PI / 2) {
            --m;
            printf("? %.12f %.12f\n", x, y);
            fflush(stdout);
            scanf("%lf", &d1);
            d1 = d1 / 180 * M_PI;
            adjust(d1, d, ee, e, d, e);
        }
        if (e > M_PI / 2) {
            break;
        }
        dx = cos(d);
        dy = sin(d);
        if (dx > EPS) {
            x1 = max(
                min(yy(y, x, M_PI / 4 - (d - e), y1, true),
                    yy(y, x, M_PI / 4 - (d + e), y2, true)),
                x1);
            x1 = min(x1, x);
        } else if (dx < -EPS) {
            x2 = min(
                max(yy(y, x, M_PI / 4 - (d + e), y1, false),
                    yy(y, x, M_PI / 4 - (d - e), y2, false)),
                x2);
            x2 = max(x2, x);
        }
        if (dy > EPS) {
            y1 = max(
                min(yy(x, y, d + e, x1, true),
                    yy(x, y, d - e, x2, true)),
                y1);
            y1 = min(y1, y);
        } else if (dy < -EPS) {
            y2 = min(
                max(yy(x, y, d - e, x1, false),
                    yy(x, y, d + e, x2, false)),
                y2);
            y2 = max(y2, y);
        }
        // printf("[%lf %lf] [%lf %lf]\n", x1, x2, y1, y2);
    }
    x = (x1 + x2) / 2.0;
    y = (y1 + y2) / 2.0;
    printf("! %.12f %.12f\n", x, y);
    fflush(stdout);

    return 0;
}
