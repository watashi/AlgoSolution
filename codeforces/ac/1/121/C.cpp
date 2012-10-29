#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<long long> fact;
vector<long long> lucky;

void gen(int n, long long m) {
	lucky.push_back(m);
	if (n > 0) {
		gen(n - 1, m * 10 + 4);
		gen(n - 1, m * 10 + 7);
	}
}

void init() {
	lucky.clear();
	gen(10, 0);
	sort(lucky.begin(), lucky.end());

	fact.push_back(1);
	for (int i = 1; i < 20; ++i) {
		fact.push_back(i * fact.back());
	//	cout << "f[" << i << "] = " << fact[i] << endl;
	}
}

vector<long long> gao(vector<long long> v, long long m) {
	if (m == 0) {
		return v;
	} else {
		int n = (int)v.size() - 1;
		int k = m / fact[n];
		vector<long long> ret(1, v[k]);
		v.erase(v.begin() + k);
		v = gao(v, m % fact[n]);
		ret.insert(ret.end(), v.begin(), v.end());
		return ret;
	}
}

int main() {
	vector<long long> v, w;
	long long n, m;
	int ans;

	init();
	cin >> n >> m;
	ans = 0;
	if (n < 18) {
		if (m > fact[n]) {
			puts("-1");
			return 0;
		}
	} else {
		ans += upper_bound(lucky.begin(), lucky.end(), n - 18) - lucky.begin() - 1;
	}
	
	for (int i = 0; i < 18 && i < n; ++i) {
		v.push_back(n - i);
		w.push_back(n - i);
	}
	reverse(v.begin(), v.end());
	reverse(w.begin(), w.end());
	v = gao(v, m - 1);
	for (int i = 0; i < 18 && i < n; ++i) {
	//	printf("%lld => %lld\n", w[i], v[i]);
		if (binary_search(lucky.begin(), lucky.end(), v[i]) &&
			binary_search(lucky.begin(), lucky.end(), w[i])) {
			++ans;
		}
	}
	printf("%d\n", ans);

	return 0;
}


