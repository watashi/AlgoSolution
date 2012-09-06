// vls xe的数据 囧

// The Hungarian Algorithm finds a maximum weight matching and a minimumu cost cover
// double 需要修改等于的判断
// assert(nx <= ny);

#include <map>
#include <cstdio>
#include <algorithm>

using namespace std;

const int inf = 1000000000;

const int MAXN = 350;

template<typename T>
T KuhnMunkras(int nx, int ny, int mx[], int my[], T xy[][MAXN], T lx[], T ly[])
{
    T ret = 0;
    static int p, t, q[MAXN], pre[MAXN];

    for (int i = 0; i < nx; i++) {
        lx[i] = *max_element(xy[i], xy[i] + ny);
    }
    fill(ly, ly + ny, 0);
    fill(mx, mx + nx, -1);
    fill(my, my + ny, -1);

    for (int i = 0; i < nx; i++) {
        fill(pre, pre + ny, -1);
        q[0] = i;
        p = 0;
        t = 1;
        while (p < t) {
            for (int j = 0; j < ny; j++) {
                if (lx[q[p]] + ly[j] == xy[q[p]][j] && pre[j] == -1) {
                    pre[j] = q[p];
                    if (my[j] == -1) {
                        int y, yy = j;

                        do {
                            y = yy;
                            yy = mx[pre[y]];
                            mx[pre[y]] = y;
                            my[y] = pre[y];
                        } while (yy != -1);
                        t = -1;
                        break;
                    }
                    else {
                        q[t++] = my[j];
                    }
                }
            }
            ++p;
        }
        //
        if (mx[i] == -1) {
            ret = inf;
            for (int j = 0; j < t; j++) {
                for (int k = 0; k < ny; k++) {
                    if (pre[k] == -1) {
                        ret = min(ret, lx[q[j]] + ly[k] - xy[q[j]][k]);
                    }
                }
            }
            for (int j = 0; j < t; j++) {
                lx[q[j]] -= ret;
            }
            for (int k = 0; k < ny; k++) {
                if (pre[k] != -1) {
                    ly[k] += ret;
                }
            }
            --i; // !!
        }
    }

    ret = 0;
    for (int i = 0; i < nx; i++) {
        ret += xy[i][mx[i]];
    }

    return ret;
}

int xy[250][350];
int mx[250], my[350];
int lx[250], ly[350];

int get_id(map<int, int>& mp, int id)
{
    if (mp.count(id) == 0) {
        mp.insert(make_pair(id, (int)mp.size()));
    }

    return mp[id];
}

int main()
{
    int re, nx, ny, m;
    int a, b, c;

    scanf("%d", &re);
    while (re--) {
        map<int, int> mpx, mpy;

        scanf("%d%d", &nx, &ny);
        for (int i = 0; i < nx; i++) {
            for (int j = 0; j < ny; j++) {
                xy[i][j] = -inf;
            }
        }
        scanf("%d", &m);
        while (m--) {
            scanf("%d%d%d", &a, &b, &c);
            xy[get_id(mpx, a)][get_id(mpy, b)] = -c;
        }
        printf("%d\n", -KuhnMunkras<int>(nx, ny, mx, my, xy, lx, ly));
    }

    return 0;
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//3049358   2008-08-24 22:12:32     Accepted    3035    C++     00:00.57    1204K   watashi@Zodiac

// 2012-09-07 01:57:08 | Accepted | 3035 | C++ | 200 | 528 | watashi | Source
