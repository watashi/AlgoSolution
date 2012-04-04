#include <cstdio>
#include <cstring>

int main() {
	char trump, a[8], b[8];
	const char rank[] = "6789TJQKA";

	scanf("%c%s%s", &trump, a, b);
	puts((a[1] == b[1] && strchr(rank, a[0]) > strchr(rank, b[0])) || (a[1] == trump && b[1] != trump) ? "YES" : "NO");

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//626874 	Aug 23, 2011 10:58:40 AM 	watashi 	106A - Card Game 	GNU C++ 	Accepted 	30 ms 	1300 KB 
