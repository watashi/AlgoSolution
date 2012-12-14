#include <list>
#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 1024;

#define GAO(move) do{\
	if (k->first == ox && k->second == oy) {\
		k = v.erase(k);\
		++n;\
	} else if (buf[k->first][k->second] == '*') {\
		k = v.erase(k);\
	} else {\
		if (move) {\
			k->first += sgn(ox - k->first);\
			k->second += sgn(oy - k->second);\
		}\
		if (last[k->first][k->second] == t) {\
			u.push_back(*k);\
		} else {\
			last[k->first][k->second] = t;\
		}\
		++k;\
	}\
} while (false)

char buf[MAXN][MAXN];
int last[MAXN][MAXN];

int sgn(int x) {
	if (x > 0) {
		return 1;
	} else if (x < 0) {
		return -1;
	} else {
		return 0;
	}
}

int main() {
	int r, c, n, t, ox = -1, oy = -1;
	list<pair<int, int> > u, v, w;

	while (scanf("%s", buf[0]) != EOF) {
		r = 1;
		c = strlen(buf[0]);
		while (scanf("%s", buf[r]) != EOF && buf[r][0] != '$') {
			++r;
		}

		u.clear();
		v.clear();
		w.clear();
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				last[i][j] = 0;
				if (buf[i][j] == '@') {
					ox = i;
					oy = j;
				} else if (buf[i][j] == '+') {
					v.push_back(make_pair(i, j));
				} else if (buf[i][j] == '#') {
					w.push_back(make_pair(i, j));
				}
			}
		}

		n = 0;
		t = 0;
		while (!v.empty() || !w.empty()) {
			++t;
			for (list<pair<int, int> >::iterator k = v.begin(); k != v.end(); ) {
				GAO(true);
			}
			for (list<pair<int, int> >::iterator k = w.begin(); k != w.end(); ) {
				GAO(true);
			}
			for (list<pair<int, int> >::iterator k = u.begin(); k != u.end(); k = u.erase(k)) {
				buf[k->first][k->second] = '*';
			}
			++t;
			for (list<pair<int, int> >::iterator k = v.begin(); k != v.end(); ) {
				GAO(false);
			}
			for (list<pair<int, int> >::iterator k = w.begin(); k != w.end(); ) {
				GAO(true);
			}
			for (list<pair<int, int> >::iterator k = u.begin(); k != u.end(); k = u.erase(k)) {
				buf[k->first][k->second] = '*';
			}
		}
		printf("%d\n", n);
	}

	return 0;
}
//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//870188 	5054 	Killbots 	Accepted 	C++ 	0.036 	2011-08-30 06:14:44
/*
id => 1174347
pid => 5054
pname => Killbots
status => Accepted
lang => C++
time => 0.042
date => 2012-12-14 18:00:16
*/
