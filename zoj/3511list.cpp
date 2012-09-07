#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int MAXN = 1 << 14;

int next[MAXN];
pair<int, PII> cut[MAXN];

int gao(int begin, int end) {
    int ret = 0;
    while (begin != end) {
        begin = next[begin];
        ++ret;
    }
    return ret;
}

int main() {
    int n, m, ans, rem, tmp;

    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 0; i < n; ++i) {
            next[i] = i + 1;
        }
        next[n - 1] = 0;

        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &cut[i].second.first, &cut[i].second.second);
            --cut[i].second.first;
            --cut[i].second.second;
            if (cut[i].second.first > cut[i].second.second) {
                swap(cut[i].second.first, cut[i].second.second);
            }
            cut[i].first = cut[i].second.second - cut[i].second.first;
            if (cut[i].first + cut[i].first > n) {
                cut[i].first = n - cut[i].first;
                swap(cut[i].second.first, cut[i].second.second);
            }
        }

        ans = 0;
        rem = n;
        sort(cut, cut + m);
        for (int i = 0; i < m; ++i) {
            tmp = gao(cut[i].second.first, cut[i].second.second);
            ans = max(ans, tmp + 1);
            rem -= tmp - 1;
            next[cut[i].second.first] = cut[i].second.second;
        }
        ans = max(ans, rem);
        printf("%d\n", ans);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//759   2011-06-20 22:13:19     Accepted    B   C++     0   436     admin   Source

// 2012-09-07 16:03:43 | Accepted | 3511 | C++ | 0 | 436 | watashi | Source
