#include <queue>
#include <cstdio>

using namespace std;

const int MAXN = 13;

int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, -1, 0, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
char color[6][MAXN][MAXN];
bool in[MAXN][MAXN][MAXN], bad[MAXN][MAXN][MAXN];

struct XYZ {
	int x, y, z;
	XYZ(int x, int y, int z) : x(x), y(y), z(z) { }
};

int main() {
	int n;
	int ans;

	while (scanf("%d", &n) != EOF && n > 0) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < 6; ++j) {
				scanf("%s", color[j][i]);
			}
		}

		queue<XYZ> q;
		for (int i = 0; i <= n + 1; ++i) {
			for (int j = 0; j <= n + 1; ++j) {
				for (int k = 0; k <= n + 1; ++k) {
					in[i][j][k] = (i == 1 || i == n || j == 1 || j == n || k == 1 || k == n);
					bad[i][j][k] = (i < 1 || i > n || j < 1 || j > n || k < 1 || k > n);
					if (!bad[i][j][k] && in[i][j][k]) {
						q.push(XYZ(i, j, k));
					}
				}
			}
		}

		while (!q.empty()) {
			char c = ' ', cc;
			XYZ s = q.front();
			q.pop();
//			printf("@ %d %d %d\n", s.x, s.y, s.z);
			in[s.x][s.y][s.z] = false;
			for (int i = 0; i < 6; ++i) {
				int xx = s.x + dx[i], yy = s.y + dy[i], zz = s.z + dz[i];
				while (1 <= xx && xx <= n && 1 <= yy && yy <= n && 1 <= zz && zz <= n && bad[xx][yy][zz]) {
					xx += dx[i];
					yy += dy[i];
					zz += dz[i];
				}
				if (xx < 1 || xx > n || yy < 1 || yy > n || zz < 1 || zz > n) {
				//	if (bad[s.x + dx[i]][s.y + dy[i]][s.z + dz[i]]) {
					switch (i) {
						case 0: cc = color[i][n - s.z][s.y - 1]; break;
						case 1: cc = color[i][n - s.z][s.x - 1]; break;
						case 2: cc = color[i][n - s.z][n - s.y]; break;
						case 3: cc = color[i][n - s.z][n - s.x]; break;
						case 4: cc = color[i][s.x - 1][s.y - 1]; break;
						case 5: cc = color[i][n - s.x][s.y - 1]; break;
					}
//					printf("for [%d]: cc = %c\n", i, cc);
					if (cc == '.' || (c != ' ' && c != cc)) {
						bad[s.x][s.y][s.z] = true;
						break;
					} else {
						c = cc;
					}
				}
			}
			if (bad[s.x][s.y][s.z]) {
				for (int i = 0; i < 6; ++i) {
					int xx = s.x + dx[i], yy = s.y + dy[i], zz = s.z + dz[i];
					while (1 <= xx && xx <= n && 1 <= yy && yy <= n && 1 <= zz && zz <= n && bad[xx][yy][zz]) {
						xx += dx[i];
						yy += dy[i];
						zz += dz[i];
					}
					if (!bad[xx][yy][zz] && !in[xx][yy][zz]) {
						in[xx][yy][zz] = true;
						q.push(XYZ(xx, yy, zz));
					}
				}
			}
		}

		ans = n * n * n;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				for (int k = 1; k <= n; ++k) {
					if (bad[i][j][k]) {
						--ans;
					}
				}
			}
		}
		printf("Maximum weight: %d gram(s)\n", ans);
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//723902  	2011-01-22 15:25:37 	Accepted	0.014	Minimum	26909	C++	2995 - Image Is Everything

/*
id => 1174050
pid => 2995
pname => Image Is Everything
status => Accepted
lang => C++
time => 0.012
date => 2012-12-14 17:15:30
*/
