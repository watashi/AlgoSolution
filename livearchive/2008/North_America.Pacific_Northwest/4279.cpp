#include <cstdio>

const int MAXN = 1024;

long long s[MAXN];

int main() {
    int re, n;

    s[0] = 0;
    for (int i = 1; i < MAXN; ++i) {
        s[i] = s[i - 1] + i;
    }
    for (int i = 1; i < MAXN; ++i) {
        s[i] += s[i - 1];
    }
//    freopen("a.in", "r", stdin);
    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d", &n);
        printf("%d: %d %lld\n", ri, n, s[n]);
    }

    return 0;
}
//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
// 727362  	2011-01-29 12:21:06 	Accepted	0.002	Minimum	26909	C++	4279 - Cannonball Pyramids
/*
id => 1174033
pid => 4279
pname => Cannonball Pyramids
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:13:04
*/
