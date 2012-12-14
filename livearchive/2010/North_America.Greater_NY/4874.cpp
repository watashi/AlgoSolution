#include <cstdio>

int gao(int b, int x, int y) {
	if (x == 0 && y == 0) {
		return 0;
	} else {
		return gao(b, x / b, y / b) * b + (x % b + y % b) % b;
	}
}

int main() {
	int re, rid, b, x, y;

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d%d%d%d", &rid, &b, &x, &y);
		printf("%d %d\n", rid, gao(b, x, y));
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//881212 	4874 	Nim-B Sum 	Accepted 	C++ 	0.012 	2011-09-13 13:37:40
/*
id => 1174165
pid => 4874
pname => Nim-B Sum
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:32:35
*/
