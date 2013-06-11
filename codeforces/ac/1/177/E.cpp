#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100100;
const long long INF = 1000000007LL * 1000000007LL;

int a[MAXN], b[MAXN];

long long gao(int n, long long d) {
    long long l = 1, r = INF;
    while (l < r) {
        long long m = (l + r) / 2;
        long long t = d;
        for (int i = 0; t > 0 && i < n; ++i) {
            if (a[i] == 0) {
            } else if (m >= (t * b[i] + a[i] - 1) / a[i]) {
                t = 0;
            } else {
                t -= (a[i] * m) / b[i];
            }
        }
        if (t > 0) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return r;
}

int main() {
    int n, m;
    bool flag = true;

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i], &b[i]);
        flag &= a[i] == 0;
    }
    m -= n;
    flag &= m == 0;
    cout << (flag ? -1LL : gao(n, m + 1) - gao(n, m)) << endl;

    return 0;
}

/*
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
1643517 	Apr 29, 2012 11:13:41 AM 	watashi 	E2 - Space Voyage (70 points) 	GNU C++0x 	Accepted 	80 ms 	2200 KB
1643516 	Apr 29, 2012 11:13:26 AM 	watashi 	E1 - Space Voyage (30 points) 	GNU C++0x 	Accepted 	30 ms 	2200 KB
*/
