#include <cmath>
#include <cstdio>

using namespace std;

int main() {
    int n;
    double z;

    while (scanf("%d%lf", &n, &z) != EOF) {
        printf("%.6le\n", yn(n, z));
    }

    return 0;
}

// 2012-09-07 15:56:22 | Accepted | 3443 | C++ | 120 | 180 | watashi | Source
