#include <cmath>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 10086;

int gao(int a, int b) {
	long long c = (long long)a * a - (long long)b * b;
	long long d = (long long)sqrt((double)c) + 1;
	while (d * d > c) {
		--d;
	}
	return (int)d;
}

bool cmp(const pair<int, int>& lhs, const pair<int, int>& rhs) {
	return lhs.first != rhs.first ? lhs.first < rhs.first : lhs.second > rhs.second;
}

int main() {
	int re, z, n, s, d, t, l, r, m;
	vector<pair<int, int> > v, w;
	static int x[MAXN], y[MAXN];

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d%d%d%d", &z, &n, &s, &d);
		l = 0;
		r = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &x[i], &y[i]);
			y[i] -= z;
			r = max(r, y[i]);
		}
		r = d - r + 1;
		
		while (l < r) {
			m = (l + r) / 2;
			
			v.clear();
			for (int i = 0; i < n; ++i) {
				t = gao(d, y[i] + m);
				v.push_back(make_pair(x[i] - t, x[i] + t));
			}
			sort(v.begin(), v.end(), cmp);

			w.clear();
			for (int i = 0; i < n; ++i) {
				while (!w.empty() && v[i].second <= w.back().second) {
					w.pop_back();
				}
				w.push_back(v[i]);
			}
		
			t = s;
			z = w[0].second;
			for (int i = 1; t > 0 && i < (int)w.size(); ++i) {
				if (w[i].first > z) {
					z = w[i].second;
					--t;
				}
			}

			if (t > 0) {
				l = m + 1;
			} else {
				r = m;
			}
		}

		printf("Case %d: ", ri);
		if (l == 0) {
			puts("IMPOSSIBLE");
		} else {
			printf("%d\n", l - 1);
		}
	}

	return 0;
}
// ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
// 714853  	2011-01-03 16:30:46 	Accepted	0.689	824	26909	C++	5000 - Underwater Snipers

/*
id => 1174112
pid => 5000
pname => Underwater Snipers
status => Accepted
lang => C++
time => 0.209
date => 2012-12-14 17:23:56
*/
