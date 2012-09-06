#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Point
{
    int x, y;
    Point() : x(0), y(0) { }
    Point(const int x, const int y): x(x), y(y) { }
    bool operator<(const Point& rhs) const
    {
        if(x < rhs.x) return true;
        else if(x > rhs.x) return false;
        else return y < rhs.y;
    }
};

struct Line
{
    Point a, b;
    Line() { }
    Line(const Point& a, const Point& b)
    {
        if(a.y < b.y) {
            this->a = a;
            this->b = b;
        }
        else {
            this->a = b;
            this->b = a;
        }
    }
    bool operator<(const Line& rhs) const
    {
        if(a < rhs.a) return true;
        else if(rhs.a < a) return false;
        else return b < rhs.b;
    }
};

bool InLeft(const Point& p, const Line& l)
{
    int x1 = l.b.x - l.a.x, y1 = l.b.y - l.a.y, x2 = p.x - l.a.x, y2 = p.y - l.a.y;
    return x1 * y2 - x2 * y1 > 0;
}

int cnt[1024];

int main(void)
{
    int n, m, l, r, mid;
    int x1, y1, x2, y2;
    Point p;
    vector<Line> ls;

    while(scanf("%d%d", &n, &m) == 2 && n > 0) {
        ls.clear();
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        ls.push_back(Line(Point(x1, y1), Point(x1, y2)));
        ls.push_back(Line(Point(x2, y1), Point(x2, y2)));
        while(n--) {
            scanf("%d%d", &x1, &x2);
            ls.push_back(Line(Point(x1, y1), Point(x2, y2)));
        }
        n = (int)ls.size();
        sort(ls.begin(), ls.end());
        fill(cnt, cnt + n, 0);
        while(m--) {
            scanf("%d%d", &x1, &x2);
            p.x = x1;
            p.y = x2;
            l = 0;
            r = n - 1;
            while(l < r) {
                mid = (l + r) >> 1;
                if(InLeft(p, ls[mid])) r = mid;
                else l = mid + 1;
            }
            ++cnt[r];
        }
        sort(cnt, cnt + n);
        l = 0;
        while(l < n) {
            for (r = l + 1; r < n && cnt[r] == cnt[l]; r++);
            if(cnt[l] == 0) puts("Box");
            else printf("%d: %d\n", cnt[l], r - l);
            l = r;
        }
    }

    return 0;
}

//2799613 2008-03-23 22:23:02 Accepted 1996 C++ 00:00.00 876K わたし

/*
Rank Submit time Run time Run memory Language User
1 2006-09-28 13:16:03 00:00.00 452K C++ SHiVa
2 2006-05-16 16:42:15 00:00.00 464K C++ Freedom
3 2006-09-28 13:15:40 00:00.00 464K C++ ÅÆÇ
4 2008-03-23 22:23:02 00:00.00 876K C++ わたし
5 2005-09-14 00:05:28 00:00.01 412K C Leave me alone
6 2006-09-29 13:20:51 00:00.01 412K C++ ERIC
7 2006-02-02 11:11:39 00:00.01 420K C++ wcm
8 2006-10-01 09:18:24 00:00.01 456K C++ Endless Rain
9 2006-03-06 15:39:04 00:00.01 472K C++ ant
10 2008-02-01 17:58:29 00:00.01 476K C++ 王~~
11 2007-04-22 12:01:01 00:00.01 852K C++ 阿九
12 2007-04-22 13:44:30 00:00.01 856K C++ van
13 2006-04-01 08:14:48 00:00.02 412K C Nubix
*/

// 2012-09-07 04:44:32 | Accepted | 1996 | C++ | 0 | 184 | watashi | Source
