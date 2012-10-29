#include <cstdio>
#include <algorithm>

using namespace std;

struct Edge {
	int s, f, l, h, a[10];
} e[100];

bool operator<(const Edge& lhs, const Edge& rhs) {
	return lhs.s < rhs.s;
}

int n, m;
int cur[10];
pair<int, int> ans;

void gao(int k, int c) {
//	printf("@%d, %d\n", k, c);
	if (k == m) {
		if (ans.second < c) {
			for (int i = 1; i < n; ++i) {
				if (cur[i] > 0) {
					return;
				}
			}
			ans.second = c;
		}
	} else {
		for (int i = 1; i < e[k].s; ++i) {
			if (cur[i] > 0) {
				return;
			}
		}
		for (int j = e[k].l; j <= e[k].h && j <= cur[e[k].s]; ++j) {
			cur[e[k].s] -= j;
			cur[e[k].f] += j;
			gao(k + 1, c + e[k].a[j]);
			cur[e[k].s] += j;
			cur[e[k].f] -= j;
		}
	}
}

int main() {

	scanf("%d", &n);
	m = 0;
	while (scanf("%d%d%d%d%d", &e[m].s, &e[m].f, &e[m].l, &e[m].h, &e[m].a[0]) != EOF) {
		for (int i = 1; i < 10; ++i) {
			e[m].a[i] = e[m].a[0] + i * i;
		}
		e[m].a[0] = 0;
		++m;
	}
	sort(e, e + m);
	ans.second = -1;
	for (ans.first = 0; ans.first <= 25 && ans.second == -1; ++ans.first) {
		fill(cur, cur + 10, 0);
		cur[1] = ans.first;
		gao(0, 0);
	}
	if (ans.second != -1) {
		printf("%d %d\n", ans.first - 1, ans.second);
	} else {
		puts("-1 -1\n");
	}

	return 0;
}

