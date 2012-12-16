#include <stdio.h>

int
main(int argc, char *argv[])
{
	int n, s, d;

	scanf("%d%d", &n, &s);
	while (n--) {
		scanf("%d", &d);
		printf("%d%c", s / d - 1, n == 0 ? '\n' : ' ');
		s = d;
	}

	return 0;
}
/*
id => 4678074
date => 03:47:1216 Dec 2012
user => watashi
pname => Array
lang => C
status => Accepted
testid => 
time => 0.015
mem => 112 KB
pid => 1228
*/
