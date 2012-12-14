#include <cstdio>

typedef long long P[1024];

long long mod[12];
long long MOD;

void debug(int n, const P p) {
    for (int i = 0; i < n; ++i) {
        printf("%lld%c", p[i], i == n - 1 ? '\n' : ' ');
    }
}


void mul(int n, const P a, const P b, P ret) {
    static P c;
    for (int i = 0; i < n; ++i) {
        c[i] = 0;
        for (int j = 0; j < n; ++j) {
            c[i] += a[j] * b[(i - j + n) % n];
        }
    }
    for (int i = 0; i < n; ++i) {
        ret[i] = c[i] % MOD;
    }
}

void pow(int n, P a, int b, P ret) {
    static P c;
    for (int i = 0; i < n; ++i) {
        c[i] = 0;
    }
    c[0] = 1;
    while (b > 0) {
        if ((b & 1) != 0) {
            mul(n, c, a, c);
        }
        mul(n, a, a, a);
        b >>= 1;
    }
    for (int i = 0; i < n; ++i) {
        ret[i] = c[i] % MOD;
    }
}

int main() {
    int re;
    int n, s, l, r, m;
    long long ans;
    P p, v;

    mod[0] = 1;
    for (int i = 1; i < 12; ++i) {
        mod[i] = mod[i - 1] * 10;
    }
    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d%d%d%d%d", &n, &s, &l, &r, &m);
        MOD = mod[m];
        for (int i = 0; i < n; ++i) {
            scanf("%lld", &v[i]);
            v[i] %= MOD;
        }
        for (int i = 0; i < n; ++i) {
            p[i] = 0;
        }
        p[0] = 1 % MOD;
        p[n - 1] += l % MOD;
        p[1] += r % MOD;
        pow(n, p, s, p);
       // debug(n, p);
        for (int i = 0; i < n; ++i) {
            ans = 0;
            for (int j = 0; j < n; ++j) {
                ans += p[(j - i + n) % n] * v[j];
            }
            printf("%lld%c", ans % MOD, i == n - 1 ? '\n' : ' ');
        }
    }

    return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//723954  	2011-01-22 17:24:23 	Accepted	3.273	428	26909	C++	4303 - Top Secret

/*
id => 1174117
pid => 4303
pname => Top Secret
status => Accepted
lang => C++
time => 0.536
date => 2012-12-14 17:25:22
*/
