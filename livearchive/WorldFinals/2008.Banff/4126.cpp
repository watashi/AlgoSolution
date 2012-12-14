#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int SIGMA = 26;
const int ELEMENT_MAX = 128;
int tot;
struct node {
	int match;
	node *pre, *child[SIGMA];
} T[ELEMENT_MAX];

void trie_init() {
	tot = 1;
	memset(T, 0, sizeof(T));
}

void insert(char* s, int n, int id) {
	node* t = T;
	for (int i = 0; i < n; ++i) {
		int c = s[i] - 'a';
		if (!t->child[c]) {
			t->child[c] = &T[tot++];
		}
		t = t->child[c];
	}
	t->match |= 1 << id;
}

void build_graph() {
	node* t = T;
	queue<node*> Q;
	for (int i = 0; i < SIGMA; ++i) {
		if (t->child[i]) {
			t->child[i]->pre = t;
			Q.push(t->child[i]);
		} else {
			t->child[i] = t;
		}
	}
	while (!Q.empty()) {
		t = Q.front();
		Q.pop();
		t->match |= t->pre->match;
		for (int i = 0; i < SIGMA; ++i) {
			if (t->child[i]) {
				t->child[i]->pre = t->pre->child[i];
				Q.push(t->child[i]);
			} else {
				t->child[i] = t->pre->child[i];
			}
		}
	}
}

const int MAXN = 27;
const int MAXM = 10;

long long dp[MAXN][ELEMENT_MAX][1 << MAXM];
vector<pair<pair<int, int>, int> > pre[MAXN][ELEMENT_MAX][1 << MAXM];
vector<string> all;
char buf[80];

void dump(int i, int j, int k) {
	if (i == 0) {
		all.push_back(buf);
	} else {
		for (int t = 0; t < (int)pre[i][j][k].size(); ++t) {
			buf[i - 1] = 'a' + pre[i][j][k][t].second;
			dump(i - 1, pre[i][j][k][t].first.first, pre[i][j][k][t].first.second);
		}
	}
}

int main() {
	int ri = 0, n, m;
	long long ans;

	while (scanf("%d%d", &n, &m) != EOF && n > 0) {
		trie_init();
		for (int i = 0; i < m; ++i) {
			scanf("%s", buf);
			insert(buf, strlen(buf), i);
		}
		build_graph();

		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j < tot; ++j) {
				for (int k = 0; k < (1 << m); ++k) {
					dp[i][j][k] = 0LL;
					pre[i][j][k].clear();
				}
			}
		}
		dp[0][0][T[0].match] = 1LL;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < tot; ++j) {
				for (int k = 0; k < (1 << m); ++k) {
					if (dp[i][j][k] == 0) {
						continue;
					}
					for (int t = 0; t < SIGMA; ++t) {
						dp[i + 1][T[j].child[t] - T][k | T[j].child[t]->match] += dp[i][j][k];
						pre[i + 1][T[j].child[t] - T][k | T[j].child[t]->match].push_back(
							make_pair(make_pair(j, k), t));
					}
				}
			}
		}

		ans = 0;
		for (int j = 0; j < tot; ++j) {
			ans += dp[n][j][(1 << m) - 1];
		}
		printf("Case %d: %lld suspects\n", ++ri, ans);
		if (ans <= 42) {
			all.clear();
			buf[n] = '\0';
			for (int j = 0; j < tot; ++j) {
				dump(n, j, (1 << m) - 1);
			}
			sort(all.begin(), all.end());
			for (int i = 0; i < (int)all.size(); ++i) {
				puts(all[i].c_str());
			}
		}
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//803458 	4126 	Password Suspects 	Accepted 	C++ 	2.440 	2011-05-19 10:43:08
/*
id => 1174044
pid => 4126
pname => Password Suspects
status => Accepted
lang => C++
time => 2.865
date => 2012-12-14 17:14:43
*/
