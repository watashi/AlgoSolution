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

struct EllysDeathStars {
	double getMax(vector <string> stars, vector <string> ships);
};


const int MAXN = 4096;
const int MAXM = 32768;
const double EPS = 1e-8;

inline int RE(int i) { return i ^ 1; }

struct Edge {
	int v;
	double c;
};

struct FlowNetwork {
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

	void addEdge(int a, int b, double c) {
        // printf("%d => %d (%lf)\n", a, b, c);
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
				if (d[edge[id].v] == n && edge[RE(id)].c > EPS) {
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
			if (d[v] > d[arc.v] + 1 && arc.c > EPS) {
				d[v] = d[arc.v] + 1;
				done[v] = i;	// ~
			}
		}
		++c[d[v]];
	}

	double _augment() {
		int todo = -1;
		double flow = 1e100;
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

	double sap() {
		double flow = 0;
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
					if (d[arc.v] == d[back] - 1 && arc.c > EPS) {
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
} fn;

struct Point {
    double x, y;
    Point() { }
    Point(double x, double y): x(x), y(y) { }
    double abs() const { return hypot(x, y); }
    Point operator-(const Point& o) const { return Point(x - o.x, y - o.y); }
} p[MAXN], s[MAXN], t[MAXN];

double v[MAXN], r[MAXN], c[MAXN];

struct pr {
    bool operator()(double lhs, double rhs) const {
        return rhs - lhs > EPS;
    }
};

pair<double, double> gao(const Point& s, const Point& t, const Point& o, double r) {
    Point d = t - s;
    if (d.x == 0 && d.y == 0) {
        return make_pair(0, -1);
    }
    Point w = s - o;
    double a = d.x * d.x + d.y * d.y;
    double b = 2 * (d.x * w.x + d.y * w.y);
    double c = w.x * w.x + w.y * w.y - r * r;
    double delta = b * b - 4 * a * c;
    if (delta < EPS) {
        return make_pair(0, -1);
    }
    delta = sqrt(fabs(delta));
    double t1 = (-b - delta) / (2 * a);
    double t2 = (-b + delta) / (2 * a);
    double tt = d.abs();
    t1 = max(0.0, t1) * tt;
    t2 = min(1.0, t2) * tt;
    return make_pair(t1, t2);
}

double EllysDeathStars::getMax(vector <string> stars, vector <string> ships) {
    int n = stars.size();
    FOR (i, n) {
        sscanf(stars[i].c_str(), "%lf%lf", &p[i].x, &p[i].y);
    }
    int m = ships.size();
    fn.init(MAXN, m, MAXN - 1);
    FOR (i, m) {
        sscanf(ships[i].c_str(), "%lf%lf%lf%lf%lf%lf%lf",
            &s[i].x, &s[i].y, &t[i].x, &t[i].y, &v[i], &r[i], &c[i]);
        fn.addEdge(m, i, c[i]);
    }

    int cur = m + 1;
    FOR (i, n) {
        map<double, int, pr> mp;
        vector<double> key;
        vector<pair<double, double> > vec;
        FOR (j, m) {
            pair<double, double> ret = gao(s[j], t[j], p[i], r[j]);
            // printf("%d x %d: %lf %lf\n", i, j, ret.first, ret.second);
            if (ret.first < ret.second) {
                ret.first /= v[j];
                ret.second /= v[j];
                mp[ret.first];
                mp[ret.second];
            }
            vec.push_back(ret);
        }
        for (map<double, int, pr>::iterator it = mp.begin(); it != mp.end(); ++it) {
            it->second = cur + (int)key.size();
            key.push_back(it->first);
        }
        for (int i = 1; i < (int)key.size(); ++i) {
            fn.addEdge(cur + i - 1, MAXN - 1, key[i] - key[i - 1]);
        }
        FOR (j, m) {
            pair<double, double> ret = vec[j];
            if (ret.first < ret.second) {
                int first = mp[ret.first];
                int second = mp[ret.second];
                for (int k = first; k < second; ++k) {
                    fn.addEdge(j, k, MAXN);
                }
            }
        }
        cur += (int)key.size();
    }
    printf("cur = %d\n", cur);

    return fn.sap();
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
        string starsARRAY[] = {"2 2"};
        vector <string> stars( starsARRAY, starsARRAY+ARRSIZE(starsARRAY) );
        string shipsARRAY[] = {"1 1 5 3 2 1 2"};
        vector <string> ships( shipsARRAY, shipsARRAY+ARRSIZE(shipsARRAY) );
        EllysDeathStars theObject;
        eq(0, theObject.getMax(stars, ships),0.894427190999916);
    }
    {
        string starsARRAY[] = {"12 10", "7 5"};
        vector <string> stars( starsARRAY, starsARRAY+ARRSIZE(starsARRAY) );
        string shipsARRAY[] = {"10 10 12 10 1 1 3", "6 1 8 10 1 2 3", "3 6 8 2 5 3 1", "42 42 42 42 6 6 6"};
        vector <string> ships( shipsARRAY, shipsARRAY+ARRSIZE(shipsARRAY) );
        EllysDeathStars theObject;
        eq(1, theObject.getMax(stars, ships),4.983770744659944);
    }
    // exit(0.0);
    {
        string starsARRAY[] = {"5 77", "60 50", "10 46", "22 97", "87 69"};
        vector <string> stars( starsARRAY, starsARRAY+ARRSIZE(starsARRAY) );
        string shipsARRAY[] = {"42 17 66 11 5 7 13", "10 10 20 20 3 3 3", "13 15 18 9 4 1 2",
            "99 71 63 81 19 4 60", "27 34 56 43 11 3 12"};
        vector <string> ships( shipsARRAY, shipsARRAY+ARRSIZE(shipsARRAY) );
        EllysDeathStars theObject;
        eq(2, theObject.getMax(stars, ships),0.0);
    }
    {
        string starsARRAY[] = {"141 393", "834 847", "568 43", "18 228", "515 794",
            "167 283", "849 333", "719 738", "434 261", "613 800",
            "127 340", "466 938", "598 601"};
        vector <string> stars( starsARRAY, starsARRAY+ARRSIZE(starsARRAY) );
        string shipsARRAY[] = {"410 951 472 100 337 226 210", "713 352 677 908 731 687 300",
            "191 41 337 92 446 716 213", "598 889 446 907 148 650 203",
            "168 556 470 924 344 369 198", "300 182 350 936 737 533 45",
            "410 871 488 703 746 631 80", "270 777 636 539 172 103 56",
            "466 906 522 98 693 77 309", "768 698 846 110 14 643 14",
            "755 724 664 465 263 759 120"};
        vector <string> ships( shipsARRAY, shipsARRAY+ARRSIZE(shipsARRAY) );
        EllysDeathStars theObject;
        eq(3, theObject.getMax(stars, ships),31.965770956316362);
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

