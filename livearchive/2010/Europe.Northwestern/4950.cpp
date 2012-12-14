// GOOD PROBLEM
#include <map>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1024;
char s[MAXN];
int h[MAXN];
int l[MAXN];

struct Gao {
	vector<pair<int, int> > s;
	
	void init() {
		s.clear();
	}

	void insert(int h, int p) {
		while (!s.empty() && s.back().first > h) {
			s.pop_back();
		}
		if (s.empty() || s.back().second < p) {
			s.push_back(make_pair(h, p));
		}
	}

	int query() const {
		return s.back().second;
	}
} gao;

int main() {
	int re;
	int n, m;
	map<int, int> ans;

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d%d", &n, &m);
		ans.clear();
		fill(h, h + m, 0);
		for (int i = 0; i < n; ++i) {
			scanf("%s", s);
			gao.init();
			for (int j = 0; j < m; ++j) {
				++h[j];
				if (s[j] == '#') {
					h[j] = 0;
					gao.init();
				}
				l[j] = j - 1;
				while (l[j] >= 0 && h[j] <= h[l[j]]) {
					l[j] = l[l[j]];
				}
				if (h[j] > 0) {
					gao.insert(h[j], h[j] - l[j]);
		//			printf("@%d %d: h = %d, l = %d, %d\n", i, j, h[j], l[j], gao.query() + j);
					++ans[gao.query() + j];
				}
			}
		}
		for (map<int, int>::const_iterator it = ans.begin(); it != ans.end(); ++it) {
			printf("%d x %d\n", it->second, it->first * 2);
		}
	}

	return 0;
}
//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//714971  	2011-01-04 04:04:08 	Accepted	3.254	520	26909	C++	4950 - Selling Land
/*
id => 1174281
pid => 4950
pname => Selling Land
status => Accepted
lang => C++
time => 0.382
date => 2012-12-14 17:48:34
*/
