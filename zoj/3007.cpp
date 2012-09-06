#include <cmath>
#include <vector>
#include <cstdio>

using namespace std;

int pre[512], tag[512], dis[512], cc;
vector<int> e[512];

void dfs(int n, int p, int c, int d)
{
    for (size_t i = 0; i < e[p].size(); i++) {
        if (pre[e[p][i]] == -1) {
            pre[e[p][i]] = p;
            tag[e[p][i]] = c;
            dis[e[p][i]] = d + 1;
            ++cc;
            dfs(n, e[p][i], c, d + 1);
        }
    }
}

int cnt[512];

int handle(int n)
{
    int ret = 0, t, tt;

    for (int i = 0; i < n; i++) {
        pre[i] = -1;
        e[i].clear();
    }
    for (int i = 1; i < n; i++) {
        scanf("%d", &t);
        e[i - 1].push_back(t);
        e[t].push_back(i - 1);
    }
    pre[0] = -2;
    dis[0] = 0;
    dfs(n, 0, 0, 0);
    t = n - 1;
    do {
        tt = pre[t];
        pre[t] = -2;
        tag[t] = dis[t];
        dis[t] = 0;
        t = tt;
    } while (t != -2);
    for (int i = 0; i < n; i++) {
        if (pre[i] != -2) {
            pre[i] = -1;
        }
    }
    for (int i = 0; i < n; i++) {
        if (pre[i] == -2) {
            ++ret;
            cc = 1;
            dfs(n, i, tag[i], 0);
            cnt[tag[i]] = cc;
        }
    }

    return ret;
}

double calc_x(int m, double x, double y)
{
    double ret = 0;

    for (int i = 1; i <= m; i++) {
        ret += x / hypot(x, y);
        y += cnt[i];
    }

    return ret;
}

double calc_y(int m, double x, double y)
{
    double ret = 0;

    for (int i = 1; i <= m; i++) {
        ret += y / hypot(x, y);
        y += cnt[i];
    }

    return ret;
}

int main(void)
{
    int n, m, k;
    double s, lx, rx, mx, ly, ry, my, xx, yy;

    while (scanf("%d%lf%d", &n, &s, &k) != EOF) {
        m = handle(n) - 1;
        lx = 0;
        rx = 1e11;  //1e4
        while (rx - lx > 1e-8) {    //1e-4
            mx = (lx + rx) / 2;
            ly = -n;
            ry = n;
            while (ry - ly > 1e-8) {    //1e-4
                my = (ly + ry) / 2;
                yy = calc_y(m, mx, my);
                if (yy >= 0) {
                    ry = my;
                }
                else {
                    ly = my;
                }
            }
            my = (ly + ry) / 2;
            xx = calc_x(m, mx, my);
            if (xx >= s) {
                rx = mx;
            }
            else {
                lx = mx;
            }
        }
        mx = (lx + rx) / 2;

        xx = 0;
        yy = 0;
        for (int i = 1; i <= tag[k]; i++) {
            xx += mx / hypot(mx, my);
            yy += my / hypot(mx, my);
            my += cnt[i];
        }
        yy -= dis[k];
        printf("%.3lf %.3lf\n", xx, yy);
    }

    return 0;
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//3015254   2008-07-31 14:47:50     Accepted    3007    C++     00:00.40    876K    Re:ReJudge

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//3015257   2008-07-31 14:48:57     Accepted    3007    C++     00:00.11    876K    Re:ReJudge

// 2012-09-07 01:54:23 | Accepted | 3007 | C++ | 110 | 192 | watashi | Source
