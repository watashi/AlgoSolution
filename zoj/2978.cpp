// solution by whatashya @ zju

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>

using namespace std;

const double eps = 1e-8;

template<typename T>
inline T sqr(const T x)
{
    return x * x;
}

template<typename T>
inline T sqrdist(const pair<T, T>& a, const pair<T, T>& b)
{
    return sqr(a.first - b.first) + sqr(a.second - b.second);
}

int n, r, rr, tmp, ans;
vector<double> in, out;
vector<pair<int, int> > vp;

void doit(const pair<int, int>& src, const pair<int, int>& tar)
{
    int dd = sqrdist(src, tar);
    double x, y, z, a, b;

    if(dd > rr * 4)
        return;
    x = (tar.first - src.first) / 2.0;
    y = (tar.second - src.second) / 2.0;
    z = sqrt((4 * rr - dd) / (double)dd);
    in.push_back(a = atan2(y - z * x, x + z * y));
    out.push_back(b = atan2(y + z * x, x - z * y) + eps);
    if(a > b)
        ++tmp;
}

int main(void)
{
    //  for (double x = 0.0; x <= 3.14; x += 0.1) printf("%lf %lf\n", x, atan2(sin(x), cos(x)));
    while(scanf("%d%d\n", &n, &r) != EOF && n > 0) {
        rr = r * r;
        vp.resize(n);
        for (int i = 0; i < n; i++)
            scanf("%d%d", &vp[i].first, &vp[i].second);
        ans = 0;
        for (int i = 0; i < n; i++) {
            tmp = 0;
            in.clear();
            out.clear();
            for (int j = 0; j < n; j++)
                if(i != j)
                    doit(vp[i], vp[j]);
            sort(in.begin(), in.end());
            sort(out.begin(), out.end());
            ans = max(ans, tmp);
            for (vector<double>::iterator i = in.begin(), it = out.begin(); i != in.end(); ++i) {
                ++tmp;
                while(it != out.end() && *it < *i) {
                    ++it;
                    --tmp;
                }
                ans = max(ans, tmp);
            }
        }
        printf("It is possible to cover %d points.\n", ans + 1);
    }

    return 0;
}

/*
// TODO : .staff.test.sh
*/

//real    0m2.250s
//user    0m2.234s
//sys     0m0.015s

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2948284   2008-06-12 15:40:06     Accepted    2978    C++     00:02.95    916K    Re:ReJudge

// 2012-09-07 01:51:56 | Accepted | 2978 | C++ | 2120 | 180 | watashi | Source
