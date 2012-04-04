#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 200200;

struct DisjointSet {
	int p[MAXN];
	
	void init(int n) {
		for (int i = 0; i < n; ++i) {
			p[i] = i;
		}
	}

	int getp(int i) {
		return i == p[i] ? i : (p[i] = getp(p[i]));
	}

	void setp(int i, int j) {
		i = getp(i);
		j = getp(j);
		if (i != j) {
			p[i] = j;
		}
	}
} ds;

int a[MAXN], b[MAXN];
vector<int> e[MAXN];
vector<string> ans[MAXN];

int main() {
	int n, m;

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &a[i], &b[i]);
		--a[i];
		--b[i];
		e[a[i]].push_back(i);
		e[b[i]].push_back(i);
	}

	return 0;
}
