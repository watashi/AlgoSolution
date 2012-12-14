#include <stdio.h>
#include <string.h>
char buf[64];
int main()
{
	int i, d, c, p, l;
	int cnt, len, ini, dis;

	while(gets(buf) && strcmp(buf, "END")) {
		l = strlen(buf);
		len = l - 1;
		cnt = (buf[len] == '.');
		ini = len;
		dis = 1;
		for (i = 0; i < l; i++)
			for (d = 1; i + d < l; d++) {
				c = 0;
				p = i;
				while(buf[p] == '.') {
					c++;
					if(p + d >= l) break;
					else p += d;
				}
				if(c > cnt) {
					cnt = c;
					len = p;
					ini = i;
					dis = d;
				}
				else if(c == cnt) {
					if(p > len) {
						len = p;
						ini = i;
						dis = d;
					}
					else if(p == len) {
						if(i > ini) {
							ini = i;
							dis = d;
						}
						else if(i == ini && d < dis) {
							dis = d;
						}
					}
				}
			}
		printf("%d %d\n", ini, dis);
	}
	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//806017 	3853 	Rock Skipping 	Accepted 	C++ 	0.008 	2011-05-23 17:16:46
/*
id => 1174269
pid => 3853
pname => Rock Skipping
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:47:00
*/
