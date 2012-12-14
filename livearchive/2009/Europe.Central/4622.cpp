#include <cstdio>
#include <algorithm>
#include <sys/resource.h>

using namespace std;

const int MAXN = 1024;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const bool dz[][4] = {
	{false, false, false, false},
	{false, true, true, false},
	{false, false, true, true},
	{true, false, false, true},
	{true, true, false, false},
	{true, true, true, true}
};

char buf[MAXN][MAXN];

void gao(int i, int j) {
	int a = buf[i][j] - 'A';
	buf[i][j] = 'A';
	for (int k = 0; k < 4; ++k) {
		int b = buf[i + dx[k]][j + dy[k]] - 'A';
		if (dz[a][k] && dz[b][k ^ 2]) {
			gao(i + dx[k], j + dy[k]);
		}
	}
}

int main() {
	int re, r, c, ans;
	struct rlimit rlim;

	getrlimit(RLIMIT_STACK, &rlim);
//	printf("%d %d\n", rlim.rlim_cur, rlim.rlim_max);
	rlim.rlim_cur = 128 * 1024 * 1024;
	setrlimit(RLIMIT_STACK, &rlim);
//	printf("%d %d\n", rlim.rlim_cur, rlim.rlim_max);
	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d%d", &r, &c);
		fill(buf[0], buf[0] + c + 2, 'A');
		for (int i = 1; i <= r; ++i) {
			scanf("%s", buf[i] + 1);
			buf[i][0] = buf[i][c + 1] = 'A';
		}
		fill(buf[r + 1], buf[r + 1] + c + 2, 'A');
		
		ans = 0;
		for (int i = 1; i <= r; ++i) {
			for (int j = 1; j <= c; ++j) {
				if (buf[i][j] != 'A') {
					++ans;
					gao(i, j);
				}
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}
//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//715000  	2011-01-04 06:39:50 	Accepted	0.561	24816	26909	C++	4622 - Decision

/*
id => 1174288
pid => 4622
pname => Decision
status => Accepted
lang => C++
time => 0.375
date => 2012-12-14 17:49:56
*/
