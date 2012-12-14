#include <cstdio>

char str[256];

int main(void)
{
	int re;
	int tmp, ans;

	scanf("%d", &re);
	gets(str);
	for (int ri = 1; ri <= re; ri++) {
		gets(str);
		tmp = ans = 0;
		for (int i = 0; str[i] != '\0'; ++i) {
			if (str[i] == '[')
				++tmp;
			else
				--tmp;
			if (tmp > ans)
				ans = tmp;
		}
		printf("%d %d\n", ri, 1 << ans);
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//805993 	3915 	Monkey Vines 	Accepted 	C++ 	0.008 	2011-05-23 16:46:56
/*
id => 1174180
pid => 3915
pname => Monkey Vines
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:34:34
*/
