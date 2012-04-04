#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> gray[11];
vector<int> sub[1 << 10];
vector<int> cur;
vector<vector<int> > ans;

void dump(const vector<int>& v) {
	for (int j = 0; j < (int)v.size(); ++j) {
		if (j > 0) {
			putchar(',');
		}
		putchar('{');
		for (int k = v[j]; k != 0; k ^= 1 << __builtin_ctz(k)) {
			if (k != v[j]) {
				putchar(',');
			}
			printf("%d", __builtin_ctz(k) + 1);
		}
		putchar('}');
	}
}

bool pr(int a, int b) {
	return __builtin_ctz(a) < __builtin_ctz(b);
}

void gao(int a) {
	if (a == 0) {
		ans.push_back(cur);
	}
	int s = cur.size();
	for (vector<int>::const_iterator b = sub[a].begin(); b != sub[a].end(); ++b) {
		int t = ans.size();

		cur.push_back(*b);
		gao(a ^ *b);
		cur.pop_back();

		if (b != sub[a].begin()) {
			int c = *b ^ *(b - 1);
			vector<int> end = vector<int>(ans[t - 1].begin() + s + 1, ans[t - 1].end());
			if (*b & c) {
				for (vector<int>::iterator it = end.begin(); it != end.end(); ++it) {
					*it &= ~c;
				}
				end.erase(remove(end.begin(), end.end(), 0), end.end());
				sort(end.begin(), end.end(), pr);
			} else if (end.empty()) {
				end.push_back(c);
			} else {
				end[0] |= c;
			}
			cur.push_back(*b);
			end.insert(end.begin(), cur.begin(), cur.end());
			cur.pop_back();
			vector<vector<int> >::iterator mid = find(ans.begin() + t, ans.end(), end);
			if (mid == ans.end()) {
				throw 1;
			}
			rotate(ans.begin() + t, mid, ans.end());
		}
	}
}

int main() {
	for (int i = 1; i <= 10; ++i) {
		for (int j = 1 << (i - 1); j < (1 << i); ++j) {
			gray[i].push_back(j ^ (j / 2));
		}
		rotate(gray[i].begin(), find(gray[i].begin(), gray[i].end(), (1 << i) - 1), gray[i].end());
	}
	for (int i = 1; i < (1 << 10); ++i) {
		vector<int> bit;
		for (int j = 0; j < 10; ++j) {
			if (i & (1 << j)) {
				bit.push_back(j);
			}
		}
		int popcnt = bit.size();
		for (vector<int>::const_iterator j = gray[popcnt].begin(); j != gray[popcnt].end(); ++j) {
			sub[i].push_back(0);
			for (int k = 0; k < (int)bit.size(); ++k) {
				if (*j & (1 << (bit.size() - 1 - k))) {
					sub[i].back() |= 1 << bit[k];
				}
			}
		}
	}

	int n;

	scanf("%d", &n);
	gao((1 << n) - 1);
	printf("%d\n", (int)ans.size());
	for (int i = 0; i < (int)ans.size(); ++i) {
		dump(ans[i]);
		puts("");
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//404508 	Apr 21, 2011 2:39:56 PM 	watashi 	44I - Toys 	GNU C++ 	Accepted 	410 ms 	7500 KB 
