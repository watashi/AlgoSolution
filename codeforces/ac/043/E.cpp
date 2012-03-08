#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int gao(const vector<pair<int, int> >& lhs, const vector<pair<int, int> >& rhs) {
	int i = 0, j = 0, s = 0, si = 0, sj = 0, scmp = 0, t, ti, tj, tcmp, ret = 0;
	while (i < (int)lhs.size() && j < (int)rhs.size()) {
		t = min(lhs[i].first, rhs[j].first);
		ti = si + lhs[i].second * (t - s);
		tj = sj + rhs[j].second * (t - s);
		if (ti < tj) {
			tcmp = -1;
		} else if (ti > tj) {
			tcmp = 1;
		} else {
			tcmp = si == sj ? 0 : scmp;
		}
		if (t == lhs[i].first) {
			++i;
		}
		if (t == rhs[j].first) {
			++j;
		}
		if (scmp * tcmp == -1) {
			++ret;
		}
		s = t;
		si = ti;
		sj = tj;
		scmp = tcmp;
	}
	return ret;
}

int main() {
	int n, s, k, ans = 0;
	vector<pair<int, int> > v[128];	

	scanf("%d%d", &n, &s);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &k);
		v[i].resize(k);
		for (int j = 0; j < k; ++j) {
			scanf("%d%d", &v[i][j].second, &v[i][j].first);
			if (j > 0) {
				v[i][j].first += v[i][j - 1].first;
			}
		}
		for (int j = 0; j < i; ++j) {
			ans += gao(v[i], v[j]);
		}
	}
	printf("%d\n", ans);

	return 0;
}

// (si < sj && ti > tj) || (si > sj && ti < tj) => WA21
// s > 0 && ((si <= sj && ti > tj) || (si >= sj && ti < tj)) => WA23
//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//209002 	Dec 6, 2010 12:50:25 PM 	watashi 	E - Race 	GNU C++ 	Accepted 	50 ms 	1392 KB 
// 3y
