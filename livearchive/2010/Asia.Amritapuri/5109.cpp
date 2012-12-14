// GOOD PROBLEM

#include <queue>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, char> Edge;
vector<vector<Edge> > e;

int newnode() {
	e.push_back(vector<Edge>());
	return (int)e.size() - 1;
}

void gao(const char* &p, int& s, int& t) {
	if (*p != '(') {
		s = newnode();
		t = newnode();
		e[s].push_back(Edge(t, *(p++)));
	} else {
		int s1, t1, s2, t2;
		++p;
		gao(p, s1, t1);
		if (*p == '*') {
			++p;
			e[t1].push_back(Edge(s1, ' '));
			s = t = s1;
		} else if (*p == '|') {
			++p;
			gao(p, s2, t2);
			s = newnode();
			t = newnode();
			e[s].push_back(Edge(s1, ' '));
			e[s].push_back(Edge(s2, ' '));
			e[t1].push_back(Edge(t, ' '));
			e[t2].push_back(Edge(t, ' '));
		} else {
			gao(p, s2, t2);
			e[t1].push_back(Edge(s2, ' '));
			s = s1;
			t = t2;
		}
		// *p == ')'
		++p;
	}
}

int gao(const int s[2], const int t[2], const vector<vector<Edge> > e[2]) {
	vector<vector<int> > d(e[0].size(), vector<int>(e[1].size(), 0x3f3f3f3f));
	priority_queue<pair<int, pair<int, int> > > q;

	q.push(make_pair(0, make_pair(s[0], s[1])));
	d[s[0]][s[1]] = 0;
	while (!q.empty()) {
		int x = q.top().second.first;
		int y = q.top().second.second;
		int z = -q.top().first;
		q.pop();
		if (d[x][y] != z) {
			continue;
		}
		if (x == t[0] && y == t[1]) {
			return z;
		}
		for (vector<Edge>::const_iterator it = e[0][x].begin(); it != e[0][x].end(); ++it) {
			for (vector<Edge>::const_iterator jt = e[1][y].begin(); jt != e[1][y].end(); ++jt) {
				if (it->second == jt->second) {
					if (d[it->first][jt->first] > z) {
						d[it->first][jt->first] = z;
						q.push(make_pair(-z, make_pair(it->first, jt->first)));
					}
				} else {
					if (d[it->first][jt->first] > z + 1) {
						d[it->first][jt->first] = z + 1;
						q.push(make_pair(-(z + 1), make_pair(it->first, jt->first)));
					}
				}
			}
		}
		for (vector<Edge>::const_iterator it = e[0][x].begin(); it != e[0][x].end(); ++it) {
			if (d[it->first][y] > z + (it->second == ' ' ? 0 : 1)) {
				d[it->first][y] = z + (it->second == ' ' ? 0 : 1);
				q.push(make_pair(-(z + (it->second == ' ' ? 0 : 1)), make_pair(it->first, y)));					
			}
		}
		for (vector<Edge>::const_iterator jt = e[1][y].begin(); jt != e[1][y].end(); ++jt) {
			if (d[x][jt->first] > z + (jt->second == ' ' ? 0 : 1)) {
				d[x][jt->first] = z + (jt->second == ' ' ? 0 : 1);
				q.push(make_pair(-(z + (jt->second == ' ' ? 0 : 1)), make_pair(x, jt->first)));
			}
		}
	}
}

int main() {
	int re;
	char buf[80];
	const char *pbuf;
	int s[2], t[2];
	vector<vector<Edge> > e[2];

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		for (int i = 0; i < 2; ++i) {
			scanf("%s", buf);
			pbuf = buf;
			::e.clear();
			gao(pbuf, s[i], t[i]);
			e[i] = ::e;
		}
		printf("%d\n", gao(s, t, e));
	}

	return 0;
}

// ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
// 714849  	2011-01-03 16:23:19 	Accepted	0.014	Minimum	26909	C++	5109 - Regular Expression
/*
id => 1174193
pid => 5109
pname => Regular Expression Edit Distance
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:36:22
*/
