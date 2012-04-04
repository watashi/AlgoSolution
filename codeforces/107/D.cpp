#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 130;
const int MOD = 12345;

void dump(int n, const int a[MAXN][MAXN]) {
	printf("|%d|\n", n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("%4d ", a[i][j]);
		}
		puts("");
	}
	puts("----");
}

void dup(int n, const int a[MAXN][MAXN], int ret[MAXN][MAXN]) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			ret[i][j] = a[i][j];
		}
	}
}

void mul(int n, const int a[MAXN][MAXN], const int b[MAXN][MAXN], int ret[MAXN][MAXN]) {
	static int c[MAXN][MAXN];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			long long t = 0;
			for (int k = 0; k < n; ++k) {
				t += a[i][k] * b[k][j];
			}
			c[i][j] = t % MOD;
		}
	}
	dup(n, c, ret);
}

void pow(int n, const int _a[MAXN][MAXN], long long b, int ret[MAXN][MAXN]) {
	static int a[MAXN][MAXN], c[MAXN][MAXN];
	dup(n, _a, a);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			c[i][j] = i == j ? 1 : 0;
		}
	}
	while (b > 0) {
		if (b & 1) {
			mul(n, a, c, c);
		}
		b >>= 1;
		mul(n, a, a, a);
	}
	dup(n, c, ret);
}

int a[MAXN][MAXN];

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}

vector<int> decode(int a, const vector<int>& b) {
	vector<int> d;
	for (int i = 0; i < (int)b.size(); ++i) {
		d.push_back(a % b[i]);
		a /= b[i];
	}
	return d;
}

int encode(const vector<int>& d, const vector<int>& b) {
	int a = 0;
	for (int i = (int)b.size() - 1; i >= 0; --i) {
		a *= b[i];
		a += d[i] % b[i];
	}
	return a;
}

int main() {
	long long n;
	int m, x;
	char ch;
	vector<int> v[26], w;
	vector<vector<int> > vv;

//	scanf("%lld%d", &n, &m);
	scanf("%I64d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf(" %c%d", &ch, &x);
		v[ch - 'A'].push_back(x);
	}

	m = 1;
	for (int k = 0; k < 26; ++k) {
		if (v[k].empty()) {
			continue;
		}
		sort(v[k].begin(), v[k].end());		
		v[k].erase(unique(v[k].begin(), v[k].end()), v[k].end());
		x = 1;
		for (int i = 0; i < (int)v[k].size(); ++i) {
			x = lcm(x, v[k][i]);
		}
		w.push_back(x);
		vv.push_back(v[k]);
		m *= x;
	}

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			a[i][j] = 0;
		}
	}
	for (int i = 0; i < m; ++i) {
		vector<int> u = decode(i, w);
		for (int j = 0; j < (int)u.size(); ++j) {
			++u[j];
			++a[encode(u, w)][i];
			--u[j];
		}
	}
//	dump(m, a);
	pow(m, a, n, a);
//	dump(m, a);

	x = 0;
	for (int i = 0; i < m; ++i) {
		vector<int> u = decode(i, w);
		bool ok = true;
		for (int j = 0; ok && j < (int)u.size(); ++j) {
			ok = false;
			for (int k = 0; k < (int)vv[j].size(); ++k) {
				if (u[j] % vv[j][k] == 0) {
					ok = true;
					break;
				}
			}
		}
		if (ok) {
			x += a[i][0];
		}
	}
	printf("%d\n", x % MOD);

	return 0;
}

//634523 	Aug 23, 2011 10:07:06 PM 	watashi 	106D - Treasure Island 	GNU C++0x 	Accepted 	140 ms 	18800 KB 
