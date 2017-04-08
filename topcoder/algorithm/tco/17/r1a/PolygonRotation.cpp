#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <utility>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

#define ALL(c) (c).begin(), (c).end()
#define FOR(i, n) for (int i = 0; i < (int)(n); ++i)
#define MEMSET(p, c) memset(p, c, sizeof(p))
typedef int64_t LL;
typedef pair<double, double> PDD;
const int E9 = 1000000000;
/// BEGIN CUT HERE
// <errf>
inline void errf(const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  vfprintf(stderr, fmt, args);
  va_end(args);
}

template<typename T>
inline void errf(const char *fmt, const vector<T>& v) {
  errf("{");
  for (const auto& i: v) {
    errf(fmt, i);
  }
  errf("}\n");
}
// </errf>
/// END CUT HERE
#ifndef __WATASHI__
#define errf(fmt, ...) do { } while (false)
#endif

struct PolygonRotation {
  double getVolume(vector <int> x, vector <int> y);
};

double volume(double r1, double r2, double h) {
  return M_PI * h * (r1 * r1 + r2 * r2 + r1 * r2) / 3;
}

double fx(const vector<PDD>& v, double y) {
  auto it = upper_bound(ALL(v), make_pair(y, 1e100)) - 1;
  if (it->first == y) {
    return it->second;
  } else {
    auto a = *it, b = *(it + 1);
    return a.second + 1.0 * (y - a.first) / (b.first - a.first) * (b.second - a.second);
  }
}

vector<PDD> compress(const vector<PDD>& v) {
  vector<PDD> ret;
  for (auto i: v) {
    if (!ret.empty() && ret.back().first == i.first) {
      ret.back().second = max(ret.back().second, i.second);
    } else {
      ret.push_back(i);
    }
  }
  return ret;
}

void intersect(const PDD& p1, const PDD& p2, const PDD& q1, const PDD& q2, vector<double>& ret) {
  double y1 = max(p1.first, q1.first), y2 = min(p2.first, q2.first);
  if (y1 >= y2) {
    return;
  }
  double k1 = 1.0 * (p2.second - p1.second) / (p2.first - p1.first);
  double k2 = 1.0 * (q2.second - q1.second) / (q2.first - q1.first);
  if (fabs(k1 - k2) < 1e-8) {
    return;
  }
  double y = ((k1 * p1.first - p1.second) - (k2 * q1.first - q1.second)) / (k1 - k2);
  if (y1 < y && y < y2) {
    ret.push_back(y);
  }
}

double PolygonRotation::getVolume(vector <int> x, vector <int> y) {
  vector<PDD> a, b;
  a.emplace_back(y[0], x[0]);
  for (int i = 1; i < (int)x.size(); ++i) {
    if (x[i] >= 0) {
      a.emplace_back(y[i], x[i]);
    }
    if (x[i] <= 0) {
      b.emplace_back(y[i], -x[i]);
    }
  }
  b.emplace_back(y[0], x[0]);
  reverse(a.begin(), a.end());
  a = compress(a);
  b = compress(b);
  errf("(%lf, %lf) ", a);
  errf("(%lf, %lf) ", b);

  vector<double> yy(ALL(y));
  for (int i = 1; i < (int)a.size(); ++i) {
    for (int j = 0; j < (int)b.size(); ++j) {
      intersect(a[i - 1], a[i], b[j - 1], b[j], yy);
    }
  }
  sort(ALL(yy));
  yy.erase(unique(ALL(yy)), yy.end());
  errf("%lf ", yy);


  double ret = 0;
  for (int i = 1; i < (int)yy.size(); ++i) {
    double r1 = max(fx(a, yy[i - 1]), fx(b, yy[i - 1]));
    double r2 = max(fx(a, yy[i]), fx(b, yy[i]));
    errf("%lf %lf %lf\n", r1, r2, yy[i] - yy[i - 1]);
    ret += volume(r1, r2, yy[i] - yy[i - 1]);
  }
  return ret;
}

/// BEGIN CUT HERE
// <main>
#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))

template<typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
  os << "{";
  FOR(i, v.size()) {
    os << "\"" << v[i] << "\",";
  }
  os << "}";

  return os;
}

vector<bool> __eq__;

template<typename S, typename T>
void eq(int id, S v1, T v2) {
  ostringstream s1, s2;

  s1 << v1;
  s2 << v2;

  errf("Case #%d: ", id);
  if (s1.str() == s2.str()) {
    __eq__.push_back(true);
    errf("\033[1;32mPassed\033[0m\n");
  } else {
    __eq__.push_back(false);
    errf("\033[1;31mFailed\033[0m\n");
    errf("\tReceived \"%s\"\n", s1.str().c_str());
    errf("\tExpected \"%s\"\n", s2.str().c_str());
  }
}

int main(int argc, char *argv[]) {
  (void)argc;
  (void)argv;

      {
        int xARRAY[] = {0, 1, 1, 0};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {1, 1, 0, 0};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        PolygonRotation theObject;
        eq(0, theObject.getVolume(x, y),3.141592653589793);
    }
    {
        int xARRAY[] = {0, 1, 0, -1};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {2, 1, 0, 1};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        PolygonRotation theObject;
        eq(1, theObject.getVolume(x, y),2.0943951023931953);
    }
    {
        int xARRAY[] = {0, 3, 0, -2, -2};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {2, 0, -3, -1, 1};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        PolygonRotation theObject;
        eq(2, theObject.getVolume(x, y),49.91641660703782);
    }
    {
        int xARRAY[] = {0, 3, 3, 0, -1, -1};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {2, 2, -2, -2, -1, 1};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        PolygonRotation theObject;
        eq(3, theObject.getVolume(x, y),113.09733552923255);
    }

  int __pass__ = count(ALL(__eq__), true);
  int __fail__ = count(ALL(__eq__), false);
  if (__fail__ == 0) {
    errf("\033[1;32mAll %d Passed\033[0m\n", __pass__);
  } else if (__pass__ == 0) {
    errf("\033[1;31mAll %d Failed\033[0m\n", __fail__);
  } else {
    errf("\033[1;31m%d Passed; %d Failed\033[0m\n", __pass__, __fail__);
    if (__eq__[0]) {
      errf("\033[1;31mDid you reset global variables?\033[0m\n");
    }
  }
  errf("\033[1;33mPress any key to continue...\033[0m\n");
  getchar();

  return 0;
}

/*
 * __builtin_popcount __builtin_ctz
 * make_pair first second
 * iterator const_iterator
 * priority_queue
 * push_back
 */
/*
 * vim: ft=cpp.doxygen
 */
// </main>
/// END CUT HERE
