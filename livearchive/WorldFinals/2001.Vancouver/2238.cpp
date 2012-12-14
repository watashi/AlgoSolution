#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 512;
const int INF = 1000000000;

int kuhnMunkras(int m, int n, int mat[][MAXN], int match1[], int match2[]) {
	int s[MAXN + 1], t[MAXN], l1[MAXN], l2[MAXN], p, q, ret = 0, i, j, k;
	for (i = 0; i < m; ++i) {
		l1[i] = *max_element(mat[i], mat[i] + n);
	}
	fill(l2, l2 + n, 0);
	fill(match1, match1 + m, -1);
	fill(match2, match2 + n, -1);
	for (i = 0; i < m; ++i) {
//	for (int i = 0; i < m; ++i) {
//		for (int j = 0; j < n; ++j) {
//			printf("%10d", mat[i][j]);
//		}
//		puts("");
//	}
//		printf("@%d\n", i);
		fill(t, t + n, -1);
		for (s[p = q = 0] = i; p <= q && match1[i] < 0; ++p) {
			k = s[p];
			for (j = 0; j < n && match1[i] < 0; ++j) {
				if (l1[k] + l2[j] == mat[k][j] && t[j] < 0) {
					s[++q] = match2[j];
					t[j] = k;
					if (s[q] < 0) {
						for (p = j; p >= 0; j = p) {
							match2[j] = k = t[j];
							p = match1[k];
							match1[k] = j;
						}
					}
				}
			}
		}
		if (match1[i] < 0) {
			--i;
			p = INF;
			for (k = 0; k <= q; ++k) {
				for (j = 0; j < n; ++j) {
					if (t[j] < 0 && l1[s[k]] + l2[j] - mat[s[k]][j] < p) {
						p = l1[s[k]] + l2[j] - mat[s[k]][j];
					}
				}
			}
//			printf("delta = %d\n", p);
			for (j = 0; j < n; ++j) {
				l2[j] += (t[j] < 0 ? 0 : p);
			}
			for (k = 0; k <= q; ++k) {
				l1[s[k]] -= p;
			}
		}
	}
	for (i = 0; i < m; ++i) {
		ret += mat[i][match1[i]];
	}
	return ret;
}

int mat[MAXN][MAXN], match1[MAXN], match2[MAXN];

int main() {
	int ri = 0, n, m, r, x[MAXN], s[MAXN], t[MAXN], which[MAXN], begin[MAXN], end[MAXN];
	double ret;
	vector<vector<pair<int, int> > > ans;

	while (scanf("%d%d", &n, &m) != EOF && n > 0) {
		for (int i = 0; i < n; ++i) {
			scanf("%d", &x[i]);
		}
		for (int i = 0; i < m; ++i) {
			scanf("%d", &r);
			for (int j = 1; j <= r; ++j) {
				scanf("%d%d", &s[j], &t[j]);
			}
			s[0] = 0;
			t[0] = INF;
			for (int j = 0; j < n; ++j) {
				int k = r;
				while (s[k] > x[j]) {
					--k;
				}
				for (int tt = 0; tt < m; ++tt) {
					mat[i][j * m + tt] = (k == 0 ? -INF : -t[k] * (tt + 1));
				}
			}
		}
		ret = kuhnMunkras(m, n * m, mat, match1, match2);
		
		ans.clear();
		ans.resize(n);
		for (int i = 0; i < m; ++i) {
			which[i] = match1[i] / m;
			ans[match1[i] / m].push_back(make_pair(-mat[i][match1[i]] / (match1[i] % m + 1) , i));
		}
		for (int i = 0; i < n; ++i) {
			sort(ans[i].begin(), ans[i].end());
			int last = 0;
			for (int j = 0; j < (int)ans[i].size(); ++j) {
				begin[ans[i][j].second] = last;
				last += ans[i][j].first;
				end[ans[i][j].second] = last;
			}
		}
		
		if (ri > 0) {
			puts("");
		}
		printf("Case %d\n", ++ri);
		printf("Average turnaround time = %.2lf\n", -ret / m);
		for (int i = 0; i < m; ++i) {
			printf("Program %d runs in region %d from %d to %d\n", i + 1, which[i] + 1, begin[i], end[i]);
		}
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//722956  	2011-01-20 15:03:38 	Accepted	1.111	1520	26909	C++	2238 - Fixed Partition Memory Management

/*
id => 1174024
pid => 2238
pname => Fixed Partition Memory Management
status => Accepted
lang => C++
time => 0.066
date => 2012-12-14 17:11:53
*/
