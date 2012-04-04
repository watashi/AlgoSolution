#include <map>
#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 100100;
const int INF = 1000000007;

int v[MAXN], c[MAXN], l[MAXN], r[MAXN];
int dp[MAXN], pre[MAXN];
map<pair<int, int>, int> mp;

int main() {
	int n, m;
	vector<int> ans;

	scanf("%d", &n);
	fill(pre, pre + n + 1, 0);
	dp[m = 0] = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d%d%d", &v[i], &c[i], &l[i], &r[i]);
		if (l[i] == 0) {
			dp[i] = v[i];
		} else if (mp.count(make_pair(l[i] + c[i] + r[i], l[i])) != 0) {
			pre[i] = mp[make_pair(l[i] + c[i] + r[i], l[i])];
			dp[i] = dp[pre[i]] + v[i];
		} else {
			dp[i] = -INF;
			continue;
		}
		if (r[i] == 0 && dp[i] > dp[m]) {
			m = i;
		}
		int& k = mp[make_pair(l[i] + c[i] + r[i], l[i] + c[i])];
		if (k == 0 || dp[k] < dp[i]) {
			k = i;
		}
	}

	while (m != 0) {
		ans.push_back(m);
		m = pre[m];
	}
	printf("%d\n", (int)ans.size());
	for (vector<int>::const_reverse_iterator it = ans.rbegin(); it != ans.rend(); ++it) {
		printf("%d ", *it);
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//423156 	May 3, 2011 7:25:21 PM 	watashi 	28D - Do not fear, DravDe is kind 	GNU C++ 	Accepted 	220 ms 	8300 KB 
