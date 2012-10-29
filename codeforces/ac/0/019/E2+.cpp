#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 10086;

vector<pair<int, int> > e[MAXN];
int codd, e2a, tag[MAXN], color[MAXN], e2p[MAXN], odd[MAXN], even[MAXN];
// odd[i] is the number of odd-cycle that contains edge e2p[i];

void gao(int v, int p, int c) {
	tag[v] = 1;
	color[v] = c;
	for (vector<pair<int, int> >::const_iterator i = e[v].begin(); i != e[v].end(); ++i) {
		int w = i->first;
		if (w == p) {
		} else if (tag[w] == 0) {
			e2p[w] = i->second;
			gao(w, v, -c);
			odd[v] += odd[w];
			even[v] += even[w];
		} else if (tag[w] == 1) {
			if (color[w] == color[v]) {
				++odd[v];
				++codd;
				e2a = i->second;
			} else {
				++even[v];
			}
		} else {
			if (color[w] == color[v]) {
				--odd[v];
			} else {
				--even[v];
			}
		}
	}
	tag[v] = 2;
}

int main() {
	int n, m, a, b;
	vector<int> ans;

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d", &a, &b);
		e[a].push_back(make_pair(b, i));
		e[b].push_back(make_pair(a, i));
	}
	for (int i = 1; i <= n; ++i) {
		if (tag[i] == 0) {
			gao(i, -1, 1);
		}
	}

	if (codd == 0) {
		for (int i = 1; i <= m; ++i) {
			ans.push_back(i);
		}
	} else {	
		if (codd == 1) {
			ans.push_back(e2a);
		}
		for (int i = 1; i <= n; ++i) {
			if (odd[i] == codd && even[i] == 0) {
				ans.push_back(e2p[i]);
			}
		}
		sort(ans.begin(), ans.end());
	}

	printf("%d\n", (int)ans.size());
	for (int i = 0; i < (int)ans.size(); ++i) {
		printf("%d ", ans[i]);
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//445771 	May 12, 2011 6:26:39 PM 	watashi 	19E - Fairy 	GNU C++ 	Accepted 	50 ms 	2700 KB 
