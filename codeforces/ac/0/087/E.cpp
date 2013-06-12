// TAG: Minkowski sum

/*
http://en.wikipedia.org/wiki/Minkowski_addition#Two_convex_polygons_in_the_plane

For two convex polygons P and Q in the plane with m and n vertices, their
Minkowski sum is a convex polygon with at most m + n vertices and may be
computed in time O (m + n) by a very simple procedure, which may be informally
described as follows. Assume that the edges of a polygon are given and the
direction, say, counterclockwise, along the polygon boundary. Then it is easily
seen that these edges of the convex polygon are ordered by polar angle. Let us
merge the ordered sequences of the directed edges from P and Q into a single
ordered sequence S. Imagine that these edges are solid arrows which can be
moved freely while keeping them parallel to their original direction. Assemble
these arrows in the order of the sequence S by attaching the tail of the next
arrow to the head of the previous arrow. It turns out that the resulting
polygonal chain will in fact be a convex polygon which is the Minkowski sum of
P and Q.
*/

#include <map>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long llint;

struct Point {
  llint x, y;

  Point () { }
  Point (llint x_, llint y_): x(x_), y(y_) { }
  Point operator+(const Point& o) const { return Point(x + o.x, y + o.y); }
  Point operator-(const Point& o) const { return Point(x - o.x, y - o.y); }
  llint operator%(const Point& o) const { return x * o.y - y * o.x; }
  double arg() const { return atan2(y, x); }
};

Point offset(const vector<Point>& p) {
  Point ret = p[0];
  for (const auto& i: p) {
    ret.x = min(ret.x, i.x);
    ret.y = min(ret.y, i.y);
  }
  return ret;
}

void diff(const vector<Point>& p, vector<pair<double, Point> >& ret) {
  for (int i = 0; i < (int)p.size(); ++i) {
    Point d = p[(i + 1) % (int)p.size()] - p[i];
    ret.push_back({d.arg(), d});
  }
}

vector<Point> minkowskiSum(const vector<Point>& a, const vector<Point>& b) {
  Point off = offset(a) + offset(b);
  vector<pair<double, Point> > v;
  vector<Point> ret;

  diff(a, v);
  diff(b, v);
  sort(v.begin(), v.end(),
    [](const pair<double, Point>& lhs, const pair<double, Point>& rhs) {
      return lhs.first < rhs.first;
    });
  for (const auto& i: v) {
    ret.push_back(i.second);
  }
  partial_sum(ret.begin(), ret.end(), ret.begin());
  off = off - offset(ret);
  for (auto& i: ret) {
    i = i + off;
  }

  return ret;
}

vector<Point> readConvect() {
  int n;
  vector<Point> ret;

  scanf("%d", &n);
  ret.resize(n);
  for (int i = 0; i < n; ++i) {
    scanf("%I64d%I64d", &ret[i].x, &ret[i].y);
  }

  return ret;
}

int main() {
  vector<Point> u = readConvect();
  vector<Point> v = readConvect();
  vector<Point> w = readConvect();
  vector<Point> p = minkowskiSum(minkowskiSum(u, v), w);

  Point o;
  map<double, Point> mp;

  // @see: CF70D (query point in convex polygen)
  o = Point(0, 0);
  for (const auto& i: p) {
    o = o + i;
  }
  o.x /= (int)p.size();
  o.y /= (int)p.size();
  for (auto& i: p) {
    i = i - o;
    mp[i.arg()] = i;
  }

  int n;
  Point q, a, b;
  map<double, Point>::iterator it;

  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%I64d%I64d", &q.x, &q.y);
    q.x *= 3;
    q.y *= 3;
    q = q - o;
    if (q.x == 0 && q.y == 0) {
      puts("YES");
    } else {
      it = mp.lower_bound(q.arg());
      b = (it == mp.end() ? mp.begin() : it)->second;
      a = it == mp.begin() ? mp.rbegin()->second : (--it)->second;
      puts((b - a) % (q - a) >= 0 ? "YES" : "NO");
    }
  }

  return 0;
}

