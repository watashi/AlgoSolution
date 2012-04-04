#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const char *ans[3] = {"Carrots", "Kiwis", "Grapes"};

int main() {
	int r, c, n, m, x, y;
	vector<int> w;

	scanf("%d%d%d%d", &r, &c, &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &x, &y);
		--x;
		--y;
		w.push_back(x * c + y);
	}
	sort(w.begin(), w.end());
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &x, &y);
		--x;
		--y;
		x = x * c + y;
		y = lower_bound(w.begin(), w.end(), x) - w.begin();
		if (y < (int)w.size() && w[y] == x) {
			puts("Waste");
		} else {
			puts(ans[(x - y) % 3]);
		}
	}

	return 0;
}

