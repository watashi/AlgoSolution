#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 20;
const long long INF = 3123456789123456789LL;

long long a[MAXN];
long double p[MAXN];

long long b[1 << MAXN];
long double pp[1 << MAXN], qq[1 << MAXN];

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    if (a >= INF || b >= INF) {
        return INF;
    } else {
        a /= gcd(a, b);
        return a > INF / b || b > INF / a ? INF : min(INF, a * b);
    }
}

int main() {
    int n;
    long long m;
    long double ans;

    scanf("%d%lld", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%Lf", &p[i]);
        p[i] /= 100;
    }

    b[0] = 1;
    pp[0] = qq[0] = 1;
    for (int i = 1; i < (1 << n); ++i) {
        int j = __builtin_ctz(i);
        b[i] = lcm(b[i ^ (1 << j)], a[j]);
        pp[i] = pp[i ^ (1 << j)] * p[j];
        qq[i] = qq[i ^ (1 << j)] * (1 - p[j]);
    }
    for (int i = 0; i < (1 << n); ++i) {
        b[i] = m / b[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < (1 << n); ++j) {
            if (j & (1 << i)) {
                b[j] = llabs(b[j ^ (1 << i)] - b[j]);
            }
        }
    }

    ans = 0.0;
    for (int i = 0; i < (1 << n); ++i) {
        ans += pp[i] * qq[((1 << n) - 1) ^ i] * (m - b[i]);
        // printf("%Lf %Lf %lld\n", pp[i], qq[((1 << n) - 1) ^ i], b[i]);
    }
    printf("%.12Lf\n", ans);

    return 0;
}

//Run# 	Author 	Problem 	Status 	Lang 	Time 	Memory 	Submission Date
//#486754 	watashi 	G 	: Accepted 	C++ 	00:09 sec 	42052 KB 	Sun Sep 16 16:27:39

//Run# 	Author 	Problem 	Status 	Lang 	Time 	Memory 	Code 	Submission Date
//#489399 	watashi 	2446 	: Accepted 	C++ 	00:10 sec 	42052 KB 	1692 Bytes 	Wed Sep 19 16:40:42

