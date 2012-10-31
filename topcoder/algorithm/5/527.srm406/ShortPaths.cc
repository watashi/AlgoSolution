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
#include <list>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
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

struct ShortPaths {
	long long getPath(vector <string> graph, long long k, int start, int finish);
};

const int MAXN = 64;
const int INF = 1000000007;
int w[MAXN][MAXN], id[MAXN];

long long ShortPaths::getPath(vector <string> g, long long x, int start, int finish) {
	int n = g.size();
	FOR (i, n) FOR (j, n) {
		w[i][j] = g[i][j] == '0' ? INF : g[i][j] - '0';
	}
	FOR (k, n) FOR (i, n) FOR (j, n) {
		w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
	}
	FOR (i, n) {
		id[i] = -1;
		FOR (j, n) {
			if (w[i][j] < INF && w[j][i] < INF) {
				id[i] = j;
				break;
			}
		}
	}

	//	FOR (i, n) {
	//		printf("id = %d; cycle = %d\n", id[i], w[i][i]);
	//	}
	int base = w[start][finish];
	if (base >= INF) {
		return -1;
	}

	set<int> st;
	while (start != finish) {
		//		errf("%d -> %d: %d\n", start, finish, w[start][finish]);
		st.insert(id[start]);
		FOR (i, n) {
			if (g[start][i] != '0' && w[start][finish] == (i == finish ? 0 : w[i][finish]) + g[start][i] - '0') {
				start = i;
				break;
			}
		}
	}
	st.insert(id[finish]);

	vector<int> v;
	FOREACH (cycle, st) {
		if (*cycle != -1) {
			v.push_back(w[*cycle][*cycle]);
		}
	}
	sort(v.rbegin(), v.rend());
	errf("%d, ", v);

	if (v.empty()) {
		return x == 1 ? base : -1;
	} else if (v.size() == 1) {
		return v[0] * (x - 1) + base;
	} else if (v.size() == 2) {
		long long l = 0, r = (v[0] + v[1]) << 20;
		while (l < r) {
			long long m = (l + r) / 2;
			long long y = x;
			for (int i = 0; v[0] * i <= m && y >= 0; ++i) {
				y -= (m - v[0] * i) / v[1] + 1;
			}
			//	errf("[%lld, %lld] y = %lld\n", l, r, y);
			if (y > 0) {
				l = m + 1;
			} else {
				r = m;
			}
		}
		return r + base;
	} else  {
		vector<long long> dp(10000000 / v.size(), 0LL);	// at least ??
		dp[0] = 1LL;
		FOREACH (w, v) {
			for (int i = *w; i < (int)dp.size(); ++i) {
				dp[i] += dp[i - *w];
			}
		}
		for (int i = 0; ; ++i) {
			if (dp[i] >= x) {
				return i + base;
			}
			dp[i + 1] += dp[i];
		}
	}
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
		string graphARRAY[] = {
			"0100",
			"0020",
			"0003",
			"4000"
		};
		vector <string> graph( graphARRAY, graphARRAY+ARRSIZE(graphARRAY) );
		ShortPaths theObject;
		eq(0, theObject.getPath(graph, 1L, 0, 2),3L);
	}
	{
		string graphARRAY[] = {
			"0100",
			"0020",
			"0003",
			"4000"
		};
		vector <string> graph( graphARRAY, graphARRAY+ARRSIZE(graphARRAY) );
		ShortPaths theObject;
		eq(1, theObject.getPath(graph, 2L, 0, 2),13L);
	}
	{
		string graphARRAY[] = {
			"011",
			"000",
			"000"
		};
		vector <string> graph( graphARRAY, graphARRAY+ARRSIZE(graphARRAY) );
		ShortPaths theObject;
		eq(2, theObject.getPath(graph, 1L, 1, 2),-1L);
	}
	{
		string graphARRAY[] = {
			"010000",
			"001010",
			"000101",
			"000000",
			"010000",
			"001000"
		};
		vector <string> graph( graphARRAY, graphARRAY+ARRSIZE(graphARRAY) );
		ShortPaths theObject;
		eq(3, theObject.getPath(graph, 3L, 0, 3),5L);
	}
	{
		string graphARRAY[] = {
			"010000",
			"001010",
			"000103",
			"000000",
			"010000",
			"002000"
		};
		vector <string> graph( graphARRAY, graphARRAY+ARRSIZE(graphARRAY) );
		ShortPaths theObject;
		eq(4, theObject.getPath(graph, 11L, 0, 3),14L);
	}
	{
		string graphARRAY[] = {
			"010000000",
			"001002000",
			"000100000",
			"000010900",
			"000000006",
			"030000000",
			"007000000",
			"000040000",
			"000000070"
		};
		vector <string> graph( graphARRAY, graphARRAY+ARRSIZE(graphARRAY) );
		ShortPaths theObject;
		eq(5, theObject.getPath(graph, 5621L, 0, 7),363L);
	}
	{
		string graphARRAY[] = {
			"09000000000000000000000002000000000000000000000000",
			"00900000000000000000000000000000000000000000000000",
			"00090000000000000000000000000000000000000000000000",
			"00009000000000000000000000000000000000000000000000",
			"00000900000000000000000000000000000000000000000000",
			"00000090000000000000000000000000000000000000000000",
			"00000009000000000000000000000000000000000000000000",
			"00000000900000000000000000000000000000000000000000",
			"00000000090000000000000000000000000000000000000000",
			"00000000009000000000000000000000000000000000000000",
			"00000000000900000000000000000000000000000000000000",
			"00000000000090000000000000000000000000000000000000",
			"00000000000009000000000000000000000000000000000000",
			"00000000000000900000000000000000000000000000000000",
			"00000000000000090000000000000000000000000000000000",
			"00000000000000009000000000000000000000000000000000",
			"00000000000000000900000000000000000000000000000000",
			"00000000000000000090000000000000000000000000000000",
			"00000000000000000009000000000000000000000000000000",
			"00000000000000000000900000000000000000000000000000",
			"00000000000000000000090000000000000000000000000000",
			"00000000000000000000009000000000000000000000000000",
			"00000000000000000000000900000000000000000000000000",
			"00000000000000000000000090000000000000000000000000",
			"40000000000000000000000000000000000000000000000000",
			"00000000000000000000000000900000000000000000000000",
			"00000000000000000000000000090000000000000000000000",
			"00000000000000000000000000009000000000000000000000",
			"00000000000000000000000000000900000000000000000000",
			"00000000000000000000000000000090000000000000000000",
			"00000000000000000000000000000009000000000000000000",
			"00000000000000000000000000000000900000000000000000",
			"00000000000000000000000000000000090000000000000000",
			"00000000000000000000000000000000009000000000000000",
			"00000000000000000000000000000000000900000000000000",
			"00000000000000000000000000000000000090000000000000",
			"00000000000000000000000000000000000009000000000000",
			"00000000000000000000000000000000000000900000000000",
			"00000000000000000000000000000000000000090000000000",
			"00000000000000000000000000000000000000009000000000",
			"00000000000000000000000000000000000000000900000000",
			"00000000000000000000000000000000000000000090000000",
			"00000000000000000000000000000000000000000009000000",
			"00000000000000000000000000000000000000000000900000",
			"00000000000000000000000000000000000000000000090000",
			"00000000000000000000000000000000000000000000009000",
			"00000000000000000000000000000000000000000000000900",
			"00000000000000000000000000000000000000000000000090",
			"00000000000000000000000000000000000000000000000009",
			"00000000000000000000000004000000000000000000000000"
		};
		vector <string> graph( graphARRAY, graphARRAY+ARRSIZE(graphARRAY) );
		ShortPaths theObject;
		eq(6, theObject.getPath(graph, 10000000000LL, 0, 49),31112618LL);
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
