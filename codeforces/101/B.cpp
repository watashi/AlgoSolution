#include <map>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 200200;
const int MOD = 1000000007;

long long dp[MAXN], sum[MAXN];

int main() {
	int n, m, s, t;
	map<int, int> mp;
	vector<pair<int, int> > v;

	scanf("%d%d", &n, &m);
	mp[0];
	mp[n];
	for (int i = 0; i < m; ++i) {
		scanf("%d", &s);
		scanf("%d", &t);
		mp[s];
		mp[t];
		v.push_back({s, t});
	}
	n = 0;
	for (auto& p: mp) {
		p.second = n++;
	}
	for (auto& p: v) {
		p.first = mp[p.first];
		p.second = mp[p.second];
	}
	sort(v.begin(), v.end(), [](const pair<int, int>& lhs, const pair<int, int>& rhs){ return lhs.second > rhs.second; });

	dp[0] = 1;
	sum[0] = 0;
	for (int i = 0; i < n; ++i) {
		while (!v.empty() && v.back().second == i) {
			dp[i] += sum[i] - sum[v.back().first];
			v.pop_back();
		}
		sum[i + 1] = (sum[i] + dp[i]) % MOD;
	}
	printf("%d\n", (int)((dp[n - 1] % MOD + MOD) % MOD));

	return 0;
}


