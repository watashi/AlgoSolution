#include <cctype>
#include <cstdio>

typedef bool judge(int x, int y);
typedef void handle(int x, int y);

int h, w;
int cnt, ans;
char ch;
char buf[128][128];

inline bool isvalid(int x, int y)
{
    return x >= 0 && y >= 0 && x < h && y < w - (x & 1);
}

void dfs(int x, int y, judge* j, handle* h)
{
    (*h)(x, y);
    if((*j)(x, y + 1)) dfs(x, y + 1, j, h);
    if((*j)(x, y - 1)) dfs(x, y - 1, j, h);
    if((*j)(x + 1, y)) dfs(x + 1, y, j, h);
    if((*j)(x - 1, y)) dfs(x - 1, y, j, h);
    if((x & 1) == 0 && (*j)(x + 1, y - 1)) dfs(x + 1, y - 1, j, h);
    if((x & 1) == 0 && (*j)(x - 1, y - 1)) dfs(x - 1, y - 1, j, h);
    if((x & 1) == 1 && (*j)(x + 1, y + 1)) dfs(x + 1, y + 1, j, h);
    if((x & 1) == 1 && (*j)(x - 1, y + 1)) dfs(x - 1, y + 1, j, h);
}

bool judge1(int x, int y)
{
    return isvalid(x, y) && buf[x][y] == ch;
}

bool judge2(int x, int y)
{
    return isvalid(x, y) && buf[x][y] != ' ';
}

void handle1(int x, int y)
{
    ++cnt;
    buf[x][y] = toupper(buf[x][y]);
}

void handle2(int x, int y)
{
    ++cnt;
    buf[x][y] = ' ';
}

int main(void)
{
    int hh, ww;

    while (scanf("%d%d%d%d", &h, &w, &hh, &ww) != EOF) {
        ans = 0;
        for (int i = 0; i < h; i++) {
            scanf("%s", buf[i]);
            for (int j = 0; j < w - (i & 1); j++) {
                if (buf[i][j] != 'E') {
                    ++ans;
                }
                else {
                    buf[i][j] = ' ';
                }
            }
        }
        --hh;
        --ww;
        ch = buf[hh][ww];
        cnt = 0;
        dfs(hh, ww, judge1, handle1);
        if (cnt >= 3) {
            ch = toupper(ch);
            dfs(hh, ww, judge1, handle2);
            cnt = 0;
            for (int j = 0; j < w; j++) {
                if ((*judge2)(0, j)) {
                    dfs(0, j, judge2, handle2);
                }
            }
            ans -= cnt;
        }
        else {
            ans = 0;
        }
//      for (int i = 0; i < h; i++) puts(buf[i]);
        printf("%d\n", ans);
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//3021089 2008-08-04 15:48:02 Accepted 2743 C++ 00:00.02 1072K Re:ReJudge
//

// 2012-09-07 01:37:30 | Accepted | 2743 | C++ | 0 | 196 | watashi | Source
