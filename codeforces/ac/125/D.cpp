// The elements of the progression are different integers!!!

#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAXN = 32768;
const int UNDEF = 0x80000000;

int d, s, a[MAXN];
int dx, dy;
vector<int> x, y;

void print(const vector<int>& v) {
	for (int i: v) {
		printf("%d ", i);
	}
	puts("");
}

void ok() {
	if (y.empty()) {
		y.push_back(x.back());
		x.pop_back();
	}
	print(x);
	print(y);
	exit(0);
}

int main() {
	int n;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	d = a[n - 1] - a[n - 2];
	s = n - 2;
	while (s > 0 && a[s] - a[s - 1] == d) {
		--s;
	}

	for (int t = 0; t < 3; ++t) {
		switch (t) {
		case 0:
			x = {a[0], a[1]};
			y = {};
			break;
		case 1:
			x = {a[0], a[2]};
			y = {a[1]};
			break;
		case 2:
			x = {a[1], a[2]};
			y = {a[0]};
			break;
		}
		dx = x[1] - x[0];
		dy = UNDEF;
		for (int i = t == 0 ? 2 : 3; i <= n; ++i) {
			if (i == n) {
				ok();
			}
			if (i >= s) {
				if (a[i] == x.back() + d && dx == d) {
					x.insert(x.end(), a + i, a + n);
					ok();
				}
				if (y.empty() || (a[i] == y.back() + d && (dy == UNDEF || dy == d))) {
					y.insert(y.end(), a + i, a + n);
					ok();
				}
			}
			if (a[i] == x.back() + dx) {
				x.push_back(a[i]);
			} else if (dy == UNDEF || a[i] == y.back() + dy) {
				y.push_back(a[i]);
				if (y.size() == 2) {
					dy = y[1] - y[0];
				}
			} else {
				break;
			}
		}
	}
	puts("No solution");

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//863375 	Nov 14, 2011 5:41:23 PM 	watashi 	125D - Two progressions 	GNU C++0x 	Accepted 	50 ms 	1800 KB
