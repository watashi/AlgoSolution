#include <cstdio>

template<int N>
struct Fibonacii {
    long long a[N];
    Fibonacii() {
        a[0] = 0;
        a[1] = 1;
        for (int i = 2; i < N; ++i) {
            a[i] = a[i - 1] + a[i - 2];
        }
    }
    long long operator[](int i) const {
        return a[i];
    }
};

Fibonacii<64> fib;

int main() {
    long long m, n, l;

    while (scanf("%lld%lld", &m, &n) != EOF) {
        l = 1;
        for (int i = 3; fib[i] <= m || fib[i] <= n; ++i) {
            if (m % fib[i] == 0 || n % fib[i] == 0) {
                l = fib[i];
            }
        }
        printf("%lld\n\n", m * n - m * n / l);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//2117119   2010-03-18 23:06:02     Accepted    2705    C++     0   176     watashi@Zodiac

// 2012-09-07 15:44:40 | Accepted | 2705 | C++ | 0 | 180 | watashi | Source
