#include <cstdio>
#include <algorithm>

using namespace std;

const long long MOD = 1000000007;

template<int N>
struct Matrix {
    long long a[N][N];

    Matrix() {
        fill(a[0], a[N], 0);
    }
};

template<int N>
Matrix<N> operator*(const Matrix<N>& a, const Matrix<N>& b) {
    Matrix<N> c;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                c.a[i][j] = (c.a[i][j] + a.a[i][k] * b.a[k][j]) % MOD;
            }
        }
    }
    return c;
}

template<int N>
Matrix<N> pow(Matrix<N> a, long long b) {
    Matrix<N> c;
    for (int i = 0; i < N; ++i) {
        c.a[i][i] = 1;
    }
    while (b > 0) {
        if (b & 1) {
            c = c * a;
        }
        a = a * a;
        b >>= 1;
    }
    return c;
}

int main() {
    int re;
    long long n;
    Matrix<2> a, c;

    scanf("%d", &re);
    a.a[0][0] = a.a[0][1] = 2;
    a.a[1][0] = 1;
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%lld", &n);
        c = pow(a, n - 1);
        printf("%lld\n", (3 * c.a[1][0] + c.a[1][1]) % MOD);
    }

    return 0;
}

//Correct Answer
//Execution Time: 2.49

