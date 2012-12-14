#include <cstdio>
#include <algorithm>

using namespace std;

const int LIMIT = 2012 * 52;

int main() {
	int n, x, y, z;
	char op[80];
	bool firstBlood, mark[LIMIT];

	while (scanf("%d", &n) != EOF && n > 0) {
		mark[0] = false;
		fill(mark + 1, mark + LIMIT, true);
		y = z = 0;
		firstBlood = true;
		for (int i = 0; i < n; ++i) {
			scanf("%s%d", op, &x);
			if (op[0] == 'P') {
				y += x;
			} else if (op[0] != 'C') {
				if (firstBlood) {
					firstBlood = false;
				} else {
					for (int j = 1; j < LIMIT; ++j) {
						if (mark[j] && j + z > 0 && y % (j + z) != 0) {
							mark[j] = false;
						}
					}
				}
				y = 0;
				if (op[0] == 'I') {
					z += x;
				} else if (op[0] == 'O') {
					z -= x;
				}
				if (z < 0) {
					fill(mark, mark + (1 - z), false);
				}
			}
		}
		if (count(mark, mark + LIMIT, true) == 0) {
			puts("IMPOSSIBLE");
		} else if (mark[LIMIT - 1]) {
			printf("SIZE >= %d\n", find(mark, mark + LIMIT, true) - mark);
		} else {
			bool first = true;
			for (int i = 0; i < LIMIT; ++i) {
				if (mark[i]) {
					if (first) {
						first = false;
					} else {
						putchar(' ');
					}
					printf("%d", i);
				}
			}
			puts("");
		}
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//726003  	2011-01-25 18:42:43 	Accepted	0.105	500	26909	C++	3567 - Pilgrimage

/*
id => 1174026
pid => 3567
pname => Pilgrimage
status => Accepted
lang => C++
time => 0.049
date => 2012-12-14 17:12:13
*/
