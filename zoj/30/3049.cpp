#include <string>
#include <utility>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

const int inf = 123456789;

pair<int, int> p[1024];
int dp[10240];

int main(void)
{
    int n, m, p0, sum, ans, p1, p2;
    string cur;

    while (cin >> n >> p0) {
        while (cin.get() != '\n');
        sum = 0;
        ans = 0;
        m = 0;
        for (int i = 0; i < n; i++) {
            getline(cin, cur);
            istringstream iss(cur);
            iss >> p1;
            if (iss >> p2) {
                p[m++] = make_pair(max(p2 - p1 - p0, 0), p1);
            }
            else {
                sum += p1;
            }
            ans += p1;
        }
/*
*/

        for (int i = 0; i <= p0; i++) {
            dp[i] = inf;
        }
        dp[min(sum, p0)] = 0;
        for (int i = 0; i < m; i++) {
            for (int j = p0; j >= 0; j--) {
                int to = min(p0, j + p[i].second);
                dp[to] = min(dp[to], dp[j] + p[i].first);
            }
        }

        if (dp[p0] != inf) {
            ans -= dp[p0];
            for (int i = 0; i < m; i++) {
                ans += p[i].first;
            }
        }
/*
*/
        cout << ans << endl;
    }

    return 0;
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1711132   2008-11-26 21:23:29     Accepted    3049    C++     120     232     watashi@Zodiac

// 2012-09-07 01:58:34 | Accepted | 3049 | C++ | 140 | 236 | watashi | Source
