#include <cstdio>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

const int MAXN = 100100;

int n, p[MAXN], q[MAXN];

vector<vector<pair<int, int> > > todo[6];

void gao(vector<pair<int, int> >& w) {
	for (int i = 1; i < (int)w.size(); ++i) {
		swap(p[w[i - 1].first], p[w[i].first]);
		swap(w[i - 1].second, w[i].second);
	}
	for (int i = 0; i < (int)w.size(); ++i) {
		q[p[w[i].first]] = w[i].first;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &p[i]);
		q[p[i]] = i;
	}

	int m, t, a[5], b[5], c[5];
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		assert(scanf("%d", &t) == 1 && 2 <= t && t <= 5);
		for (int j = 0; j < t; ++j) {
			scanf("%d", &a[j]);
			a[j] = p[a[j]];
		}
		for (int j = 0; j < t; ++j) {
			scanf("%d", &b[j]);
			p[b[j]] = a[j];
		}
	}
	for (int i = 1; i <= n; ++i) {
		assert(p[i] == i);
	}
	printf("OK %d %d\n", n, m);
	
	return 0;	
}

