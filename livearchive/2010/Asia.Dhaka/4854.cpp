#include <cctype>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

const int ROWS = 8;
const int COLS = 8;
const int off[] = {0, 10};

int main() {
	int re, h[2], v[2], w[26];
	char buf[20][80];
	string s[2];

	scanf("%d", &re);
	for (int i = 0; i < 26; ++i) {
		int c = 65 + i;
		w[i] = 0;
		while (c > 0) {
			w[i] += (c % 2 == 0 ? 1 : 2);
			c /= 2;
		}
	}
	for (int ri = 1; ri <= re; ++ri) {
		for (int i = 0; i < ROWS; ++i) {
			scanf("%s", buf[i]);
		}
		for (int k = 0; k < 2; ++k) {
			for (int i = 0; i < ROWS; ++i) {
				if (buf[i][off[k] + 1] == '_') {
					h[k] = i;
					break;
				}
			}
			s[k] = "";
			v[k] = 0;
			for (int j = 1; j <= 6; ++j) {
				if (isupper(buf[h[k] - 1][off[k] + j])) {
					s[k] += buf[h[k] - 1][off[k] + j];
					v[k] += w[buf[h[k] - 1][off[k] + j] - 'A'];
				}
			}
		}
		if (v[0] > v[1]) {
			v[0] = 6;
			v[1] = 4;
		} else if (v[0] < v[1]) {
			v[0] = 4;
			v[1] = 6;
		} else {
			v[0] = v[1] = 5;
		}

		printf("Case %d:\n", ri);
		if (v[0] == h[0] && v[1] == h[1]) {
			puts("The figure is correct.");
			continue;
		} else {
			for (int i = 0; i < ROWS; ++i) {
				strcpy(buf[i], "........||........");
			}
			for (int k = 0; k < 2; ++k) {
				buf[v[k] - 4][off[k] + 3] = '/';
				buf[v[k] - 4][off[k] + 4] = '\\';
				buf[v[k] - 3][off[k] + 2] = '/';
				buf[v[k] - 3][off[k] + 5] = '\\';
				buf[v[k] - 2][off[k] + 1] = '/';
				buf[v[k] - 2][off[k] + 6] = '\\';
				buf[v[k] - 1][off[k] + 0] = '/';
				buf[v[k] - 1][off[k] + 7] = '\\';
				buf[v[k] - 0][off[k] + 0] = '\\';
				buf[v[k] - 0][off[k] + 7] = '/';
				for (int j = 1; j <= 6; ++j) {
					buf[v[k]][off[k] + j] = '_';
				}
				for (int j = 1; j <= s[k].length(); ++j) {
					buf[v[k] - 1][off[k] + j] = s[k][j - 1];
				}
			}
			for (int i = 0; i < ROWS - 1; ++i) {
				puts(buf[i]);
			}
		}
	}

	return 0;
}
//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//714972  	2011-01-04 04:07:19 	Accepted	0.035	Minimum	26909	C++	4854 - A Digital Satire of Digital Age
/*
id => 1174075
pid => 4854
pname => A Digital Satire of Digital Age
status => Accepted
lang => C++
time => 0.018
date => 2012-12-14 17:18:50
*/
