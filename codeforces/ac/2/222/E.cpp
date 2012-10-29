#include <cstdio>
#include <algorithm>

using namespace std;

int c2i(char ch) {
    if (islower(ch)) {
        return ch - 'a';
    } else {
        return ch - 'A' + 26;
    }
}

const int MAXN = 64;
const long long MOD = 1000000007;

typedef long long Mat[MAXN][MAXN];

void cpy(int n, const Mat a, Mat b) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            b[i][j] = a[i][j];
        }
    }
}

void mul(int n, const Mat a, const Mat b, Mat ret) {
    static Mat c;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            c[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    cpy(n, c, ret);
}

void pow(int n, const Mat& a, long long b, Mat ret) {
    static Mat c;
    cpy(n, a, c);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ret[i][j] = i == j ? 1 : 0;
        }
    }
    while (b > 0) {
        if (b & 1) {
            mul(n, c, ret, ret);
        }
        mul(n, c, c, c);
        b >>= 1;
    }
}

int main() {
    int n, k;
    char rule[80];
    long long m;
    static Mat a;

    scanf("%I64d%d%d", &m, &n, &k);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = 1;
        }
    }
    for (int i = 0; i < k; ++i) {
        scanf("%s", rule);
        a[c2i(rule[1])][c2i(rule[0])] = 0;
    }
    pow(n, a, m - 1, a);
    m = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            m += a[i][j];
        }
    }
    printf("%I64d\n", m % MOD);

    return 0;
}

