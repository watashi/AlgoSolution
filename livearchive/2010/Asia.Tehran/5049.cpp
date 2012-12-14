#include <cstdio>
#include <algorithm>

using namespace std;

const char* led[] = {
	"-.-||||",
	"....|.|",
	"---.||.",
	"---.|.|",
	".-.||.|",
	"---|..|",
	"---|.||",
	"-...|.|",
	"---||||",
	"---||.|",
	".......",	// all off
};

bool match(const char str[], const char pat[]) {
	for (int i = 0; i < 7; ++i) {
		if (str[i] != '*' && str[i] != pat[i]) {
			return false;
		}
	}
	return true;
}

const int x[] = {0, 1, 2, 0, 0, 1, 1, 2, 2, 0, 1, 2, 0, 0, 1, 1, 2, 2, 0, 1, 2};
const int y[] = {0, 0, 0, 3, 4, 3, 4, 3, 4, 1, 1, 1, 5, 6, 5, 6, 5, 6, 2, 2, 2};
const int MOD = 1000;

int main() {
	int t, tt;
	bool digit[3][12], mark[MOD];
	char str[3][80];

	do {
		fill(mark, mark + MOD, true);
		while (scanf("%d", &t) == 1) {
			for (int i = 0; i < 21; ++i) {
				scanf(" %c", &str[x[i]][y[i]]);
			}
			for (int i = 0; i < 3; ++i) {
				for (int j = 0; j <= 10; ++j) {
					digit[i][j] = match(str[i], led[j]);
				}
			}
			for (int i = 0; i < MOD; ++i) {
				tt = (t + i) % MOD;
				mark[i] &=
					digit[0][tt < 100 ? 10 : tt / 100] &&
					digit[1][tt < 10 ? 10 : tt / 10 % 10] &&
					digit[2][tt % 10];
			}
		}
		t = count(mark, mark + MOD, true);
		if (t != 1) {
			printf("? %d\n", t);
		} else {
			printf("%d\n", find(mark, mark + MOD, true) - mark);
		}
	} while (scanf(" %c", &str[0][0]) != EOF && str[0][0] == '#');

	return 0;
}
//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//716166  	2011-01-06 17:44:08 	Presentation Error	0.004	Minimum	26909	C++	5049 - Seven Segment Counter

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//722971  	2011-01-20 15:39:26 	Accepted	0.004	Minimum	26909	C++	5049 - Seven Segment Counter
/*
id => 1174146
pid => 5049
pname => Seven Segment Counter
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:30:06
*/
