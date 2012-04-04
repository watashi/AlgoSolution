// Fermat's 4n+1 Theorem
// Fermat's theorem on sums of two squares

#include <cstdio>

const int MAXN = 300000003;

int main() {
	int l, r;
	static int s[MAXN];

	for (int i = 2; i < MAXN; ++i) {
		if (s[i] == 0) {
			if (i % 4 != 3) {
				s[i] = 1;
			}
			if (i < 20000) {
				for (int j = i * i; j < MAXN; j += i) {
					s[j] = 1;
				}
			}
		} else {
			s[i] = 0;
		}
		s[i] += s[i - 1];
	}
	scanf("%d%d", &l, &r);
	printf("%d\n", s[r] - s[l - 1]);

	return 0;
}

