#include <cstdio>
#include <cstring>

using namespace std;

const unsigned MASK = 0x04c11db7U;

unsigned R[8 << 20];

void init() {
	R[0] = 1;
	for (int i = 1; i < (8 << 20); ++i) {
		if (R[i - 1] & 1U << 31) {
			R[i] = (R[i - 1] << 1) ^ MASK;
		} else {
			R[i] = (R[i - 1] << 1);
		}
	}
}

unsigned checksum(char str[], int len) {
	unsigned r = 0;
	for (int i = 0; i < len; ++i) {
		for (int j = 7; j >= 0; --j) {
			if (r & 1U << 31) {
				r = (r << 1) ^ MASK;
			} else {
				r <<= 1;
			}
			if (str[i] & 1U << j) {
				r ^= 1;
			}
		}
	}
	return r;
}

char str[1 << 20];

int main() {
	int re, n, m, p;
	unsigned s;
	char ch;
	
	init();
	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d%s", &n, str);
		s = checksum(str, n);
		printf("%u\n", s);
		scanf("%d", &m);
		for (int i = 0; i < m; ++i) {
			scanf("%d %c", &p, &ch);
			ch ^= str[p - 1];
			str[p - 1] ^= ch;
			for (int j = 7; j >= 0; --j) {
				if (ch & 1U << j) {
					s ^= R[(n - p) * 8 + j];
				}
			}
			printf("%u\n", s);
		}
	}

	return 0;
}
//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//714999  	2011-01-04 06:39:25 	Accepted	1.680	34176	26909	C++	4620 - Better and faster!
/*
id => 1174287
pid => 4620
pname => Better and faster!
status => Accepted
lang => C++
time => 0.356
date => 2012-12-14 17:49:43
*/
