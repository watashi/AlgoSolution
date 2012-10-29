#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

string x, y;

bool gao(int i, int a, int b) {
//	printf("%d %d %d\n", i, a, b);
	if (a == 0 && b == 0) {
		return true;
	}
	if (a > 0) {
		y += '4';
		if (x[i] < '4') {
			y.insert(y.length(), a - 1, '4');
			y.insert(y.length(), b, '7');
			return true;
		} else if (x[i] == '4' && gao(i + 1, a - 1, b)) {
			return true;
		} else {
			y.erase(y.length() - 1);
		}
	}
	if (b > 0) {		
		y += '7';
		if (x[i] < '7') {
			y.insert(y.length(), a, '4');
			y.insert(y.length(), b - 1, '7');
			return true;
		} else if (x[i] == '7' && gao(i + 1, a, b - 1)) {
			return true;
		} else {
			y.erase(y.length() - 1);
		}
	}
	return false;
}

int main() {
	cin >> x;
	if (x.length() % 2 != 0) {
		x = "0" + x;
	}
	while (true) {
		y = "";
		if (gao(0, x.length() / 2, x.length() / 2)) {
			break;
		}
		x = "00" + x;
	}
	cout << y << endl;
	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//604573 	Aug 13, 2011 6:15:01 AM 	watashi 	96B - Lucky Numbers (easy) 	GNU C++0x 	Accepted 	30 ms 	1400 KB 


