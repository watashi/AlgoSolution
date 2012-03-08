#include <set>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

const int LIMIT = 48;
const long long MOD = 1000000007;
const long long MOD2 = 1000000007 * 2;

const int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
const int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

int main() {
	int m, x, y;
	long long n, z[LIMIT + 1];
	set<pair<int, int> > from, to, del;

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> x >> y;
		del.insert(make_pair(x, y));
	}

	from.insert(make_pair(0, 0));
	for (int i = 0; i < LIMIT && i <= n; ++i) {
		z[i] = from.size();
		to = from;
		for (set<pair<int, int> >::const_iterator it = from.begin(); it != from.end(); ++it) {
			for (int i = 0; i < 8; ++i) {
				if (del.count(make_pair(it->first + dx[i], it->second + dy[i])) == 0) {
					to.insert(make_pair(it->first + dx[i], it->second + dy[i]));
				}
			}
		}
		from.swap(to);
	}
	
	if (n < LIMIT) {
		cout << z[n] << endl;
	} else {
		long long d1 = z[LIMIT - 1] - z[LIMIT - 2];
		long long d2 = z[LIMIT - 2] - z[LIMIT - 3];
		long long a = d1 - d2;
		long long b = d1 - (LIMIT - 1) * a;
		long long c = z[LIMIT - 1] - a * (LIMIT - 1) * LIMIT / 2 - b * (LIMIT - 1);
		long long ans = 0;
		ans += a * (n % MOD2) % MOD2 * ((n + 1) % MOD2) % MOD2;
		ans += 2 * b * (n % MOD2) % MOD2;
		ans += 2 * c;
		ans /= 2;
		cout << (ans % MOD + MOD) % MOD << endl;
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//421831 	May 2, 2011 10:36:52 AM 	watashi 	57E - Chess 	GNU C++ 	Accepted 	640 ms 	3300 KB 
