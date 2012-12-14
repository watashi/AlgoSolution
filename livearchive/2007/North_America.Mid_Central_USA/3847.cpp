#include <stdio.h>
char buf;
int main()
{
	while((buf = getchar()) != '#') {
		switch(buf) {
		case ' ': printf("%%20"); break;
		case '!': printf("%%21"); break;
		case '$': printf("%%24"); break;
		case '%': printf("%%25"); break;
		case '(': printf("%%28"); break;
		case ')': printf("%%29"); break;
		case '*': printf("%%2a"); break;
		default: putchar(buf);
		}
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//806011 	3847 	The Seven Percent Solution 	Accepted 	C++ 	0.008 	2011-05-23 17:12:22
/*
id => 1174265
pid => 3847
pname => The Seven Percent Solution
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:46:38
*/
