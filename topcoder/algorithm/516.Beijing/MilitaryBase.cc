#include <algorithm>
#include <iostream>
#include <sstream>
#include <numeric>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstdarg>
#include <cstring>
using namespace std;

#define FOR(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOREACH(i, n) for (typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
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

struct MilitaryBase {
	int getSchoolBuildingCount(vector <string> photo, int k);
};

const int MAXN = 64;
char str[MAXN][MAXN];
int x1, y1, x2, y2, z;

void gao(int i, int j) {
	x1 = min(x1, i);
	x2 = max(x2, i);
	y1 = min(y1, j);
	y2 = max(y2, j);
	++z;
	str[i][j] = ',';
	for (int ii = i - 1; ii <= i + 1; ++ii) {
		for (int jj = j - 1; jj <= j + 1; ++jj) {
			if (str[ii][jj] == '*') {
				gao(ii, jj);
			}
		}
	}
}

int MilitaryBase::getSchoolBuildingCount(vector <string> photo, int k) {
	int n = photo.size(), m = photo[0].size();
	MEMSET(str, 0);
	FOR(i, n) {
		copy(photo[i].c_str(), photo[i].c_str() + m, str[i + 1] + 1);
	}
	int ret = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (str[i][j] == '*') {
				x2 = y2 = 1;
				x1 = n;
				y1 = m;
				z = 0;
				gao(i, j);
				x2 = x2 - x1 + 1;
				y2 = y2 - y1 + 1;
				if (x2 > k + k && y2 > k + k && x2 * y2 - (x2 - k - k) * (y2 - k - k) == z) {
					bool flag = true;
					for (int ii = x1 + k; ii + k < x1 + x2; ++ii) {
						for (int jj = y1 + k; jj + k < y1 + y2; ++jj) {
							flag &= str[ii][jj] == '.';
							//	str[ii][jj] = ';';
						}
					}
					if (flag) {
						++ret;
					}
				}
			}
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
		string photoARRAY[] = {"***......",
			"*.*......",
			"***.*****",
			"....*****",
			"....**.**",
			"....**.**",
			"....**.**",
			"....*****",
			"....*****"};
		vector <string> photo( photoARRAY, photoARRAY+ARRSIZE(photoARRAY) );
		MilitaryBase theObject;
		eq(0, theObject.getSchoolBuildingCount(photo, 1),1);
	}
	{
		string photoARRAY[] = {"*****.*****",
			"*****.*****",
			"**.**.**.**",
			"*****.*****",
			"*****.*****",
			"...........",
			"*****.*****",
			"**.**.*****",
			"*****.**.**",
			"...........",
			"****.......",
			"****.......",
			"**.........",
			"**........."};
		vector <string> photo( photoARRAY, photoARRAY+ARRSIZE(photoARRAY) );
		MilitaryBase theObject;
		eq(1, theObject.getSchoolBuildingCount(photo, 2),2);
	}
	{
		string photoARRAY[] = {"*********",
			"*.......*",
			"*.*****.*",
			"*.*...*.*",
			"*.*...*.*",
			"*.*****.*",
			"*.......*",
			"*********"};
		vector <string> photo( photoARRAY, photoARRAY+ARRSIZE(photoARRAY) );
		MilitaryBase theObject;
		eq(2, theObject.getSchoolBuildingCount(photo, 1),1);
	}
	{
		string photoARRAY[] = {"..........",
			".****.....",
			".*..*.....",
			".****.....",
			".....****.",
			".....*..*.",
			".....****.",
			".........."};
		vector <string> photo( photoARRAY, photoARRAY+ARRSIZE(photoARRAY) );
		MilitaryBase theObject;
		eq(3, theObject.getSchoolBuildingCount(photo, 1),0);
	}
	{
		string photoARRAY[] = {"*********.",
			"*.......*.",
			"*.***...*.",
			"*.*.*.*.*.",
			"*.***...*.",
			"*.......*.",
			"*********.",
			"*********."};
		vector <string> photo( photoARRAY, photoARRAY+ARRSIZE(photoARRAY) );
		MilitaryBase theObject;
		eq(4, theObject.getSchoolBuildingCount(photo, 1),1);
	}
	{
		string photoARRAY[] = {"*******",
			"*.....*",
			"*.**..*",
			"*..**.*",
			"*.....*",
			"*******"};
		vector <string> photo( photoARRAY, photoARRAY+ARRSIZE(photoARRAY) );
		MilitaryBase theObject;
		eq(5, theObject.getSchoolBuildingCount(photo, 1),0);
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
