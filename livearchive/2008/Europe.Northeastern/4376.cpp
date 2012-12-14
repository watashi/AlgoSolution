#include <cstdio>

const int MAXN = 81;

long long end[MAXN], len[MAXN], one[MAXN];

// len(n)=m [0,n)
long long gao(long long m, long long n) {
    if (n <= 1) {
        return 0;
    } else if (end[m - 1] <= n) {
        --m;
        n -= end[m];
        return one[m] + n + gao(m - 1, n);
    } else {
        return gao(m - 1, n);
    }
}

long long fib(long long n, long long v) {
    long long m = 0;
    while (end[m + 1] <= v) {
        ++m;
    }
    long long ret = 0;
    for (int i = 0; i < n; ++i) {
        if (v >= end[m - i]) {
            v -= end[m - i];
            ++ret;
        }
    }
    return ret;
}

long long solve(long long n) {
    long long m, c, ans;
    if (n == 0) {
        return 0;
    }
    m = 0;
    while (len[m + 1] <= n) {
        ++m;
    }
    n -= len[m];
    c = n / (m + 1);
    n -= c * (m + 1);
    ans = gao(m + 1, end[m] + c);
    //     printf("%lld %lld\n", end[m] + c, ans);
    ans += fib(n, end[m] + c);
    //     printf("%lld %lld\n", n, fib(n, end[m] + c));

    return ans;
}
int main() {
    long long n;

    end[0] = 1;
    len[0] = 0;
    one[0] = 0;
    end[1] = 2; // exclude
    len[1] = 1; // include
    one[1] = 1; // include
    for (int i = 2; i < MAXN; ++i) {
        end[i] = end[i - 1] + end[i - 2];
        len[i] = len[i - 1] + end[i - 2] * i;
        one[i] = one[i - 1] + one[i - 2] + end[i - 2];
       //        printf("%d: %lld %lld %lld\n", i, end[i], len[i], one[i]);
    }

    while (scanf("%lld\n", &n) != EOF) {
        printf("%lld\n", solve(n));
    }
/*  for (int i = 1; i < 100000; ++i) {
        int tmp = solve(i) - solve(i - 1);
        if (tmp != 0 && tmp != 1) {
            printf("%d\n", i);
            printf("%lld %lld\n", solve(i - 1), solve(i));
            break;
        }
    }
*/
    return 0;
}
//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//727390  	2011-01-29 13:10:44 	Accepted	0.002	Minimum	26909	C++	4376 - Fibonacci System
/*
id => 1174314
pid => 4376
pname => Fibonacci System
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:53:08
*/
