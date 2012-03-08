#include <set>
#include <cstdio>

using namespace std;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	int n, a, b, g;
	set<int> s;
	set<int>::const_iterator p;

	scanf("%d%d", &a, &b);
	g = gcd(a, b);
	for (int i = 1; i * i <= g; ++i) {
		if (g % i == 0) {
			s.insert(i);
			s.insert(g / i);
		}
	}
	
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &a, &b);
		p = s.upper_bound(b);
		if (p == s.begin() || *--p < a) {
			puts("-1");
		} else {
			printf("%d\n", *p);
		}
	}

	return 0;
}

