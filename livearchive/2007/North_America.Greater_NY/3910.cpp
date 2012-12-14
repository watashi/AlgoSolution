#include <cstdio>
#include <cstring>

char buf[108];

int main(void)
{
	int ri, re;
	int m;

	scanf("%d", &re);
	for (ri = 1; ri <= re; ri++) {
		printf("%d ", ri);
		scanf("%d%s", &m, buf + 1);
		for (int i = 1; buf[i] != '\0'; ++i) {
			if(i != m) {
				putchar(buf[i]);
			}
		}
		putchar('\n');
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//805984 	3910 	Mispelling 	Accepted 	C++ 	0.012 	2011-05-23 16:39:26
/*
id => 1174184
pid => 3910
pname => Mispelling
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:35:22
*/
