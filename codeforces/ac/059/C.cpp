#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

bool mark[26];
vector<pair<int, int> > v;

int main() {
	int n;
	string s;

	cin >> n >> s;
	for (int i = 0, j = (int)s.length() - 1; i <= j; ++i, --j) {
		if (s[i] == '?') {
			if (s[j] == '?') {
				v.push_back(make_pair(i, j));
				continue;
			} else {
				s[i] = s[j];
			}
		} else if (s[j] == '?') {
			s[j] = s[i];
		} else if (s[i] != s[j]) {
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}
		mark[s[i] - 'a'] = true;
	}
	
	for (int i = n - 1; i >= 0; --i) {
		if (mark[i]) {
			continue;
		}
		if (v.empty()) {
			cout << "IMPOSSIBLE" << endl;
			return 0;			
		}
		s[v.back().first] = s[v.back().second] = 'a' + i;
		v.pop_back();
	}
	while (!v.empty()) {
		s[v.back().first] = s[v.back().second] = 'a';
		v.pop_back();
	}

	cout << s << endl;
	
	return 0;
}

