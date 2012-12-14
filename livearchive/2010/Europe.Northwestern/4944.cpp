#include <list>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

const int MAXN = 218;

int main() {
	int re, n, m, d;
	int a[MAXN], b[MAXN];
	vector<pair<int, int> > p;
	list<int> c;

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d%d", &m, &n);
		p.clear();
		c.clear();
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			b[i] = 0;
			p.push_back(make_pair(-a[i], i));
			c.push_back(a[i]);
		}
		sort(p.begin(), p.end());
		while (m > 0 && !c.empty()) {
			if (m < (int)c.size()) {
				for (int j = 0; m > 0 && j < n; ++j) {
					int i = p[j].second;
					if (a[i] > 0) {
						--a[i];
						++b[i];
						--m;
					}
				}
			} else {
				d = min(*min_element(c.begin(), c.end()), m / (int)c.size());
				for (int j = 0; j < n; ++j) {
					int i = p[j].second;
					if (a[i] >= d) {
						a[i] -= d;
						b[i] += d;
						m -= d;
					}
				}
				transform(c.begin(), c.end(), c.begin(), bind2nd(minus<int>(), d));
				c.erase(remove(c.begin(), c.end(), 0), c.end());
			}
		}

		if (m > 0) {
			puts("IMPOSSIBLE");
		} else {
			for (int i = 0; i < n; ++i) {
				printf("%d%c", b[i], i == n - 1 ? '\n' : ' ');
			}
		}
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//881080 	4944 	Fair Division 	Accepted 	C++ 	0.012 	2011-09-13 09:34:12
/*
id => 1174282
pid => 4944
pname => Fair Division
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:48:49
*/
