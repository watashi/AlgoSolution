// 最小度限制生成树
// Degree-constrained minimum spanning tree (DCMST)

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 5050;
const int INF = 1000000007;

struct DisjointSet {
	int p[MAXN];

	void init(int n) {
		for (int i = 0; i < n; ++i) {
			p[i] = i;
		}
	}

	int getp(int i) {
		return p[i] == i ? i : (p[i] = getp(p[i]));
	}

	bool setp(int i, int j) {
		i = getp(i);
		j = getp(j);
		if (i != j) {
			p[i] = j;
			return true;
		} else {
			return false;
		}
	}
} ds;

struct Edge {
	int i, a, b;
	double c;

	bool operator<(const Edge& o) const {
		return c < o.c;
	}
};

vector<Edge> e, ee;

int kruskal(int n, double d, vector<int>& ans) {
	int ret = 0;
	
	ee = e;
	for (Edge& i: ee) {
		if (i.a == 0) {
			i.c += d;
		}
	}
	sort(ee.begin(), ee.end());

	ds.init(n);
	ans.clear();
	for (const Edge& i: ee) {
		if (ds.setp(i.a, i.b)) {
			if (i.a == 0) {
				++ret;
			}
			ans.push_back(i.i);
		}
	}

	return ret;
}

int main() {
	Edge edge;
	int n, m, k, t;
	double l, r, mid;
	vector<int> ans;

	scanf("%d%d%d", &n, &m, &k);
	for (edge.i = 0; edge.i < m; ++edge.i) {
		scanf("%d%d%lf", &edge.a, &edge.b, &edge.c);
		--edge.a;
		--edge.b;
		edge.c += 1e-6 * edge.i;
		if (edge.a > edge.b) {
			swap(edge.a, edge.b);
		}
		e.push_back(edge);
	}

	l = -1e6;
	r = 1e6;
	for (int loop = 0; loop < 64; ++loop) {
		mid = (l + r) / 2;
		t = kruskal(n, mid, ans);
		if (t > k) {
			l = mid;
		} else if (t < k) {
			r = mid;
		} else {
			break;
		}
	}

	if (t != k) {
		puts("-1");
	} else {
		printf("%d\n", n - 1);
		for (int i: ans) {
			printf("%d ", i + 1);
		}
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//863472 	Nov 14, 2011 6:47:29 PM 	watashi 	125E - MST Company 	GNU C++0x 	Accepted 	440 ms 	6900 KB
