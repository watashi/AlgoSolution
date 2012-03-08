#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

pair<pair<int, int>, int> p[100100];
int m[100100][17];
int ans[100100];

int main() {
	int n;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &p[i].first.first, &p[i].first.second);
		p[i].second = i;
	}
	sort(p, p + n);

	for (int i = n - 1; i >= 0; --i) {
		int t = lower_bound(p + i, p + n, make_pair(make_pair(p[i].first.first + p[i].first.second, 0), 0)) - p;
		m[i][0] = t;
		for (int j = 0, s = i + 1; s != t; ++j) {
			if ((t - s) & (1 << j)) {
				m[i][0] = max(m[i][0], m[s][j]);
				s += 1 << j;
			}
		}
		ans[p[i].second] = m[i][0] - i;
		for (int j = 0; j < 16; ++j) {
			m[i][j + 1] = max(m[i][j], m[min(n, i + (1 << j))][j]);
		}
	}

	for (int i = 0; i < n; ++i) {
		printf("%d ", ans[i]);
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//267797 	Jan 30, 2011 3:23:06 PM 	watashi 	56E - Domino Principle 	GNU C++ 	Accepted 	170 ms 	9500 KB
//267796 	Jan 30, 2011 3:22:00 PM 	watashi 	56E - Domino Principle 	GNU C++ 	Accepted 	200 ms 	9500 KB 
