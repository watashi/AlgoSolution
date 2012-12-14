#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1024;
const long long MOD = 1000000007LL;

int s[MAXN];
bool r[MAXN];
vector<int> e[MAXN];
long long c[MAXN][MAXN];

long long gao(int v) {
	long long ret = 1LL;
	
	s[v] = 0;
	for (vector<int>::const_iterator w = e[v].begin(); w != e[v].end(); ++w) {
		ret = ret * gao(*w) % MOD;
		s[v] += s[*w];
		ret = ret * c[s[v]][s[*w]] % MOD;
	}
	++s[v];

	return ret;
}

int main() {
	int re, n, a, b;

	for (int i = 0; i < MAXN; ++i) {
		c[i][0] = c[i][i] = 1LL;
		for (int j = 1; j < i; ++j) {
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
		}
	}

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			r[i] = true;
			e[i].clear();
		}
		for (int i = 1; i < n; ++i) {
			scanf("%d%d", &a, &b);
			r[b - 1] = false;
			e[a - 1].push_back(b - 1);
		}

		a = find(r, r + n, true) - r;
		printf("Case %d: %lld\n", ri, gao(a));
	}	

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//868542 	5002 	The Queue 	Accepted 	C++ 	0.116 	2011-08-28 06:30:44
/*
id => 1174113
pid => 5002
pname => The Queue
status => Accepted
lang => C++
time => 0.106
date => 2012-12-14 17:24:19
*/
