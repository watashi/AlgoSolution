#include <map>
#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 100100;
const long long MOD1 = 1000000007;
const long long MOD2 = 1000000009;

long long pow11[MAXN], pow13[MAXN];

void init() {
	pow11[0] = pow13[0] = 1;
	for (int i = 1; i < MAXN; ++i) {
		pow11[i] = pow11[i - 1] * 11 % MOD1;
		pow13[i] = pow13[i - 1] * 13 % MOD2;
	}
}

int main() {
	int n, m, p, q;
	static char s[MAXN];
	pair<long long, long long> hash;
	map<pair<long long, long long>, int> mp;

	init();
	scanf("%d%d%s", &n, &m, s);
	hash = {0, 0};
	for (int i = 0; i < n; ++i) {
		hash.first = (hash.first * 11 + s[i] - '0') % MOD1;
		hash.second = (hash.second * 13 + s[i] - '0') % MOD2;
	}
	mp[hash] = 0;

	p = q = 1;
	while (p < n && m > 0) {
		//	printf("%d %d\n", p, m);
		if (s[p - 1] == '4' && s[p] == '7') {
			--m;
			if (p % 2 != 0) {
				hash.first = ((hash.first - 3 * pow11[n - 1 - p]) % MOD1 + MOD1) % MOD1;
				hash.second = ((hash.second - 3 * pow13[n - 1 - p]) % MOD2 + MOD2) % MOD2;
				s[p] = '4';
			} else {
				hash.first = (hash.first + 3 * pow11[n - p]) % MOD1;
				hash.second = (hash.second + 3 * pow13[n - p]) % MOD2;
				s[p - 1] = '7';
				if (p > 1 && s[p - 2] == '4') {
					--p;
				}
			}
			if (q != -1) {
				if (mp.find(hash) == mp.end()) {
					mp[hash] = q++;
				} else {
				//	printf("[%d %d]\n", mp[hash], q);
					m %= q - mp[hash];
					q = -1;
				}
			}
		} else {
			++p;
		}
		//	puts(s);
	}
	puts(s);

	return 0;
}

