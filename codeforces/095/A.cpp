#include <cctype>
#include <string>
#include <iostream>

using namespace std;

int main() {
	int n, m, l;
	char ch, zh;
	bool b[128];
	string s[128];

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	cin >> s[n] >> ch;
	if (tolower(ch) == 'a') {
		zh = 'b';
	} else {
		zh = 'a';
	}
	m = s[n].length();
	fill(b, b + m, false);

	for (int i = 0; i < n; ++i) {
		l = s[i].length();
		for (int j = 0; j + l <= m; ++j) {
			bool flag = true;
			for (int k = 0; flag && k < l; ++k) {
				flag &= (tolower(s[i][k]) == tolower(s[n][j + k]));
			}
			if (flag) {
				fill(b + j, b + j + l, true);
			}
		}
	}

	for (int i = 0; i < m; ++i) {
		if (b[i]) {
			if (tolower(s[n][i]) != tolower(ch)) {
				if (islower(s[n][i])) {
					s[n][i] = tolower(ch);
				} else {
					s[n][i] = toupper(ch);
				}
			} else {
				if (islower(s[n][i])) {
					s[n][i] = tolower(zh);
				} else {
					s[n][i] = toupper(zh);
				}
			}
		}
	}
	cout << s[n] << endl;

	return 0;
}


