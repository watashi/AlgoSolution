#include <string>
#include <iostream>

using namespace std;

int main() {
	int a, b, c, n, m;
	string s;

	cin >> c >> a >> b >> s;
	n = s.length();
	m = 0;
	if (a * c <= n && n <= b * c) {
		for (int i = 0; i < c; ++i) {
			cout << s.substr(m, (n - m) / (c - i)) << endl;
			m += (n - m) / (c - i);
		}
	} else {
		cout << "No solution" << endl;
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//404506 	Apr 21, 2011 2:38:05 PM 	watashi 	44E - Anfisa the Monkey 	GNU C++ 	Accepted 	30 ms 	1400 KB 
