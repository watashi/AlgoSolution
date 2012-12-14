#include <set>
#include <cstdio>

using namespace std;

long long x, n, r;

long long extGcd(long long a, long long b, long long& x, long long& y) {
    long long t, ret;
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    ret = extGcd(b, a % b, x, y);
    t = x;
    x = y;
    y = t - a / b * y;
    return ret;
}

long long mod(long long a, long long m) {
    a %= m;
    return a < 0 ? a + m : a;
}

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

void solve(long long a1, long long a2, long long m1, long long m2, set<long long>& ans) {
    long long m = lcm(m1, m2), c = gcd(m1, m2), p, q, z;
    a1 = mod(a1, m1);
    a2 = mod(a2, m2);
   // printf("[%lld%%%lld %lld%%%lld %lld]", a1, m1, a2, m2, c);
    if ((a1 - a2) % c != 0) {
   //     puts("x");
        return;
    }
    extGcd(m2 / c, m1 / c, p, q);
    z = (a1 - a2) / c * p;
    x = mod(a2 + m2 * z, m);
    while (x < n) {
   //     printf(" %lld", x);
        ans.insert((r + x) % n);
        x += m;
    }
   // puts("");
}

int main() {
    int ri = 0;
    set<long long> ans;

/*    for (long long i = 0; i < 362880; ++i) {
        if (i * i % 362880 == 1) {
            printf(" %lld", i);
        }
    }
    puts("");
*/    while (scanf("%lld%lld%lld", &x, &n, &r) != EOF && n > 0) {
        ans.clear();
        ans.insert(r);
        ans.insert(mod(-r, n));
        for (long long i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                solve(0, -2 * r, i, n / i, ans);
                solve(0, -2 * r, n / i, i, ans);
            }
        }
        printf("Case %d:", ++ri);
        for (set<long long>::const_iterator it = ans.begin(); it != ans.end(); ++it) {
            printf(" %lld", *it);
        }
        puts("");
    }

    return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//727378  	2011-01-29 12:52:29 	Accepted	0.070	Minimum	26909	C++	4270 - Discrete Square Roots
/*
id => 1174036
pid => 4270
pname => Discrete Square Roots
status => Accepted
lang => C++
time => 0.049
date => 2012-12-14 17:13:30
*/
