#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int n, c;
	double pre, cur;

	while (scanf("%d", &n) == 1) {
		c = 0;
		pre = -1e100;
		for (int i = 0; i < n; ++i) {
			scanf("%lf", &cur);
			if (cur > pre) {
				++c;
				pre = cur + 1 - 1e-8;
			}
		}
		printf("%d\n", c);
	}

	return 0;
}
//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//714952  	2011-01-04 03:31:01 	Accepted	0.080	Minimum	26909	C++	4820 - Control Points

/*
id => 1174243
pid => 4820
pname => Control Points
status => Accepted
lang => C++
time => 0.048
date => 2012-12-14 17:43:55
*/
