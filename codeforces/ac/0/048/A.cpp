#include <cstdio>

inline bool win(char a, char b) {
	switch (a) {
		case 'r': return b == 's';
		case 's': return b == 'p';
		case 'p': return b == 'r';
	}
	return false;
}

int main() {
	int t;
	char c[3];
	const char* s[3] = {"F", "M", "S"};

	for (int i = 0; i < 3; ++i) {
		scanf(" %c%*s", &c[i]);
	}
	for (int i = 0; i < 3; ++i) {
		t = 0;
		for (int j = 0; j < 3; ++j) {
			if (win(c[i], c[j])) {
				++t;
			}
		}
		if (t == 2) {
			puts(s[i]);
			return 0;
		}
	}
	puts("?");

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//218377 	Dec 12, 2010 3:44:59 PM 	watashi 	A - Rock-paper-scissors 	GNU C++ 	Accepted 	30 ms 	1292 KB 
