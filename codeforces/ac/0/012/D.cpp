#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1 << 19;

struct SegTree {
	int n, a[MAXN + MAXN];

	void init(int i) {
		n = 1;
		while (n < i) {
			n <<= 1;
		}
		fill(a, a + n + n, 0);
	}

	void set(int i, int v) {
		i += n;
		while (i > 0) {
			a[i] = max(a[i], v);
			i >>= 1;
		}
	}

	int get(int i) {
		int ret = 0, p = 1, pl = 0, pr = n, pm;
		while (p < n) {
			pm = (pl + pr) / 2;
			if (i < pm) {
				ret = max(ret, a[p * 2 + 1]);
				p = p * 2;
				pr = pm;
			} else {
				p = p * 2 + 1;
				pl = pm;
			}
		}
		return ret;
	}
} st;

struct Girl {
	int b, i, r;
} g[MAXN];

bool pr1(const Girl& lhs, const Girl& rhs) {
	return lhs.i < rhs.i;
}

bool pr2(const Girl& lhs, const Girl& rhs) {
	return lhs.b > rhs.b || (lhs.b == rhs.b && lhs.i < rhs.i);
}

int main() {
	int n, t;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &g[i].b);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &g[i].i);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &g[i].r);
	}

	sort(g, g + n, pr1);
	t = -1;
	for (int i = 0; i < n; ++i) {
		if (g[i].i == t) {
			g[i].i = g[i - 1].i;
		} else {
			t = g[i].i;
			g[i].i = i;
		}
	}

	sort(g, g + n, pr2);
	st.init(n);
	t = 0;
	for (int i = 0; i < n; ++i) {
		if (st.get(g[i].i) > g[i].r) {
			++t;
		} else {
			st.set(g[i].i, g[i].r);
		}
	}
	printf("%d\n", t);

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//209759 	Dec 7, 2010 4:52:24 PM 	watashi 	D - Ball 	GNU C++ 	Accepted 	950 ms 	11552 KB 
