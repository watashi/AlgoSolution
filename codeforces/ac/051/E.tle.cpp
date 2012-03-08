#include <bitset>
#include <cstdio>

using namespace std;

const int MAXN = 720;
int h[MAXN][MAXN], *ph;
bool f[MAXN][MAXN];
bitset<MAXN> e[MAXN], g[MAXN][MAXN], *pg;

int main() {
	int n, m, a, b;
	long long ans;

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &a, &b);
		e[a].set(b);
		e[b].set(a);
		f[a][b] = f[b][a] = true;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			g[i][j] = e[i] & e[j];
			h[i][j] = g[i][j].count();
		}
	}

	ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			for (int k = i + 1; k <= n; ++k) {
				if (g[j][k].test(i)) {
					g[j][k].set(i, 0);
					--h[j][k];
				}
			}
		}
		ph = h[i];
		pg = g[i];
		for (int j = i + 1; j <= n; ++j) {
			for (int k = j + 1; k <= n; ++k) {
				if (f[j][k]) {
					a = ph[j] - 1;
					b = ph[k] - 1;
					ans += a * b - (pg[j] & pg[k]).count();
				}
			}
		}
	}
//	printf("%lld\n", ans);	// WA38
	printf("%I64d\n", ans);

	return 0;
}

// TLE38 || TLE39 || TLE41
