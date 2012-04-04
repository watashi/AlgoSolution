#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 32;

int r, c;
char buf[MAXN][MAXN];
int cnt[MAXN][MAXN], tmp[MAXN][MAXN];
pair<int, int> other[MAXN][MAXN];
vector<pair<int, int> > group;
int cur[MAXN], how[MAXN], ans;

void gao(int n) {
	if (n == 0) {
		if (ans == 0) {
			copy(cur, cur + 14, how);
		}
		++ans;
	} else {
		--n;
		int x = group[n].first;
		int y = group[n].second;
		for (int k = 0; k < 7; ++k) {
			cur[n] = k;
			bool flag = true;
			for (int ii = x; ii <= x + 1; ++ii) {
				for (int jj = y; jj <= y + 1; ++jj) {
					tmp[ii][jj] = k;
					pair<int, int> o = other[ii][jj];
					int t = tmp[o.first][o.second];
					if (t != -1) {
						int s = k;
						if (s > t) {
							swap(s, t);
						}
						if (--cnt[s][t] < 0) {
							flag = false;
							goto ENDFOR1;
						}
					}
				}
			}
ENDFOR1:
			;
			if (flag) {
				gao(n);
			}
			for (int ii = x; ii <= x + 1; ++ii) {
				for (int jj = y; jj <= y + 1; ++jj) {
					if (tmp[ii][jj] == -1) {
						goto ENDFOR2;
					}
					tmp[ii][jj] = -1;
					pair<int, int> o = other[ii][jj];
					int t = tmp[o.first][o.second];
					if (t != -1) {
						int s = k;
						if (s > t) {
							swap(s, t);
						}
						++cnt[s][t];
					}
				}
			}
ENDFOR2:
			;
		}
	}
}

int main() {
	scanf("%d%d", &r, &c);
	for (int i = 0; i < r; ++i) {
		scanf("%s", buf[i]);
	}
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (buf[i + 1][j] == buf[i][j]) {
				other[i][j] = {i + 1, j};
				other[i + 1][j] = {i, j};
			} else if (buf[i][j + 1] == buf[i][j]) {
				other[i][j] = {i, j + 1};
				other[i][j + 1] = {i, j};
			}
		}
	}
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (buf[i][j] != '.') {
				group.push_back({i, j});
				for (int ii = i; ii <= i + 1; ++ii) {
					for (int jj = j; jj <= j + 1; ++jj) {
						buf[ii][jj] = '.';
					}
				}
			}
		}
	}

	for (int i = 0; i <= 6; ++i) {
		for (int j = i; j <= 6; ++j) {
			cnt[i][j] = 1;
		}
	}

	ans = 0;
	fill(tmp[0], tmp[r], -1);
	gao(14);
	printf("%d\n", ans);
	for (int i = 0; i < 14; ++i) {
		for (int ii = group[i].first; ii <= group[i].first + 1; ++ii) {
			for (int jj = group[i].second; jj <= group[i].second + 1; ++jj) {
				buf[ii][jj] = '0' + how[i];
			}
		}
	}
	for (int i = 0; i < r; ++i) {
		puts(buf[i]);
	}

	return 0;
}

