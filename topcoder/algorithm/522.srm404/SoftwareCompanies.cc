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

struct SoftwareCompanies {
	vector <string> produceData(vector <string> names, vector <string> process, vector <int> cost, vector <int> amount, string company1, string company2);
};

const int MAXN = 128;
const int MAXM = 1024;
inline int RE(int i) { return i ^ 1; }

struct Edge {
	int v;
	int c;
};

struct FlowNetwork {
	int n, m, source, sink;
	vector<int> e[MAXN];
	Edge edge[MAXM * 2];

	void init(int n, int source, int sink) {	// if no source & sink, then source = sink = -1
		this->n = n;
		this->m = 0;
		this->source = source;
		this->sink = sink;
		for (int i = 0; i < n; ++i) {
			e[i].clear();
		}
	}

	void addEdge(int a, int b, int c) {
		edge[m].v = b;
		edge[m].c = c;
		e[a].push_back(m);
		edge[m + 1].v = a;
		edge[m + 1].c = 0;
		e[b].push_back(m + 1);
		m += 2;
	}

	// shortest augmenting path
	int c[MAXN];		//*
	int d[MAXN];		//*
	int done[MAXN];		//*
	int path[MAXN];		//*
	int len;			//*
	
	void _bfs() {
		queue<int> q;
		fill(c, c + n, 0);
		fill(d, d + n, n);	// n->inf
		d[sink] = 0;
		q.push(sink);
		while (!q.empty()) {
			int cur = q.front();
			++c[d[cur]];
			for (size_t i = 0; i < e[cur].size(); ++i) {
				int id = e[cur][i];
				if (d[edge[id].v] == n && edge[RE(id)].c > 0) {
					d[edge[id].v] = d[cur] + 1;
					q.push(edge[id].v);
				}
			}
			q.pop();
		}
	}

	void _retreat(int v) {
		--c[d[v]];
		d[v] = n;	// n->inf
		for (size_t i = 0; i < e[v].size(); ++i) {
			Edge &arc = edge[e[v][i]];
			if (d[v] > d[arc.v] + 1 && arc.c > 0) {
				d[v] = d[arc.v] + 1;
				done[v] = i;	// ~
			}
		}
		++c[d[v]];
	}

	int _augment() {
		int todo = -1;
		int flow = 0x7fffff;
		for (int i = 0; i < len; ++i) {
			Edge &arc = edge[e[path[i]][done[path[i]]]];
			if (arc.c < flow) {
				flow = arc.c;
				todo = i;
			}
		}
		for (int i = 0; i < len; ++i) {
			int id = e[path[i]][done[path[i]]];
			edge[id].c -= flow;
			edge[RE(id)].c += flow;
		}
		len = todo;
		return flow;
	}

	int sap() {
		int flow = 0;
		_bfs();
		fill(done, done + n, 0);
		len = 0;
		path[0] = source;
		while (d[source] != n/* && len >= 0*/) {	// n->inf
			int back = path[len];
			if (back == sink) {
				flow += _augment();
			} else {
				while (done[back] < (int)e[back].size()) {
					Edge &arc = edge[e[back][done[back]]];
					if (d[arc.v] == d[back] - 1 && arc.c > 0) {
						break;
					} else {
						++done[back];
					}
				}
				if (done[back] == (int)e[back].size()) {
					if (c[d[back]] == 1) {
						break;	// return;
					} else {
						_retreat(back);
						if (back != source) {	// !!
							--len;	// pop
						}
					}
				} else {
					path[++len] = edge[e[back][done[back]]].v;	// push
				}
			}
		}
		return flow;
	}
	// end of sap
} _fn, fn;

const int INF = 1000000007;
inline int IN(int i) { return i << 1; }
inline int OUT(int i) { return IN(i) ^ 1; }

vector <string> SoftwareCompanies::produceData(vector <string> names, vector <string> process, vector <int> cost, vector <int> amount, string company1, string company2) {
	int n = names.size();
	map<string, int> mp;
	FOR (i, n) {
		mp[names[i]] = i;
	}
	int s = mp[company1];
	int t = mp[company2];
	_fn.init(2 * n, IN(s), OUT(t));
	FOR (i, n) {
		istringstream iss(process[i]);
		string str;
		while (iss >> str) {
			_fn.addEdge(OUT(i), IN(mp[str]), INF);
		}
	}

	pair<int, int> best = make_pair(-1, 0);
	vector<string> ans;
	FOR (i, 1 << n) {
		pair<int, int> temp = make_pair(0, 0);
		vector<string> cur;
		fn = _fn;
		FOR (j, n) {
			if (i & (1 << j)) {
				fn.addEdge(IN(j), OUT(j), amount[j]);
				temp.second -= cost[j];
				cur.push_back(names[j]);
			}
		}
		sort(cur.begin(), cur.end());
		temp.first = fn.sap();
		if (temp > best || (temp == best && cur < ans)) {
			best = temp;
			ans = cur;
		}
	}
	return ans;
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
        string namesARRAY[] = {"topcoder", "doodle", "nasa", "ninny", "idm", "noname", "kintel"};
        vector <string> names( namesARRAY, namesARRAY+ARRSIZE(namesARRAY) );
        string processARRAY[] = {"doodle nasa noname", "idm ninny noname", "idm ninny noname", "kintel", "kintel", "", ""};
        vector <string> process( processARRAY, processARRAY+ARRSIZE(processARRAY) );
        int costARRAY[] = {1, 2, 7, 4, 6, 1, 2};
        vector <int> cost( costARRAY, costARRAY+ARRSIZE(costARRAY) );
        int amountARRAY[] = {50, 10, 11, 9, 14, 11, 23};
        vector <int> amount( amountARRAY, amountARRAY+ARRSIZE(amountARRAY) );
        string retrunValueARRAY[] = {"doodle", "idm", "kintel", "nasa", "ninny", "topcoder" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        SoftwareCompanies theObject;
        eq(0, theObject.produceData(names, process, cost, amount, "topcoder", "kintel"),retrunValue);
    }
    {
        string namesARRAY[] = {"b", "bz", "ba", "d", "z", "ca", "y", "a", "x"};
        vector <string> names( namesARRAY, namesARRAY+ARRSIZE(namesARRAY) );
        string processARRAY[] = {"bz ba z ca", "ba", "d", "", "ca", "d", "a", "x", ""};
        vector <string> process( processARRAY, processARRAY+ARRSIZE(processARRAY) );
        int costARRAY[] = {5, 5, 5, 10, 6, 6, 3, 0, 3};
        vector <int> cost( costARRAY, costARRAY+ARRSIZE(costARRAY) );
        int amountARRAY[] = {10, 7, 10, 9, 6, 9, 23, 13, 11};
        vector <int> amount( amountARRAY, amountARRAY+ARRSIZE(amountARRAY) );
        string retrunValueARRAY[] = {"a", "b", "ba", "d" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        SoftwareCompanies theObject;
        eq(1, theObject.produceData(names, process, cost, amount, "b", "d"),retrunValue);
    }
    {
        string namesARRAY[] = {"b", "bz", "ba", "d", "z", "ca", "y", "a", "x"};
        vector <string> names( namesARRAY, namesARRAY+ARRSIZE(namesARRAY) );
        string processARRAY[] = {"bz ba z ca", "ba", "d", "", "ca", "d", "a", "x", ""};
        vector <string> process( processARRAY, processARRAY+ARRSIZE(processARRAY) );
        int costARRAY[] = {5, 5, 5, 10, 6, 6, 3, 1, 3};
        vector <int> cost( costARRAY, costARRAY+ARRSIZE(costARRAY) );
        int amountARRAY[] = {10, 7, 10, 9, 6, 9, 23, 13, 11};
        vector <int> amount( amountARRAY, amountARRAY+ARRSIZE(amountARRAY) );
        string retrunValueARRAY[] = {"b", "ba", "d" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        SoftwareCompanies theObject;
        eq(2, theObject.produceData(names, process, cost, amount, "b", "d"),retrunValue);
    }
    {
        string namesARRAY[] = {"coma", "comb", "comc", "comd"};
        vector <string> names( namesARRAY, namesARRAY+ARRSIZE(namesARRAY) );
        string processARRAY[] = {"comb", "coma", "comd", "comc"};
        vector <string> process( processARRAY, processARRAY+ARRSIZE(processARRAY) );
        int costARRAY[] = {10, 54, 18, 93};
        vector <int> cost( costARRAY, costARRAY+ARRSIZE(costARRAY) );
        int amountARRAY[] = {10, 10, 10, 10};
        vector <int> amount( amountARRAY, amountARRAY+ARRSIZE(amountARRAY) );
        SoftwareCompanies theObject;
        eq(3, theObject.produceData(names, process, cost, amount, "comb", "comc"),vector <string>());
    }
    {
        string namesARRAY[] = {"c", "b", "a"};
        vector <string> names( namesARRAY, namesARRAY+ARRSIZE(namesARRAY) );
        string processARRAY[] = {"b", "c", ""};
        vector <string> process( processARRAY, processARRAY+ARRSIZE(processARRAY) );
        int costARRAY[] = {1, 1, 0};
        vector <int> cost( costARRAY, costARRAY+ARRSIZE(costARRAY) );
        int amountARRAY[] = {1, 1, 22};
        vector <int> amount( amountARRAY, amountARRAY+ARRSIZE(amountARRAY) );
        string retrunValueARRAY[] = {"a", "b", "c" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        SoftwareCompanies theObject;
        eq(4, theObject.produceData(names, process, cost, amount, "c", "b"),retrunValue);
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
