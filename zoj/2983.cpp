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
#include <functional>

using namespace std;

class Point
{
public:
    inline int& id()
    {
        return _id;
    }
    inline int& x()
    {
        return _pii.first;
    }
    inline int& y()
    {
        return _pii.second;
    }
    inline int _x() const
    {
        return _pii.first;
    }
    inline int _y() const
    {
        return _pii.second;
    }
private:
    int _id;
    pair <int, int> _pii;
}v[1001];

inline bool xpr(const Point& lhs, const Point& rhs)
{
    return lhs._x() < rhs._x() || lhs._x() == rhs._x() && lhs._y() < rhs._y();
}

inline bool ypr(const Point& lhs, const Point& rhs)
{
    return lhs._y() < rhs._y() || lhs._y() == rhs._y() && lhs._x() < rhs._x();
}

struct Edge
{
    pair <char, int> e[2];
}e[1001];

char ans[1001];

int main(void)
{
    int n, a, b, c;

    while(scanf("%d", &n) != EOF && n > 0) {
        for (int i = 0; i < n; i++) {
            v[i].id() = i;
            scanf("%d%d", &v[i].x(), &v[i].y());
        }
        sort(v, v + n, xpr);
        for (int i = 0; i < n; i += 2) {
            a = v[i].id();
            b = v[i + 1].id();
            e[a].e[0] = make_pair('N', b);
            e[b].e[0] = make_pair('S', a);
        }
        c = v[0].id();
        sort(v, v + n, ypr);
        for (int i = 0; i < n; i += 2) {
            a = v[i].id();
            b = v[i + 1].id();
            e[a].e[1] = make_pair('E', b);
            e[b].e[1] = make_pair('W', a);
        }
        a = c;
        b = 0;
        c = -1;
        for (int i = 0; i < n; i++) {
            if(a == 0)
                c = i;
            ans[i] = e[a].e[b].first;
            a = e[a].e[b].second;
            b = 1 - b;
        }
        for (int i = c; i < n; i++)
            putchar(ans[i]);
        for (int i = 0; i < c; i++)
            putchar(ans[i]);
        putchar('\n');
    }

    return 0;
}

/*
real    0m0.078s
user    0m0.046s
sys     0m0.046s
*/


//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2948287   2008-06-12 15:45:53     Accepted    2983    C++     00:00.07    464K    Re:ReJudge

// 2012-09-07 01:52:15 | Accepted | 2983 | C++ | 20 | 208 | watashi | Source
