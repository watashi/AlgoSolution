#include <iomanip>
#include <iostream>

using namespace std;

int main() {
	long long a, b, c, d;
	
	cin >> a >> b >> c;
	for (int i = 1; i <= a && i < c; ++i) {
		d = i * 1000000000 % c;
		if (0 < d && d + b < c) {
			cout << 1 << " " << setw(9) << setfill('0') << i << endl;
			return 0;
		}
	}
	cout << 2 << endl;
	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//735778 	Oct 3, 2011 4:05:11 PM 	watashi 	117B - Very Interesting Game 	GNU C++0x 	Accepted 	200 ms 	1400 KB
