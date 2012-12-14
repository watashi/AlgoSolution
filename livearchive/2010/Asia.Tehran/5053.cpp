#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1024;

bool mark[MAXN];
vector<int> e[MAXN];

void dfs(int v) {
	if (!mark[v]) {
		mark[v] = true;
		for (vector<int>::const_iterator w = e[v].begin(); w != e[v].end(); ++w) {
			dfs(*w);
		}
	}
}

int main() {
	int n, ans;
	char ch;

	while (scanf("%d", &n) != EOF && n > 0) {
		for (int i = 0; i < n; ++i) {
			e[i].clear();
		}
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				scanf(" %c", &ch);
				if (ch == '1') {
					e[i].push_back(j);
				} else {
					e[j].push_back(i);
				}
			}
		}
		ans = 0;
		for (int i = 0; i < n; ++i) {
			fill(mark, mark + n, false);
			dfs(i);
			if (count(mark, mark + n, false) == 0) {
				++ans;
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//716180  	2011-01-06 17:54:20 	Accepted	3.389	4200	26909	C++	5053 - World Cup Nominations

/*
id => 1174140
pid => 5053
pname => World Cup Nominations
status => Accepted
lang => C++
time => 1.469
date => 2012-12-14 17:29:30
*/
