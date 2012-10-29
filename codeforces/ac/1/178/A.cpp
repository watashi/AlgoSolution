#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = 100100;

int a[MAXN];

int bin(int n) {
    return 1 << (31 - __builtin_clz(n));
}

int main() {
    int n;
    long long ans = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n - 1; ++i) {
        ans += a[i];
        a[i + bin(n - 1 - i)] += a[i];
        printf("%I64d\n", ans);
    }

    return 0;
}

