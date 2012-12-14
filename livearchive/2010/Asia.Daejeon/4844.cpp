#include <map>
#include <cstdio>
#include <string>

using namespace std;

map<pair<int, int>, bool> dp;

bool test(int a, int b) {
	return (a >> b) & 1;
}

bool gao(int n, int m) {
	if (dp.count(make_pair(n, m)) != 0) {
		return dp[make_pair(n, m)];
	} else {
		bool& ret = dp[make_pair(n, m)];
		for (int i = 0, j = 0; i < n; i = j) {
			while (j < n && test(m, i) == test(m, j)) {
				++j;
			}
			if (j - i >= 2 && gao(n - (j - i), m ^ (m >> i << i) ^ (m >> j << i))) {
				ret = true;
				break;
			}
		}
		return ret;
	}
}

int main() {
	int re, n, m;
	char buf[80];

	scanf("%d", &re);
	dp[make_pair(0, 0)] = true;
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%s", buf);
		for (n = 0, m = 0; buf[n] != '\0'; ++n) {
			m <<= 1;
			if (buf[n] == 'a') {
				m ^= 1;
			}
		}
		puts(gao(n, m) ? "1" : "0");
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//866481 	4844 	String Popping 	Accepted 	C++ 	0.036 	2011-08-26 05:31:59
/*
id => 1174205
pid => 4844
pname => String Popping
status => Accepted
lang => C++
time => 0.032
date => 2012-12-14 17:38:00
*/
