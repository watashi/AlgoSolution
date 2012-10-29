#include <cstdio>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

const int MAXN = 100;

vector<int> w;
vector<long long> v[MAXN];
long long begin[MAXN], end[MAXN], self[MAXN], sum[MAXN], elem[MAXN];

int main() {
	int n, m, t;
	long long s, ans;

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &t);
		v[i].resize(t);
		for (int j = 0; j < (int)v[i].size(); ++j) {
			scanf("%d", &t);
			v[i][j] = t;
		}
	}
	w.resize(m);
	for (int i = 0; i < m; ++i) {
		scanf("%d", &t);
		w[i] = t - 1;
	}

	for (int i = 0; i < n; ++i) {
		begin[i] = end[i] = self[i] = 0;
		s = 0;
		for (vector<long long>::const_iterator j = v[i].begin(); j != v[i].end(); ++j) {
			s += *j;
			begin[i] = max(begin[i], s);
		}
		s = 0;
		for (vector<long long>::const_reverse_iterator j = v[i].rbegin(); j != v[i].rend(); ++j) {
			s += *j;
			end[i] = max(end[i], s);
		}
		s = 0;
		for (vector<long long>::const_iterator j = v[i].begin(); j != v[i].end(); ++j) {
			s = max(0LL, s + *j);
			self[i] = max(self[i], s);
		}
		sum[i] = accumulate(v[i].begin(), v[i].end(), 0LL);
		elem[i] = *max_element(v[i].begin(), v[i].end());
//		printf("%lld %lld %lld %lld %lld\n", begin[i], end[i], self[i], sum[i], elem[i]);
	}

	s = 0;
	ans = -1000000007;
	for (vector<int>::const_iterator i = w.begin(); i != w.end(); ++i) {
		ans = max(ans, elem[*i]);
		if (self[*i] > 0) {
			ans = max(ans, self[*i]);
		}
		if (begin[*i] > 0) {
			ans = max(ans, s + begin[*i]);
		}
		s = max(s + sum[*i], end[*i]);
	}
//	printf("%lld\n", ans);
	printf("%I64d\n", ans);

	return 0;
}

