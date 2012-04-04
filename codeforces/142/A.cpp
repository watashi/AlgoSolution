#include <iostream>

using namespace std;

long long gao(long long a, long long b) {
    long long c = 1;
    for (long long i = 1; i * i <= b; ++i) {
        if (b % i == 0) {
            c = i;
        }
    }
    return (a + 1) * (c + 2) * (b / c + 2);
}

int main() {
    long long n, a, b;

    cin >> n;
    a = b = (n + 1) * 3 * 3;
    for (long long i = 1; i * i <= n; ++i) {
        if (n % i != 0) {
            continue;
        }
        long long j = n / i;
        a = min(a, min(gao(i, j), gao(j, i)));
    }
    cout << a - n << ' ' << b - n << endl;

    return 0;
}
//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//1154980 	Feb 7, 2012 11:35:39 AM 	watashi 	142A - Help Farmer 	GNU C++ 	Accepted 	50 ms 	1400 KB
