#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

const double EPS = 1e-8;
const double PI = acos(-1.0);

bool gao(int n, double R, double r) {
    double rest = R - r;
    long double ra = 2 * r / (long double)(2 * sin(PI / n));
    if (rest >= 0 && n == 1) return true;
    if (ra - rest > 1e-10) return false;
    if (2 * r > R) return false;
}

int main() {
    int n;
    double R, r;

    while (scanf("%d%lf%lf", &n, &R, &r) != EOF) {
        puts(gao(n, R, r) ? "YES" : "NO");
    }

    return 0;
}

