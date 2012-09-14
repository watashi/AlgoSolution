#include <cstdio>

const int dx[4][3] = {{0, 0, 0}, {1, 2, 3}, {1, 2, 3}, {1, 2, 3}};
const int dy[4][3] = {{1, 2, 3}, {0, 0, 0}, {1, 2, 3}, {-1, -2, -3}};

int p[10];
char s[10][10];

char whose_turn()
{
    int ca = 0, cb = 0;

    for (int j = 0; j < 7; j++) {
        p[j] = -1;
        for (int i = 0; i < 7; i++) {
            if (s[i][j] == 'x') {
                ++p[j];
                if (i != p[j]) {
                    return 'x';
                }
            }
            else if (s[i][j] == '*') {
                ++ca;
            }
            else if (s[i][j] == 'o') {
                ++cb;
            }
        }
    }

    if (ca == cb + 1) return '*';
    else if (ca == cb) return 'o';
    else return 'x';
}

char whos_winner()
{
    bool flag;
    int x, y;

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            if (s[i][j] == 'x') {
                continue;
            }
            for (int d = 0; d < 4; d++) {
                flag = true;
                for (int l = 0; l < 3; l++) {
                    x = i + dx[d][l];
                    y = j + dy[d][l];
                    if (x >= 7 || y < 0 || y >= 7 || s[x][y] != s[i][j]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    return s[i][j];
                }
            }
        }
    }

    return 'x';
}

char search_winner(char ch)
{
    char chr = (ch == '*') ? 'o' : '*';
    bool f, ff;

    if (whos_winner() == ch) {
        return ch;
    }
    ff = false;
    f = true;
    for (int j = 0; j < 7; j++) {
        if (p[j] != -1) {
            s[p[j]--][j] = chr;
            if (whos_winner() == chr) {
                return chr;
            }
            if (f) {
                f = false;
                for (int jj = 0; jj < 7; jj++) {
                    if (p[jj] != -1) {
                        ff = true;
                        s[p[jj]][jj] = ch;
                        if (whos_winner() == ch) {
                            f = true;
                        }
                        s[p[jj]][jj] = 'x';
                    }
                }
            }
            s[++p[j]][j] = 'x';
        }
    }

    if (ff && f) {
        return ch;
    }
    else {
        return 'x';
    }
}

int main(void)
{
    int re;
    char ch;
    bool f, ff;

    scanf("%d", &re);
    while (re--) {
        for (int i = 0; i < 7; i++) {
            scanf("%s", s[i]);
        }
        if ((ch = whose_turn()) == 'x') {
            puts("Impossible");
            continue;
        }
        f = ff = false;
        for (int j = 0; j < 7; j++) {
            if (p[j] != 6 && s[p[j] + 1][j] == ch) {
                ff = true;
                s[p[j] + 1][j] = 'x';
                if (whos_winner() == 'x') {
                    f = true;
                }
                s[p[j] + 1][j] = ch;
            }
        }
        if (ff && !f) {
            puts("Impossible");
            continue;
        }
        switch (search_winner(ch)) {
            case 'x': puts("Neither Wins"); break;
            case '*': puts("* Wins"); break;
            case 'o': puts("o Wins"); break;
        }
    }

    return 0;
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1711108   2008-11-26 21:16:23     Accepted    3047    C++     0   176     watashi@Zodiac

// 2012-09-07 01:58:22 | Accepted | 3047 | C++ | 0 | 180 | watashi | Source
