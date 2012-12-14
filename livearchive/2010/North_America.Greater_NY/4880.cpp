#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const string lpat[] = {
	"0001101",
	"0011001",
	"0010011",
	"0111101",
	"0100011",
	"0110001",
	"0101111",
	"0111011",
	"0110111",
	"0001011",
};

const string rpat[] = {
	"1110010",
	"1100110",
	"1101100",
	"1000010",
	"1011100",
	"1001110",
	"1010000",
	"1000100",
	"1001000",
	"1110100",
};

bool cmp(const string& lhs, const string& rhs) {
	if (lhs.length() != rhs.length()) {
		return false;
	}
	for (int i = 0; i < (int)lhs.length(); ++i) {
		if (lhs[i] != '?' && rhs[i] != '?' && lhs[i] != rhs[i]) {
			return false;
		}
	}
	return true;
}

vector<int> gao(const string pat[], const string& str) {
	vector<int> ret;
	for (int i = 0; i < 10; ++i) {
		if (cmp(pat[i], str)) {
			ret.push_back(i);
		}
	}
	return ret;
}

vector<int> d[12];
vector<long long> ans, ret;

void gao(int i, long long x, int y) {
	if (ret.size() > 8) {
		return;
	} else if (i == 11) {
		y = (10 - y % 10) % 10;
		if (find(d[i].begin(), d[i].end(), y) != d[i].end()) {
			ret.push_back(x * 10 + y);
		}
	} else {
		for (vector<int>::const_iterator j = d[i].begin(); j != d[i].end(); ++j) {
			gao(i + 1, x * 10 + *j, y + (i % 2 == 0 ? 3 : 1) * *j);
		}
	}
}

int main() {
	int re, rid;
	bool flag;
	char str[100];

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d", &rid);
		scanf("%s", str);
		scanf("%s", str + 50);
	
		ans.clear();
		for (int k = 0; k < 2; ++k) {
			flag = true;
			flag &= cmp("101", string(str, str + 3));
			flag &= cmp("01010", string(str + 45, str + 50));
			flag &= cmp("101", string(str + 92, str + 95));
			for (int i = 0; i < 6; ++i) {
				d[i] = gao(lpat, string(str + 3 + 7 * i, str + 10 + 7 * i));
				flag &= !d[i].empty();
			}
			for (int i = 0; i < 6; ++i) {
				d[6 + i] = gao(rpat, string(str + 50 + 7 * i, str + 57 + 7 * i));
				flag &= !d[6 + i].empty();
			}
			if (flag) {
				ret.clear();
				gao(0, 0, 0);
				ans.insert(ans.end(), ret.begin(), ret.end());
			}
			reverse(str, str + 95);
		}

		sort(ans.begin(), ans.end());
		ans.erase(unique(ans.begin(), ans.end()), ans.end());
		if (ans.size() > 8) {
			ans.resize(9);
		}
		printf("%d %d\n", rid, (int)ans.size());
		for (int i = 0; i < (int)ans.size() && i < 8; ++i) {
			printf("%012lld\n", ans[i]);
		}
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//881219 	4880 	Scanning UPC Barcodes 	Accepted 	C++ 	0.016 	2011-09-13 13:42:03
/*
id => 1174164
pid => 4880
pname => Scanning UPC Barcodes
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:32:22
*/
