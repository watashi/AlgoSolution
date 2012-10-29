#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1 << 18;
const long long INF = 12345678987654321LL;

struct SegTree {
	int n;
	long long a[MAXN << 1], m[MAXN << 1];

	void init(int c, long long e[MAXN]) {
		n = 1;
		while (n < c) {
			n <<= 1;
		}
		fill(a, a + n + n, 0);
		copy(e, e + c, m + n);
		fill(m + n + c, m + n + n, INF);
		for (int i = n - 1; i >= 1; --i) {
			m[i] = min(m[i * 2], m[i * 2 + 1]);
		}
	}

	void inc(int p, int pl, int pr, int l, int r, int v) {
		if (pl == l && pr == r) {
			a[p] += v;
			m[p] += v;
		} else {
			int pm = (pl + pr) / 2;
			if (r <= pm) {
				inc(p * 2, pl, pm, l, r, v);
			} else if (pm <= l) {
				inc(p * 2 + 1, pm, pr, l, r, v);
			} else {
				inc(p * 2, pl, pm, l, pm, v);
				inc(p * 2 + 1, pm, pr, pm, r, v);
			}
			m[p] = a[p] + min(m[p * 2], m[p * 2 + 1]);
		}
	}

	void inc(int l, int r, int v) {
		if (l <= r) {
			inc(1, 0, n, l, r + 1, v);
		} else {
			inc(1, 0, n, 0, r + 1, v);
			inc(1, 0, n, l, n, v);
		}
	}

	long long rmq(int p, int pl, int pr, int l, int r) {
		if (pl == l && pr == r) {
			return m[p];
		} else {
			int pm = (pl + pr) / 2;
			if (r <= pm) {
				return a[p] + rmq(p * 2, pl, pm, l, r);
			} else if (pm <= l) {
				return a[p] + rmq(p * 2 + 1, pm, pr, l, r);
			} else {
				return a[p] + min(rmq(p * 2, pl, pm, l, pm), rmq(p * 2 + 1, pm, pr, pm, r));
			}
		}
	}

	long long rmq(int l, int r) {
		if (l <= r) {
			return rmq(1, 0, n, l, r + 1);
		} else {
			return min(rmq(1, 0, n, 0, r + 1), rmq(1, 0, n, l, n));
		}
	}
} st;

long long e[MAXN];

int main() {
	int n, m, l, r, v;
	char buf[80];

	scanf("%d ", &n);
	for (int i = 0; i < n; ++i) {
//		scanf("%lld", &e[i]);
		scanf("%I64d", &e[i]);
	}
	st.init(n, e);

	scanf("%d ", &m);
	for (int i = 0; i < m; ++i) {
		fgets(buf, sizeof(buf), stdin);
		if (sscanf(buf, "%d%d%d", &l, &r, &v) == 3) {
			st.inc(l, r, v);
		} else {
//			printf("%lld\n", st.rmq(l, r));
			printf("%I64d\n", st.rmq(l, r));
		}
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//241380 	Jan 7, 2011 7:58:11 PM 	watashi 	52C - Circular RMQ 	GNU C++ 	Accepted 	520 ms 	11552 KB 

