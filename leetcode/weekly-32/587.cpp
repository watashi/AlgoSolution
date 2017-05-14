/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

const double eps = 1e-8;

bool operator <(const Point& lhs, const Point& rhs)
{
    return (lhs.y != rhs.y) ? lhs.y < rhs.y : lhs.x < rhs.x;
}

bool operator ==(const Point& lhs, const Point& rhs)
{
    return (lhs.y == rhs.y) && (lhs.x == rhs.x);
}

Point operator -(const Point& lhs, const Point& rhs)
{
    return Point(lhs.x - rhs.x, lhs.y - rhs.y);
}

int xmult(const Point& lhs, const Point& rhs)
{
    return lhs.x * rhs.y - lhs.y * rhs.x;
}

int GrahamScan(int n, Point p[], Point ret[], bool all = false)
{
    const double eps = all ? ::eps : -::eps;
    int sp, tmp;

    if (n < 3) {
        for (int i = 0; i < n; i++) {
            ret[i] = p[i];
        }
        return n;
    }
    sort(p, p + n);
    ret[0] = p[0];
    ret[1] = p[1];
    sp = 2;
    for (int i = 2; i < n; i++) {
        while (sp > 1 && xmult(ret[sp - 1] - ret[sp - 2], p[i] - ret[sp - 2]) > eps) {
            --sp;
        }
        ret[sp++] = p[i];
    }
    tmp = sp;
    ret[sp++] = p[n - 2];
    for (int i = n - 3; i >= 0; i--) {
        while (sp > tmp && xmult(ret[sp - 1] - ret[sp - 2], p[i] - ret[sp - 2]) > eps) {
            --sp;
        }
        ret[sp++] = p[i];
    }

    return sp - 1;
}

class Solution {
public:
    vector<Point> outerTrees(vector<Point>& points) {
        vector<Point> ret;
        ret.resize(points.size() * 3);
        ret.resize(GrahamScan(points.size(), points.data(), ret.data(), true));
        sort(ret.begin(), ret.end());
        ret.erase(unique(ret.begin(), ret.end()), ret.end());
        return ret;
    }
};
