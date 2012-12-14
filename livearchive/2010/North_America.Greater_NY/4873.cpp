#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int re;
	int c[8], d;
	char buf[80];

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%s", buf);
		printf("%s", buf);
		scanf("%s", buf);
		fill(c, c + 8, 0);
		d = 0;
		for (int i = 0; i < 40; ++i) {
			d = (d << 1) & 7;
			if (buf[i] == 'H') {
				d ^= 1;
			}
			if (i >= 2) {
				++c[d];
			}
		}
		for (int i = 0; i < 8; ++i) {
			printf(" %d", c[i]);
		}
		puts("");
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//881078 	4873 	Penney Game 	Accepted 	C++ 	0.008 	2011-09-13 09:33:04
/*
id => 1174163
pid => 4873
pname => Penney Game
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:32:11
*/
