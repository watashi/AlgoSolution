#include <list>
#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 100100;
const int MAXM = 300300;

bool mark[MAXN], used[MAXM];
vector<int> e[MAXN];
pair<int, int> edge[MAXM];

void dfs(int v, int p) {
	mark[v] = true;
	while (!e[v].empty()) {
		int i = e[v].back();
		e[v].pop_back();
		if (used[i]) {
			continue;
		} else {
			used[i] = true;
		}
		int w = edge[i].first + edge[i].second - v;
		if (v != edge[i].first) {
			swap(edge[i].first, edge[i].second);
		}
		dfs(w, v);
	}
}

int main() {
	int n, m, a, b;

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &a, &b);
		--a;
		--b;
		e[a].push_back(i);
		e[b].push_back(i);
		edge[i] = {min(a, b), max(a, b)};
	}

	for (int k = 0; k < 2; ++k) {
		fill(mark, mark + n, false);
		fill(used, used + m, false);
		dfs(0, -1);
		if (count(mark, mark + n, false) > 0) {
			puts("0");
			break;
		}
		for (int i = 0; i < m; ++i) {
			if (k == 0) {
				swap(edge[i].first, edge[i].second);
				e[edge[i].first].push_back(i);
			} else {
				printf("%d %d\n", edge[i].first + 1, edge[i].second + 1);
			}
		}
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//750263 	Oct 8, 2011 12:06:47 PM 	watashi 	118E - Bertown roads 	GNU C++0x 	Accepted 	630 ms 	18400 KB 
