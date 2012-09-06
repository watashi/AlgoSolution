#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

int main() {
    int re, n, a, b, ans;
    vector<PII> v, w;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d", &n);
        v.clear();
        v.push_back(make_pair(0, 0));
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &a, &b);
            w.clear();
            for (vector<PII>::const_iterator j = v.begin(); j != v.end(); ++j) {
                w.push_back(make_pair(j->first + a, max(j->first, j->second)));
                w.push_back(make_pair(max(j->first, j->second), j->second + b));
            }
            sort(w.begin(), w.end());
            v.clear();
            for (vector<PII>::const_iterator j = w.begin(); j != w.end(); ++j) {
                if (v.empty() || j->second < v.back().second) {
                    v.push_back(*j);
                }
            }
        }
        ans = 0x7f7f7f7f;
        for (vector<PII>::const_iterator i = v.begin(); i != v.end(); ++i) {
            ans = min(ans, max(i->first, i->second));
        }
        printf("%d\n", ans);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//2168592   2010-04-19 00:03:40     Accepted    3331    C++     30  176     watashi@Zodiac

/*
Submit Time     Language    Run Time(ms)    Run Memory(KB)      User Name
2010-04-19 00:03:09     C++     30  176     watashi@Zodiac
2010-04-18 21:37:11     C++     70  180     Sysu_Water
2010-04-18 02:36:43     C++     80  176     bbirush
2010-04-18 01:02:18     C++     80  264     zqhzx@iStepad
2010-04-18 18:12:16     C++     90  176     cocls
2010-04-18 10:57:46     C++     90  264     code_life
2010-04-18 13:37:03     C++     90  280     xiaobo
2010-04-17 22:20:44     C++     100     184     SCNU20082200090
2010-04-17 23:25:26     C++     100     260     ACer
2010-04-18 07:53:24     C++     100     260     11
2010-04-17 23:36:15     C++     110     256     hhanger@Zodiac
*/

// 2012-09-07 02:08:33 | Accepted | 3331 | C++ | 30 | 180 | watashi | Source
