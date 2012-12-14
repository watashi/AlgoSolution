#include <cstdio>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int re;
    int n;
    long long a, b, c, d, g;
    bool flag;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        flag = true;
        scanf("%d", &n);
        d = 1;
        g = 0;
        for (int i = 0; i < n; ++i) {
            b = 0;
            for (int j = 0; j < 9; ++j) {
                scanf("%lld", &a);
                b += a;
            }
            scanf("%lld", &c);
            d = max(d, c);
            if (flag) {
                if (b < c) {
                    flag = false;
                } else {
                    g = gcd(g, b - c);
                }
            }
        }
        if (g <= d) {
            flag = false;
        }
        if (flag) {
            printf("%lld\n", g);
        } else {
            puts("impossible");
        }
    }

    return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//723955  	2011-01-22 17:24:39 	Accepted	0.328	400	26909	C++	4304 - Transcribed Books

/*
id => 1174116
pid => 4304
pname => Transcribed Books
status => Accepted
lang => C++
time => 0.152
date => 2012-12-14 17:24:53
*/
