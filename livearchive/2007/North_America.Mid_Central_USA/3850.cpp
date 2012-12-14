#include <stdio.h>
#define INF 999999999
#define DIS 2520
const int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int mp[21][21][4];
char mark[21][21];
int mind[21][21];
int main()
{
	int i, j, k, x, y, m, n;
	char buf[4];

	while(scanf("%d%d", &n, &m) != EOF && (m && n)) {
		for (i = 0; i <= n; i++)
			for (j = 0; j <= m; j++) {
				mark[i][j] = 0;
				mind[i][j] = INF;
				for (k = 0; k < 4; k++)
					mp[i][j][k] = INF;
			}
		for (i = 0; i <= n; i++) {
			for (j = 0; j < m; j++) {
				scanf("%d%s", &k, buf);
				if(k == 0) continue;
				k = DIS / k;
				switch(*buf) {
				case '>': mp[i][j][2] = k; break;
				case '<': mp[i][j + 1][3] = k; break;
				case '*': mp[i][j][2] = mp[i][j + 1][3] = k; break;
				}
			}
			if(i == n) break;
			for (j = 0; j <= m; j++) {
				scanf("%d%s", &k, buf);
				if(k == 0) continue;
				k = DIS / k;
				switch(*buf) {
				case 'v': mp[i][j][0] = k; break;
				case '^': mp[i + 1][j][1] = k; break;
				case '*': mp[i][j][0] = mp[i + 1][j][1] = k; break;
				}
			}
		}

		mind[0][0] = 0;
		k = m * n;
		while(!mark[n][m]) {
			x = y = -1;
			for (i = 0; i <= n; i++)
				for (j = 0; j <= m; j++)
					if(!mark[i][j] && (x == -1 || mind[i][j] < mind[x][y])) {x = i; y = j;}
			mark[i = x][j = y] = 1;
			for (k = 0; k < 4; k++) {
				if(mp[i][j][k] == INF) continue;
				x = i + dir[k][0];
				y = j + dir[k][1];
				if(mind[x][y] > mind[i][j] + mp[i][j][k])
					mind[x][y] = mind[i][j] + mp[i][j][k];
			}
		}

		if(mind[n][m] == INF) printf("Holiday\n");
		else printf("%d blips\n", mind[n][m]);
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//806014 	3850 	Here We Go(relians) Again 	Accepted 	C++ 	0.012 	2011-05-23 17:14:36
/*
id => 1174268
pid => 3850
pname => Here We Go(relians) Again
status => Accepted
lang => C++
time => 0.012
date => 2012-12-14 17:46:56
*/
