#include <cstdio>

const int MonthDay[2][13] = {
    {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {-1, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

const int Size = 365243;

int Move[Size];
int dp[Size];
int queue[Size];

inline bool LeapYear(int y)
{
    return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0);
}

int DateToInt(int y, int m, int d)
{
    int ret = d - 1;

    if(LeapYear(y))
        for (int i = 1; i < m; i++)
            ret += MonthDay[1][i];
    else
        for (int i = 1; i < m; i++)
            ret += MonthDay[0][i];
    y -= 2000;
    ret += y * 365;
    if(y > 0) {
        --y;
        ret += y / 4 - y / 100 + y / 400 + 1;
    }

    return ret;
}

int main(void)
{
    int date, leap, ij;

    date = 0;
    for (int i = 2000; i < 3000; i++) {
        leap = LeapYear(i);
        for (int j = 1; j <= 12; j++) {
            ij = i + j;
            for (int k = 1; k <= MonthDay[leap][j]; k++)
                Move[date++] = ij + k;
        }
    }

    int y, m, d, f, t;

    while(scanf("%d-%d-%d", &y, &m, &d) != EOF) {
        for (int i = 0; i < Size; i++)
            dp[i] = -1;
        queue[f = 0] = DateToInt(y, m, d);
        t = 1;
        scanf("%d-%d-%d", &y, &m, &d);
        y = DateToInt(y, m, d);
        dp[queue[0]] = 0;
        while(f < t) {
            d = queue[f] + 1;
            if(d >= Size)
                d -= Size;
            if(dp[d] == -1) {
                dp[d] = dp[queue[f]] + 1;
                queue[t++] = d;
                if(d == y)
                    break;
            }
            d = queue[f] + Move[queue[f]];
            if(d >= Size)
                d -= Size;
            if(dp[d] == -1) {
                dp[d] = dp[queue[f]] + 1;
                queue[t++] = d;
                if(d == y)
                    break;
            }
            ++f;
        }
        printf("%d\n", dp[y]);
    }

    return 0;
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2841516   2008-04-13 14:23:38     Accepted    2534    C++     00:01.60    4676K   Re:ReJudge

// 2012-09-07 01:27:09 | Accepted | 2534 | C++ | 520 | 4460 | watashi | Source
