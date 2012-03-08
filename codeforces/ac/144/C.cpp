#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 100100;

int x[26], y[26], z;
char s[MAXN], t[MAXN];

int main() {
    int n, m, ans = 0;

    scanf("%s%s", s, t);
    n = strlen(s);
    m = strlen(t);
    for (int i = 0; i < m; ++i) {
        ++y[t[i] - 'a'];
    }
    for (int i = 0; i < n; ++i) {
        if (s[i] != '?') {
            int j = s[i] - 'a';
            if (x[j]++ == y[j]) {
                ++z;
            }
        }
        if (i >= m - 1) {
            if (z == 0) {
                ++ans;
            }
            int j = s[i - m + 1] - 'a';
            if (--x[j] == y[j]) {
                --z;
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//1133096 	Feb 2, 2012 4:55:26 PM 	watashi 	144C - Anagram Search 	GNU C++0x 	Accepted 	30 ms 	1500 KB
