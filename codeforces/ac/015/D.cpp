#include <set>
#include <cstdio>
#include <vector>
#include <numeric>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 1024;

bool mark[MAXN][MAXN];
int a[MAXN][MAXN], b[MAXN][MAXN];
long long s[MAXN][MAXN];

int main() {
	int n, m, r, c;
	vector<pair<long long, pair<int, int> > > v, w;

	scanf("%d%d%d%d", &n, &m, &r, &c);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			scanf("%d", &a[i][j]);
			s[i][j] = a[i][j];
		}
	}

	for (int i = 1; i <= n; ++i) {
		copy(a[i], a[i] + m + 1, s[i]);
		partial_sum(s[i], s[i] + m + 1, s[i]);
//		partial_sum(a[i], a[i] + m + 1, s[i]);	// overflow? bug?
		for (int j = 1; j <= m; ++j) {
			s[i][j] += s[i - 1][j];
		}
	}

	for (int i = 1; i <= n; ++i) {
		multiset<int> st;	// 可以用单调队列优化！
		for (int j = 1; j <= m; ++j) {
			if (j > c) {
				st.erase(st.find(a[i][j - c]));
			}
			st.insert(a[i][j]);
			b[i][j] = *st.begin();
		}
	}
	for (int j = 1; j <= m; ++j) {
		multiset<int> st;
		for (int i = 1; i <= n; ++i) {
			if (i > r) {
				st.erase(st.find(b[i - r][j]));
			}
			st.insert(b[i][j]);
			a[i][j] = *st.begin();
		}
	}

	for (int i = r; i <= n; ++i) {
		for (int j = c; j <= m; ++j) {
			v.push_back(make_pair(
					s[i][j] - s[i - r][j] - s[i][j - c] + s[i - r][j - c]
					- r * c * (long long)a[i][j],
					make_pair(i, j)));
		}
	}
	sort(v.begin(), v.end());
	for (int k = 0; k < (int)v.size(); ++k) {
		int x = v[k].second.first;
		int y = v[k].second.second;
		if (mark[x][y]) {
			continue;
		}
		w.push_back(v[k]);
		for (int i = x - r + 1; i < x + r && i <= n; ++i) {
			fill(mark[i] + y - c + 1, mark[i] + min(y + c, m + 1), true);
		}
	}

	printf("%d\n", (int)w.size());
	for (int k = 0; k < (int)w.size(); ++k) {
		printf("%d %d %I64d\n", w[k].second.first - r + 1, w[k].second.second - c + 1, w[k].first);
	}

	return 0;
}

// rmq=>MLE
//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//276661 	Feb 7, 2011 1:00:17 PM 	watashi 	15D - Map 	GNU C++ 	Accepted 	1530 ms 	59900 KB
