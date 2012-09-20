#include <cstdio>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

const int MAXL = 5;
const int MAXN = 218;
const long long MOD = 1000000007LL;

long long f[MAXN], c[MAXN][MAXN], x[MAXN];
long long ten[MAXL * MAXN];

void init() {
    f[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        f[i] = f[i - 1] * i % MOD;
    }

    for (int i = 0; i < MAXN; ++i) {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            if (c[i][j] >= MOD) {
                c[i][j] -= MOD;
            }
        }
    }

    for (int i = 0; i < MAXN; ++i) {
        x[i] = 0;
        for (int j = 0; j <= i; ++j) {
            x[i] = (x[i] + c[i][j] * f[j]) % MOD;
        }
    }

    ten[0] = 1;
    for (int i = 1; i < MAXL * MAXN; ++i) {
        ten[i] = ten[i - 1] * 10 % MOD;
    }
}

int a[MAXN];

int main() {
    int n, t, s[MAXL];
    vector<int> v[MAXL];

    init();
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t);
        v[upper_bound(ten, ten + MAXN, t) - ten].push_back(t);
    }
    for (int i = 0; i < MAXL; ++i) {
        s[i] = accumulate(v[i].begin(), v[i].end(), 0LL);
    }

    int i[MAXL];
    long long ans = 0;

#define FOR_I(k) for (i[k] = 0; i[k] <= (int)v[k].size(); ++i[k])
    FOR_I(0) FOR_I(1) FOR_I(2) FOR_I(3) FOR_I(4) {
        int z = 0, nz = 0, sz = 0, len = 0;
        for (int k = 0; k < MAXL; ++k) {
            sz += i[k];
            nz += (int)v[k].size() - i[k];
            len += max(k, 1) * i[k];
        }
        z = (int)v[0].size() - i[0];
        nz -= z + 1;
        if (nz < 0) {
            continue;
        }
        for (int k = 1; k < MAXL; ++k) {
            if (i[k] < (int)v[k].size()) {
                long long cnt = f[sz];
                for (int kk = 0; kk < MAXL; ++kk) {
                    cnt = cnt * c[v[kk].size() - (kk == k ? 1 : 0)][i[kk]] % MOD;
                }
                if (nz > 0) {
                    cnt = cnt * (nz * x[nz - 1 + z] % MOD + 1) % MOD;
                }
                ans = (ans + s[k] * ten[len] % MOD * cnt) % MOD;
            }
        }
    }
#undef FOR_I
    printf("%lld\n", ans % MOD);

    return 0;
}

//Run# 	Author 	Problem 	Status 	Lang 	Time 	Memory 	Code 	Submission Date
//#490567 	watashi 	2436 	: Accepted 	C++ 	00:75 sec 	1440 KB 	2234 Bytes 	Fri Sep 21 00:00:54

