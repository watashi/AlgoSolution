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
	if (x >= 0 && y >= 0 && x < r && y < c && buf[x][y] == -1)
		return;
	x -= dir[d][0];
	y -= dir[d][1];
	++d;
	if (d == 4)
		d = 0;
	x += dir[d][0];
	y += dir[d][1];
}

char str[128];

int main(void)
{
	int re;

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		//scanf("%d%d%*c%[A-Z ]", &r, &c, str); Ã»ÓÐ%[A-Z ]¾Í²»»á¸Ä±ästr
		scanf("%d%d%[^\n]", &r, &c, str);
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				buf[i][j] = -1;
		x = 0;
		y = -1;
		d = 0;
		for (int i = 1; str[i] != '\0'; ++i) { // str[0] = ' '
			if (str[i] == ' ') {
				str[i] = 0;
			}
			else {
				str[i] = str[i] - 'A' + 1;
			}
			for (int j = 5 - 1; j >= 0; --j) {
				next();
				buf[x][y] = ((str[i] & (1 << j)) != 0);
			}
		}

		printf("%d ", ri);
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				putchar('0' + (buf[i][j] == 1));
		putchar('\n');
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//805987 	3912 	Encoding 	Accepted 	C++ 	0.008 	2011-05-23 16:40:30
/*
id => 1174182
pid => 3912
pname => Encoding
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:34:55
*/
