// GOOD PROBLEM

#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 101010;
const int BLOCK = 512;
int a[MAXN], b[MAXN], c[MAXN];

void gao(int l, int p) {
	int r = l + BLOCK;
	for (int i = min(r, p) - 1; i >= l; --i) {
		if (i < a[i] && a[i] < r) {
			b[i] = b[a[i]];
			c[i] = c[a[i]] + 1;
		} else {
			b[i] = a[i];
			c[i] = 1;
		}
	}
}

int main() {
	int n, m, x, y;

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		a[i] = i + (i + a[i] >= n ? 0 : a[i]);
	}
	for (int j = 0; j < n; j += BLOCK) {
		gao(j, n);
	}

	for (int i = 0; i < m; ++i) {
		scanf("%d", &x);
		if (x == 0) {
			scanf("%d%d", &x, &y);
			--x;
			a[x] = x + (x + y >= n ? 0 : y);
			gao(x & ~(BLOCK - 1), x + 1);

		} else {
			scanf("%d", &x);
			--x;
			y = 0;
			for (int j = x & ~(BLOCK - 1); ; j = x & ~(BLOCK - 1)) {
				y += c[x];
				x = b[x];
				if (x < j + BLOCK) {
					break;
				}
			}
			printf("%d %d\n", x + 1, y);
		}
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//283503 	Feb 12, 2011 8:39:15 PM 	watashi 	13E - Holes 	GNU C++ 	Accepted 	270 ms 	2500 KB 
