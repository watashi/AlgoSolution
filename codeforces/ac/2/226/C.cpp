#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const long long MAXN = 1 << 20;

struct Mat {
    long long a[2][2];
    Mat() { fill(a[0], a[2], 0); }
};

Mat mul(const Mat& a, const Mat& b, long long m) {
    Mat c;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                c.a[i][j] = (c.a[i][j] + a.a[i][k] * b.a[k][j]) % m;
            }
        }
    }
    return c;
}

Mat pow(Mat a, long long b, long long m) {
    Mat c;
    c.a[0][0] = c.a[1][1] = 1;
    while (b > 0) {
        if (b & 1) {
            c = mul(a, c, m);
        }
        a = mul(a, a, m);
        b >>= 1;
    }
    return c;
}

long long fib(long long k, long long m) {
    Mat a;
    a.a[0][0] = a.a[0][1] = a.a[1][0] = 1;
    a = pow(a, k, m);
    return a.a[1][0];
}

int main() {
    long long m, l, r, k, d;

    cin >> m >> l >> r >> k;
    d = 1;
    for (long long s = 1; s < MAXN; ++s) {
        long long t = r / (s + k - 1);
        if (s * t >= l) {
            d = max(d, t);
        }
    }
    for (long long t = 1; t < MAXN; ++t) {
        long long s = r / t - (k - 1);
        if (s * t >= l) {
            d = max(d, t);
        }
    }
    // printf("%d\n", (int)d);
    printf("%d\n", (int)fib(d, m));

    return 0;
}

