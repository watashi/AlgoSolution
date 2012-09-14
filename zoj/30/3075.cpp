#include <set>
#include <cstdio>
#include <functional>

using namespace std;

long long a[100001];
multiset<long long, greater<int> > st1, st2;
set<long long>::iterator it;

int main(void)
{
    int n, p, q, t;
    long long f, ans;

    while (scanf("%d%d%d%lld", &n, &p, &q, &f) != EOF) {
        p += 2;
        q += 2;
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
        }
        st1.clear();
        st2.clear();
        ans = a[p] + a[1];
        for (int i = 1; i <= n; i++) {
            if (i >= p) {
                st1.insert(-a[i - p + 1]);
            }
            if (i > q) {
                it = st1.find(-a[i - q]);
                st1.erase(it);
                st2.insert(-a[i - q] + (i - q - 1) * f);
            }
            if (!st1.empty()) {
                ans = min(ans, a[i] - *st1.begin());
            }
            if (!st2.empty()) {
                ans = min(ans, a[i] + (i - q) * f - *st2.begin());
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1801447   2009-03-24 04:58:12     Accepted    3075    C++     680     3996    watashi@Zodiac

// 2012-09-07 02:00:24 | Accepted | 3075 | C++ | 640 | 3996 | watashi | Source
