#include <set>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100100;
const int MOD = 1000000009;

struct DisjointSet {
	int p[MAXN];
	
	void init(int n) {
		for (int i = 0; i < n; ++i) {
			p[i] = i;
		}
	}

	int getp(int i) {
		return p[i] == i ? i : (p[i] = getp(p[i]));
	}

	bool setp(int i, int j) {
		i = getp(i);
		j = getp(j);
		if (i == j) {
			return false;
		} else {
			p[i] = j;
			return true;
		}
	}
} ds;

set<int> x[MAXN];
bool y[MAXN];

int main() {
	int n, m, a, b;
	int ans;

	scanf("%d%d", &n, &m);
	ds.init(n);
	ans = 1;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &a, &b);
		--a;
		--b;
		if (!ds.setp(a, b)) {
			ans += ans;
			if (ans >= MOD) {
				ans -= MOD;
			}
		}
		printf("%d\n", (ans + MOD - 1) % MOD);
	}

	return 0;
}

