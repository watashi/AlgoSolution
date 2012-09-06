#include <map>
#include <cstdio>
#include <limits>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    int x, y;

    while (scanf("%d%d", &n, &m) != EOF) {
        map<int, int> mp;
        map<int, int>::iterator it;

        while (n--) {
            scanf("%d%d", &x, &y);
            it = mp.insert(make_pair(2 * x + y, x)).first;
            it->second = min(x, it->second);
        }

        vector<pair<int, int> > ans;

        while (m--) {
            scanf("%d%d", &x, &y);
            if (((it = mp.find(2 * x + y)) == mp.end() || it->second > x) &&
                    ((it = mp.find(2 * x + y - 2)) == mp.end() || it->second >= x) &&
                    ((it = mp.find(2 * x + y - 1)) == mp.end() || it->second >= x) &&
                    ((it = mp.find(2 * x + y + 1)) == mp.end() || it->second > x) &&
                    ((it = mp.find(2 * x + y + 2)) == mp.end() || it->second > x)
                    ) {
                ans.push_back(make_pair(x, y));
            }
        }
        sort(ans.begin(), ans.end());

        printf("%u\n", ans.size());
        for (size_t i = 0; i < ans.size(); i++) {
            printf("(%d,%d)\n", ans[i].first, ans[i].second);
        }
    }

    return 0;
}



//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1644792   2008-09-15 15:44:39     Accepted    3042    C++     490     3480    watashi

// 2012-09-07 01:57:51 | Accepted | 3042 | C++ | 480 | 3400 | watashi | Source
