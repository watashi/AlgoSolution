// 要考虑的情况太多了

#include <cmath>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const double eps = 1e-8;

struct Point
{
    double x, y;
    Point() { }
    Point(double x, double y) : x(x), y(y) { }
};

struct Line
{
    Point a, b;
    Line(const Point& a, const Point& b) : a(a), b(b) { }
};

// ::begin
inline Point operator-(const Point& lhs, const Point& rhs)
{
    return Point(lhs.x - rhs.x, lhs.y - rhs.y);
}

// cross product
inline double operator*(const Point& lhs, const Point& rhs)
{
    return lhs.x * rhs.y - lhs.y * rhs.x;
}
/*
// dot product
inline double operator()(const Point& lhs, const Point& rhs)
{
    return lhs.x * rhs.x + lhs.y * rhs.y;
}

// a b p共线
inline bool same_line(const Point& a, const Point& b, const Point& p)
{
    return fabs((a - p) * (b - p)) < eps;
}

// a和b在l同侧
inline bool same_side(const Point& a, const Point& b, const Line& l)
{
    return ((l.a - l.b) * (a - l.b)) * ((l.a - l.b) * (b - l.b)) > eps;
}

// 点在直线上，含端点
inline bool on_line(const Point& p, const Line& l)
{
    return same_line(l.a, l.b, p) &&
        (l.a.x - p.x) * (l.b.x - p.x) < eps &&
        (l.a.y - p.y) * (l.b.y - p.y) < eps;
}

// 判平行
inline bool parallel(const Line& lhs, const Line& rhs)
{
    return fabs((lhs.a - lhs.b) * (rhs.a - rhs.b)) < eps;
}

// 判相交
inline bool intersect(const Line& lhs, const Line& rhs)
{
    if (!same_line(lhs.a, lhs.b, rhs.a) || !same_line(lhs.a, lhs.b, rhs.b)) {
        return !same_side(lhs.a, lhs.b, rhs) && !same_side(rhs.a, rhs.b, lhs);
    }
    else {
        return on_line(lhs.a, rhs) || on_line(lhs.b, rhs) ||
            on_line(rhs.a, lhs) || on_line(rhs.b, lhs);
    }
}
*/

// a和b在l异侧
bool opposite_side(const Point& a, const Point& b, const Line& l)
{
    return ((l.a - l.b) * (a - l.b)) * ((l.a - l.b) * (b - l.b)) < -eps;
}

// 判规范相交
inline bool intersect(const Line& lhs, const Line& rhs)
{
    return opposite_side(lhs.a, lhs.b, rhs) && opposite_side(rhs.a, rhs.b, lhs);
}

// 在相交且不平行前提下求交点
Point intersection(const Line& lhs, const Line& rhs)
{
    Point ret = lhs.a;
    double r = ((lhs.a - rhs.a) * (rhs.a - rhs.b)) / ((lhs.a - lhs.b) * (rhs.a - rhs.b));

    ret.x += (lhs.b.x - lhs.a.x) * r;
    ret.y += (lhs.b.y - lhs.a.y) * r;

    return ret;
}

bool intersection(const Line& lhs, const Line& rhs, Point& p)
{
    if (!intersect(lhs, rhs)) {
        return false;
    }
    else {
        p = intersection(lhs, rhs);
        return true;
    }
}

// ::end

vector<Point> vp;
vector<pair<int, int> > vl;
vector<vector<int> > ve;

inline bool GT(const double& lhs, const double& rhs)
{
    return lhs > rhs + eps;
}

bool operator<(const Point& lhs, const Point& rhs)
{
    if (GT(lhs.y, rhs.y)) {
        return true;
    }
    else if (GT(rhs.y, lhs.y)) {
        return false;
    }
    else {
        return GT(lhs.x, rhs.x);
    }
}

inline void addPoint(const Point& p)
{
    vp.push_back(p);
    ve.push_back(vector<int>());
}

inline void addLine(int a, int b, bool flag = true)
{
    if (flag) vl.push_back(make_pair(a, b));    // a > b
    ve[a].push_back(b);
    ve[b].push_back(a);
}

bool get_next(int& prev, int& next)
{
    bool ret = false;
    int p = -1, n = -1;
    double k, kk;
    vector<int> v;

    for (size_t i = 0; i < vp.size(); i++) {
        if (fabs(vp[i].y - vp[prev].y) < eps) {
            v.push_back(i);
        }
    }
    for (size_t i = 0; i < v.size(); i++) {
        for (vector<int>::const_iterator j = ve[v[i]].begin(); j != ve[v[i]].end(); ++j) {
            if (GT(vp[v[i]].y, vp[*j].y)) {
                kk = (vp[*j].x - vp[v[i]].x) / (vp[*j].y - vp[v[i]].y);
                if (!ret ||
                    GT(vp[v[i]].x, vp[p].x) ||
                    !GT(vp[p].x, vp[v[i]].x) && (GT(k, kk) || !GT(kk, k) && GT(vp[*j].y, vp[n].y))) {
                        ret = true;
                        k = kk;
                        p = v[i];
                        n = *j;
                }
            }
        }
    }
    prev = p;
    next = n;

    return ret;
}

const double cosa = 1.0 / 2.0, sina = sqrt(3.0) / 2.0;

int main(void)
{
    int n, prev, next;
    double r, h, l, ans;
    Point p;

    while (scanf("%d%lf", &n, &l) != EOF) {
        // handle input
        vp.clear();
        vl.clear();
        ve.clear();
        scanf("%lf%lf", &r, &h);
        addPoint(Point(0, h * l));
        for (int i = 1; i <= n; i++) {
            scanf("%lf%lf", &r, &h);
            h *= l;
            addPoint(Point(r, h));
            addLine(vp.size() - 1, (i == 1) ? 0 : (vp.size() - 6));
            addPoint(Point(r * cosa, h + r * sina));
            addLine(vp.size() - 1, (i == 1) ? 0 : (vp.size() - 6));
            addPoint(Point(r * cosa, h - r * sina));
            addLine(vp.size() - 1, (i == 1) ? 0 : (vp.size() - 6));
            addPoint(Point(0, h + r * sina));
            addPoint(Point(0, h - r * sina));
            addLine(vp.size() - 2, vp.size() - 4);
            addLine(vp.size() - 1, vp.size() - 3);
            addLine(vp.size() - 4, vp.size() - 5);
            addLine(vp.size() - 3, vp.size() - 5);

        }
        // get pic/graph
        for (size_t i = 0; i < vl.size(); i++) {
            for (size_t j = 0; j < i; j++) {
                if (vl[i].first == vl[j].first ||
                    vl[i].second == vl[j].second ||
                    vl[i].first == vl[j].second ||
                    vl[i].second == vl[j].first) {
                        continue;
                }
                else if (!intersection(Line(vp[vl[i].first], vp[vl[i].second]),
                            Line(vp[vl[j].first], vp[vl[j].second]),
                            p)) {
                    continue;
                }
                addPoint(p);
                addLine(vp.size() - 1, vl[i].first, false);
                addLine(vp.size() - 1, vl[i].second, false);
                addLine(vp.size() - 1, vl[j].first, false);
                addLine(vp.size() - 1, vl[j].second, false);
            }
        }
        // calc
        prev = min_element(vp.begin(), vp.end()) - vp.begin();
        ans = 0;
        while (get_next(prev, next)) {
            ans += (vp[prev].x + vp[next].x) * (vp[prev].y - vp[next].y);
            prev = next;
        }
        // output
        printf("%.4lf\n", ans);
    }

    return 0;
}

//3026991 2008-08-07 20:22:07 Accepted 3012 C++ 00:00.11 1544K Re:ReJudge

// 2012-09-07 01:54:53 | Accepted | 3012 | C++ | 60 | 1296 | watashi | Source
