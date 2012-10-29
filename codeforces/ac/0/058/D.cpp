// of similar length ................
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	string sep, ans;
	vector<string> v, w[22];

	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	cin >> sep;
	m = 0;
	for (int i = 0; i < n; ++i) {
		m += v[i].length();
		w[v[i].length()].push_back(v[i]);
	}
	m /= n / 2;
	
	v.clear();
	for (int i = 1; i < m - i; ++i) {
		sort(w[i].begin(), w[i].end());
		sort(w[m - i].begin(), w[m - i].end());
		for (int j = 0; j < (int)w[i].size() && j < (int)w[m - i].size(); ++j) {
			v.push_back(min(w[i][j] + sep + w[m - i][j], w[m - i][j] + sep + w[i][j]));
		}
	}
	if (m % 2 == 0) {
		m /= 2;
		sort(w[m].begin(), w[m].end());
		for (int j = 0; j + 1 < (int)w[m].size(); j += 2) {
			v.push_back(min(w[m][j] + sep + w[m][j + 1], w[m][j + 1] + sep + w[m][j]));
		}
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < (int)v.size(); ++i) {
		cout << v[i].c_str() << endl;
	}

	return 0;
}

