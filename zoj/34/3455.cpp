#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXL = 500500;
const int SIGMA = 256;

int c[SIGMA];
int l[MAXL];
char str[MAXL];
char pat[MAXL];

int main() {
    int n, m, k;
    vector<int> ans;

    while (scanf("%s%s", str, pat) != EOF) {
        n = strlen(str);
        m = strlen(pat);
        fill(c, c + SIGMA, 0);
        for (int i = 0; i < m; ++i) {
            ++c[pat[i]];
        }

        fill(l + 1, l + 1 + m, 0);
        for (int i = 0; i < SIGMA; ++i) {
            --l[c[i]];
        }
        k = count(l + 1, l + 1 + m, 0);

        ans.clear();
        fill(c, c + SIGMA, 0);
        for (int i = 0; i < n; ++i) {
            if (i >= m) {
        //      puts("DO");
                int& cc = c[str[i - m]];
                switch (l[cc]) {
                case 0: --k; break;
                case 1: ++k; break;
                }
                --l[cc];
                --cc;
                ++l[cc];
                if (cc != 0) {
                    switch (l[cc]) {
                    case 0: ++k; break;
                    case 1: --k; break;
                    }
                }
            }

            int& cc = c[str[i]];
        //  printf("%d %d [%d %d %d %d]\n", cc, k, l[1], l[2], l[3], l[4]);
            if (cc != 0) {
                switch (l[cc]) {
                case 0: --k; break;
                case 1: ++k; break;
                }
            }
            --l[cc];
            ++cc;
            ++l[cc];
            switch (l[cc]) {
            case 0: ++k; break;
            case 1: --k; break;
            }
        //  printf("%d %d [%d %d %d %d]\n\n", cc, k, l[1], l[2], l[3], l[4]);

            if (k == m) {
                ans.push_back(i - m + 1);
            }
        }

        if (ans.empty()) {
            puts("No");
        } else {
            puts("Yes");
            for (int i = 0; i < (int)ans.size(); ++i) {
                printf("%d%c", ans[i], i == (int)ans.size() - 1 ? '\n' : ' ');
            }
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//612   2010-12-23 20:03:31     Accepted    K   C++     300     6192    watashi@Zodiac  Source

// 2012-09-07 15:57:49 | Accepted | 3455 | C++ | 190 | 6192 | watashi | Source
