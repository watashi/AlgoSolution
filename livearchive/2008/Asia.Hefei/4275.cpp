#include <cstdio>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int ri = 0;
    long long a, b, c, n, a1, b1, a2, b2, aa, bb;

    while (scanf("%lld%lld%lld", &a, &b, &n) != EOF && n > 0) {
        c = gcd(a, b);
        a /= c;
        b /= c;
        printf("Case %d:", ++ri);
        if (b <= n) {
            printf(" %lld/%lld %lld/%lld\n", a, b, a, b);
            continue;
        }
        a1 = 0;
        b1 = a2 = b2 = 1;
        while (true) {
            aa = a1 + a2;
            bb = b1 + b2;
            if (bb > n) {
                break;
            }
            if (aa * b < a * bb) {
                c = (b1 * a - a1 * b) / (a2 * b - b2 * a);
                c = min(c, (n - b1) / b2);
            //    printf("1 %lld\n", c);
                a1 = a1 + c * a2;
                b1 = b1 + c * b2;
            } else {
                c = (a2 * b - b2 * a) / (b1 * a - a1 * b);
                c = min(c, (n - b2) / b1);
            //    printf("2 %lld\n", c);
                a2 = c * a1 + a2;
                b2 = c * b1 + b2;
            }
        }
        printf(" %lld/%lld %lld/%lld\n", a1, b1, a2, b2);
        // printf(" %.6lf < %.6lf < %.6lf \n", (double)a1 / b1, (double)a / b, (double)a2 / b2);
    }

    return 0;
}
//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//727380  	2011-01-29 12:54:22 	Accepted	0.002	Minimum	26909	C++	4275 - Rational Number Approximation

/*
id => 1174038
pid => 4275
pname => Rational Number Approximation
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:13:44
*/
