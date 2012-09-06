// Stable (marriage) Matchings
// Gale-Shapley Proposal Algorithm

// x propose to y; produce best possible choice for x;

// Stable (marriage) Matchings
// Gale-Shapley Proposal Algorithm

// x propose to y; produce best possible choice for x;


#include <cstdio>
#include <queue>

using namespace std;

const int MAXN = 1024;

void GaleShapley(int n, int xy[][MAXN], int yx[][MAXN], int x[], int y[])
{
    static int pr[MAXN][MAXN];
    static int p, t, tar, pat, nxt[MAXN], pia[MAXN * MAXN];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            pr[i][yx[i][j]] = j;
        }
    }
    for (int i = 0; i < n; i++) {
        pia[i] = i;
        nxt[i] = 0;
        x[i] = y[i] = -1;
    }
    p = 0;
    t = n;
    while (p < t) {
        while (true) {
            tar = xy[pia[p]][nxt[pia[p]]++];
            pat = y[tar];
            if (pat == -1 || pr[tar][pia[p]] < pr[tar][pat]) {
                x[pia[p]] = tar;
                y[tar] = pia[p];
                if (pat != -1) {
                    pia[t++] = pat;
                }
                break;
            }
        }
        ++p;
    }
}

int xy[MAXN][MAXN], yx[MAXN][MAXN];
int x[MAXN], y[MAXN];

int main()
{
    int re, n;

    scanf("%d", &re);
    while (re--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &xy[i][j]);
                --xy[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &yx[i][j]);
                --yx[i][j];
            }
        }
        GaleShapley(n, xy, yx, x, y);
        for (int i = 0; i < n; i++) {
            printf("%d\n", x[i] + 1);
        }
    }

    return 0;
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//3049395   2008-08-24 23:00:59     Accepted    3037    C++     00:03.04    12696K  watashi@Zodiac

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//3049403   2008-08-24 23:10:20     Accepted    3037    C++     00:02.93    16788K  watashi@Zodiac

// 2012-09-07 01:57:20 | Accepted | 3037 | C++ | 790 | 16576 | watashi | Source
