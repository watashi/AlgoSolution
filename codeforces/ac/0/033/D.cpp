#include <bitset>
#include <cstdio>

const int MAXN = 1024;
std::bitset<MAXN> b[MAXN];

inline bool judge(long long x, long long y, long long rr) {
	return x * x + y * y <= rr;	
}

int main() {
	int n, m, q, x, y, r;
	int xx[MAXN], yy[MAXN];
	long long rr;

	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &xx[i], &yy[i]);
	}
	for (int j = 0; j < m; ++j) {
		scanf("%d%d%d", &r, &x, &y);
		rr = 1LL * r * r;
		for (int i = 0; i < n; ++i) {
			b[i].set(j, judge(x - xx[i], y - yy[i], rr));
		}
	}
	for (int k = 0; k < q; ++k) {
		scanf("%d%d", &x, &y);
		printf("%d\n", (b[x - 1] ^ b[y - 1]).count());
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//242492 	Jan 8, 2011 11:16:53 PM 	watashi 	D - Knights 	GNU C++ 	Accepted 	130 ms 	1448 KB 
