#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int INF = 1000000000;
const int MAXN = 65536;

int x[MAXN], y[MAXN];

int main() {
	int re, m, n, d;
	long long ans;
	vector<pair<int, int> > v;

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d%d", &m, &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &x[i], &y[i]);
		}
		if (x[0] > x[1]) {
			swap(x[0], x[1]);
		}
		
		v.clear();
		for (int i = 0; i < n; ++i) {
			v.push_back(make_pair(abs(x[i] - x[0]) + abs(y[i] - y[0]), abs(x[i] - x[1]) + abs(y[i] - y[1])));
		}
		sort(v.begin(), v.end());

		ans = 0;
		for (int i = 0, j = 0, k = INF; k > 0; ++i) {
			while (j < (int)v.size() && v[j].first <= i) {
				k = min(k, v[j].second);
				++j;
			}
			d = min(i, (x[0] - x[1] + k + i + 1) / 2);
			ans += max(0, min(d, m - y[0]) + min(d, y[0] + 1) - 1);
		}
		printf("%lld\n", ans);
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//714858  	2011-01-03 16:40:50 	Accepted	0.518	1484	26909	C++	4851 - Restaurant

/*
id => 1174201
pid => 4851
pname => Restaurant
status => Accepted
lang => C++
time => 0.205
date => 2012-12-14 17:37:33
*/
