#include <map>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100100;
const long long INF = 12345678987654321LL;
pair<int, int> r[MAXN];

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int rev(int x) {
	int y = 0;
	while (x > 0) {
		y = y * 10 + x % 10;
		x /= 10;
	}
	return y;
}

pair<int, int> inv(const pair<int, int>& p) {
	return pair<int, int>(p.second, p.first);
}

void init() {
	for (int i = 1; i < MAXN; ++i) {
		int t = rev(i);
		int g = gcd(t, i);
		r[i] = make_pair(t / g, i / g);
	}
}

int main() {
	int nx, ny, nw;
	long long x, y, w;
	map<pair<int, int>, int> mx, my;

	init();
	scanf("%d%d%d", &nx, &ny, &nw);
	for (int j = 1; j <= ny; ++j) {
		++my[r[j]];
	}
	long long t = 0;
	for (int i = 1; i <= nx; ++i) {
		t += my[inv(r[i])];
	}
	printf("%lld\n", t);
/*	x = y = -1;
	w = INF;
	for (long long i = 1, j = ny, k = 0; i <= nx; ++i) {
		++mx[r[i]];
		k += my[inv(r[i])];
		while (j > 0 && k >= nw) {
		//	if (make_pair(k, i * j) < make_pair(w, x * y)) {
			if (w == INF || i * j < x * y) {
				x = i;
				y = j;
				w = k;
			}
			--my[r[j]];
			k -= mx[inv(r[j])];
			--j;
			if (k < nw) {
				++j;
				k += mx[inv(r[j])];
				++my[r[j]];
				break;
			}
		}
	}
	if (w < INF) {
		printf("%d %d\n", (int)x, (int)y);
	} else {
		puts("-1");
	}
*/
	return 0;
}

