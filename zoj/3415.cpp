#include <algorithm> // auto fix CE
#include <cstdio>
#include <algorithm> // auto fix CE
#include <utility>

using namespace std;

typedef pair<double, double> PDD;
const PDD ONE = make_pair(0.0, 1.0);

PDD operator*(double lhs, const PDD& rhs) {
    return make_pair(lhs * rhs.first, lhs * rhs.second);
}

PDD operator+(const PDD& lhs, const PDD& rhs) {
    return make_pair(lhs.first + rhs.first, lhs.second + rhs.second);
}

PDD operator-(const PDD& lhs, const PDD& rhs) {
    return make_pair(lhs.first - rhs.first, lhs.second - rhs.second);
}

int main() {
    int n, m;
    double p, q;
    PDD a, b, c;

    while (scanf("%d%d", &n, &m) != EOF) {
        q = 1.0 / m;
        p = 1 - q;

        if (n < 100) {
            a = PDD(1, 0);
            b = PDD(1, -1 / p);
            // printf("%d: %lf %lf\n", n, a.first, a.second);
            for (int i = n - 1; i >= 1; --i) {
                // printf("%d: %lf %lf\n", i, b.first, b.second);
                c = (-1 / p) * (q * a - b + ONE);
                a = b;
                b = c;
            }
            // printf("%d: %lf %lf\n", 0, b.first, b.second);
            printf("%.10lf\n", -b.second / b.first);
        } else if (m == 2) {
            printf("%.10lf\n", 1.0 * n * (n + 1));
        } else {
            printf("%.10lf\n", 1.0 * m * n / (m - 2) - 1.0 * m / (m - 2) / (m - 2));
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//587   2010-07-16 19:52:28     Accepted    1075    C++     10  180     anotherpeg  Source

// 2012-09-07 15:53:39 | Accepted | 3415 | C++ | 0 | 180 | watashi | Source
