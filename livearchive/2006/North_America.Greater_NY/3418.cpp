#include <string>
#include <cstdio>
using namespace std;

int main(void)
{
	int re, n, k;
	char buf[1024];
	string lhs, rhs, src, tar;

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d", &n);
		scanf("%s", buf);
		lhs = buf;
		scanf("%s", buf);
		rhs = lhs + buf;
		scanf("%s", buf);
		tar = buf;

		src = lhs = rhs;
		k = 0;
		while(true) {			
			for (int i = 0; i < n; i++) {
				rhs[2 * i] = lhs[n + i];
				rhs[2 * i + 1] = lhs[i];
			}
			++k;
			if (rhs == tar) {
				printf("%d %d\n", ri, k);
				break;
			}
			if (rhs == src) {
				printf("%d %d\n", ri, -1);
				break;
			}
			lhs.swap(rhs);
		}
	}

	return 0;
}
//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//805978 	3418 	Shuffle'm Up 	Accepted 	C++ 	0.008 	2011-05-23 16:28:38
/*
id => 1174170
pid => 3418
pname => Shuffle'm Up
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:33:12
*/
