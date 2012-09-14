#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int mp[50][50];

inline bool pr(const pair <int, int> &lhs, const pair <int, int> &rhs)
{
    return mp[lhs.first][lhs.second] > mp[rhs.first][rhs.second];
}

inline int dist(const pair <int, int> &lhs, const pair <int, int> &rhs)
{
    return abs(lhs.first - rhs.first) + abs(lhs.second - rhs.second);
}

int main(void)
{
    int re, n, m, t;
    int ans;

    scanf("%d", &re);
    while(re--) {
        vector <pair <int, int> > vp;

        scanf("%d%d%d", &n, &m, &t);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                scanf("%d", &mp[i][j]);
                if(mp[i][j] > 0) vp.push_back(make_pair(i, j));
            }
        if(vp.size() == 0) {
            printf("0\n");
            continue;
        }
        sort(vp.begin(), vp.end(), pr);
        t -= 2;
        ans = 0;
        t -= vp[0].first;
        for (size_t i = 0; i < vp.size(); i++) {
            if(i > 0) t -= dist(vp[i - 1], vp[i]);
            if(t <= vp[i].first) break;
            else {
                --t;
                ans += mp[vp[i].first][vp[i].second];
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2772309 2008-03-06 14:07:53 Accepted 2235 C++ 00:00.01 920K ¤ï¤¿¤·

// 2012-09-07 01:16:32 | Accepted | 2235 | C++ | 0 | 188 | watashi | Source
