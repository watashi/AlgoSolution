#include <list>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 128;

int main() {
#ifndef __WATASHI__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, m, t0;
	static int a[MAXN][2], b[MAXN][2], c[MAXN], d[MAXN][MAXN];
	char buf[MAXN];
	string word[MAXN];
	list<int> deck;
	vector<int> ans[MAXN];

	scanf("%d%d", &n, &t0);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 2; ++j) {
			scanf("%d%d", &a[i][j], &b[i][j]);
		}
	}
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		scanf("%s%d", buf, &c[i]);
		word[i] = buf;
		deck.push_back(i);
	}

	while (!deck.empty()) {
		for (int j = 0; j < 2 && !deck.empty(); ++j) {
			for (int i = 0; i < n && !deck.empty(); ++i) {
				int t = t0;
				while (t > 0 && !deck.empty()) {
					int k = deck.front();
					int x = max(1, c[k] - (a[i][j] + b[i][1 - j]) - d[i][k]);
					deck.pop_front();
					if (x <= t) {
						ans[i].push_back(k);
					} else {
						d[i][k] += t;
						deck.push_back(k);
					}
					t -= x;
				}
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		printf("%d", ans[i].size());
		for (int j: ans[i]) {
			printf(" %s", word[j].c_str());
		}
		puts("");
	}

	return 0;
}
