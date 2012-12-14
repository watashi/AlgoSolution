#include <map>
#include <queue>
#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 2048;
const int INF = 2000000002;
const int dx[] = {0, -1, 0, 1};
const int dy[] = {-1, 0, 1, 0};

int d[MAXN][MAXN], e[MAXN][MAXN][4];

int main() {
	int ri = 0, n, nx, ny, x, y, z, xx, yy;
	int x1[MAXN], y1[MAXN], x2[MAXN], y2[MAXN];
	map<int, int> mx, my;

	while (scanf("%d", &n) != EOF && n > 0) {
		mx.clear();
		my.clear();
		mx[-INF];
		mx[INF];
		my[-INF];
		my[INF];
		for (int i = 0; i <= n; ++i) {
			scanf("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);
			mx[x1[i]];
			my[y1[i]];
			mx[x2[i]];
			my[y2[i]];
		}
		nx = ny = 0;
		for (map<int, int>::iterator i = mx.begin(); i != mx.end(); ++i) {
			i->second = nx++;
		}
		for (map<int, int>::iterator i = my.begin(); i != my.end(); ++i) {
			i->second = ny++;
		}
		for (int i = 0; i <= n; ++i) {
			x1[i] = mx[x1[i]];
			y1[i] = my[y1[i]];
			x2[i] = mx[x2[i]];
			y2[i] = my[y2[i]];
		}

		for (int i = 0; i < nx; ++i) {
			for (int j = 0; j < ny; ++j) {
				d[i][j] = INF;
				for (int k = 0; k < 4; ++k) {
					e[i][j][k] = 0;
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			if (x1[i] == x2[i]) {
				if (y1[i] > y2[i]) {
					swap(y1[i], y2[i]);
				}
				for (int j = y1[i]; j < y2[i]; ++j) {
					e[x1[i] - 1][j][3] = 1;
					e[x1[i]][j][1] = 1;
				}
			} else if (y1[i] == y2[i]) {
				if (x1[i] > x2[i]) {
					swap(x1[i], x2[i]);
				}
				for (int j = x1[i]; j < x2[i]; ++j) {
					e[j][y1[i] - 1][2] = 1;
					e[j][y1[i]][0] = 1;
				}
			}
	//		printf("Line %d %d %d %d\n", x1[i], y1[i], x2[i], y2[i]);
		}
	//	printf("DO %d %d %d %d\n", x1[n], y1[n], x2[n], y2[n]);

		priority_queue<pair<int, pair<int, int> > > q;
		x = x1[n];
		y = y1[n];
		d[x][y] = 0;
		q.push(make_pair(-d[x][y], make_pair(x, y)));
		while (!q.empty()) {
			x = q.top().second.first;
			y = q.top().second.second;
			z = -q.top().first;
	//		printf("%d %d %d\n", x, y, z);
			q.pop();
			if (d[x][y] != z) {
				continue;
			}
			for (int i = 0; i < 4; ++i) {
				xx = x + dx[i];
				yy = y + dy[i];
				if (0 <= xx && xx < nx && 0 <= yy && yy < ny && d[xx][yy] > z + e[x][y][i]) {
					d[xx][yy] = z + e[x][y][i];
					q.push(make_pair(-d[xx][yy], make_pair(xx, yy)));
				}
			}
		}
		printf("City %d\nPeter has to cross %d streets\n", ++ri, d[x2[n]][y2[n]]);
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//725276  	2011-01-24 17:03:06 	Accepted	0.002	Minimum	26909	C++	3274 - Crossing Streets

/*
id => 1174321
pid => 3274
pname => Crossing Streets
status => Accepted
lang => C++
time => 0.013
date => 2012-12-14 17:54:02
*/
