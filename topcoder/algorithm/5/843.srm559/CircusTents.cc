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
#define FOREACH(i, n) for (typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
#define MEMSET(p, c) memset(p, c, sizeof(p))
typedef long long llint;
typedef pair<int, int> PII;
/// BEGIN CUT HERE
#define WATASHI_PC

inline void errf(const char *fmt, ...) {
	va_list args;
	va_start(args, fmt);
	vfprintf(stderr, fmt, args);
	va_end(args);
}

template<typename T>
inline void errf(const char *fmt, const vector<T>& v) {
	errf("{");
	FOR(i, v.size()) {
		errf(fmt, v[i]);
	}
	errf("}\n");
}
// TODO
/// END CUT HERE
#ifndef WATASHI_PC
#define errf(fmt, ...) do { } while (false)
#endif

struct CircusTents {
	double findMaximumDistance(vector <int> x, vector <int> y, vector <int> r);
};

const int MAXN = 127;
const int RE = 100;
const double PI = M_PI;
const double EPS = 1e-10;
typedef pair<double, double> Range;

const Range EMPTY(PI, -PI);
const Range FULL(-PI, PI);

// [0, 2*PI]
double normalize(double x) {
  x = fmod(x, 2 * PI);
  x = fmod(x + 2 * PI, 2 * PI);
  return x;
}

struct Function {
  double d, z, r, alpha, beta;

  void init(double x, double y, double z, double r) {
    this->d = hypot(x, y);
    this->z = z;
    this->r = r;
    this->alpha = atan2(y, x);
    this->beta = acos(r / d);
  }

  double dist(double delta) const {
    double x = r * cos(delta);
    double y = r * sin(delta);
    return hypot(x - d, y) - z;
  }

  double eval(double delta) const {
    // delta = normalize(delta - alpha);
    delta = normalize(delta);
    if (delta > PI) {
      delta = 2 * PI - delta;
    }
    // [0, PI]
    if (delta <= beta) {
      return dist(delta);
    } else {
      return dist(beta) + (delta - beta) * r;
    }
  }

  // [-PI, PI]
  Range reval(double t) const {
    if (eval(0) > t) {
      return EMPTY;
    } else if (eval(PI) <= t) {
      return FULL;
    } else {
      double lo = 0, hi = PI;
      for (int it = 0; it < RE; ++it) {
        double mi = (lo + hi) / 2;
        if (eval(mi) <= t) {
          lo = mi;
        } else {
          hi = mi;
        }
      }
      lo = (lo + hi) / 2;
      // printf("lo = %lf\n", lo);
      return Range(-lo, lo);
    }
  }
} f[MAXN];

bool ok(int n, double x) {
  vector<Range> good;
  good.push_back(Range(-2 * PI, 2 * PI));
  // printf("x = %lf\n", x);
  for (int i = 1; i < n; ++i) {
    Range t = f[i].reval(x);
    if (t == FULL) {
      return false;
    } else if (t == EMPTY) {
      continue;
    }
    vector<Range> lhs = good;
    vector<Range> rhs;
    t.first += f[i].alpha;
    t.second += f[i].alpha;
    swap(t.first, t.second);
    t.first -= 2 * PI;
    for (int j = -2; j <= 2; j += 2) {
      rhs.push_back(Range(t.first + j * PI, t.second + j * PI));
    }
    good.clear();
    for (vector<Range>::const_iterator it = lhs.begin(); it != lhs.end(); ++it) {
      for (vector<Range>::const_iterator jt = rhs.begin(); jt != rhs.end(); ++jt) {
        Range tmp(max(it->first, jt->first), min(it->second, jt->second));
        // printf(">[%lf, %lf]\n", tmp.first, tmp.second);
        if (tmp.second - tmp.first > EPS) {
          good.push_back(tmp);
        }
      }
    }
    if (good.empty()) {
      return false;
    }
  }
  return true;
}

double CircusTents::findMaximumDistance(vector <int> x, vector <int> y, vector <int> r) {
  int n = x.size();
  for (int i = 1; i < n; ++i) {
    f[i].init(x[i] - x[0], y[i] - y[0], r[i], r[0]);
    // printf("%lf %lf %lf\n", f[i].d, f[i].alpha, f[i].beta);
    // printf("%lf %lf\n", f[i].reval(3).first, f[i].reval(3).second);
    // printf("eval(PI) = %lf\n", f[i].eval(PI));
  }

  double lo = 0, hi = 1e6;
  for (int it = 0; it < RE; ++it) {
    double mi = (lo + hi) / 2;
    if (ok(n, mi)) {
      lo = mi;
    } else {
      hi = mi;
    }
  }
  return (lo + hi) / 2;
}

/// BEGIN CUT HERE
// TODO
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

template<typename S, typename T>
void eq(int id, S v1, T v2) {
	ostringstream s1, s2;

	s1 << v1;
	s2 << v2;

	errf("Case #%d: ", id);
	if (s1.str() == s2.str()) {
		errf("\033[1;32mPassed\033[0m\n");
	} else {
		errf("\033[1;31mFailed\033[0m\n");
		errf("\tReceived \"%s\"\n", s1.str().c_str());
		errf("\tExpected \"%s\"\n", s2.str().c_str());
	}
}

int main(int argc, char *argv[]) {
	    {
        int xARRAY[] = {0,3};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {0,0};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        int rARRAY[] = {1,1};
        vector <int> r( rARRAY, rARRAY+ARRSIZE(rARRAY) );
        CircusTents theObject;
        eq(0, theObject.findMaximumDistance(x, y, r),3.7390603609952078);
    }
    {
        int xARRAY[] = {0,3,-3,3,-3};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {0,3,3,-3,-3};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        int rARRAY[] = {1,1,1,1,1};
        vector <int> r( rARRAY, rARRAY+ARRSIZE(rARRAY) );
        CircusTents theObject;
        eq(1, theObject.findMaximumDistance(x, y, r),2.6055512754639887);
    }
    {
        int xARRAY[] = {3,7,7,7,3};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {4,6,1,-3,0};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        int rARRAY[] = {2,2,2,1,1};
        vector <int> r( rARRAY, rARRAY+ARRSIZE(rARRAY) );
        CircusTents theObject;
        eq(2, theObject.findMaximumDistance(x, y, r),4.3264459099620725);
    }
    {
        int xARRAY[] = {10,-1};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {0,0};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        int rARRAY[] = {8,2};
        vector <int> r( rARRAY, rARRAY+ARRSIZE(rARRAY) );
        CircusTents theObject;
        eq(3, theObject.findMaximumDistance(x, y, r),24.63092458664212);
    }
    {
        int xARRAY[] = {0,4,-4};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {0,4,-4};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        int rARRAY[] = {1,1,1};
        vector <int> r( rARRAY, rARRAY+ARRSIZE(rARRAY) );
        CircusTents theObject;
        eq(4, theObject.findMaximumDistance(x, y, r),4.745474963675133);
    }

	puts("\033[1;33mPress any key to continue...\033[0m");
	getchar();

	return 0;
}

/*
 * __builtin_popcount __builtin_ctz make_pair
 * priority_queue
 * push_back
 * first second iterator const_iterator
 */
/*
 * vim: ft=cpp.doxygen
 */
/// END CUT HERE

