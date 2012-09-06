//二分图最大匹配,hungary算法,邻接表形式,邻接阵接口,复杂度O(m*e)s
//返回最大匹配数,传入二分图大小m,n和邻接阵
//match1,match2返回一个最大匹配,未匹配顶点match值为-1

#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 128;

int Hungary(int nl, int nr, int ml[], int mr[], const vector<int> e[])
{
    int ret = 0;
    static int p, t, q[MAXN], pre[MAXN];

    memset(ml, 0xff, nl * sizeof(int));
    memset(mr, 0xff, nr * sizeof(int));
    for (int i = 0; i < nl; i++) {
        memset(pre, 0xff, nr * sizeof(int));
        q[0] = i;
        p = 0;
        t = 1;
        while (p < t) {
            for (vector<int>::const_iterator i = e[q[p]].begin(); i < e[q[p]].end(); ++i) {
                if (pre[*i] == -1) {
                    pre[*i] = q[p];
                    if (mr[*i] == -1) {
                        int y, yy = *i;

                        do {
                            y = yy;
                            yy = ml[pre[y]];
                            ml[pre[y]] = y;
                            mr[y] = pre[y];
                        } while (yy != -1);
                        ++ret;
                        t = -1;
                        break;
                    }
                    else {
                        q[t++] = mr[*i];
                    }
                }
            }
            ++p;
        }
    }

    return ret;
}

int mat1[MAXN], mat2[MAXN];
int p[MAXN][2], t[MAXN][2];
double d[MAXN][MAXN];
vector<int> e[MAXN];

double dist(int i, int j)
{
    double x = p[i][0] - t[j][0], y = p[i][1] - t[j][1];

    return sqrt(x * x + y * y);
}

int main(void)
{
    int n, m;
    double l, r, mid, v;

    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &p[i][0], &p[i][1]);
        }
        for (int j = 0; j < m; j++) {
            scanf("%d%d", &t[j][0], &t[j][1]);
        }
        scanf("%lf\n", &v);
        r = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                d[i][j] = dist(i, j);
                if (d[i][j] > r) {
                    r = d[i][j];
                }
            }
        }
        l = 0;
        while (fabs(r - l) > 1e-6 * v) {
            mid = (l + r) / 2;
            for (int i = 0; i < n; i++) {
                e[i].clear();
                for (int j = 0; j < m; j++) {
                    if (d[i][j] <= mid) {
                        e[i].push_back(j);
                    }
                }
            }
            if (Hungary(n, m, mat1, mat2, e) == n) {
                r = mid;
            }
            else {
                l = mid;
            }
//          printf("%lf %lf\n", l, r);
        }
        printf("%.2lf\n", (l + r) / (2 * v));
    }

    return 0;
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1748023   2009-01-24 17:25:22     Accepted    3156    C++     20  312     watashi@Zodiac

// 2012-09-07 02:04:17 | Accepted | 3156 | C++ | 20 | 312 | watashi | Source
