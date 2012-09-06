#include <cmath>
#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 10001;

double k[MAXN], b[MAXN];

bool pr1(const pair<double, int>& lhs, const pair<double, int>& rhs)
{
    static const double eps = 1e-8;

    if (fabs(lhs.first - rhs.first) > eps) {
        return lhs.first < rhs.first;
    }
    else {
        return k[lhs.second] < k[rhs.second];
    }
}

bool pr2(const pair<double, int>& lhs, const pair<double, int>& rhs)
{
    static const double eps = 1e-8;

    if (fabs(lhs.first - rhs.first) > eps) {
        return lhs.first < rhs.first;
    }
    else {
        return lhs.second < rhs.second;
    }
}

int inv(int n, int a[])
{
    static int b[MAXN];
    int i, j, k, t, ret = 0;

    if (n <= 1) {
        return ret;
    }
    t = n / 2;
    ret = inv(t, a) + inv(n - t, a + t);
    for (i = 0, j = t, k = 0; i < t && j < n; ) {
        if (a[i] <= a[j]) {
            b[k++] = a[i++];
        }
        else {
            ret += t - i;
            b[k++] = a[j++];
        }
    }
    while (i < t) {
        b[k++] = a[i++];
    }
    while (j < n) {
        b[k++] = a[j++];
    }
    for (k = 0; k < n; k++) {
        a[k] = b[k];
    }

    return ret;
}

pair<double, int> v[MAXN];
int a[MAXN];

int main(void)
{
    int i, n;
    double x1, y1, x2, y2;
    double l, r;

    while (scanf("%d", &n) != EOF) {
        for (i = 0; i < n; i++) {
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            k[i] = (y2 - y1) / (x2 - x1);
            b[i] = (x2 * y1 - x1 * y2) / (x2 - x1);
        }
        scanf("%lf%lf", &l, &r);
        for (i = 0; i < n; i++) {
            v[i].first = k[i] * l + b[i];
            v[i].second = i;
        }
        sort(v, v + n, pr1);
        for (i = 0; i < n; i++) {
            v[i].first = k[v[i].second] * r + b[v[i].second];
            v[i].second = i;
        }
        sort(v, v + n, pr2);
        for (i = 0; i < n; i++) {
            a[i] = v[i].second;
//          printf("%d", a[i]);
        }
        printf("%d\n", inv(n, a));
//      printf("%d%d%d\n", a[0], a[1], a[2]);
    }

    return 0;
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1748026   2009-01-24 17:27:23     Accepted    3157    C++     80  528     watashi@Zodiac

// 2012-09-07 02:04:23 | Accepted | 3157 | C++ | 60 | 532 | watashi | Source
