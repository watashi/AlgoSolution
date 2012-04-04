#include <map>
#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

long long pow(long long a, long long b, long long c) {
	long long ret = 1;
	for (int i = 0; i < b && ret < c; ++i) {
		ret *= a;
	}
	return ret;
}

map<pair<long long, long long>, int> dp;

int gao(long long a, long long b, long long c) {
	if (pow(a, b, c) >= c) {
		return 1;
	}
	if (dp.count(make_pair(a, b)) == 0) {
		if (a == 1 && pow(a + 1, b, c) >= c) {
			dp[make_pair(a, b)] = 0;
		} else if (b == 1 && pow(a, b + 1, c) >= c) {
			dp[make_pair(a, b)] = (c - a) % 2 == 0 ? 1 : -1;
		} else {
			dp[make_pair(a, b)] = max(-gao(a + 1, b, c), -gao(a, b + 1, c));
		}
	}
	return dp[make_pair(a, b)];
}

const char* ans[] = {
	"Stas",
	"Missing",
	"Masha",
};

int main() {
	int a, b, c;

	scanf("%d%d%d", &a, &b, &c);
	puts(ans[gao(a, b, c) + 1]);

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//396355 	Apr 19, 2011 3:34:33 PM 	watashi 	39E - What Has Dirichlet Got to Do with That? 	GNU C++ 	Accepted 	60 ms 	10000 KB 
