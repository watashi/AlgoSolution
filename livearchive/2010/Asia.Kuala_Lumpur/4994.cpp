#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

string concat(const string& a, const string& b) {
	for (int i = min(a.length(), b.length()); i >= 0; --i) {
		if (a.substr(a.length() - i) == b.substr(0, i)) {
			return a + b.substr(i);
		}
	}
}

int main() {
	int re, n;
	string s[6], tmp, ans;

	cin >> re;
	for (int ri = 1; ri <= re; ++ri) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> s[i];
		}
		sort(s, s + n);

		ans = string(100, '?');
		do {
			tmp = "";
			for (int i = 0; i < n; ++i) {
				tmp = concat(tmp, s[i]);
			}
			if (tmp.length() < ans.length()) {
				ans = tmp;
			}
		} while (next_permutation(s, s + n));
		cout << "Case " << ri << ": " << ans.length() << endl;
	}

	return 0;
}

/*
id => 1174391
pid => 4994
pname => Overlapping Scenes
status => Accepted
lang => C++
time => 0.039
date => 2012-12-14 18:37:33
*/
