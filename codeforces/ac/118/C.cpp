#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, k, m, s;
	string pat, tmp;
	pair<int, string> ans = make_pair(1000000007, "");

	cin >> n >> k;
	cin >> pat;
	for (int d = 0; d < 10; ++d) {
		s = 0;
		tmp = pat;
		m = count(tmp.begin(), tmp.end(), '0' + d);
		for (int x = 1; x < 10; ++x) {
			if (d + x < 10) {
				char y = '0' + (d + x);
				for (int i = 0; m < k && i < n; ++i) {
					if (tmp[i] == y) {
						tmp[i] = '0' + d;
						s += x;
						++m;
					}
				}
			}			
			if (0 <= d - x) {
				char y = '0' + (d - x);
				for (int i = n - 1; m < k && i >= 0; --i) {
					if (tmp[i] == y) {
						tmp[i] = '0' + d;
						s += x;
						++m;
					}
				}
			}
		}
		ans = min(ans, make_pair(s, tmp));
	}
	cout << ans.first << endl << ans.second << endl;

	return 0;
}

