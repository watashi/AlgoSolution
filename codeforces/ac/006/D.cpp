#include <cstdio>
#include <algorithm>

using namespace std;

struct { int s, c[16]; } cur, ans;
int a, b, h[16];

inline int cnt(int x, int y) {
	return x >= 0 ? x / y + 1 : 0;
}

void gao(int i) {
	if (cur.s >= ans.s) {
		return;
	} else if (i == 0) {
		if (h[i + 1] < 0) {	// without `h[i + 1] < 0`: WA49
			ans = cur;
		}
	} else {
		int l = cnt(h[i + 1], b);
		int r = max(l, cnt(h[i], a)) + 1;
		cur.s += l;
		cur.c[i] += l;
		h[i] -= l * a;
		h[i - 1] -= l * b;
		for (int j = l; j < r; ++j) {
			gao(i - 1);
			++cur.s;
			++cur.c[i];
			h[i] -= a;
			h[i - 1] -= b;
		}
		cur.s -= r;
		cur.c[i] -= r;
		h[i] += r * a;
		h[i - 1] += r * b;
	}
}

int main() {
	int n;
	bool blank = false;

	scanf("%d%d%d", &n, &a, &b);
	cur.s = 0;
	ans.s = 10000;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &h[i]);
		cur.c[i] = 0;
	}

	cur.c[1] += cnt(h[0], b);
	cur.s += cur.c[1];
	h[0] -= cur.c[1] * b;
	h[1] -= cur.c[1] * a;
	h[2] -= cur.c[1] * b;
	gao(n - 2);

	printf("%d\n", ans.s);
	for (int i = 1; i < n - 1; ++i) {
		for (int j = 0; j < ans.c[i]; ++j) {
			if (blank) {
				putchar(' ');
			} else {
				blank = true;
			}
			printf("%d", i + 1);
		}
	}
	puts("");

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//201405 	Nov 30, 2010 8:31:39 PM 	watashi 	D - Lizards and Basements 2 	GNU C++ 	Accepted 	30 ms 	1292 KB 

