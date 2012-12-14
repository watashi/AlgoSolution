#include <cstdio>

int main() {
	int n, s;

	while (scanf("%d%d", &n, &s) != EOF) {
		printf("%d\n", s / (n + 1));
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//910240 	4825 	Shares 	Accepted 	C++ 	0.012 	2011-10-18 10:41:50
/*
id => 1174244
pid => 4825
pname => Shares
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:44:09
*/
