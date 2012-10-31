#include <algorithm>
#include <iostream>
#include <sstream>
#include <numeric>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <set>
#include <limits>
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

struct TransformMatrix {
	int transform(vector <string> A, vector <string> B, vector <string> count);
};

const int MAXN = 1000;
const int MAXM = 10000;

struct Edge {
	int v, c, w;
	Edge() { }
	Edge(int v, int c, int w) : v(v), c(c), w(w) { }
};

struct NegativeCostCircuitExistsException {
};

struct MinCostMaxFlow {
	int n, m, source, sink;
	vector<int> e[MAXN];
	Edge edge[MAXM * 2];

	void init(int n, int source, int sink) {
		this->n = n;
		this->m = 0;
		this->source = source;
		this->sink = sink;
		for (int i = 0; i < n; ++i) {
			e[i].clear();
		}
	}

	void addEdge(int a, int b, int c, int w) {
		edge[m] = Edge(b, c, w);
		e[a].push_back(m++);
		edge[m] = Edge(a, 0, -w);
		e[b].push_back(m++);
	}

	bool mark[MAXN];
	int maxc[MAXN];
	int minw[MAXN];
	int pre[MAXN];
	int d[MAXN];

	// assert @return == true
	bool _spfa() {
		queue<int> q;

		fill(mark, mark + n, false);
		fill(maxc, maxc + n, 0);
		fill(minw, minw + n, numeric_limits<int>::max());
		fill(pre, pre + n, -1);
		fill(d, d + n, 0);
		mark[source] = true;
		maxc[source] = numeric_limits<int>::max();
		minw[source] = 0;
		// pre[source] = source;
		q.push(source);
		while (!q.empty()) {
			int cur = q.front();
//			fprintf(stderr, "%d %d %d\n", cur, maxc[cur], minw[cur]);
			mark[cur] = false;
			q.pop();
			for (size_t i = 0; i < e[cur].size(); ++i) {
				int id = e[cur][i];
				int v = edge[id].v;
				int c = min(maxc[cur], edge[id].c);
				if (c == 0) {	// ~~
					continue;
				}
				int w = minw[cur] + edge[id].w;
				if (minw[v] > w || (minw[v] == w && maxc[v] < c)) {
					maxc[v] = c;
					minw[v] = w;
					pre[v] = id;	// e not v !
					d[v] = d[cur] + 1;
					if (d[v] >= n) {
						return false;
					}
					if (!mark[v]) {
						mark[v] = true;
						q.push(v);
					}
				}
			}
		}

		return true;
	}

	pair<int, int> gao() {
		int sumc = 0, sumw = 0;

		while (true) {
			if (!_spfa()) {
				throw NegativeCostCircuitExistsException();
			} else if (maxc[sink] == 0) {
				break;
			} else {
				int c = maxc[sink];
				sumc += c;
				sumw += c * minw[sink];
				int cur = sink;
				while (cur != source) {
					int id = pre[cur];
					edge[id].c -= c;
					edge[id ^ 1].c += c;
					cur = edge[id ^ 1].v;
				}
			}
		}

		return make_pair(sumc, sumw);
	}
} mcmf;

inline int IN(int i, int j, int c) { return (i * c + j) * 2; }
inline int OUT(int i, int j, int c) { return IN(i, j, c) ^ 1; }

int TransformMatrix::transform(vector <string> A, vector <string> B, vector <string> count) {
	int r = A.size();
	int c = A[0].size();
	int s = r * c * 2;
	int t = s + 1;
	int f = 0, g = 0;
	mcmf.init(t + 1, s, t);
	FOR (i, r) {
		FOR (j, c) {
			if (A[i][j] == '1' && B[i][j] != '1') {
				mcmf.addEdge(s, OUT(i, j, c), 1, 0);
				++f;
			}
			if (B[i][j] == '1' && A[i][j] != '1') {
				mcmf.addEdge(IN(i, j, c), t, 1, 0);
				++g;
			}
			if (A[i][j] != B[i][j]) {
				if (count[i][j] == '0') {
					return -1;
				} else {
					--count[i][j];	//
				}
			}
			mcmf.addEdge(IN(i, j, c), OUT(i, j, c), (count[i][j] - '0') / 2, 0);
			for (int ii = i - 1; ii <= i + 1; ++ii) {
				for (int jj = j - 1; jj <= j + 1; ++jj) {
					if (0 <= ii && ii < r && 0 <= jj && jj < c) {
						mcmf.addEdge(OUT(i, j, c), IN(ii, jj, c), s + t, 1);
					}
				}
			}
		}
	}
	PII ans = mcmf.gao();
	if (ans.first == f && ans.first == g) {
		return ans.second;
	} else {
		return -1;
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
        string AARRAY[] = {"110", 
            "000",
            "001"};
        vector <string> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        string BARRAY[] = {"000",
            "110",
            "100"};
        vector <string> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        string countARRAY[] = {"222",
            "222",
            "222"};
        vector <string> count( countARRAY, countARRAY+ARRSIZE(countARRAY) );
        TransformMatrix theObject;
        eq(0, theObject.transform(A, B, count),4);
    }
    {
        string AARRAY[] = {"10"};
        vector <string> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        string BARRAY[] = {"01"};
        vector <string> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        string countARRAY[] = {"11"};
        vector <string> count( countARRAY, countARRAY+ARRSIZE(countARRAY) );
        TransformMatrix theObject;
        eq(1, theObject.transform(A, B, count),1);
    }
    {
        string AARRAY[] = {"111",
            "000",
            "111"};
        vector <string> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        string BARRAY[] = {"111",
            "000",
            "111"};
        vector <string> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        string countARRAY[] = {"013",
            "537",
            "136"};
        vector <string> count( countARRAY, countARRAY+ARRSIZE(countARRAY) );
        TransformMatrix theObject;
        eq(2, theObject.transform(A, B, count),0);
    }
    {
        string AARRAY[] = {"001",
            "110"};
        vector <string> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        string BARRAY[] = {"000",
            "111"};
        vector <string> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        string countARRAY[] = {"000",
            "111"};
        vector <string> count( countARRAY, countARRAY+ARRSIZE(countARRAY) );
        TransformMatrix theObject;
        eq(3, theObject.transform(A, B, count),-1);
    }
    {
        string AARRAY[] = {"100",
            "000"};
        vector <string> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        string BARRAY[] = {"000",
            "000"};
        vector <string> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        string countARRAY[] = {"999",
            "999"};
        vector <string> count( countARRAY, countARRAY+ARRSIZE(countARRAY) );
        TransformMatrix theObject;
        eq(4, theObject.transform(A, B, count),-1);
    }
    {
        string AARRAY[] = {"011101",
            "110000",
            "000011",
            "000000",
            "100000"};
        vector <string> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        string BARRAY[] = {"110100",
            "000011",
            "000000",
            "110001",
            "000010"};
        vector <string> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        string countARRAY[] = {"305713",
            "537211",
            "352421",
            "242212",
            "333313"};
        vector <string> count( countARRAY, countARRAY+ARRSIZE(countARRAY) );
        TransformMatrix theObject;
        eq(5, theObject.transform(A, B, count),10);
    }
    {
        string AARRAY[] = {"10",
            "00"};
        vector <string> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        string BARRAY[] = {"00",
            "01"};
        vector <string> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        string countARRAY[] = {"11",
            "11"};
        vector <string> count( countARRAY, countARRAY+ARRSIZE(countARRAY) );
        TransformMatrix theObject;
        eq(6, theObject.transform(A, B, count),1);
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
