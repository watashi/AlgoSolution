#include <map>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100100;
const int INF = 1000000007;

struct DisjointSet {
	int p[MAXN], s[MAXN];

	void init(int n) {
		for (int i = 0; i < n; ++i) {
			p[i] = i;
			s[i] = 1;
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
			s[j] += s[i];
		}
	}
} st;

int dp[100100];

int main() {
	int n, m, a, b;
	vector<int> lucky, lucky1(1, 0);
	map<int, int> mp;
	vector<pair<int, int> > s;

	for (int i = 0; i < 5; ++i) {
		vector<int> lucky2;
		for (int j: lucky1) {
			lucky2.push_back(j * 10 + 4);
			lucky2.push_back(j * 10 + 7);
		}
		lucky1.swap(lucky2);
		lucky.insert(lucky.end(), lucky1.begin(), lucky1.end());
	}
//	for (int i: lucky) {
//		printf("%d\n", i);
//	}

	scanf("%d%d", &n, &m);
	st.init(n);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &a, &b);
		st.setp(a - 1, b - 1);
	}
	for (int i = 0; i < n; ++i) {
		if (i == st.getp(i)) {
			++mp[st.s[i]];
		}
	}

	for (auto p: mp) {
		int x = p.first;
		int y = p.second;
		for (int i = 1; y >= i; y -= i, i *= 2) {
			s.push_back(make_pair(x * i, i));		
		}
		if (y > 0) {
			s.push_back(make_pair(x * y, y));
		}
	}

//	fprintf(stderr, "=%d\n", s.size());
	sort(s.begin(), s.end());
	fill(dp, dp + n + 1, INF);
	dp[0] = 0;
	int tot = 0;
	for (auto p: s) {
//		printf("->%d %d\n", p.first, p.second);
		tot += p.first;
		for (int j = tot; j >= p.first; --j) {
			dp[j] = min(dp[j], dp[j - p.first] + p.second);
		}
	}

	int ans = INF;
	for (int i = 0; i < (int)lucky.size(); ++i) {
		if (lucky[i] <= n) {
			ans = min(ans, dp[lucky[i]]);
		}
	}
	printf("%d\n", ans == INF ? -1 : ans - 1);

	return 0;
}

