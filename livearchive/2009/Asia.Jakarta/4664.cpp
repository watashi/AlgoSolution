#include <cstdio>
#include <numeric>
#include <algorithm>

using namespace std;

const int MAXN = 2132456;
const int MAXL = 20;
int a[MAXN], b[MAXN];

int main() {
	int n, m, a0, A, B, M;
	double l, r, mid, sigma, cmp;

	while (scanf("%d", &n) != EOF) {
		scanf("%d%d%d%d", &a0, &A, &B, &M);
		m = n + 1;
		a[0] = b[0] = 0;
		for (int i = 1; i <= m; ++i) {
			a[i] = a0;
			a0 = (A * a0 + B) % M;
			b[i] = a0;
			a0 = (A * a0 + B) % M;
			b[i] += a[i];
		}
		partial_sum(a, a + m + 1, a);
		partial_sum(b, b + m + 1, b);
		sigma = a[m];

		l = 0;
		r = 0.5;
		while (r - l > 1e-7) {
			mid = (l + r) / 2;
			cmp = mid * sigma;
			for (int i = 0; i <= MAXL && i <= m; ++i) {
				for (int j = i; j <= MAXL && j <= m; ++j) {
					if (a[j] - a[i] - mid * (b[j] - b[i]) >= cmp) {
						goto L;
					}
				}
				for (int j = max(i, m - MAXL); j <= m; ++j) {
					if (a[j] - a[i] - mid * (b[j] - b[i]) >= cmp) {
						goto L;
					}
				}
			}

			r = mid;
			continue;
L:
			l = mid;
			continue;
		}
		printf("%.6lf\n", l + r);
	}

	return 0;
}

//MAXL=500
//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//715034  	2011-01-04 07:59:32 	Accepted	7.568	17040	26909	C++	4664 - Spam Detection

//MAXL=20
//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//715035  	2011-01-04 08:00:42 	Accepted	3.670	17056	26909	C++	4664 - Spam Detection

