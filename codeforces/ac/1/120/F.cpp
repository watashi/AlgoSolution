#include <cstdio>
#include <algorithm>

using namespace std;

int d[128];
vector<int> e[128];

int gao(int v, int p) {
	int ret = 0;
	d[v] = 0;
	for (int w: e[v]) {
		if (w == p) {
			continue;
		}
		ret = max(ret, gao(w, v));
		ret = max(ret, d[v] + d[w] + 1);
		d[v] = max(d[v], d[w] + 1);
	}
	return ret;
}

int main() {
#ifndef __WATASHI__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, m, a, b, s = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &m);
		for (int j = 0; j < m; ++j) {
			e[j].clear();
		}
		for (int j = 1; j < m; ++j) {
			scanf("%d%d", &a, &b);
			--a;
			--b;
			e[a].push_back(b);
			e[b].push_back(a);
		}
		s += gao(0, -1);
	}
	printf("%d\n", s);

	return 0;
}
