//太ym了，这种模型好神奇~
//……复杂度居然就是O(n^3)的，虽然不会有这样的case……

#include <map>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

#pragma warning(disable:4996)

const double inf = 1e111;

map<string, int> mp;
vector<vector<int> > tr;

double v;
vector<double> vp;
vector<int> cnt;
double dp[1000][1000];

void gao(int p)
{
    int s = 0;

    dp[p][0] = 0;
    for (vector<int>::const_iterator i = tr[p].begin(); i != tr[p].end(); ++i) {
        gao(*i);
        if (cnt[*i] == 0) {
            continue;
        }
        for (int j = s + cnt[*i]; j > s; j--) {
            dp[p][j] = inf;
        }
        s += cnt[*i];
        for (int j = s; j > 0; j--) {
            for (int k = cnt[*i]; k > 0; k--) {
                if (j >= k) {
                    dp[p][j] = min(dp[p][j], dp[p][j - k] + dp[*i][k]);
                }
            }
        }
    }
    if (s == 0) {
        dp[p][1] = vp[p] / v;
    }
    else {
        for (int i = s; i > 0; i--) {
            dp[p][i + 1] = dp[p][i] + vp[p] / (v + i);
        }
        dp[p][1] = inf;
    }

    cnt[p] = s + 1;
}

int main(void)
{
    int n, p;
    char a[256], b[256];

    while(scanf("%d%lf", &n, &v) != EOF) {
        mp.clear();
        vp.resize(n);
        for (int i = 0; i < n; i++) {
            scanf("%s%d", a, &p);
            mp[a] = i;
            vp[i] = p;
        }
        //tr.swap(vector<vector<int> >(n));
        tr = vector<vector<int> >(n);
        for (int i = 1; i < n; i++) {
            scanf("%s%s", a, b);
            tr[mp[b]].push_back(mp[a]);
        }
        scanf("%s", a);
        p = mp[a];
        //cnt.swap(vector<int>(n, 0));
        cnt = vector<int>(n, 0);
        gao(p);
        printf("%.2lf\n", *min_element(dp[p] + 1, dp[p] + cnt[p] + 1));
    }

    return 0;
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2954394   2008-06-22 07:45:47     Accepted    3003    C++     00:00.04    8744K   Re:ReJudge

// 2012-09-07 01:53:58 | Accepted | 3003 | C++ | 10 | 7992 | watashi | Source
