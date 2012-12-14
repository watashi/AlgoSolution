#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int dy[4] = {1, 0, -1, 0};
const int dz[4] = {0, 1, 0, -1};

char a[11][111][111];
int d[11][111][111];
int dp[5050];

int main() {
	int re;
	int f, r, c, x, y, z, t, n, m;

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		memset(a, 'X', sizeof(a));
		memset(d, 0xff, sizeof(d));
		scanf("%d%d%d%d%d", &f, &r, &c, &n, &m);
		for (int i = 1; i <= f; ++i) {
			for (int j = 1; j <= r; ++j) {
				scanf("%s", a[i][j] + 1);
				a[i][j][c + 1] = 'X';
				for (int k = 1; k <= c; ++k) {
					if (a[i][j][k] == 'S') {
						x = i;
						y = j;
						z = k;
					}
				}
			}
		}

		queue<int> q;
		d[x][y][z] = 0;
		q.push((((x << 8) ^ y) << 8) ^ z);
		while (!q.empty()) {
			x = q.front();
			q.pop();
			z = x & 0xff;
			x >>= 8;
			y = x & 0xff;
			x >>= 8;
			t = d[x][y][z];
			for (int i = 0; i < 4; ++i) {
				y += dy[i];
				z += dz[i];
				if (a[x][y][z] != 'X' && d[x][y][z] == -1) {
					d[x][y][z] = t + 1;
					q.push((((x << 8) ^ y) << 8) ^ z);
				}
				y -= dy[i];
				z -= dz[i];
			}
			if (a[x][y][z] == 'U') {
				++x;
				if (d[x][y][z] == -1) {
					d[x][y][z] = t + 1;
					q.push((((x << 8) ^ y) << 8) ^ z);
				}
				--x;
			} else if (a[x][y][z] == 'D') {
				--x;
				if (d[x][y][z] == -1) {
					d[x][y][z] = t + 1;
					q.push((((x << 8) ^ y) << 8) ^ z);
				}
				++x;
			}
		}

		m /= 3;
		fill(dp, dp + m + 1, 0);
		for (int i = 0; i < n; ++i) {
			scanf("%d%d%d%d", &x, &y, &z, &t);
			if (d[x][y][z] != -1) {
				for (int j = m; j >= d[x][y][z]; --j) {
					dp[j] = max(dp[j], dp[j - d[x][y][z]] + t);
				}
			}
		}
		printf("%d\n", *max_element(dp, dp + m + 1));
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//864744 	5066 	Fire Drill 	Accepted 	C++ 	0.276 	2011-08-24 06:02:56
/*
id => 1174300
pid => 5066
pname => Fire Drill
status => Accepted
lang => C++
time => 0.175
date => 2012-12-14 17:51:22
*/
