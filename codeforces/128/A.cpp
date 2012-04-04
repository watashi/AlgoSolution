#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 8;

int main() {
	char buf[MAXN + 1];
	bool loop, a[MAXN][MAXN], b[MAXN][MAXN];
	vector<pair<int, int> > v;
	
	for (int i = 0; i < MAXN; ++i) {
		fill(a[i], a[i] + MAXN, false);
		scanf("%s", buf);
		for (int j = 0; j < MAXN; ++j) {
			if (buf[j] == 'S') {
				v.push_back({i, j});
			}
		}
	}

	loop = true;
	a[MAXN - 1][0] = true;
	while (loop) {
		loop = false;
		fill(b[0], b[MAXN], false);
		for (int i = 0; i < MAXN; ++i) {
			for (int j = 0; j < MAXN; ++j) {
				if (a[i][j]) {
					loop = true;
					for (int ii = max(0, i - 1); ii <= min(MAXN - 1, i + 1); ++ii) {
						for (int jj = max(0, j - 1); jj <= min(MAXN - 1, j + 1); ++jj) {
							b[ii][jj] = true;
						}
					}
				}
			}
		}
		for (auto& p: v) {
			if (p.first < MAXN) {
				b[p.first][p.second] = false;
				++p.first;
				if (p.first < MAXN) {
					b[p.first][p.second] = false;
				}
			}
		}
		copy(b[0], b[MAXN], a[0]);
		if (a[0][MAXN - 1]) {
			break;
		}
	}
	puts(loop ? "WIN" : "LOSE");

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//871257 	Nov 15, 2011 2:52:52 PM 	watashi 	128A - Statues 	GNU C++0x 	Accepted 	30 ms 	1400 KB 
