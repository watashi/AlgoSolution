#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

const int MAXN = 5050;

int main() {
	int re, n, s, a[MAXN];

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d", &n);
		s = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			s += count_if(a, a + i, bind2nd(less_equal<int>(), a[i]));
		}
		printf("%d\n", s);
	}
	
	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//866479 	4843 	Sales 	Accepted 	C++ 	0.056 	2011-08-26 05:31:46
/*
id => 1174202
pid => 4843
pname => Sales
status => Accepted
lang => C++
time => 0.029
date => 2012-12-14 17:37:45
*/
