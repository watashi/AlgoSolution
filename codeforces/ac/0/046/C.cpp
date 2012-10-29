#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int n, m, ans;
	char s[4096];

	scanf("%d%s", &n, s);
	ans = 1000000000;
	m = count(s, s + n, 'H');
	for (int i = 0; i < n; ++i) {
		ans = min(ans, m - count(s + i, s + i + m, 'H'));
		s[n + i] = s[i];
	}
	printf("%d\n", ans);

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//208608 	Dec 5, 2010 7:49:54 PM 	watashi 	C - Hamsters and Tigers 	GNU C++ 	Accepted 	30 ms 	1296 KB 
