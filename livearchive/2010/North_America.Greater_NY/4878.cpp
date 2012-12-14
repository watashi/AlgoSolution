#include <cstdio>
#include <string>

using namespace std;

int main() {
	int re, rid, n;
	char buf[128];
	string str;
	bool cont;
	int status, slave, bytes;
	bool scl, sda, pscl, psda;

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d%d", &rid, &n);
		str = "";
		for (int i = 0; i < n; i += 40) {
			scanf("%s", buf);
			str += buf;
		}

		status = 0;
		slave = 0;
		bytes = 0;
		cont = true;
		pscl = false;
		for (int i = 0; cont && i < n; ++i) {
			scl = str[i + i] == '1';
			sda = str[i + i + 1] == '1';
			if (10 <= status && status <= 17 && pscl && scl && !psda && sda) {
				status = -1;
				cont = false;
			} else if (scl) {
				if (status == 0) {			// START
					if (sda == 0) {
						++status;
					}
				} else if (status <= 8) {	// SLAVE
					slave <<= 1;
					if (sda) {
						slave ^= 1;
					}
					++status;
				} else if (status == 9) {	// ACK
					if (sda) {
						cont = false;
					} else {
						++status;
					}
				} else if (status <= 17) {	// TRANSFER
					++bytes;
					++status;
				} else if (status == 18) {	// ACK
					if (sda) {
						cont = false;
					} else {
						status = 10;
					}
				}
			}
			pscl = scl;
			psda = sda;
		}

		printf("%d ", rid);
		if (status == 0) {
			puts("ERROR NO START BIT");
		} else if (status == 9) {
			printf("ERROR NO ACK FROM SLAVE %02X\n", slave >> 1);
		} else if (status == 18) {
			puts("ERROR NO ACK FOR DATA");
		} else if (status != -1) {
			puts("ERROR NO STOP BIT");
		} else {
			printf("%s OF %d BYTES %s SLAVE %02X\n",
				slave % 2 == 0 ? "WRITE" : "READ",
				bytes / 8,
				slave % 2 == 0 ? "TO" : "FROM",
				slave >> 1);
		}
	}

	return 0;
}

// 完全看不懂@,@
//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//881282 	4878 	I2C 	Accepted 	C++ 	0.008 	2011-09-13 18:11:40
/*
id => 1174160
pid => 4878
pname => I2C
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:31:35
*/
