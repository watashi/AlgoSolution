#include <cstdio>

struct Catalan {
    long long *C;

    Catalan(int n) {
        C = new long long[n];
        C[0] = 1;
        for (int i = 1; i < n; ++i) {
            C[i] = 0;
            for (int j = 0; j < i; ++j) {
                C[i] += C[j] * C[i - 1 - j];
            }
        }
    }

    long long operator[](int i) {
        return C[i];
    }
} catalan(20);

char buf[26];
char ans[26][2];

char gao(int n, long long k, char ch) {
    if (n == 0) {
        return '*';
    }
    for (int i = 0; i < n; ++i) {
        if (k < catalan[i] * catalan[n - 1 - i]) {
            putchar(ch + i);
            ans[ch + i - 'a'][0] = gao(i, k / catalan[n - 1 - i], ch);
            ans[ch + i - 'a'][1] = gao(n - 1 - i, k % catalan[n - 1 - i], ch + i + 1);
            return ch + i;
        } else {
            k -= catalan[i] * catalan[n - 1 - i];
        }
    }
    return '#';
}

int main() {
    bool b = false;
    int n;
    long long k;

    while (scanf("%d%lld", &n, &k) != EOF) {
        if (b) {
            puts("");
        } else {
            b = true;
        }
        gao(n, k - 1, 'a');
        puts("");
        for (int i = 0; i < n; ++i) {
            printf("%c %c %c\n", 'a' + i, ans[i][0], ans[i][1]);
        }
    }

    return 0;
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1795128   2009-03-20 14:33:19     Accepted    2738    C++     0   176     watashi@Zodiac

// 2012-09-07 01:37:12 | Accepted | 2738 | C++ | 0 | 180 | watashi | Source
