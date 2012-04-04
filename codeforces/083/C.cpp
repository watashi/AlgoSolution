#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 54;
const int MAXD = 5000;
const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {-1, 0, 1, 0};

static int d0;

bool valid[256];
int r, c;
char buf[MAXN][MAXN];
int d[MAXN][MAXN], p[MAXN][MAXN];

string gao(int sx, int sy) {
	queue<pair<int, int> > q;
	vector<vector<pair<int, int> > > v;
	static int x, y, xx, yy, z;

	d[sx][sy] = d0;
	q.push(make_pair(sx, sy));
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		z = d[x][y] + 1;
		v.resize(z - d0 + 1);
		v[z - d0].push_back(make_pair(x, y));
	//	printf("(%d, %d)\n", x, y);
		q.pop();
		if (buf[x][y] == 'S') {
			break;
		}
		for (int i = 0; i < 4; ++i) {
			xx = x + dx[i];
			yy = y + dy[i];
			if (valid[(int)buf[xx][yy]] && d[xx][yy] > z) {
				d[xx][yy] = z;
				q.push(make_pair(xx, yy));
			}
		}
	}

	if (buf[x][y] != 'S') {
		return "~";
	} else {
		for (int i = 0; i < (int)v.size(); ++i) {
			vector<pair<pair<char, int>, pair<int, int> > > w;
			for (int j = 0; j < (int)v[i].size(); ++j) {
				x = v[i][j].first;
				y = v[i][j].second;
				w.push_back(make_pair(make_pair(buf[x][y], MAXD), make_pair(x, y)));
				for (int k = 0; k < 4; ++k) {
					xx = x + dx[k];
					yy = y + dy[k];
					if (d[xx][yy] == d[x][y] - 1) {
						w.back().first.second = min(w.back().first.second, p[xx][yy]);
					}
				}
			}
			sort(w.begin(), w.end());
			for (int j = 0; j < (int)w.size(); ++j) {
				p[w[j].second.first][w[j].second.second] = j;
			}
		}

		string ret;
		while (true) {
			sx = -1;
			sy = -1;
			for (int i = 0; i < 4; ++i) {
				xx = x + dx[i];
				yy = y + dy[i];
				if (d[xx][yy] == d[x][y] - 1 && (sx == -1 || p[xx][yy] < p[sx][sy])) {
					sx = xx;
					sy = yy;
				}
			}
		//	printf("%d %d\n", sx, sy);
		//	system("sleep 3");
			if (buf[sx][sy] == 'T') {
				break;
			} else {
				ret += buf[sx][sy];
			}
			x = sx;
			y = sy;
		}
	//	reverse(ret.begin(), ret.end());
		return ret;
	}
}

int main() {
	int n, sx = -1, sy = -1, tx = -1, ty = -1;
	bool select[MAXN];
	string ans, tmp;
	
	scanf("%d%d%d", &r, &c, &n);
	memset(buf, '~', sizeof(buf));
	for (int i = 1; i <= r; ++i) {
		scanf("%s", buf[i] + 1);
		for (int j = 1; j <= c; ++j) {
			if (buf[i][j] == 'S') {
				sx = i;
				sy = j;
			} else if (buf[i][j] == 'T') {
				tx = i;
				ty = j;
			}
		}
		buf[i][c + 1] = '~';
	}

	fill(select, select + 26, false);
	fill(select, select + n, true);
	sort(select, select + 26);
	valid['S'] = valid['T'] = true;
	ans = "~";
	d0 = 0;
	do {
		d0 -= MAXD;
		for (int i = 0; i < 26; ++i) {
			valid['a' + i] = select[i];
		}
		tmp = gao(tx, ty);
		if (tmp != "~" && (ans == "~" || tmp.length() < ans.length() || (tmp.length() == ans.length() && tmp < ans))) {
			ans = tmp;
		}
	//	puts("A");
	} while (next_permutation(select, select + 26));

	if (ans == "~") {
		puts("-1");
	} else {
		puts(ans.c_str());
	}

	return 0;
}

/*
3 4 3
cccT
aaca
Sdab
*/

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//452977 	May 13, 2011 10:25:56 PM 	watashi 	C - Track 	GNU C++ 	Accepted 	1280 ms 	1432 KB 
