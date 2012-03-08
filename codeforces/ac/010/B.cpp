#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAXN = 128;
const int INF = 1000000007;

bool a[MAXN][MAXN];

int main() {
	int n, m, o, w, v, d, t, x, y;

	scanf("%d%d", &n, &m);
	o = m / 2;
	for (int k = 0; k < n; ++k) {
		scanf("%d", &w);
		d = INF;
		for (int i = 0; i < m; ++i) {
			v = 0;
			t = abs(i - o) * w;
			for (int j = 0; j < m; ++j) {
				if (a[i][j]) {
					v = 0;
				} else {
					++v;
				}
				if (j >= w) {
					t -= abs(j - w - o);
				}
				t += abs(j - o);
				if (v >= w && t < d) {
					d = t;
					x = i;
					y = j - w + 1;
				}
			}
		}
		if (d < INF) {
			fill(a[x] + y, a[x] + y + w, true);
			printf("%d %d %d\n", x + 1, y + 1, y + w);
		} else {
			puts("-1");
		}
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//275140 	Feb 4, 2011 8:07:31 PM 	watashi 	10B - Cinema Cashier 	GNU C++ 	Accepted 	80 ms 	1300 KB 
