#include <algorithm> // auto fix CE
#include <cstdio>
#include <algorithm> // auto fix CE
#include <vector>
#include <algorithm> // auto fix CE
#include <cstdlib>

using namespace std;

const int COLS = 9;
const int h[COLS] = {7, 8, 9, 10, 11, 10, 9, 8, 7};
vector<char> s[COLS];

char hive[32][32] = {
    "         _",
    "       _/%\\_",
    "     _/%\\_/%\\_",
    "   _/%\\_/%\\_/%\\_",
    " _/%\\_/%\\_/%\\_/%\\_",
    "/%\\_/%\\_/%\\_/%\\_/%\\",
    "\\_/%\\_/%\\_/%\\_/%\\_/",
    "/%\\_/%\\_/%\\_/%\\_/%\\",
    "\\_/%\\_/%\\_/%\\_/%\\_/",
    "/%\\_/%\\_/%\\_/%\\_/%\\",
    "\\_/%\\_/%\\_/%\\_/%\\_/",
    "/%\\_/%\\_/%\\_/%\\_/%\\",
    "\\_/%\\_/%\\_/%\\_/%\\_/",
    "/%\\_/%\\_/%\\_/%\\_/%\\",
    "\\_/%\\_/%\\_/%\\_/%\\_/",
    "/%\\_/%\\_/%\\_/%\\_/%\\",
    "\\_/%\\_/%\\_/%\\_/%\\_/",
    "/%\\_/%\\_/%\\_/%\\_/%\\",
    "\\_/%\\_/%\\_/%\\_/%\\_/",
    "  \\_/%\\_/%\\_/%\\_/",
    "    \\_/%\\_/%\\_/",
    "      \\_/%\\_/",
    "        \\_/",
};

int main() {
    int n, x, ans;
    char buf[80];

    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < COLS; ++i) {
            s[i].clear();
        }
        ans = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%s", buf);
            x = buf[0] - 'A';
            if ((int)s[x].size() < h[x]) {
                if (!s[x].empty() && buf[1] == s[x].back()) {
                    ++ans;
                    s[x].pop_back();
                } else {
                    s[x].push_back(buf[1]);
                }
            }
        }

        printf("The number of candy is %d.\n", ans);
        for (int i = 0; i < COLS; ++i) {
            for (int j = 0; j < h[i]; ++j) {
                hive[(10 - j) * 2 + 1 - abs(i - 4)][i * 2 + 1] = ' ';
            }
            for (int j = 0; j < (int)s[i].size(); ++j) {
                hive[(10 - j) * 2 + 1 - abs(i - 4)][i * 2 + 1] = s[i][j];
            }
        }
        for (int i = 0; i < 23; ++i) {
            puts(hive[i]);
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//1096  2010-07-27 15:50:03     Accepted    1138    C++     10  180     anotherpeg  Source

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//692   2011-01-30 15:37:02     Accepted    I   C++     0   180     watashi@ArcOfDream  Source

// 2012-09-07 15:58:50 | Accepted | 3465 | C++ | 0 | 180 | watashi | Source
