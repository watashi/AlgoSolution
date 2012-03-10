#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstdarg>
#include <cstring>
using namespace std;

#define FOR(i, n) for (int i = 0; i < (int)(n); ++i)
#define MEMSET(p, c) memset(p, c, sizeof(p))
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

struct ParticleCollision {
	vector <double> collision(int vx, int vy, int vz, int x0, int y0, int z0);
};

const double PI = 3.14159265358979323846;
const double EPS = 1e-8;

vector <double> ParticleCollision::collision(int vx, int vy, int vz, int x0, int y0, int z0) {
	int a = vx * vx + vy * vy;
	int b = 2 * (vx * x0 + vy * y0);
	int c = x0 * x0 + y0 * y0 - 1;
	int d = b * b - 4 * a * c;
	vector<double> ret;
	if (a == 0) {
		if (c == 0) {
			if (vz != 0) {
				ret.resize(3);
			} else if (fabs(cos(PI * z0) - x0) < EPS && fabs(sin(PI * z0) - y0) < EPS) {
				ret.push_back(x0);
				ret.push_back(y0);
				ret.push_back(z0);
			}
		}
	} else if (d >= 0) {
		double t1, t2;
		t2 = (-b - sqrt(d)) / a / 2;
		t1 = vz * t2 + z0;
		if (fabs(cos(PI * t1) - vx * t2 - x0) < EPS && fabs(sin(PI * t1) - vy * t2 - y0) < EPS) {
			ret.push_back(vx * t2 + x0);
			ret.push_back(vy * t2 + y0);
			ret.push_back(vz * t2 + z0);
		}
		if (d > 0) {
			t2 = (-b + sqrt(d)) / a / 2;
			t1 = vz * t2 + z0;
			if (fabs(cos(PI * t1) - vx * t2 - x0) < EPS && fabs(sin(PI * t1) - vy * t2 - y0) < EPS) {
				ret.push_back(vx * t2 + x0);
				ret.push_back(vy * t2 + y0);
				ret.push_back(vz * t2 + z0);
			}
		}
		if (ret.size() > 3) {
			vector<double>(3).swap(ret);
		}
	}
	return ret;
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
		ParticleCollision theObject;
		eq(0, theObject.collision(0, 0, 0, 0, 0, 0),vector <double>());
	}
	{
		double retrunValueARRAY[] = {0.0, 1.0, 0.5 };
		vector <double> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
		ParticleCollision theObject;
		eq(1, theObject.collision(2, 4, 1, -1, -1, 0),retrunValue);
	}
	{
		double retrunValueARRAY[] = {0.0, 0.0, 0.0 };
		vector <double> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
		ParticleCollision theObject;
		eq(2, theObject.collision(4, 4, 2, 5, 4, 0),retrunValue);
	}
	{
		double retrunValueARRAY[] = {0.0, 0.0, 0.0 };
		vector <double> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
		ParticleCollision theObject;
		eq(3, theObject.collision(0, 0, 1, 1, 0, 0),retrunValue);
	}

	puts("\033[1;33mPress any key to continue...\033[0m");
	getchar();

	return 0;
}

/*
 * first second iterator
 * push_back priority_queue
 */
/*
 * vim: ft=cpp.doxygen
 */
/// END CUT HERE
