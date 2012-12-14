#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char a[101][101];
char p[6][6];

int main(void)
{
	int ri = 0;
	int n, c, m, mm;

	while(true) {
		mm = 0;
		for (int i = 0; i < 5; i++) {
			scanf("%s", p[i]);
			for (int j = 0; j < 5; j++)
				if(p[i][j] == 'X')
					++mm;
		}
		scanf("%d", &n);
		if(n == 0)
			break;
		if(ri > 0)
			putchar('\n');
		printf("Game %d\n", ++ri);
		for (int k = 1; k <= n; k++) {
			m = 0;
			for (int i = 0; i < 5; i++)
				for (int j = 0; j < 5; j++) {
					scanf("%d", &c);
					if(p[i][j] == 'X')
						a[k][m++] = c;
				}
			sort(a[k], a[k] + mm);
			for (int kk = 1; kk < k; kk++)
				if(!strncmp(a[kk], a[k], mm)) {
					printf("Card %d is equivalent to card %d\n", k, kk);
					break;
				}
		}
	}

	return 0;
}
//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//806257 	2015 	Bob's Bingo Bonanza 	Accepted 	C++ 	0.044 	2011-05-24 10:57:44
/*
id => 1174096
pid => 2015
pname => Bob's Bingo Bonanza
status => Accepted
lang => C++
time => 0.032
date => 2012-12-14 17:21:48
*/
