#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	string s;
	string::size_type p;

	cin >> s;
	p = s.find_last_of('1');
	if (p == 0) {
		n = s.length() - 1;
	} else {
		n = s.length() + 1;
		n += count(s.begin(), s.begin() + p, '0');
	}
	cout << n << endl;

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//508512 	Jun 23, 2011 11:10:32 AM 	watashi 	92B - Binary Number 	GNU C++ 	Accepted 	130 ms 	2900 KB
