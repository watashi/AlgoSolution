#include <cstdio>

int main() {
	char s[80];
	int a;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%s%d", s, &a);
	puts(((s[0] == 'f') ^ (a == 2)) ? "L" : "R");

	return 0;
}

