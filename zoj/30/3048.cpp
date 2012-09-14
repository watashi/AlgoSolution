#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

const int dir[4][2] = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1}
};

int n, m;
char ch;
char s[25][25];
int t[25][25], c;

void dfs(int x, int y, bool flag = false)
{
    int xx, yy;

    t[x][y] = 1;
    ++c;
    if (flag) {
        s[x][y] = '\0';
    }
    for (int i = 0; i < 4; i++) {
        xx = x + dir[i][0];
        yy = y + dir[i][1];
        if (xx >= 0 && yy >= 0 && xx < n && yy < m && s[xx][yy] == ch && !t[xx][yy]) {
            dfs(xx, yy, flag);
        }
    }
}

pair<int, int> find()
{
    pair<int, int> ret = make_pair(n, m);
    int maxc = 2;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            t[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '\0' || t[i][j]) {
                continue;
            }
            c = 0;
            ch = s[i][j];
            dfs(i, j);
            if (c > maxc) {
                maxc = c;
                ret = make_pair(i, j);
            }
            else if (c == maxc) {
                ret = min(ret, make_pair(i, j));
            }
        }
    }

    return ret;
}

void move(int j)
{
    int k = n - 1;

    for (int i = n - 1; i >= 0; i--) {
        if (s[i][j] == '\0') {
            continue;
        }
        else {
            s[k--][j] = s[i][j];
        }
    }
    while (k >= 0) {
        s[k--][j] = '\0';
    }
}

void move2()
{
    int k = 0;

    for (int j = 0; j < m; j++) {
        bool empty = true;
        for (int i = 0; i < n; i++) {
            if (s[i][j] != '\0') {
                empty = false;
                break;
            }
        }
        if (empty) {
            continue;
        }
        for (int i = 0; i < n; i++) {
            s[i][k] = s[i][j];
        }
        ++k;
    }
    while (k < m) {
        for (int i = 0; i < n; i++) {
            s[i][k] = '\0';
        }
        ++k;
    }
}

int main(void)
{
    pair<int, int> p;
    int ans;

    while (scanf("%d%d", &n, &m) != EOF) {
        while (getchar() != '\n');
        for (int i = 0; i < n; i++) {
            gets(s[i]);
        }
        ans = 0;
        while ((p = find()) != make_pair(n, m)) {
            ch = s[p.first][p.second];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    t[i][j] = 0;
                }
            }
            c = 0;
            dfs(p.first, p.second, true);
            ans += c * (c - 1);
            for (int j = 0; j < m; j++) {
                move(j);
            }
            move2();
//          for (int i = 0; i < n; i++) {
//              puts(s[i]);
//          }
        }
        printf("%d\n", ans);
    }

    return 0;
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1711112   2008-11-26 21:18:14     Accepted    3048    C++     20  180     watashi@Zodiac

// 2012-09-07 01:58:28 | Accepted | 3048 | C++ | 30 | 184 | watashi | Source
