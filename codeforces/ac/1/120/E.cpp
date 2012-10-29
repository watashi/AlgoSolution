#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
#ifndef __WATASHI__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	int re, n;

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d", &n);
		puts(n % 2 == 0 ? "1" : "0");
	}

	return 0;
}
