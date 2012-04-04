#include <map>
#include <string>
#include <iostream>

using namespace std;

const double EPS = 1e-8;

int main() {
	int n, m, ex;
	double k;
	string name;
	map<string, int> mp;

	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		cin >> name >> ex;
		ex = (int)(ex * k + EPS);
		if (ex >= 100) {
			mp[name] = ex;
		}
	}
	for (int i = 0; i < m; ++i) {
		cin >> name;
		if (mp.count(name) == 0) {
			mp[name] = 0;
		}
	}
	cout << mp.size() << endl;
	for (auto p: mp) {
		cout << p.first << " " << p.second << endl;
	}

	return 0;
}

