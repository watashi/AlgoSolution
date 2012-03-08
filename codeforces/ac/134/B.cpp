#include <cstdio>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int gao(int a, int b) {
    return a == 1 ? b - 1 : b / a + gao(b % a, a);
}

int main() {
    int n, m;

    scanf("%d", &n);
    m = n - 1;
    for (int i = 2; i + i < n; ++i) {
        if (gcd(i, n) == 1) {
            m = min(m, gao(i, n - i) + 1);
        }
    }
    printf("%d\n", m);

    return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//1132975 	Feb 2, 2012 4:10:03 PM 	watashi 	134B - Pairs of Numbers 	GNU C++0x 	Accepted 	140 ms 	1300 KB
