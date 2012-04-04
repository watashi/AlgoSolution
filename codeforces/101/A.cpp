#include <map>
#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	string s;
	int n, m;
	map<char, int> mp;
	vector<bool> tab(128, false);
	vector<pair<int, char> > v;

	cin >> s >> n;
	for (char c: s) {
		++mp[c];
	}
	for (auto p: mp) {
		v.push_back({p.second, p.first});
	}
	sort(v.begin(), v.end());

	m = v.size();
	for (auto p: v) {
		if (p.first > n) {
			break;
		} else {
			n -= p.first;
			--m;
			tab[p.second] = true;
		}
	}
	s.erase(remove_if(s.begin(), s.end(), [&tab](char c){ return tab[c]; }), s.end());
	cout << m << endl << s << endl;

	return 0;
}

