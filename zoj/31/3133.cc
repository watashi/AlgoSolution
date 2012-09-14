#include <cstdio>
#include <limits>
#include <algorithm>

using namespace std;

// begin with 1
int wmin[50005], wmax[50005], hmin[50005], hmax[50005];

void update(int x, int& xmin, int& xmax)
{
    if (xmin == -1 || x <= xmin) {
        xmin = x;
    }
    if (xmax == -2 || x >= xmax) {
        xmax = x + 1;
    }
}

int gao(int maxl, int m, int xmin[], int xmax[])
{
    static int l[50005], r[50005];
    unsigned int s = 0, ans = numeric_limits<unsigned int>::max();

    l[m] = xmin[m];
    r[m] = xmax[m];
    s += r[m] - l[m] + 1;
    for (int i = m - 1; i >= 1; i--) {
        l[i] = xmin[i];
        r[i] = xmax[i];
        if (l[i] == -1) {
            l[i] = l[i + 1];
            r[i] = r[i + 1];
        }
        else if (l[i + 1] != -1) {
            l[i] = min(l[i], l[i + 1]);
            r[i] = max(r[i], r[i + 1]);
        }
        s += r[i] - l[i] + 1;
//printf("%d: l = %d; r = %d\n", i, l[i], r[i]);
    }
    for (int i = 1; i <= m; i++) {
        s -= r[i] - l[i] + 1;
        if (i > 1) {
            l[i - 1] = xmin[i - 1];
            r[i - 1] = xmax[i - 1];
            if (i > 2 && l[i - 1] == -1) {
                l[i - 1] = l[i - 2];
                r[i - 1] = r[i - 2];
            }
            else if (i > 2 && l[i - 2] != -1) {
                l[i - 1] = min(l[i - 1], l[i - 2]);
                r[i - 1] = max(r[i - 1], r[i - 2]);
            }
            s += r[i - 1] - l[i - 1] + 1;
//printf("%d: l = %d; r = %d\n", i - 1, l[i - 1], r[i - 1]);
        }
        ans = min(s + maxl, ans);
    }

    return ans;
}

int main() {
    int re, w, h, n, x, y;

    scanf("%d", &re);
    while (re--) {
        scanf("%d%d", &w, &h);
        for (int i = 1; i <= w; i++) {
            wmin[i] = -1;
            wmax[i] = -2;
        }
        for (int j = 1; j <= h; j++) {
            hmin[j] = -1;
            hmax[j] = -2;
        }

        scanf("%d", &n);
        while (n--) {
            scanf("%d%d", &x, &y);
            if (x >= 1) {
                update(y, wmin[x], wmax[x]);
            }
            if (x + 1 <= w) {
                update(y, wmin[x + 1], wmax[x + 1]);
            }
            if (y >= 1) {
                update(x, hmin[y], hmax[y]);
            }
            if (y + 1 <= h) {
                update(x, hmin[y + 1], hmax[y + 1]);
            }
        }

        for (int i = 1; i <= w; i++) {
            if (wmin[i] == 0) {
                wmin[i] = 1;
            }
            if (wmax[i] == h + 1) {
                wmax[i] = h;
            }
            //printf("%d %d %d\n", i, wmin[i], wmax[i]);
        }
        for (int j = 1; j <= h; j++) {
            if (hmin[j] == 0) {
                hmin[j] = 1;
            }
            if (hmax[j] == w + 1) {
                hmax[j] = w;
            }
            //printf("%d %d %d\n", j, hmin[j], hmax[j]);
        }

        printf("%u\n", min(gao(w, h, hmin, hmax), gao(h, w, wmin, wmax)));
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1750160   2009-01-28 14:54:30     Accepted    3133    C++     80  1348    watashi@Zodiac

// 2012-09-07 02:02:45 | Accepted | 3133 | C++ | 60 | 1352 | watashi | Source
