#include <cstdio>

const int MAXN = 100100;

struct Gao {
	int p[MAXN], q[MAXN];
	bool r[MAXN];

	void init(int n) {
		for (int i = 0; i < n; ++i) {
			q[i] = 1;
			r[i] = true;
		}
	}

	void next(int i) {
		if (!r[p[i]] && p[i] != i) {
			next(p[i]);
			q[i] += q[p[i]];
			p[i] = p[p[i]];
		}
	}

	void kill(int i) {
		if (r[i]) {
			next(i);
			r[i] = false;
		}
	}
} gao;

int main() {
	int n, m, x, y, z;
	static int a[MAXN], b[MAXN];

	scanf("%d%d", &n, &m);
	gao.init(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &gao.p[i]);
		--gao.p[i];
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d", &a[i]);
		--a[i];
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d", &b[i]);
	}

	z = 0;
	for (int i = 0; i < m; ++i) {
		x = (a[i] + z) % n;
		y = b[i];
		z = 0;
		while (true) {
			if (!gao.r[x]) {
				gao.next(x);
				y -= gao.q[x];
				x = gao.p[x];
			}
			if (gao.r[x] && y > 0) {
				++z;
				gao.kill(x);
			} else {
				break;
			}
		}
		printf("%d\n", z);
	}

	return 0;
}

// GOOD PROBLEM
// TODO
//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//413321 	Apr 28, 2011 1:20:59 AM 	watashi 	45B - School 	GNU C++ 	Accepted 	160 ms 	3900 KB
