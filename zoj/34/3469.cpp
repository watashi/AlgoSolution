#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int inf = 1000000000;

int dp[1001][1001][2];
int nl, nr;
vector<pair<int, int> > vl, vr;

int gao(int l, int r, int p) {
    int &ret = dp[l][r][p];

    if (ret == -1) {
        ret = inf;
        if (p == 0) {
            if (l != 0) {
                int tmp = vl[l - 1].second + vr[r].second;
                ret = min(ret, gao(l - 1, r, 0) + (vl[l].first - vl[l - 1].first) * tmp);
                ret = min(ret, gao(l - 1, r, 1) + (vl[l].first + vr[r].first) * tmp);
            }
        } else {
            if (r != 0) {
                int tmp = vl[l].second + vr[r - 1].second;
                ret = min(ret, gao(l, r - 1, 0) + (vl[l].first + vr[r].first) * tmp);
                ret = min(ret, gao(l, r - 1, 1) + (vr[r].first - vr[r - 1].first) * tmp);
            }
        }
    }

    return ret;
}

int main(void)
{
    int n, v, x, xx, bb;

    while (scanf("%d%d%d", &n, &v, &x) != EOF) {
        vl.clear();
        vr.clear();
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &xx, &bb);
            if (xx > x) {
                vr.push_back(make_pair(xx - x, bb));
            }
            else if (xx < x) {
                vl.push_back(make_pair(x - xx, bb));
            }
        }

        vl.push_back(make_pair(0, 0));
        vr.push_back(make_pair(0, 0));
        sort(vl.begin(), vl.end());
        sort(vr.begin(), vr.end());
        nl = vl.size() - 1;
        nr = vr.size() - 1;
        for (int i = 0; i < nl; i++) {
            vl[i].second = vl[i + 1].second;
        }
        vl[nl].second = 0;
        for (int i = nl; i > 0; i--) {
            vl[i - 1].second += vl[i].second;
        }
        for (int i = 0; i < nr; i++) {
            vr[i].second = vr[i + 1].second;
        }
        vr[nr].second = 0;
        for (int i = nr; i > 0; i--) {
            vr[i - 1].second += vr[i].second;
        }

        for (int i = 0; i <= nl; i++) {
            for (int j = 0; j <= nr; j++) {
                dp[i][j][0] = dp[i][j][1] = -1;
            }
        }
        dp[0][0][0] = 0;
        dp[0][0][1] = 0;
        printf("%d\n", v * min(gao(nl, nr, 0), gao(nl, nr, 1)));
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//719   2011-02-11 12:32:00     Accepted    C   C++     400     8008    watashi@ArcOfDream  Source

// 2012-09-07 15:59:15 | Accepted | 3469 | C++ | 400 | 8008 | watashi | Source
