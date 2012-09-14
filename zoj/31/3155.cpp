#include <cstdio>

using namespace std;

const int bin[11] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};

bool mp[16][16][2]; // 0 up; 1 down
int n, m, s[16], dp[16];
char buf[1024];

inline void turn(int& s, int p)
{
    s ^= bin[p];
}

bool check(int x)
{
    static int a[16];

    for (int j = 0; j < m; j++) {
        a[j] = s[j];
    }
    for (int i = 0; i < n; i++) {
        if (x & bin[i]) {
            turn(a[0], i);
            turn(a[1], i);
            if (mp[i][0][0]) turn(a[0], i - 1);
            if (mp[i][0][1]) turn(a[0], i + 1);
        }
    }
    for (int j = 1; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (a[j - 1] & bin[i]) {
                turn(a[j], i);
                turn(a[j + 1], i);
                if (mp[i][j][0]) turn(a[j], i - 1);
                if (mp[i][j][1]) turn(a[j], i + 1);
            }
        }
    }

    return a[m - 1] == 0;
}

int main(void)
{
    // by column, not by row
    while (scanf("%d%d ", &n, &m) != EOF) {
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < m; j++) {
                mp[i][j][0] = mp[i][j][1] = false;
            }
        }
        for (int j = 0; j < m; j++) {
            s[j] = 0;
        }
        for (int i = 0; i < n; i++) {
            gets(buf);
            for (int j = 0; j < m; j++) {
                if (buf[2 * j] == 'o') {
                    s[j] |= bin[i];
                }
            }
            if (i == n - 1) {
                continue;
            }
            gets(buf);
            for (int j = 0; j < m; j++) {
                if (buf[2 * j] == '|') {
                    mp[i][j][1] = mp[i + 1][j][0] = true;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < bin[n]; i++) {
            if (check(i)) {
                ++ans;
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1748018   2009-01-24 17:22:49     Accepted    3155    C++     10  180     watashi@Zodiac

// 2012-09-07 02:04:11 | Accepted | 3155 | C++ | 10 | 180 | watashi | Source
