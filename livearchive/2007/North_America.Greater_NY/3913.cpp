#include <cstdio>

const int dir[4][2] = {
	{0, 1},
	{1, 0},
	{0, -1},
	{-1, 0}
};

int r, c;
int x, y, d;
char buf[32][32];

void next()
{
	x += dir[d][0];
	y += dir[d][1];
	if (x >= 0 && y >= 0 && x < r && y < c && buf[x][y] != '#')
		return;
	x -= dir[d][0];
	y -= dir[d][1];
	++d;
	if (d == 4)
		d = 0;
	x += dir[d][0];
	y += dir[d][1];
}

char code[512];
char str[128];

int main(void)
{
	int re;
	int l;

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d%d%s", &r, &c, code);
		l = 0;
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				buf[i][j] = code[l++];
		x = 0;
		y = -1;
		d = 0;
		l = r * c / 5;
		for (int i = 0; i < l; i++) {
			str[i] = 0;
			for (int j = 5 - 1; j >= 0; j--) {
				next();
				if (buf[x][y] == '1') {
					str[i] |= (1 << j);
				}
				buf[x][y] = '#';
			}
		}
		while(l > 0 && str[l - 1] == 0) {
			--l;
		}
		printf("%d ", ri);
		for (int i = 0; i < l; i++) {
			if (str[i] == 0) {
				putchar(' ');
			}
			else {
				putchar(str[i] - 1 + 'A');
			}
		}
		putchar('\n');
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//805988 	3913 	Decoding 	Accepted 	C++ 	0.012 	2011-05-23 16:40:54
/*
id => 1174178
pid => 3913
pname => Decoding
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:34:12
*/
