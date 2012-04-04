#include <set>
#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

const int a[3][4] = {
	{0, 1, 2, 3},
	{0, 4, 2, 5},
	{1, 4, 3, 5},
};

string minp(string s) {
	string r = s;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			for (int k = 0; k < 4; ++k) {
				for (int kk = 0; kk < 3; ++kk) {
					swap(s[a[2][kk]], s[a[2][kk + 1]]);
				}
				r = min(r, s);
			}
			for (int jj = 0; jj < 3; ++jj) {
				swap(s[a[1][jj]], s[a[1][jj + 1]]);
			}
		}
		for (int ii = 0; ii < 3; ++ii) {
			swap(s[a[0][ii]], s[a[0][ii + 1]]);
		}
	}
	return r;
}

int main() {
	string str;
	set<string> st;

	cin >> str;
	sort(str.begin(), str.end());
	do {
		st.insert(minp(str));
	} while (next_permutation(str.begin(), str.end()));
	cout << st.size() << endl;

	return 0;
}

