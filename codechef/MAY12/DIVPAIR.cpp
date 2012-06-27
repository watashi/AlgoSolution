#include <cstdio>
#include <algorithm>

long long sum(long long a, long long d, long long n) {
    return n * a + n * (n - 1) / 2 * d;
}

int main() {
    int re, n, m, a, b;
    long long s = 0;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d%d", &n, &m);
        a = (1 + n) / m;
        b = (n + n) / m;
        s = 0;
        s += sum(m - 1, m, a);
        s += sum((2 * n + 1 - b * m), m, b - a);
        if (m % 2 == 0) {
            m /= 2;
        }
        s -= n / m;
        printf("%lld\n", s / 2);
    }

    return 0;
}

//Correct Answer
//Execution Time: 0.45
