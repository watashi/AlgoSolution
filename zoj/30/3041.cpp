#include <set>
#include <vector>
#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 200002;

pair<int, int> a[MAXN], b[MAXN];
int ans[MAXN];

int main(void)
{
    int n, m, l, k;

    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &a[i].first, &a[i].second);
        }
        sort(a, a + n);
        for (int j = 0; j < m; j++) {
            scanf("%d%d", &b[j].first, &b[j].second);
        }
        sort(b, b + m);
        for (int j = 1; j < m; j++) {
            b[j].second = max(b[j].second, b[j - 1].second);
        }

        l = 0;
        k = 0;
        for (int i = 0; i < n; i++) {
            while (k < m && b[k].first <= a[i].first) {
                ++k;
            }
            if (k == 0 || a[i].second > b[k - 1].second) {
                ans[l++] = i;
            }
        }

        printf("%d\n", l);
        for (int i = 0; i < l; i++) {
            printf("%d %d\n", a[ans[i]].first, a[ans[i]].second);
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1644799   2008-09-15 15:59:43     Accepted    3041    C++     950     4168    watashi

// 2012-09-07 01:57:45 | Accepted | 3041 | C++ | 720 | 4084 | watashi | Source
