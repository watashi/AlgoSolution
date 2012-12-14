#include <stack>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 128;
const long long MOD = 1000000007LL;

int C[MAXN][MAXN];
int a[MAXN], b[MAXN], p[MAXN], c[MAXN];

int main() {
	int re, n, k, m, ans;

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &c[i]);
		}
		p[0] = 1;
		a[1] = k;
		b[1] = 0;
		p[1] = k - 1;
		for (int i = 2; i <= n; ++i) {
			a[i] = b[i - 1];
			b[i] = ((k - 1LL) * a[i - 1] + (k - 2LL) * b[i - 1]) % MOD;
			p[i] = (k - 1LL) * p[i - 1] % MOD;
		}

		m = 0;
		ans = 1;
		for (int i = 0; i < n; ++i) {
			int j = i;
			stack<int> s;

			while (c[j] >= 0) {
				s.push(j);
				j = c[j];
				c[s.top()] = -1;					
			}

			if (c[j] == -1) {
				int r = 1;
				while (s.top() != j) {
					c[s.top()] = -2;
					s.pop();
					++r;
				}
				m += r;
				ans = 1LL * ans * b[r] % MOD;
			}

			while (!s.empty()) {
				c[s.top()] = -2;
				s.pop();
			}
		}
		ans = 1LL * ans * p[n - m] % MOD;
		printf("%d\n", ans);
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//716595  	2011-01-07 11:37:21 	Accepted	0.004	Minimum	26909	C++	5117 - Chemicals

/*
id => 1174194
pid => 5117
pname => Chemicals
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:36:31
*/
