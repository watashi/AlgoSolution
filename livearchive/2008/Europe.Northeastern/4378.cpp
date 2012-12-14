#include <cstdio>
#include <cstdlib>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 100100;
long long a[MAXN], l[MAXN], r[MAXN];

int main() {
    int n;
    long long s;

    while (scanf("%d", &n) != EOF) {
        l[0] = r[0] = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%lld", &a[i]);
            l[i] = l[i - 1] - a[i];
            r[i] = r[i - 1] + a[i];
        }
        if (r[n] % 2 == 0) {
            s = 0;
            for (int i = n; i >= 1; --i) {
                // printf("%lld %lld %lld\n", l[i], s, r[i]);
                s -= a[i];
                if (l[i - 1] <= s && s <= r[i - 1]) {
                    a[i] = 1;
                } else {
                    s += a[i] << 1;
                    a[i] = -1;
                }
            }
            puts("Yes");
            for (int i = 1; i <= n; ++i) {
                printf("%lld%c", a[i], i == n ? '\n' : ' ');
            }
        } else {
            puts("No");
        }
    }

    return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//727392  	2011-01-29 13:12:22 	Accepted	0.445	2748	26909	C++	4378 - Hell on the Markets
/*
id => 1174315
pid => 4378
pname => Hell on the Markets
status => Accepted
lang => C++
time => 0.255
date => 2012-12-14 17:53:12
*/
