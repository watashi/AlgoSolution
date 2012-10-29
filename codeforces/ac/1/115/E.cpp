#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1 << 18;
const long long INF = 1000000007LL * 1000000007LL;

struct SegTree {
	int n;
	long long a[MAXN + MAXN], b[MAXN + MAXN];

	static int L(int i) {
		return i << 1;
	}

	static int R(int i) {
		return L(i) ^ 1;
	}

	void init(int m) {
		n = 1;
		while (n < m) {
			n <<= 1;
		}
		fill(a, a + n + n, -INF);
		fill(b, b + n, 0);
		fill(b + n, b + n + n, -INF);
	}

	long long get(int i) {
		long long ret = 0;
		for (i += n; i > 0; i >>= 1) {
			ret += b[i];
		}
		return ret;
	}

	void set(int i, long long x) {
		x -= get(i);
		if (x > 0) {
			i += n;
			a[i] += x;
			b[i] += x;
			for (i >>= 1; i > 0; i >>= 1) {
				a[i] = max(a[L(i)], a[R(i)]) + b[i];
			}
		}
	}

	long long query(int p, int pl, int pr, int l, int r) {
		if (pl == l && pr == r) {
			return a[p];
		} else {
			int pm = (pl + pr) / 2;
			if (r <= pm) {
				return query(L(p), pl, pm, l, r) + b[p];
			} else if (pm <= l) {
				return query(R(p), pm, pr, l, r) + b[p];
			} else {
				return max(query(L(p), pl, pm, l, pm), query(R(p), pm, pr, pm, r)) + b[p];
			}
		}
	}

	void add(int p, int pl, int pr, int l, int r, long long x) {
		if (pl == l && pr == r) {
			a[p] += x;
			b[p] += x;
		} else {
			int pm = (pl + pr) / 2;
			if (r <= pm) {
				add(L(p), pl, pm, l, r, x);
			} else if (pm <= l) {
				add(R(p), pm, pr, l, r, x);
			} else {
				add(L(p), pl, pm, l, pm, x);
				add(R(p), pm, pr, pm, r, x);
			}
			a[p] = max(a[L(p)], a[R(p)]) + b[p];
		}
	}
} st;

long long cost[MAXN];
vector<pair<pair<int, int>, int> > todo;

int main() {
	int n, m, t;
	long long ans;

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &t);
		cost[i] = t;
	}
	partial_sum(cost, cost + n + 1, cost);
	todo.resize(m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d", &todo[i].first.first, &todo[i].first.second, &todo[i].second);
	}
	sort(todo.rbegin(), todo.rend());

	ans = 0;
	st.init(n + 2);
//	for (int i = 0; i <= n; ++i) {
//		st.set(i, cost[i]);
//	}
	for (int i = 0; i <= n; ++i) {
		ans = max(ans, st.get(i) - cost[i]);
//		printf("[%d] %lld\n", i, ans);
		st.set(i, ans + cost[i]);
		while (!todo.empty() && todo.back().first.first == i + 1) {
			int l = todo.back().first.first;
			int r = todo.back().first.second;
			int p = todo.back().second;
			todo.pop_back();
			st.set(r, max(
					ans - (cost[r] - cost[l - 1]),
					st.query(1, 0, st.n, l, r + 1) - cost[r]) + cost[r]);
			st.add(1, 0, st.n, r, st.n, p);
		}
//		for (int j = 0; j <= n; ++j) {
//			printf("%lld ", st.get(j));
//		}
//		puts("-");
	}
	printf("%I64d\n", ans);
//	printf("%lld\n", ans);

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//702365 	Sep 15, 2011 10:14:46 PM 	watashi 	E - Linear Kingdom Races 	GNU C++0x 	Accepted 	640 ms 	14000 KB 
