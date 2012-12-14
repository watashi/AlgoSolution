#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAXN = 100;

const int dx[5] = {0, 1, 1, 1, 2};
const int dy[5] = {0, -1, 0, 1, 0};

int id[20][20];
char buf[20][20];
int x[MAXN], y[MAXN];

int c[MAXN][3], color[MAXN];
vector<int> e[MAXN];

bool gao(int n, int i) {
	if (i == n) {
		return true;
	} else {
		for (int k = 0; k < 3; ++k) {
			if (c[i][k] == 0) {
				color[i] = k;
				for (vector<int>::const_iterator j = e[i].begin(); j != e[i].end(); ++j) {
					++c[*j][k];
				}
				if (gao(n, i + 1)) {
					return true;
				}
				for (vector<int>::const_iterator j = e[i].begin(); j != e[i].end(); ++j) {
					--c[*j][k];
				}
			}
		}
		return false;
	}
}

int main() {
	int re, n, m;
	bool flag;

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%s", buf[i]);
			fill(id[i], id[i] + n, -1);
		}

		m = 0;
		flag = true;
		for (int i = 0; flag && i < n; ++i) {
			for (int j = 0; flag && j < n; ++j) {
				if (buf[i][j] == '.') {
					for (int k = 0; flag && k < 5; ++k) {
						int xx = i + dx[k];
						int yy = j + dy[k];
						flag &= 0 <= xx && xx < n && 0 <= yy && yy < n && buf[xx][yy] == '.';
						buf[xx][yy] = '?';
						id[xx][yy] = m;
					}
					x[m] = i;
					y[m] = j;
					++m;
				}
			}
		}

		for (int i = 0; i < m; ++i) {
			e[i].clear();
			for (int j = 0; j < 5; ++j) {
				int xx = x[i] + dx[j];
				int yy = y[i] + dy[j];
				for (int xxx = xx - 1; xxx <= xx + 1; ++xxx) {
					for (int yyy = yy - 1; yyy <= yy + 1; ++yyy) {
						if (0 <= xxx && xxx < n && 0 <= yyy && yyy < n && id[xxx][yyy] != -1 && id[xxx][yyy] != i) {
							e[i].push_back(id[xxx][yyy]);
						}
					}
				}
			}
			sort(e[i].begin(), e[i].end());
			e[i].erase(unique(e[i].begin(), e[i].end()), e[i].end());
		}

		if (flag && m > 0) {
			fill(c[0], c[m], 0);
			flag &= gao(m, 0);
		}
		printf("Case %d:", ri);
		if (flag) {
			for (int i = 0; i < m; ++i) {
				for (int j = 0; j < 5; ++j) {
					buf[x[i] + dx[j]][y[i] + dy[j]] = 'B' + color[i];
				}
			}
			puts("");
			for (int i = 0; i < n; ++i) {
				puts(buf[i]);
			}
		} else {
			puts(" Not Possible!");
		}
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//868539 	4997 	ABCD Tiles 	Accepted 	C++ 	0.044 	2011-08-28 06:29:39
/*
id => 1174108
pid => 4997
pname => ABCD Tiles
status => Accepted
lang => C++
time => 0.038
date => 2012-12-14 17:23:15
*/
