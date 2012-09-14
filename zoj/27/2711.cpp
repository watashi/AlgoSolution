#include <cstdio>

class BigInteger
{
private:
    static const int LEN = 10;
    static const int MOD = 100000000;
    int a[LEN];
    int len;
public:
    BigInteger(int x = 0)
    {
        len = 0;
        do {
        a[len++] = x % MOD;
        x /= MOD;
        } while(x != 0);
    }

    BigInteger& operator+=(const BigInteger& rhs)
    {
        int c = 0;

        for (int i = 0; i < len && i < rhs.len; i++) {
            a[i] += rhs.a[i] + c;
            if (a[i] >= MOD) {
                a[i] -= MOD;
                c = 1;
            }
            else {
                c = 0;
            }
        }
        if (len < rhs.len) {
            for (int i = len; i < rhs.len; i++) {
                a[i] = rhs.a[i] + c;
                if (a[i] >= MOD) {
                    a[i] -= MOD;
                    c = 1;
                }
                else {
                    c = 0;
                }
            }
            len = rhs.len;
        }
        else {
            for (int i = rhs.len; c != 0 && i < len; i++) {
                ++a[i];
                if (a[i] == MOD) {
                    a[i] = 0;
                }
                else {
                    c = 0;
                }
            }
        }
        if (c != 0) {
            a[len++] = c;
            c = 0;
        }

        return *this;
    }

    void out(FILE* fpout = stdout) const
    {
        int l = len - 1;

        fprintf(fpout, "%d", a[l--]);
        while (l >= 0)
            fprintf(fpout, "%08d", a[l--]);
    }
};

BigInteger dp[61][61][61];

int main(void)
{
    dp[0][0][0] = 1;
    for (int i = 0; i <= 60; i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k <= j; k++) {
                if (i > 0) dp[i][j][k] += dp[i - 1][j][k];
                if (j > 0) dp[i][j][k] += dp[i][j - 1][k];
                if (k > 0) dp[i][j][k] += dp[i][j][k - 1];
            }
        }
    }

    int n;

    while (scanf("%d", &n) != EOF) {
        dp[n][n][n].out();
        printf("\n\n");
    }

    return 0;
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2953714   2008-06-21 01:40:02     Accepted    2711    C++     00:00.04    10192K  Re:ReJudge

// 2012-09-07 15:45:35 | Accepted | 2711 | C++ | 0 | 9932 | watashi | Source
