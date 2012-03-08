#include <cstdio>
#include <algorithm>

using namespace std;

#define FOR(i, n) for (int i = 1; i <= n; ++i)

int main() {
	int n, m, a, b, c;
	int w[320][320];
	long long s;	// WA38 unless int64<del>, why? test case bug?</del>

	scanf("%d", &n);
	FOR(i, n) FOR(j, n) scanf("%d", &w[i][j]);
	scanf("%d", &m);
	FOR(k, m) {
		scanf("%d%d%d", &a, &b, &c);
		s = 0;
		FOR(i, n) FOR(j, n) s += (w[i][j] = min(w[i][j], min(w[i][a] + c + w[b][j], w[i][b] + c + w[a][j])));
		printf("%I64d\n", s / 2);
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//219468 	Dec 15, 2010 5:33:10 PM 	watashi 	C - Roads in Berland 	GNU C++ 	Accepted 	310 ms 	1692 KB 

//Elements of g may be more then 1000, because they are not lengths of edges but lengths of minimal paths !!!!!!!!!!!!!
