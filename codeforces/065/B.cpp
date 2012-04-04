#include <cstdio>
#include <vector>
#include <string>

using namespace std;

const int LAST = 2011;
string year[10000];

int diff(const string& lhs, const string& rhs) {
	int ret = 0;
	for (int i = 0; i < 4; ++i) {
		if (lhs[i] != rhs[i]) {
			++ret;
		}
	}
	return ret;
}

int main() {
	int n;
	int y;
	char buf[80];
	vector<int> ans;

	ans.push_back(1000);
	for (int i = 1000; i < 10000; ++i) {
		sprintf(buf, "%d", i);
		year[i] = buf;
	}
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &y);
		for (int j = ans.back(); j <= LAST; ++j) {
			if (diff(year[j], year[y]) <= 1) {
				ans.push_back(j);
				break;
			}
		}
		if (ans.size() != i + 2) {
			break;
		}
	}
	if (ans.size() != n + 1) {
		puts("No solution");
	} else {
		for (int i = 1; i <= n; ++i) {
			printf("%d\n", ans[i]);
		}
	}

	return 0;
}

