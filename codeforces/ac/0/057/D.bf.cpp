#include <queue>
#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 128;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

long long gao(int r, int c, char buf[MAXN][MAXN], int x, int y) {
	static int mind[MAXN][MAXN];
	queue<pair<int, int> > q;
	long long s = 0;

	fill(mind[0], mind[r], -1);
	q.push(make_pair(x, y));
	mind[x][y] = 0;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		s += mind[x][y];
		for (int i = 0; i < 4; ++i) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (0 <= xx && xx < r && 0 <= yy && yy < c && buf[xx][yy] == '.' && mind[xx][yy] == -1) {
				mind[xx][yy] = mind[x][y] + 1;
				q.push(make_pair(xx, yy));
			}
		}
	}

	return s;
}

int main() {
	int r, c;
	long long sum = 0, num = 0;
	static char buf[MAXN][MAXN];

	scanf("%d%d", &r, &c);
	for (int i = 0; i < r; ++i) {
		scanf("%s", buf[i]);
	}

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (buf[i][j] == '.') {
				sum += gao(r, c, buf, i, j);
				++num;
			}
		}
	}
	printf("%lld %lld\n", sum, num);
	printf("%.10lf\n", 1.0 * sum / num / num);

	return 0;
}

