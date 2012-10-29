#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> e;

int gao(int m) {
	if (m == 0) {
		return m;
	} else {
		int n = __builtin_ctz(m);
		int a = gao(m ^ (1 << n));
		int b = gao(m & ~e[n]) ^ (1 << n);
		return __builtin_popcount(a) > __builtin_popcount(b) ? a : b;
	}
}

int main() {
	int n, m;
	string a, b;
	vector<string> v, w;
	map<string, int> mp;

	cin >> n >> m;
	v.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		mp[v[i]] = i;
		e.push_back(1 << i);
	}
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		e[mp[a]] |= 1 << mp[b];
		e[mp[b]] |= 1 << mp[a];
	}

	m = gao((1 << n) - 1);
	for (int i = 0; i < n; ++i) {
		if ((m & (1 << i)) != 0) {
			w.push_back(v[i]);
		}
	}
	sort(w.begin(), w.end());
	cout << w.size() << endl;
	for (int i = 0; i < (int)w.size(); ++i) {
		cout << w[i] << endl;
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//686277 	Sep 9, 2011 6:23:47 PM 	watashi 	114B - PFAST Inc. 	GNU C++ 	Accepted 	30 ms 	1400 KB 
