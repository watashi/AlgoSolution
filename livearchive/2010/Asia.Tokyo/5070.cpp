#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAXN = 25 * 25 + 1;

typedef bitset<MAXN> row;
bitset<MAXN> r[MAXN];

bool gao(int n) {
	int c = 0;
	for (int i = 0; i < n; ++i) {
		while (c < n) {
			for (int j = i; j < n; ++j) {
				if (r[j].test(c)) {
					swap(r[i], r[j]);
					goto BREAK;
				}
			}
			++c;
		}
BREAK:
		if (c < n) {
			for (int j = i + 1; j < n; ++j) {
				if (r[j].test(c)) {
					r[j] ^= r[i];
				}
			}
			++c;
		} else if (r[i].test(n)) {
			return false;
		}
	}
	return true;
}

int main() {
	int n, m, d, t;

	while (scanf("%d%d%d", &m, &n, &d) != EOF && d > 0) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				r[i * m + j].reset();
				r[i * m + j].set(i * m + j);
				scanf("%d", &t);
				if (t != 0) {
					r[i * m + j].set(n * m);
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				for (int ii = 0; ii < n; ++ii) {
					for (int jj = 0; jj < m; ++jj) {
						if (abs(i - ii) + abs(j - jj) == d) {
							r[i * m + j].set(ii * m + jj);
						}
					}
				}
			}
		}
		puts(gao(n * m) ? "1" : "0");
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//771921  	2011-04-28 11:03:10 	Accepted	0.383	520	26909	C++	5070 - Awkward Lights
/*
id => 1174078
pid => 5070
pname => Awkward Lights
status => Accepted
lang => C++
time => 0.062
date => 2012-12-14 17:19:16
*/
