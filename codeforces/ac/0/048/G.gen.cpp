#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {
	int n, m, a, b;
	int p[100], s[100];
	int w[100][100];

	scanf("%d%d", &n, &m);
	srand(m);
	for (int i = 0; i < n; ++i) {
		p[i] = i;
	}
	random_shuffle(p, p + n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			w[i][j] = i == j ? 0 : 1000000000;
		}
	}
	printf("%d\n", n);
	for (int i = 1; i < n; ++i) {
		a = p[i];
		b = p[rand() % i];
		w[a][b] = w[b][a] = 1 + rand() % 40;
		printf("%d %d %d\n", a + 1, b + 1, w[a][b]);
	}
	do {
		a = rand() % n;
		b = rand() % n;
	} while (w[a][b] != 1000000000);
	w[a][b] = w[b][a] = 1 + rand() % 40;
	printf("%d %d %d\n", a + 1, b + 1, w[a][b]);

	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		s[i] = 0;
		for (int j = 0; j < n; ++j) {
			s[i] += w[i][j];
		}
	}
	for (int i = 0; i < n; ++i) {
		printf("%d%c", s[i], i == n - 1 ? '\n' : ' ');
	}

	return 0;
}

