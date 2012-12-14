// GOOD PROBLEM

#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int THRESHOLD = 1 << 10;
const int MAXN = 1 << 19;
const PII INF = make_pair(MAXN, 1);

PII a[MAXN << 1];
PII b[THRESHOLD];

inline int L(int p) {
	return p << 1;
}

inline int R(int p) {
	return L(p) ^ 1;
}

PII gao(int p, int pl, int pr, int l, int r) {
	if (pl == l && pr == r) {
		return a[p];
	} else {
		int pm = (pl + pr) / 2;
		if (r <= pm) {
			return gao(L(p), pl, pm, l, r);
		} else if (pm <= l) {
			return gao(R(p), pm, pr, l, r);
		} else {
			return min(gao(L(p), pl, pm, l, pm), gao(R(p), pm, pr, pm, r));
		}
	}
}

int main() {
	int ri = 0, n, x;
	PII p, t;
	char op;

	while (scanf("%d", &n) != EOF && n > 0) {
		if (ri > 0) {
			puts("");
		}
		printf("Case %d:\n", ++ri);
		
		fill(a, a + (MAXN << 1), INF);
		fill(b, b + THRESHOLD, INF);
		for (int i = 0, k = 1; i < n; ++i) {
			scanf(" %c%d", &op, &x);
			if (op == 'B') {
				for (int j = 1; j < THRESHOLD; ++j) {
					b[j] = min(b[j], make_pair(x % j, -k));
				}
				p = make_pair(x, -k);
				for (int j = MAXN + x; j > 0; j /= 2) {
					a[j] = min(a[j], p);
				}
				++k;
			} else {
				if (x < THRESHOLD) {
					printf("%d\n", -b[x].second);
				} else {
					p = INF;
					for (int i = 0; i < MAXN; i += x) {
						t = gao(1, 0, MAXN, i, min(MAXN, i + x));
						if (t.first < MAXN) {	// ..
							t.first %= x;
						}
						p = min(p, t);
					}
					printf("%d\n", -p.second);
				}
			}
		}
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//723944  	2011-01-22 17:07:18 	Accepted	8.484	8600	26909	C++	3699 - Harmony Forever
// 1 << 12  | 30.859
// 1 << 11  | 15.961
// 1 << 10  | 8.484
// 1 << 9   | 18.133
/*
id => 1174134
pid => 3699
pname => Harmony Forever
status => Accepted
lang => C++
time => 2.272
date => 2012-12-14 17:28:35
*/
