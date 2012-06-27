#include <cstdio>
#include <cstring>

char s[1 << 20];

long long sum(long long n) {
    return n * (n + 1) / 2;
}

int main() {
    int re, n;
    long long ans;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%s", s);
        n = strlen(s);
        ans = sum(n);
        for (int i = 0; i < n; ) {
            if (s[i] == '4') {
                ++i;
            } else {
                int j = i;
                while (j < n && s[j] == '7') {
                    ++j;
                }
                ans -= sum(j - i);
                i = j;
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}

