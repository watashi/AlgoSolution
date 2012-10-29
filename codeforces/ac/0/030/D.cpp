#include <cmath>
#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 100100;

pair<int, int> p[MAXN];
double r[MAXN];

inline double first(int a, int b, int m) {
	return min(r[a] + p[b].first - p[m].first, r[b] + p[m].first - p[a].first) + p[b].first - p[a].first;
}

inline double second(int a, int b) {
	return a <= b ? min(r[a], r[b]) + p[b].first - p[a].first : 0;
}

int main() {
	int n, m;
	double sum, ans;

	scanf("%d%d", &n, &m);
	--m;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &p[i].first);
		p[i].second = i;
	}
	sort(p, p + n);
	scanf("%d%d", &p[n].first, &p[n].second);

	if (m != n) {
		for (int i = 0; i < n; ++i) {
			if (p[i].second == m) {
				m = i;
				break;
			}
		}
	}

	sum = 0;
	for (int i = 0; i < n; ++i) {
		r[i] = hypot(p[n].first - p[i].first, p[n].second);
	}
	ans = r[0] + r[n - 1] + p[n - 1].first - p[0].first;

	if (m == n) {
		ans -= max(r[0], r[n - 1]);
	} else {
		for (int i = 0; i <= m; ++i) {
			ans = min(ans, first(i, n - 1, m) + second(0, i - 1));
		}
		for (int i = m; i < n; ++i) {
			ans = min(ans, first(0, i, m) + second(i + 1, n - 1));
		}
	}
	
	printf("%.10lf\n", ans);

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//414531 	Apr 29, 2011 4:59:42 PM 	watashi 	30D - Kings Problem? 	GNU C++ 	Accepted 	90 ms 	2900 KB
