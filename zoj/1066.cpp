//贪心就可以
//还想到匹配
#include <cstdio>

int h, w;
char mp[55][55];

inline bool ish(const int i, const int j)
{
    return i >= 1 && j >= 1 && i <= h && j <= w && mp[i][j] == 'h';
}

void mark(int i, int j)
{
    if(mp[i][j] == 'O')
        return;
    else
        mp[i][j] = 'O';
    if(ish(i - 2, j)) {
        mp[i - 1][j] = '|';
        mp[i - 2][j] = 'H';
    }
    else if(ish(i + 2, j)) {
        mp[i + 1][j] = '|';
        mp[i + 2][j] = 'H';
    }
    if(ish(i, j - 2)) {
        mp[i][j - 1] = '-';
        mp[i][j - 2] = 'H';
    }
    else if(ish(i, j + 2)) {
        mp[i][j + 1] = '-';
        mp[i][j + 2] = 'H';
    }
}

int main(void)
{
    int ri = 0;
    int i, j, k, n;

    while(scanf("%d", &n) != EOF && n > 0) {
        h = 4 * n - 3;
        w = 4 * n + 1;
        for (j = 0; j <= w + 1; j++)
            mp[0][j] = mp[h + 1][j] = '*';
        mp[0][w + 2] = mp[h + 1][w + 2] = '\0';
        for (i = 1; i <= h; i++) {
            mp[i][0] = mp[i][w + 1] = '*';
            for (j = 1; j <= w; j++)
                mp[i][j] = ' ';
            mp[i][w + 2] = '\0';
        }
        i = 1;
        while(i <= h) {
            j = 1;
            while(j <= w) {
                mp[i][j] = 'h';
                j += 4;
            }
            j = 3;
            while(j <= w) {
                mp[i][j] = 'o';
                j += 4;
            }
            i += 4;
        }
        i = 3;
        while(i <= h) {
            j = 3;
            while(j <= w) {
                mp[i][j] = 'h';
                j += 4;
            }
            i += 4;
        }

        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++) {
                scanf("%d", &k);
                if(k == 1) {
                    mp[4 * i + 1][4 * j + 3] = 'O';
                    mp[4 * i + 1][4 * j + 2] = '-';
                    mp[4 * i + 1][4 * j + 1] = 'H';
                    mp[4 * i + 1][4 * j + 4] = '-';
                    mp[4 * i + 1][4 * j + 5] = 'H';
                }
                else if(k == -1) {
                    mp[4 * i + 1][4 * j + 3] = 'O';
                    mp[4 * i - 0][4 * j + 3] = '|';
                    mp[4 * i - 1][4 * j + 3] = 'H';
                    mp[4 * i + 2][4 * j + 3] = '|';
                    mp[4 * i + 3][4 * j + 3] = 'H';
                }
            }
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                mark(4 * i + 1, 4 * j + 3);
        if(ri)
            putchar('\n');
        printf("Case %d:\n\n", ++ri);
        for (i = 0; i <= h + 1; i++)
            puts(mp[i]);
    }

    return 0;
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2835384   2008-04-10 11:08:41     Accepted    1066    C++     00:00.00    396K    わたし

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//18441     2008-04-16 20:27:53     Accepted    1007    C++     0   512     watashi

// 2012-09-07 00:35:20 | Accepted | 1066 | C++ | 0 | 184 | watashi | Source
