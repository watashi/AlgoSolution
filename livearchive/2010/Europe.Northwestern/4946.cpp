#include <vector>
#include <string>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int re, d, sum, ans;
	string str;
	vector<int> v;

	cin >> re;
	for (int ri = 1; ri <= re; ++ri) {
		cin >> str;
		v.clear();
		for (int i = 0; i < (int)str.length(); ++i) {
			d = str[i] - 'A';
			v.push_back(min(d, 26 - d));
		}
		sum = accumulate(v.begin(), v.end(), 0);
		ans = sum + str.length();
		for (int i = 0, j = 0; i < (int)str.length(); ++i) {
			j = max(i + 1, j);
			while (j < (int)str.length() && v[j] == 0) {
				++j;
			}
			ans = min(ans, min(i, (int)str.length() - j) + (int)str.length() + i - j + sum);
		}
		cout << ans << endl;
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//881082 	4946 	High Score 	Accepted 	C++ 	0.012 	2011-09-13 09:34:57
/*
id => 1174274
pid => 4946
pname => High Score
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:47:26
*/
