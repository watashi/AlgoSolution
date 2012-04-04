#include <map>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int n, m, t, x[1024], y[1024];
	multimap<int, int> r, rr;
	multimap<int, int>::iterator it;

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &x[i], &y[i]);
	}
	x[0] = x[n];
	y[0] = y[n];
	x[n + 1] = x[1];
	y[n + 1] = y[1];
	for (int i = 0; i <= n; ++i) {
		x[i] = abs(x[i + 1] - x[i]) + abs(y[i + 1] - y[i]);
	}
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &t);
		rr.insert(make_pair(t, i));
	}

	for (int s = 1; s <= 2; ++s) {
		bool flag = true;
		r = rr;
		y[s - 1] = -1;
		for (int i = s; i <= n; i += 2) {
			it = r.find(x[i - 1] + x[i]);
			if (it == r.end()) {
				flag = false;
				break;
			}
			y[i] = it->second;
			y[i + 1] = -1;
			r.erase(it);
		}
		if (flag) {
			puts("YES");
			for (int i = 1; i <= n; ++i) {
				printf("%d ", y[i]);
			}
			return 0;
		}
	}
	puts("NO");

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//309462 	Feb 28, 2011 5:15:13 PM 	watashi 	28A - Bender Problem 	GNU C++ 	Accepted 	30 ms 	1400 KB
