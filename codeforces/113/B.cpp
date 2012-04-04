#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> pos(const string& s, const string& p) {
	vector<int> ret;
	for (string::size_type i = s.find(p); i != string::npos; i = s.find(p, i + 1)) {
		ret.push_back(i);
	}
	return ret;
}

int main() {
	string str, prefix, suffix;
	vector<int> begin, end;
	vector<unsigned long long> hash;

	cin >> str >> prefix >> suffix;
	begin = pos(str, prefix);
	end = pos(str, suffix);
	for (int i: begin) {
		int k = i;
		unsigned long long code = 0;
		for (int j: end) {
			if (i <= j && i + (int)prefix.length() <= j + (int)suffix.length()) {
				while (k < j + (int)suffix.length()) {
					code = code * 29 + str[k++];
				}
				hash.push_back(code);
			}
		}
	}
	sort(hash.begin(), hash.end());
	printf("%d\n", unique(hash.begin(), hash.end()) - hash.begin());

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//750660 	Oct 8, 2011 2:31:43 PM 	watashi 	113B - Petr# 	GNU C++0x 	Accepted 	310 ms 	26000 KB 
