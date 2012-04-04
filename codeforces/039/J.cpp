#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	string a, b;
	int l, r;

	cin >> a >> b;
	if (a.length() != b.length() + 1) {
		l = 0;
		r = -1;
	} else {
		r = 0;
		while (r < (int)b.length() && a[r] == b[r]) {
			++r;
		}
		l = (int)b.length() - 1;
		while (l >= 0 && a[l + 1] == b[l]) {
			--l;
		}
		cout << max(0, r - l) << endl;
		for (int i = 0; i <= (int)b.length(); ++i) {
			if (l < i && i <= r) {
				cout << i + 1 << ' ';
			}
		}
		cout << endl;
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//402305 	Apr 19, 2011 11:24:06 PM 	watashi 	39J - Spelling Check 	GNU C++ 	Accepted 	610 ms 	4000 KB 
