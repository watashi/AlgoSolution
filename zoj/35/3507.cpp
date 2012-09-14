#include <algorithm> // auto fix CE
#include <cstdio>
#include <algorithm> // auto fix CE
#include <cassert>

// mem : 1024k

int h, w;
bool blk[12], end[12][12];
char str[12][12];
int row[12][12], col[12][12];

bool isblk(int x, int n)
{
    int i;

    while(n > 1) {
        i = x / row[n][1];
        if(blk[i])
            return true;
        x -= row[n][i];
        --n;
    }

    return blk[x];
}

bool show(int x, int y, int n)
{
    int i, j;
    bool ret = true;

    while(n > 1) {
        i = x / row[n][1];
        j = y / col[n][1];
        if(str[i][j] == ' ') {
            putchar(' ');
            return false;
        }
        else {
            x -= row[n][i];
            y -= col[n][j];
            if(!end[i][j])
                ret = false;
        }
        --n;
    }
    putchar(str[x][y]);
    if(!end[x][y])
        ret = false;

    return ret;
}

int main(void)
{
    int ri = 0;
    int n, hh, ww;

    while(scanf("%d%d", &h, &w) != EOF) {
        fgets(str[0], sizeof(str[0]), stdin);
        for (int i = 0; i < h; i++) {
            fgets(str[i], sizeof(str[i]), stdin);
            assert(str[i][w] == '\n');
            blk[i] = false;
            for (int j = 0; j < w; j++)
                end[i][j] = false;
            for (int j = w - 1; j >= -1; j--) {
                if(j == -1) {
                    blk[i] = true; // blank line
                    break;
                }
                if(str[i][j] != ' ') {
                    end[i][j] = true;
                    break;
                }
            }
        }

        scanf("%d", &n);
        row[0][h] = col[0][w] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= h; j++)
                row[i][j] = j * row[i - 1][h];
            for (int j = 0; j <= w; j++)
                col[i][j] = j * col[i - 1][w];
        }

        if(ri > 0)
            putchar('\n');
        printf("Fractal #%d:\n", ++ri);
        hh = row[n][h];
        ww = col[n][w];
        for (int i = 0; i < hh; i++) {
            if(isblk(i, n)) {
                putchar('\n');
                continue;
            }
            for (int j = 0; j < ww; j++)
                if(show(i, j, n)) {
                    putchar('\n');
                    break;
                }
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//738   2011-04-26 22:37:45     Accepted    H   C++     230     180     watashi@ArcOfDream  Source

// 2012-09-07 16:03:12 | Accepted | 3507 | C++ | 230 | 180 | watashi | Source
