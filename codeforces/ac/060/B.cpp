#include <cstdio>

const int dx[6] = {-1, 1, 0, 0, 0, 0};
const int dy[6] = {0, 0, -1, 1, 0, 0};
const int dz[6] = {0, 0, 0, 0, -1, 1};
char s[12][12][12];

int gao(int i, int j, int k) {
	if (s[i][j][k] != '.') {
		return 0;
	} else {
		int ret = 1;
		s[i][j][k] = 'X';
		for (int t = 0; t < 6; ++t) {
			ret += gao(i + dx[t], j + dy[t], k + dz[t]);
		}
		return ret;
	}
}

int main() {
	int x, y, z;

	scanf("%d%d%d", &x, &y, &z);
	for (int i = 1; i <= x; ++i) {
		for (int j = 1; j <= y; ++j) {
			scanf("%s", s[i][j] + 1);
		}
	}
	scanf("%d%d", &y, &z);
	printf("%d\n", gao(1, y, z));

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//292259 	Feb 20, 2011 10:51:04 AM 	watashi 	60B - Serial Time! 	GNU C++ 	Accepted 	30 ms 	1400 KB 
