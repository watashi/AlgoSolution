#include <cstdio>
#include <algorithm>

using namespace std;

const long long MOD = 1000000000000LL;
const long long HLF_MOD = 1000000LL;
long long a;

long long mul(long long a, long long b) {
	long long ah = a / HLF_MOD, al = a % HLF_MOD, bh = b / HLF_MOD, bl = b % HLF_MOD;
	return ((ah * bl + al * bh) * HLF_MOD + al * bl) % MOD;
}

long long pow(long long a, long long b) {
	long long c = 1;
	while (b > 0) {
		if (b & 1) {
			c = mul(a, c);
		}
		a = mul(a, a);
		b >>= 1;
	}
	return c;
}

void gao(long long b, long long c) {
	long long d = c * 10;
	if (pow(a, b % d) % c != b % c) {
		return;
	} else if (c < MOD) {
		for (int i = 0; i < 10; ++i) {
			gao(b, d);
			b += c;
		}
	} else if (b >= MOD / 10) {
		throw b;
	}
}

int main() {
	int ri = 0;

	while (scanf("%lld", &a) != EOF && a > 0) {
		try {
			for (int i = 0; i < 100; ++i) {
				gao(i, 10);
			}
		} catch (long long b) {
			printf("Case %d: Public Key = %lld Private Key = %lld\n", ++ri, a, b);
		}
	}

	return 0;
}

// a^b == a^(b%phi(m)) (mod m)
// for n >= 1: 10^(n+1) % phi(10^n) == 0
// a^b == a^(b%(10^(n+1))) (mod 10^n) for n >= 1
// so => a^(b%(10^(n+1))) == b (mod 10^n)
// search digit by digit

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//714590  	2011-01-02 15:32:27 	Accepted	0.395	412	26909	C++	4998 - Simple Encryption

/*
id => 1174107
pid => 4998
pname => Simple Encryption
status => Accepted
lang => C++
time => 0.062
date => 2012-12-14 17:23:04
*/
