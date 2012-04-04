#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

const double EPS = 1e-8;
const double PI = acos(-1.0);

bool gao(int n, double R, double r) {
    if (r > R) {
        return false;
    } else if (n == 1) {
        return true;
    } else if (r > R / 2) {
        return false;
    } else {
        r = asin(min(1.0, r / (R - r)));
        // printf("%.2lf %.2lf\n", r, n * r);
        return n * r <= PI + EPS;
    }
}

int main() {
    int n;
    double R, r;

    while (scanf("%d%lf%lf", &n, &R, &r) != EOF) {
        puts(gao(n, R, r) ? "YES" : "NO");
    }

    return 0;
}

