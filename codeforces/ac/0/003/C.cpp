#include <cstdio>
#include <cstring>

using namespace std;

char buf[5][5];

int main() {
	int oo = 0, xx = 0, mask = 0;

	for (int i = 0; i < 3; ++i) {
		scanf("%s", buf[i]);
		for (int j = 0; j < 3; ++j) {
			if (buf[i][j] == '0') {
				++oo;
			} else if (buf[i][j] == 'X') {
				++xx;
			}
		}
	}
	for (int i = 0; i < 3; ++i) {
		if (buf[i][0] != '.' && buf[i][0] == buf[i][1] && buf[i][0] == buf[i][2]) {
			mask |= (buf[i][0] == 'X' ? 1 : 2);
		}
		if (buf[0][i] != '.' && buf[0][i] == buf[1][i] && buf[0][i] == buf[2][i]) {
			mask |= (buf[0][i] == 'X' ? 1 : 2);
		}
	}
	if (buf[0][0] != '.' && buf[0][0] == buf[1][1] && buf[0][0] == buf[2][2]) {
		mask |= (buf[0][0] == 'X' ? 1 : 2);
	}
	if (buf[0][2] != '.' && buf[0][2] == buf[1][1] && buf[0][2] == buf[2][0]) {
		mask |= (buf[0][2] == 'X' ? 1 : 2);
	}
	if (xx == 5 && oo == 4 && mask == 0) {	// WA54, WA120
		puts("draw");
	} else if (xx == oo && mask == 0) {
		puts("first");
	} else if (xx == oo + 1 && mask == 0) {
		puts("second");
	} else if (xx == oo + 1 && mask == 1) {
		puts("the first player won");
	} else if (xx == oo && mask == 2) {
		puts("the second player won");
	} else {
		puts("illegal");
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//255710 	Jan 20, 2011 8:27:48 PM 	watashi 	3C - Tic-tac-toe 	GNU C++ 	Accepted 	30 ms 	1300 KB 

