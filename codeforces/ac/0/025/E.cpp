#include <iostream>
#include <algorithm>

using namespace std;

string comb(const string& lhs, const string& rhs) {
	static int fail[1 << 20];
	fail[(int)lhs.length() - 1] = lhs.length();
	for (int i = (int)lhs.length() - 2; i >= 0; --i) {
		fail[i] = fail[i + 1];
		while (fail[i] < (int)lhs.length() && lhs[i] != lhs[fail[i] - 1]) {
			fail[i] = fail[fail[i]];
		}
		if (lhs[i] == lhs[fail[i] - 1]) {
			--fail[i];
		}
	}

	int pos = (int)lhs.length() - 1;
	for (int i = (int)rhs.length() - 1; i >= 0; --i) {
		if (lhs[pos] == rhs[i]) {
			if (--pos == -1) {
				return rhs;
			}
		} else if (pos + 1 < (int)lhs.length()) {
			pos = fail[pos + 1] - 1;
			++i;
		}
	}

	return lhs.substr(0, pos + 1) + rhs;
}

int main() {
	int ans;
	string v[3];

	cin >> v[0] >> v[1] >> v[2];
	sort(v, v + 3);
	ans = 1 << 20;
	do {
		ans = min(ans, (int)comb(comb(v[0], v[1]), v[2]).length());
	} while (next_permutation(v, v + 3))	;
	cout << ans << endl;

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//219525 	Dec 15, 2010 7:15:48 PM 	watashi 	E - Test 	GNU C++ 	Accepted 	110 ms 	6648 KB 
