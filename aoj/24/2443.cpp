#include <queue>
#include <cstdio>
#include <algorithm>

using namespace std;

const int FACT[11] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};
const int MAXN = 3628800;

int encode(int n, const int a[]) {
    int m = (1 << n) - 1, k = 0;
    for (int i = 0; i < n; ++i) {
        k += __builtin_popcount(m & ((1 << a[i]) - 1)) * FACT[n - 1 - i];
        m ^= 1 << a[i];
    }
    return k;
}

void decode(int n, int k, int a[]) {
    bool b[32];
    fill(b, b + n, true);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; ; ++j) {
            if (b[j]) {
                if (k < FACT[n - 1 - i]) {
                    a[i] = j;
                    b[j] = false;
                    break;
                } else {
                    k -= FACT[n - 1 - i];
                }
            }
        }
    }
}

template<int MAXD>
void gao(int n, int s, int d[]) {
    static int a[32];
    queue<int> q;

    fill(d, d + FACT[n], -1);
    d[s] = 0;
    q.push(s);
    while (!q.empty()) {
        s = q.front();
        q.pop();
        decode(n, s, a);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                reverse(a + i, a + j);
                int t = encode(n, a);
                if (d[t] == -1) {
                    d[t] = d[s] + 1;
                    if (d[t] < MAXD) {
                        q.push(t);
                    }
                }
                reverse(a + i, a + j);
            }
        }
    }
}

int ds[MAXN], dt[MAXN];

int main() {
    int n, a[32];

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        --a[i];
    }
    gao<4>(n, encode(n, a), ds);
    gao<4>(n, 0, dt);

    int ans = 9;

    for (int i = 0; i < FACT[n]; ++i) {
        if (ds[i] != -1 && dt[i] != -1) {
            ans = min(ans, ds[i] + dt[i]);
        }
    }
    printf("%d\n", ans);

    return 0;
}

//Run# 	Author 	Problem 	Status 	Lang 	Time 	Memory 	Code 	Submission Date
//#489455 	watashi 	2443 	: Accepted 	C++ 	00:33 sec 	29504 KB 	1912 Bytes 	Wed Sep 19 17:38:05
//#489454 	watashi 	2443 	: Accepted 	C++ 	03:16 sec 	30304 KB 	1913 Bytes 	Wed Sep 19 17:37:15

