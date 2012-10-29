#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 100100;

pair<int, int> q[MAXN];
double ans[MAXN];

struct Node {
	int k, l, r, d;
	long long s;
	vector<Node*> c;
	
	void init() {
		if (c.empty()) {
			l = r = k;
		} else {
			if (c[0]->k > c[1]->k) {
				swap(c[0], c[1]);
			}
			c[0]->init();
			c[1]->init();
			l = c[0]->l;
			r = c[1]->r;
		}
	}

	void gao() {
		if (!c.empty()) {
			c[0]->d = d + 1;
			c[0]->s = s + c[1]->l;
			c[1]->d = d + 1;
			c[1]->s = s + c[0]->r;
			c[0]->gao();
			c[1]->gao();
		}
	}

	int solve(int m, int n, int i, pair<int, int> q[MAXN]) {
		if (c.empty()) {
			while (i < n && q[i].first < m) {
				ans[q[i].second] = 1.0 * s / d;
				++i;
			}
			return i;
		} else {
			int j = c[0]->solve(k, n, i, q);
			return c[1]->solve(m, n, j, q);
		}
	}
} node[MAXN];

int main() {
	int n, m, p, root;

	scanf("%d", &n);
//	for (int i = 0; i < n; ++i) {
//		node[i].c.clear();
//	}
	root = -1;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &p, &node[i].k);
		--p;
		if (p < 0) {
			root = i;
		} else {
	//		node[i].p = node + p;
			node[p].c.push_back(node + i);
		}
	}

	(node + root)->init();
	(node + root)->d = 0;
	(node + root)->s = 0;
	(node + root)->gao();
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d", &q[i].first);
		q[i].second = i;
	}
	sort(q, q + m);
	(node + root)->solve(1000000007, m, 0, q);
	for (int i = 0; i < m; ++i) {
		printf("%.10lf\n", ans[i]);
	}

	return 0;
}

