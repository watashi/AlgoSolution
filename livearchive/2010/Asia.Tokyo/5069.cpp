#include <map>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

map<int, int> c;
vector<int> l, r;
vector<vector<int> > ans;

void gao() {
	if (c.empty()) {
		ans.push_back(l);
		ans.back().insert(ans.back().end(), r.rbegin(), r.rend());
		return;
	}

	int x = c.rbegin()->first;
	if (l.back() < x && x < r.back()) {
		map<int, int> d;
		for (vector<int>::const_iterator i = l.begin(); i != l.end(); ++i) {
			++d[x - *i];
		}
		for (vector<int>::const_iterator i = r.begin(); i != r.end(); ++i) {
			++d[*i - x];
		}
		bool f = true;
		for (map<int, int>::const_iterator i = d.begin(); i != d.end(); ++i) {
			if (c.count(i->first) == 0 || c[i->first] < i->second) {
				f = false;
				break;
			}
		}
		if (f) {
			for (map<int, int>::const_iterator i = d.begin(); i != d.end(); ++i) {
				if ((c[i->first] -= i->second) == 0) {
					c.erase(i->first);
				}
			}
			r.push_back(x);
			gao();
			r.pop_back();
			for (map<int, int>::const_iterator i = d.begin(); i != d.end(); ++i) {
				c[i->first] += i->second;
			}
		}
	}
	
	if (x + x == r.front()) {
		return;
	}
	x = r.front() - x;
	if (l.back() < x && x < r.back()) {
		map<int, int> d;
		for (vector<int>::const_iterator i = l.begin(); i != l.end(); ++i) {
			++d[x - *i];
		}
		for (vector<int>::const_iterator i = r.begin(); i != r.end(); ++i) {
			++d[*i - x];
		}
		bool f = true;
		for (map<int, int>::const_iterator i = d.begin(); i != d.end(); ++i) {
			if (c.count(i->first) == 0 || c[i->first] < i->second) {
				f = false;
				break;
			}
		}
		if (f) {
			for (map<int, int>::const_iterator i = d.begin(); i != d.end(); ++i) {
				if ((c[i->first] -= i->second) == 0) {
					c.erase(i->first);
				}
			}
			l.push_back(x);
			gao();
			l.pop_back();
			for (map<int, int>::const_iterator i = d.begin(); i != d.end(); ++i) {
				c[i->first] += i->second;
			}
		}
	}
}

int main() {
	int n, m, t;

	while (scanf("%d", &n) != EOF && n > 0) {
		m = n * (n - 1) / 2;
		c.clear();
		for (int i = 0; i < m; ++i) {
			scanf("%d", &t);
			++c[t];
		}
		t = c.rbegin()->first;
		if (--c[t] == 0) {
			c.erase(t);
		}

		l.clear();
		l.push_back(0);
		r.clear();
		r.push_back(t);
		ans.clear();
		gao();

		sort(ans.begin(), ans.end());
		ans.erase(unique(ans.begin(), ans.end()), ans.end());
		for (int i = 0; i < (int)ans.size(); ++i) {
			for (int j = 1; j < (int)ans[i].size(); ++j) {
				printf("%d%c", ans[i][j] - ans[i][j - 1], j == (int)ans[i].size() - 1 ? '\n' : ' ');
			}
		}
		puts("-----");
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//771920  	2011-04-28 11:01:50 	Accepted	0.316	560	26909	C++	5069 - Towns along a Highway
/*
id => 1174086
pid => 5069
pname => Towns along a Highway
status => Accepted
lang => C++
time => 0.049
date => 2012-12-14 17:20:33
*/
