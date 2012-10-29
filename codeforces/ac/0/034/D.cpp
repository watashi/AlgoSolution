#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 65536;

int t[MAXN];
vector<int> e[MAXN];

void dfs(int v, int p) {
	t[v] = p;
	for (vector<int>::const_iterator w = e[v].begin(); w != e[v].end(); ++w) {
		if (*w != p) {
			dfs(*w, v);
		}
	}
}

int main() {
	int n, p, q;

	scanf("%d%d%d", &n, &p, &q);
	for (int i = 1; i <= n; ++i) {
		if (i == p) {
			continue;
		}
		int j;
		scanf("%d", &j);
		e[i].push_back(j);
		e[j].push_back(i);
	}
	dfs(q, 0);
	for (int i = 1; i <= n; ++i) {
		if (i == q) {
			continue;
		}
		printf("%d ", t[i]);
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//230174 	Dec 27, 2010 11:23:17 AM 	watashi 	D - Road Map 	GNU C++ 	Accepted 	90 ms 	5092 KB 
