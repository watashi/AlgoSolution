// GOOD PROBLEM
// IDEA
// for floating problem (CLI must has made test wrong)

#include <queue>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
const PII INI(0, 1);
const PII INF(1000000000, 1);

PII operator+(const PII& lhs, const PII& rhs) {
	return PII(lhs.first + rhs.first, lhs.second & rhs.second);
}

template<class T>
bool spfa(int n, int s, vector<pair<int, T> > e[], T mind[]) {
	int ss = s;
	queue<int> q;
	vector<int> d(n, 0);
	vector<bool> mark(n, false);

	fill(mind, mind + n, INF);
	mind[s] = INI;
	mark[s] = true;
	q.push(s);
	while (!q.empty()) {
		s = q.front();
		mark[s] = false;
		q.pop();
		for (typename vector<pair<int, T> >::const_iterator i = e[s].begin(); i != e[s].end(); ++i) {
			if (mind[i->first] > mind[s] + i->second) {
				mind[i->first] = mind[s] + i->second;
				d[i->first] = d[s] + 1;
				if (d[i->first] >= n) {
					return false;
				}
				if (!mark[i->first]) {
					mark[i->first] = true;
					q.push(i->first);
				}
			}
		}
	}
	return mind[ss] == INI;
}

const int MAXN = 256;
vector<pair<int, PII> > e[MAXN];
PII ans[MAXN][MAXN];

int main() {
	int ri, re;
	char buf[65536];
	int a, b, c, d, n;

	scanf("%d ", &re);
	for (int ri = 1; ri <= re; ++ri) {
		for (int i = 0; i < MAXN; ++i) {
			e[i].clear();
		}
		n = 0;
		while (gets(buf) != NULL && buf[0] != '#') {
			sscanf(buf, "%d%d%d%d", &a, &b, &c, &d);
			if (d != 0) {
				d = 1;
			}
			e[b].push_back(make_pair(a, make_pair(c, d)));
			n = max(n, a + 1);
			n = max(n, b + 1);
		}
		bool flag = true;
		for (int i = 0; flag && i < n; ++i) {
			flag &= spfa(n, i, e, ans[i]);
		}
		printf("Case %d:\n", ri);
		if (flag) {
			for (int j = 0; j < n; ++j) {
				for (int i = 0; i < n; ++i) {
					if (ans[i][j] == INF) {
						printf("($,<)");
					} else {
						printf("(%d,%s)", ans[i][j].first, ans[i][j].second == 0 ? "<" : "<=");
					}
					putchar(i == n - 1 ? '\n' : ' ');
				}
			}
		} else {
			puts("Canonical DBM does not exist.");
		}
		puts("");
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//723929  	2011-01-22 16:40:15 	Accepted	0.338	1224	26909	C++	3701 - John's Canonical Difference Bound Matrices

// @POJ
//Run ID	User	Problem	Result	Memory	Time	Language	Code Length	Submit Time
//8110716	watashi	3147	Wrong Answer			G++	2302B	2011-01-23 00:41:08

/*
id => 1174131
pid => 3701
pname => John's Canonical Difference Bound Matrices
status => Accepted
lang => C++
time => 0.072
date => 2012-12-14 17:28:14
*/
