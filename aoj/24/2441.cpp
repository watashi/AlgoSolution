#include <cstdio>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

const long long INF = 100000000000000000LL; /* 10 ** 17 */

long long gao(long long n, long long m) {
    return (n - 1) / m;
}

long long fizzbuzz(long long n) {
    const long long d[4] = {1, 3, 5, 15};
    long long ret = 0;
    for (long long ten = 1, len = 1; ten < n; ten *= 10, ++len) {
        long long c[4];
        for (int i = 0; i < 4; ++i) {
            c[i] = gao(min(n, ten * 10), d[i]) - gao(ten, d[i]);
        }
        c[1] -= c[3];
        c[2] -= c[3];
        c[0] -= c[1] + c[2] + c[3];
        ret += c[0] * len + c[1] * 4 + c[2] * 4 + c[3] * 8;
    }
    return ret;
}

int main() {
    long long n, l, r, m;
    char buf[80];
    string ans;

    scanf("%lld", &n);
    l = 1;
    r = INF;
    while (l < r) {
        m = (l + r) / 2;
        if (fizzbuzz(m) < n) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    m = r - 1;
    // fprintf(stderr, "%lld = %lld\n", m, fizzbuzz(m));

    for (long long i = m; i <= m + 30; ++i) {
        if (i % 3 != 0 && i % 5 != 0) {
            sprintf(buf, "%lld", i);
            ans += buf;
        } else {
            if (i % 3 == 0) {
                ans += "Fizz";
            }
            if (i % 5 == 0) {
                ans += "Buzz";
            }
        }
    }
    puts(ans.substr(n - fizzbuzz(m) - 1, 20).c_str());

    return 0;
}

//Run# 	Author 	Problem 	Status 	Lang 	Time 	Memory 	Submission Date
//#486553 	watashi 	B 	: Accepted 	C++ 	00:00 sec 	1072 KB 	Sun Sep 16 14:35:43

//Run# 	Author 	Problem 	Status 	Lang 	Time 	Memory 	Code 	Submission Date
//#489324 	watashi 	2441 	: Accepted 	C++ 	00:00 sec 	1072 KB 	1593 Bytes 	Wed Sep 19 15:24:22

