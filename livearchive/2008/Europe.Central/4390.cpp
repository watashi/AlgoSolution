#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 500500;
int b[MAXN + 1];
int np, p[MAXN];
int s[MAXN], f[MAXN];

int main() {
    fill(b, b + MAXN + 1, -1);
    for (int i = 2; i <= MAXN; ++i) {
        if (b[i] != -1) {
            continue;
        }
        p[np] = i;
        for (int j = i; j <= MAXN; j += i) {
            b[j] = np;
        }
        ++np;
    }
    
    int re;
    int n, k;
    long long ans, m;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d%lld", &n, &m);
        fill(s + 1, s + 1 + n, 1);
        for (int i = 2; i <= n; ++i) {
            scanf("%d", &f[i]);
        }
        for (int i = n; i >= 2; --i) {
            s[f[i]] += s[i];
        }
        fill(f, f + np, 0);
        for (int i = 1; i <= n; ++i) {
            k = i;
            while (k != 1) {
                ++f[b[k]];
                k /= p[b[k]];
            }
        }
        for (int i = 1; i <= n; ++i) {
            k = s[i];
            while (k != 1) {
                --f[b[k]];
                k /= p[b[k]];
            }
        }
        ans = 1;
        for (int i = 0; i < np; ++i) {
            for (int j = 0; j < f[i]; ++j) {
                ans *= p[i];
                ans %= m;
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}


//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//723961  	2011-01-22 17:39:27 	Accepted	3.637	8216	26909	C++	4390 - Counting heaps
/*
id => 1174233
pid => 4390
pname => Counting heaps
status => Accepted
lang => C++
time => 0.779
date => 2012-12-14 17:42:14
*/
