#include <set>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 218;

template<int MAXX, int MAXY>
struct Hungary {
	int nx, ny, mx[MAXX], my[MAXY];
	bool e[MAXX][MAXY];

	bool mark[MAXX];

	void init(int nx, int ny) {
		this->nx = nx;
		this->ny = ny;
		for (int i = 0; i < nx; ++i) {
			fill(e[i], e[i] + ny, true);
		}
	}

	bool augment(int i, int limit = -1) {
		if (i > limit && !mark[i]) {
			mark[i] = true;
			for (int j = 0; j < ny; ++j) {
				if (e[i][j] && (my[j] == -1 || augment(my[j], limit))) {
					mx[i] = j;
					my[j] = i;
					return true;
				}
			}
		}
		return false;
	}

	int gao() {
		int ret = 0;
		fill(mx, mx + nx, -1);
		fill(my, my + ny, -1);
		for (int i = 0; i < nx; ++i) {
			fill(mark, mark + nx, false);
			if (augment(i)) {
				++ret;
			}
		}
		return ret;
	}
};

Hungary<MAXN, MAXN> h;

void gao(int n, int i, int& k) {
	if (i == n) {
		if (--k == 0) {
			throw 1;
		}
	} else {
		for (int j = 0; j < n; ++j) {
			if (h.e[i][j] && h.my[j] >= i) {
				if (h.my[j] == i) {
					gao(n, i + 1, k);
				} else {
					// i <=> y; x <=> j;
					int x = h.my[j], y = h.mx[i];
					h.mx[i] = j;
					h.my[j] = i;
					h.mx[x] = -1;
					h.my[y] = -1;
					fill(h.mark, h.mark + h.nx, false);
					if (h.augment(x, i)) {
						gao(n, i + 1, k);
					} else {
						h.mx[i] = y;
						h.my[y] = i;
						h.mx[x] = j;
						h.my[j] = x;
					}
				}
			}
		}
	}
}

int main() {
	int re, n, m, k, t;

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d%d%d", &n, &m, &k);
		h.init(n, n);
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				scanf("%d", &t);
				h.e[j][t - 1] = false;
			}
		}
		printf("Case #%d:", ri);
		try {
			if (h.gao() == n) {
				gao(n, 0, k);
			}
			puts(" -1");
		} catch (...) {
			for (int i = 0; i < n; ++i) {
				printf(" %d", h.mx[i] + 1);
			}
			puts("");
		}
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//898523 	4748 	Flowers Placement 	Accepted 	C++ 	0.696 	2011-10-05 07:28:45
/*
id => 1174251
pid => 4748
pname => Flowers Placement
status => Accepted
lang => C++
time => 0.462
date => 2012-12-14 17:45:15
*/
