/*
#include <cstring> // auto fix CE
#include <map>
#include <cstring> // auto fix CE
#include <cstdio>

using namespace std;

int tri[10] = {
    1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683
};

map<int, int> mp;
int rp[19683];

void init(int n, int x, int y) {
    if (n == 0) {
        rp[x] = y;
        mp[y] = x;
    } else {
        --n;
        x *= 3;
        y <<= 2;
        init(n, x, y);
        init(n, x + 1, y ^ 1);
        init(n, x + 2, y ^ 3);
    }
}

long long dp[30][10][19683];

void solve(int m, int n) {
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            dp[0][0][0] = 1;
        } else {
            for (int k = 0; k < tri[m]; ++k) {
                dp[i][0][k] = dp[i - 1][m][k];
            }
        }
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < tri[m]; ++k) {
                int kk = rp[k];
                if (kk & (2 << (j << 1))) { // 3
                    dp[i][j + 1][mp[kk ^ (2 << (j << 1))]] += dp[i][j][k];
                } else if (kk & (1 << (j << 1))) {  // 1
                    dp[i][j + 1][mp[kk ^ (1 << (j << 1))]] += dp[i][j][k];
                } else {    // 0
                    dp[i][j + 1][mp[kk ^ (3 << (j << 1))]] += dp[i][j][k];
                    if (j + 3 <= m && (kk & (0x3f << (j << 1))) == 0) {
                        dp[i][j + 3][k] += dp[i][j][k];
                    }
                }
            }
        }
    }
    // return dp[n - 1][m][0];
}

int main() {
    int m, n;
    init(9, 0, 0);
    for (int i = 1; i <= 9; ++i) {
        solve(i, 30);
        putchar('{');
        for (int j = 0; j < 30; ++j) {
            printf("%lldLL, ", dp[j][i][0]);
        }
        puts("},");
    }
    return 0;
}
*/

#include <cstring> // auto fix CE
#include<cstdio>

int main() {
    long long ans[9][30] = {
        {0LL, 0LL, 1LL, 0LL, 0LL, 1LL, 0LL, 0LL, 1LL, 0LL, 0LL, 1LL, 0LL, 0LL, 1LL, 0LL, 0LL, 1LL, 0LL, 0LL, 1LL, 0LL, 0LL, 1LL, 0LL, 0LL, 1LL, 0LL, 0LL, 1LL, },
        {0LL, 0LL, 1LL, 0LL, 0LL, 1LL, 0LL, 0LL, 1LL, 0LL, 0LL, 1LL, 0LL, 0LL, 1LL, 0LL, 0LL, 1LL, 0LL, 0LL, 1LL, 0LL, 0LL, 1LL, 0LL, 0LL, 1LL, 0LL, 0LL, 1LL, },
        {1LL, 1LL, 2LL, 3LL, 4LL, 6LL, 9LL, 13LL, 19LL, 28LL, 41LL, 60LL, 88LL, 129LL, 189LL, 277LL, 406LL, 595LL, 872LL, 1278LL, 1873LL, 2745LL, 4023LL, 5896LL, 8641LL, 12664LL, 18560LL, 27201LL, 39865LL, 58425LL, },
        {0LL, 0LL, 3LL, 0LL, 0LL, 13LL, 0LL, 0LL, 57LL, 0LL, 0LL, 249LL, 0LL, 0LL, 1087LL, 0LL, 0LL, 4745LL, 0LL, 0LL, 20713LL, 0LL, 0LL, 90417LL, 0LL, 0LL, 394691LL, 0LL, 0LL, 1722917LL, },
        {0LL, 0LL, 4LL, 0LL, 0LL, 22LL, 0LL, 0LL, 121LL, 0LL, 0LL, 664LL, 0LL, 0LL, 3643LL, 0LL, 0LL, 19987LL, 0LL, 0LL, 109657LL, 0LL, 0LL, 601624LL, 0LL, 0LL, 3300760LL, 0LL, 0LL, 18109345LL, },
        {1LL, 1LL, 6LL, 13LL, 22LL, 64LL, 155LL, 321LL, 783LL, 1888LL, 4233LL, 9912LL, 23494LL, 54177LL, 126019LL, 295681LL, 687690LL, 1600185LL, 3738332LL, 8712992LL, 20293761LL, 47337405LL, 110368563LL, 257206012LL, 599684007LL, 1398149988LL, 3259051800LL, 7597720649LL, 17712981963LL, 41291922001LL, },
        {0LL, 0LL, 9LL, 0LL, 0LL, 155LL, 0LL, 0LL, 2861LL, 0LL, 0LL, 52817LL, 0LL, 0LL, 972557LL, 0LL, 0LL, 17892281LL, 0LL, 0LL, 329097125LL, 0LL, 0LL, 6052932495LL, 0LL, 0LL, 111328274273LL, 0LL, 0LL, 2047599783121LL, },
        {0LL, 0LL, 13LL, 0LL, 0LL, 321LL, 0LL, 0LL, 8133LL, 0LL, 0LL, 204975LL, 0LL, 0LL, 5158223LL, 0LL, 0LL, 129777789LL, 0LL, 0LL, 3265058453LL, 0LL, 0LL, 82145028215LL, 0LL, 0LL, 2066672862247LL, 0LL, 0LL, 51995077201711LL, },
        {1LL, 1LL, 19LL, 57LL, 121LL, 783LL, 2861LL, 8133LL, 37160LL, 143419LL, 468816LL, 1876855LL, 7263468LL, 25496863LL, 97187247LL, 372086645LL, 1352780401LL, 5071962134LL, 19220628318LL, 71025008365LL, 265095817718LL, 997839772024LL, 3713274525679LL, 13851695644227LL, 51940567251136LL, 193830054345968LL, 723361116637203LL, 2707160075336397LL, 10112661751221423LL, 37758603187152493LL, },
    };
    int m, n;

    while (scanf("%d%d", &m, &n) != EOF && (n > 0 || m > 0)) {
        printf("%lld\n", ans[m - 1][n - 1]);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1814342   2009-04-02 06:01:47     Accepted    2563    C++     0   180     watashi@Zodiac
// Run ID   Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
// 1814343  2009-04-02 06:02:48     Accepted    2563    C++     0   176     watashi@Zodiac

// 2012-09-07 15:40:21 | Accepted | 2563 | C++ | 0 | 180 | watashi | Source
