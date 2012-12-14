#include <map>
#include <queue>
#include <cstdio>
#include <vector>
#include <string>
#include <numeric>
#include <sstream>
#include <algorithm>

using namespace std;

const int MAXX = 64 * 16;
const int MAXY = 64;

struct Hungary {
	int nx, ny, mx[MAXX], my[MAXY];
	vector<int> e[MAXX];

	bool mark[MAXX];

	void init(int nx, int ny) {
		this->nx = nx;
		this->ny = ny;
		for (int i = 0; i < nx; ++i) {
			e[i].clear();
		}
		fill(mx, mx + nx, -1);
		fill(my, my + ny, -1);
	}

	void add(int a, int b) {
		e[a].push_back(b);
	}

	bool augment(int i) {
		if (!mark[i]) {
			mark[i] = true;
			for (vector<int>::const_iterator j = e[i].begin(); j != e[i].end(); ++j) {
				if (my[*j] == -1 || augment(my[*j])) {
					mx[i] = *j;
					my[*j] = i;
					return true;
				}
			}
		}
		return false;
	}
} h;

int x[20];

int gao(int n) {
	if (n == 0) {
		return 0;
	}
	int ret = gao(n - 1);
	bool flag = x[n] > x[n - 1];
	for (int i = x[n - 1]; flag && i < x[n]; ++i) {
		fill(h.mark, h.mark + h.nx, false);
		flag &= h.augment(i);
	}
	if (flag) {
		ret = max(ret, gao(n - 1) + 1);
	}
	for (int i = x[n - 1]; i < x[n]; ++i) {
		if (h.mx[i] != -1) {
			h.my[h.mx[i]] = -1;
			h.mx[i] = -1;
		}
	}
	return ret;
}

int main() {
	int ri = 0, n, m;
	char buf[4096];
	map<string, int> mp;

	while (scanf("%d%d", &n, &m) != EOF && n > 0) {
		x[0] = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%s%d", buf, &x[i + 1]);
			if (x[i + 1] > m) {
				x[i + 1] = 0;
			}
			mp[buf] = i;
		}
		partial_sum(x, x + n + 1, x);
		h.init(x[n], m);
		while (getchar() != '\n') {
		}
		for (int i = 0; i < m; ++i) {
			gets(buf);
			istringstream iss(buf);
			string str;
			while (iss >> str) {
				int j = mp[str];
				for (int k = x[j]; k < x[j + 1]; ++k) {
					h.add(k, i);
				}
			}
		}
		printf("Case #%d: %d\n", ++ri, gao(n));
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//910263 	4819 	Problemsetting 	Accepted 	C++ 	0.340 	2011-10-18 11:18:30
/*
id => 1174246
pid => 4819
pname => Problemsetting
status => Accepted
lang => C++
time => 0.208
date => 2012-12-14 17:44:27
*/
