#include <cstdio>
#include <cstring>
#include <numeric>
#include <algorithm>

using namespace std;

const int MAXN = 200200;

char buf[MAXN];
int sum[MAXN];
vector<pair<int, int> > v;

int main() {
    int n, m, l;

    scanf("%s", buf);
    n = (int)strlen(buf);
    sum[0] = 0;
    for (int i = 0; i < n; ++i) {
        sum[i + 1] = sum[i] + (strchr("aeiou", tolower(buf[i])) != NULL ? -1 : 2);
    }

    l = 0;
    for (int i = n; i >= 0; --i) {
        auto it = lower_bound(v.begin(), v.end(), make_pair(sum[i], -1));
        if (it != v.end()) {
            l = max(l, it->second - i);
        }
        if (v.empty() || v.back().first < sum[i]) {
            v.push_back(make_pair(sum[i], i));
        }
    }

    if (l == 0) {
        puts("No solution");
    } else {
        m = 0;
        for (int i = l; i <= n; ++i) {
            if (sum[i] - sum[i - l] >= 0) {
                ++m;
            }
        }
        printf("%d %d\n", l, m);
    }

    return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//1132895 	Feb 2, 2012 3:31:13 PM 	watashi 	137E - Last Chance 	GNU C++0x 	Accepted 	50 ms 	5500 KB
