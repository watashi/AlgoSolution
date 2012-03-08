#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 128;
const int INF = 1000000007;

int a[MAXN];
bool b[MAXN][MAXN];

int main() {
	int n, m, x, y;

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &x, &y);
		--x;
		--y;
		b[x][y] = b[y][x] = true;
	}
	y = INF;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (!b[i][j]) {
				continue;
			}
			for (int k = j + 1; k < n; ++k) {
				if (!b[i][k] || !b[j][k]) {
					continue;
				}
				y = min(y, a[i] + a[j] + a[k]);
			}
		}
	}
	printf("%d\n", y == INF ? -1 : y);

	return 0;
}

//602685 	Aug 11, 2011 5:00:02 PM 	watashi 	102A - Clothes 	GNU C++0x 	Accepted 	10 ms 	1400 KB
