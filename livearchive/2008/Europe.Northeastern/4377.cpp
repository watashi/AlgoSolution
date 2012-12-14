#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1024;

long long ceil(long long a, long long b) {
    return (a + b - 1) / b;
}

long long gao(long long a[], long long b[]) {
    return max(ceil(a[0], b[0]), ceil(a[2], b[2])) *
        max(ceil(a[1], b[1]), ceil(a[3], b[3]));
}

int main() {
    int n;
    long long a[5], b[5], c[5], ans;

    while (scanf("%lld%lld%lld%lld", &a[0], &a[1], &a[2], &a[3]) == 4) {
        scanf("%d", &n);
        b[0] = a[1];
        b[1] = a[0];
        b[2] = a[3];
        b[3] = a[2];
        ans = 0x7f7f7f7f7f7f7f7fLL;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 5; ++j) {
                scanf("%lld", &c[j]);
            }
            ans = min(ans, c[4] * gao(a, c));
            ans = min(ans, c[4] * gao(b, c));
        }
        printf("%lld\n", ans);
    }
}
//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//727391  	2011-01-29 13:11:39 	Accepted	0.002	Minimum	26909	C++	4377 - Giant Screen
/*
id => 1174313
pid => 4377
pname => Giant Screen
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:53:03
*/
