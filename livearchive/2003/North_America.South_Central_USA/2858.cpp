#include <cstdio>
#include <cstring>

char buf[80];
int pic[11][11];

int main(void)
{
	int r, c;

	while(scanf("%s", buf) != EOF && !strcmp("START", buf)) {
		scanf("%d%d", &r, &c);
		for (int i = 1; i <= r; i++)
			for (int j = 1; j <= c; j++)
				scanf("%1d", &pic[i][j]);
		scanf("%*s");
		for (int i = 1; i < r; i++) {
			for (int j = 1; j < c; j++)
				printf("%d", pic[i][j] + pic[i][j + 1] + pic[i + 1][j] + pic[i + 1][j + 1] >> 2);
			printf("\n");
		}
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//806290 	2858 	Blurred Vision 	Accepted 	C++ 	0.008 	2011-05-24 11:38:13

/*
id => 1174228
pid => 2858
pname => Blurred Vision
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:41:40
*/
