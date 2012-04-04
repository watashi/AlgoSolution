#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1024;

bool p[MAXN];
char s[MAXN];

int main() {
    int n, m, c[26];

    scanf("%s", s);
    n = (int)strlen(s);
    fill(c, c + 26, 0);
    for (int i = 0; i < n; ++i) {
        ++c[s[i] - 'a'];
    }
    m = max_element(c, c + 26) - c;
    fill(s, s + n, '\0');
    for (int i = 2; i + i <= n; ++i) {
        if (!p[i]) {
            for (int j = i; j <= n; j += i) {
                if (s[j - 1] == '\0') {
                    s[j - 1] = 'a' + m;
                    --c[m];
                }
            }
        }
    }

    if (c[m] < 0) {
        puts("NO");
    } else {
        m = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '\0') {
                while (c[m] == 0) {
                    ++m;
                }
                s[i] = 'a' + m;
                --c[m];
            }
        }
        puts("YES");
        puts(s);
    }

    return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//1155194 	Feb 7, 2012 12:30:38 PM 	watashi 	123A - Prime Permutation 	GNU C++ 	Accepted 	30 ms 	1300 KB
