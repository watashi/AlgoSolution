#include <iostream>

using namespace std;

int gao(int n) {
	if (n <= 10) {
		return 0;
	} else if (n <= 19) {
		return 4;
	} else if (n <= 20) {
		return 15;
	} else if (n <= 21) {
		return 4;
	} else {
		return 0;
	}
}

int main() {
	int n;

	cin >> n;
	cout << gao(n) << endl;

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//602668 	Aug 11, 2011 4:48:42 PM 	watashi 	104A - Blackjack 	GNU C++0x 	Accepted 	30 ms 	1400 KB 
