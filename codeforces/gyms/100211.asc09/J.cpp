#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const double EPS = 1e-8;

struct Point3D;
double dot(const Point3D&, const Point3D&);
Point3D cross(const Point3D&, const Point3D&);

struct Point3D {
  double x, y, z;

  Point3D() { }
  Point3D(double x, double y, double z): x(x), y(y), z(z) { }

  double abs() const {
    return sqrt(dot(*this, *this));
  }

  Point3D scale(double o) const {
    return {o * x, o * y, o * z};
  }

  Point3D trunc(double o) const {
    return scale(o / abs());
  }

  Point3D operator+(const Point3D& o) const {
    return {x + o.x, y + o.y, z + o.z};
  }

  Point3D operator-(const Point3D& o) const {
    return {x - o.x, y - o.y, z - o.z};
  }

  Point3D proj(const Point3D& x, const Point3D& y, const Point3D& z) {
    // assert(cross(x, y) == z);
    // assert(x.abs() == 1 && y.abs() == 1 && z.abs() == 1);
    return {dot(*this, x), dot(*this, y), dot(*this, z)};
  }
};

double dot(const Point3D& a, const Point3D& b) {
  return a.x * b.x + a.y * b.y + a.z * b.z;
}

Point3D cross(const Point3D& a, const Point3D& b) {
  return {a.y * b.z - b.y * a.z,
          a.z * b.x - b.z * a.x,
          a.x * b.y - b.x * a.y};
}

istream& operator>>(istream& is, Point3D& o) {
  is >> o.x >> o.y >> o.z;
  return is;
}

ostream& operator<<(ostream& os, const Point3D& o) {
  os << o.x << " " << o.y << " " << o.z;
  return os;
}

vector<double> gao(double x0, double y0, double dx, double dy, double r) {
  double a = dx * dx + dy * dy;
  double b = -2 * (dx * x0 + dy * y0);
  double c = x0 * x0 + y0 * y0 - r * r;
  double d = b * b - 4 * a * c;
  if (fabs(a) < EPS) {
    return {};  // The origin of the ray is outside the cylinder.
  } else {
    if (d < -EPS) {
      return {};
    } else if (d < EPS) {
      d = 0;
    } else {
      d = sqrt(d);
    }
    return {(-b - d) / (2 * a), (-b + d) / (2 * a)};
  }
}

int main() {
  double r, ans;
  Point3D a, u, b, v;
  Point3D sx, sy, sz, tx, ty, tz;

#ifndef __WATASHI__
  freopen("tracing.in", "r", stdin);
  freopen("tracing.out", "w", stdout);
#endif

  cin >> a >> u >> r >> b >> v;
  u = u - a;
  v = v - b;

  sx = {1, 0, 0};
  sy = {0, 1, 0};
  sz = u.trunc(1);
  if (cross(sy, sz).abs() < EPS) {
    sx = cross(sy, sz).trunc(1);
    sy = cross(sz, sx).trunc(1);
  } else {
    sy = cross(sz, sx).trunc(1);
    sx = cross(sy, sz).trunc(1);
  }

  a = a.proj(sx, sy, sz);
  u = u.proj(sx, sy, sz);
  b = b.proj(sx, sy, sz);
  v = v.proj(sx, sy, sz);

  ans = numeric_limits<double>::max();
  if (fabs(v.z) > EPS) {
    for (Point3D c: {a, a + u}) {
      double t = (c.z - b.z) / v.z;
      Point3D p = b + v.scale(t);
      if (t > EPS && (p - c).abs() < r + EPS) {
        ans = min(ans, t);
      }
    }
  }
  for (double t: gao(a.x - b.x, a.y - b.y, v.x, v.y, r)) {
    Point3D p = b + v.scale(t);
    if (t > EPS && a.z - EPS < p.z && p.z < a.z + u.z + EPS) {
      ans = min(ans, t);
    }
  }

  if (ans == numeric_limits<double>::max()) {
    cout << "NONE" << endl;
  } else {
    tx = Point3D({1, 0, 0}).proj(sx, sy, sz);
    ty = Point3D({0, 1, 0}).proj(sx, sy, sz);
    tz = Point3D({0, 0, 1}).proj(sx, sy, sz);
    cout << (b + v.scale(ans)).proj(tx, ty, tz) << endl;
  }

  return 0;
}

