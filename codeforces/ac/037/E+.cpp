#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 54;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

char color[MAXN * MAXN];
vector<int> e[MAXN * MAXN];
char buf[MAXN][MAXN];
int tag[MAXN][MAXN];

void floodfill(int x, int y, int z, char c) {
	if (buf[x][y] != c) {
		return;
	}
	buf[x][y] = '\0';
	tag[x][y] = z;
	for (int i = 0; i < 4; ++i) {
		floodfill(x + dx[i], y + dy[i], z, c);
	}
}

int gao(int n, int s) {
	int ret = -1;
	queue<int> q;
	vector<int> d(n, -1);

	d[s] = 0;
	q.push(s);
	while (!q.empty()) {
		s = q.front();
		q.pop();
		if (color[s] == 'B') {
			ret = d[s];
		}
		for (vector<int>::iterator it = e[s].begin(); it != e[s].end(); ++it) {
			if (d[*it] == -1) {
				d[*it] = d[s] + 1;
				q.push(*it);
			}
		}
	}

	return ret;
}

int main() {
	int n, r, c, ans;

	scanf("%d%d", &r, &c);
	for (int i = 1; i <= r; ++i) {
		scanf("%s", buf[i] + 1);
	}
	n = 0;
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			if (buf[i][j] != '\0') {
				color[n] = buf[i][j];
				floodfill(i, j, n, buf[i][j]);
				++n;
			}
		}
	}

	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			for (int k = 0; k < 4; ++k) {
				int x = i + dx[k];
				int y = j + dy[k];
				if (1 <= x && x <= r && 1 <= y && y <= c && tag[i][j] != tag[x][y]) {
					e[tag[i][j]].push_back(tag[x][y]);
				}
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		sort(e[i].begin(), e[i].end());
		e[i].erase(unique(e[i].begin(), e[i].end()), e[i].end());
	}

	ans = n;
	for (int i = 0; i < n; ++i) {
		ans = min(ans, gao(n, i));
	}
	printf("%d\n", ans + 1);

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//457330 	May 17, 2011 1:30:42 AM 	watashi 	37E - Trial for Chief 	GNU C++ 	Accepted 	30 ms 	1500 KB

/*
E. Trial for Chief
First, we construct the following graph: each cell we associate a vertex of the same color as the cell itself. Between neighboring cells hold an edge of weight 0, if the cells share the same color and weight of 1, if different. Now, for each cell count the shortest distance from it to the most distant black cell (denoted by D). It is easy to see that we can construct a sequence of D + 1 repainting leads to the desired coloring:

    The first step of color all the cells at a distance less than or equal to D in black color

    At the second step color all the cells at a distance less than or equal to D - 1 in white

    Etc.


Of all the cells, choose the one for which this distance is minimal, and this distance increased by one will be the answer to the problem.
*/
