#include <cstdio>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

const int MAXN = 100100;

int p[3 * MAXN], q[3 * MAXN];
vector<int> v[MAXN], x, y;

int main() {
	int n, m, a, k, b;

	scanf("%d", &n);
	m = 3 * n;
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &a);
		p[a] = i;
	}
	for (int i = 1; i <= n; ++i) {
		v[i].resize(4);
		v[i][3] = m + 1;
		for (int j = 0; j < 3; ++j) {
			scanf("%d", &v[i][j]);
			q[v[i][j]] = i;
			v[i][3] = min(v[i][3], p[v[i][j]]);
		}
	}
	for (int i = 2; i <= n; ++i) {
		assert(v[i][3] > v[i - 1][3]);
	}

	scanf("%d", &k);
	a = p[k];
	b = q[k];
	for (int j = 0; j < 3; ++j) {
		if (v[b][j] != k) {
			x.push_back(v[b][j]);
		}
		a = min(a, p[v[b][j]]);
	}
	assert(a == v[b][3]);
	if (a < p[k]) {
		for (int i = 1; i <= m; ++i) {
			if (i == k) {
				continue;
			}
			printf("%d ", i);
		}
		return 0;
	}

	a = *max_element(x.begin(), x.end());
	for (int i = 1; i < b; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (v[i][j] < a) {
				x.push_back(v[i][j]);
			} else {
				y.push_back(v[i][j]);
			}
		}
	}
	for (int i = b + 1; i <= n; ++i) {
		for (int j = 0; j < 3; ++j) {
			y.push_back(v[i][j]);
		}
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	x.insert(x.end(), y.begin(), y.end());
	for (int i = 0; i < (int)x.size(); ++i) {
		printf("%d ", x[i]);
	}

	return 0;
}

