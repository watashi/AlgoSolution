#include <map>
#include <cstdio>
#include <vector>
#include <string>
#include <cassert>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

#define fst first
#define snd second

bool cmp(const pair<PII, int>& lhs, const pair<PII, int>& rhs) {
	return lhs.fst.fst > rhs.fst.fst || (lhs.fst.fst == rhs.fst.fst && lhs.fst.snd < rhs.fst.snd);
}

struct Gao {
	int min, max, sum;
	vector<pair<PII, int> > v;

	bool operator<(const Gao& o) const {
		if (min != o.min) {
			return min < o.min;
		} else if (max != o.max) {
			return max < o.max;
		} else if (sum != o.sum) {
			return sum < o.sum;
		} else {
			return v < o.v;
		}
	}

	void dump() const {
		printf("[%d, %d] %d ", min, max, sum);
		for (vector<pair<PII, int> >::const_iterator it = v.begin(); it != v.end(); ++it) {
			printf("(");
			for (int i = it->fst.fst - 1; i >= 0; --i) {
				printf("%d", (it->fst.snd >> i) & 1);
			}
			printf(", %d) ", it->snd);
		}
		puts("");
	}

	void std() {
		while (true) {
			sort(v.rbegin(), v.rend(), cmp);
			int n = v.size();
			if (n >= 2 && v[n - 1].snd != -1 && v[n - 2].snd != -1) {
				min = std::max(min, v[n - 1].snd);
				min = std::max(min, v[n - 2].snd);
				//	assert((v[n - 1].fst.snd ^ v[n - 2].fst.snd) == 1);
				//	assert(v[n - 1].fst.fst <= v[n - 2].fst.fst);
				--v[n - 2].fst.fst;
				v[n - 2].fst.snd >>= 1;
				v[n - 2].snd += v[n - 1].snd;
				v.pop_back();
			} else {
				break;
			}
		}
		max = sum;
		int cnt = 0;
		for (int i = 0; i < (int)v.size() - 1; ++i) {
			if (v[i].snd != -1) {
				max = std::min(max, v[i].snd);
			} else {
				++cnt;
			}
		}
		if (cnt > 0) {
			max = std::min(max, sum / cnt);
		}
	}
};

PII encode(const string& s) {
	PII ret(s.length(), 0);
	for (int i = 0; i < (int)s.length(); ++i) {
		ret.second <<= 1;
		if (s[i] == '1') {
			ret.second |= 1;
		}
	}
	return ret;
}

map<Gao, long long> dp;

long long gao(const Gao& s) {
	if (dp.count(s) > 0) {
		return dp[s];
	}
	long long& ret = dp[s];
	if (s.v.size() == 1) {
		return ret = (s.sum == 0 ? 1 : 0);
	}
	int n = s.v.size();
	if (s.v[n - 1].snd == -1) {
		for (int i = s.min; i <= s.max; ++i) {
			Gao t = s;
			t.v[n - 1].snd = i;
			t.min = i;
			t.sum -= i;
			t.std();
			ret += gao(t);
		}
	} else {
		for (int i = max(s.min, s.v[n - 1].snd); i <= s.max; ++i) {
			Gao t = s;
			t.v[n - 2].snd = i;
			t.min = i;
			t.sum -= i;
			t.std();
			ret += gao(t);
		}
	}
	//	s.dump();
	//	printf("\t => %lld\n", ret);
	return ret;
}

int main() {
	int ri = 0, n;
	char buf[80];
	Gao init;

	while (scanf("%d", &n) != EOF && n > 0) {
		dp.clear();
		init.min = 1;
		init.sum = 100;
		init.v.clear();
		for (int i = 0; i < n; ++i) {
			scanf("%s", buf);
			init.v.push_back(make_pair(encode(buf), -1));
		}
		init.std();
		printf("Case %d: %lld\n", ++ri, gao(init));
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//803451 	4122 	Huffman Codes 	Accepted 	C++ 	0.264 	2011-05-19 10:40:22
/*
id => 1174043
pid => 4122
pname => Huffman Codes
status => Accepted
lang => C++
time => 0.245
date => 2012-12-14 17:14:28
*/
