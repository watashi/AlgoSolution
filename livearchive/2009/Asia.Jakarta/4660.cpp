#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	int re, x, y;
	char base, sa[80], sb[80];

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%s%s", sa, sb);
		x = strtol(sa, NULL, *max_element(sa, sa + strlen(sa)) - '0' + 1);
		y = strtol(sb, NULL, *max_element(sb, sb + strlen(sb)) - '0' + 1);
		printf("%d\n", x + y);
	}

	return 0;
}
//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//715037  	2011-01-04 08:03:12 	Accepted	0.000	Minimum	26909	C++	4660 - A+B
/*
id => 1174226
pid => 4660
pname => A+B
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:41:30
*/
