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
    for (int n = 1; n <= 100; ++n) {
        for (int R = 1; R <= 1000; ++R) {
            for (int r = 2; r <= 1000; ++r) {
                if (!gao(n, R, r) && gao(n, R, r - 1)) {
                    printf("%d %d %d\n", n, R, r - 1);
                    printf("%d %d %d\n", n, R, r);
                    break;
                }
            }
        }
    }

    return 0;
}

