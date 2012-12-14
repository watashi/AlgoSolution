#include <cstdio>
#include <cstring>

int main() {
	int n, z, x;
	char buf[1024];

	while (scanf("%s", buf) != EOF) {
		n = strlen(buf);
		z = 0;
		x = 0;
		for (int i = 0; i < n; ++i) {
			if (buf[i] == '0') {
				++z;
				if (buf[(i + 1) % n] == '0') {
					++x;
				}
			}
		}
		if (x * n > z * z) {
			puts("SHOOT");
		} else if (x * n < z * z) {
			puts("ROTATE");
		} else {
			puts("EQUAL");
		}
	}

	return 0;
}
//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//715011  	2011-01-04 06:54:18 	Accepted	0.002	Minimum	26909	C++	4596 - Headshot

/*
id => 1174221
pid => 4596
pname => Headshot
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:40:41
*/
