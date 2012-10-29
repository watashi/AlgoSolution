#include <cstdio>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int gao(int n, int m, const int a[100][100], const int c[10]) {
	vector<int> v(c, c + 3);
	vector<int> s = {0};
	int ret = 0;

	sort(v.begin(), v.end());
	for (int i = 0; i < n; ++i) {
		s.push_back(accumulate(a[i], a[i] + m, 0));
	}
	partial_sum(s.begin(), s.end(), s.begin());
	for (int i = 1; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			vector<int> w = {s[i] - s[0], s[j] - s[i], s[n] - s[j]};
			sort(w.begin(), w.end());
			if (w == v) {
				++ret;
			}
		}
	}

	return ret;
}

int main() {
#ifndef __WATASHI__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	int a[100][100], b[100][100], c[10];

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &a[i][j]);
			b[j][i] = a[i][j];
		}
	}
	for (int k = 0; k < 3; ++k) {
		scanf("%d", &c[k]);
	}
	printf("%d\n", gao(n, m, a, c) + gao(m, n, b, c));

	return 0;
}
