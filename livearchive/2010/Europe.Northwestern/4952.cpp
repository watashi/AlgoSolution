#include <map>
#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1 << 16;

struct Rec {
	int in, out, id;
};

int ans[MAXN];

void gao(int n, int b, const vector<Rec>& v) {
//	printf(">> %d %d\n", n, b);
//	for (int i = 0; i < (int)v.size(); ++i) {
//		printf("\t(%d, %d, %d)\n", v[i].in, v[i].out, v[i].id);
//	}
	if (v.empty()) {
		return;
	} else if (n-- == 0) {
		// assert(v.size() == 1);
		ans[v[0].id] = b;
	} else {
	//	map<int, vector<int> > in, out;
		vector<int> tag(v.size());
		vector<Rec> lo, hi;
		int m = (1 << n) - 1;
		vector<vector<int> > in(m + 1), out(m + 1);

		for (int i = 0; i < (int)v.size(); ++i) {
			in[v[i].in & m].push_back(i);
			out[v[i].out & m].push_back(i);
		}
		for (int i = 0; i < (int)v.size(); ++i) {
			if (tag[i] != 0) {
				continue;
			}

			queue<int> q;
			tag[i] = 1;
			q.push(i);
			while (!q.empty()) {
				int k = q.front();
				q.pop();
				if (tag[k] > 0) {
					lo.push_back(v[k]);
					lo.back().in &= ~(1 << n);
					lo.back().out &= ~(1 << n);
				} else {
					hi.push_back(v[k]);
					hi.back().in |= 1 << n;
					hi.back().out |= 1 << n;
				}

			//	const vector<int>& vin = in.find(v[k].in & m)->second;
				const vector<int>& vin = in[v[k].in & m];
				for (vector<int>::const_iterator j = vin.begin(); j != vin.end(); ++j) {
					if (tag[*j] == 0) {
						tag[*j] = -tag[k];
						q.push(*j);
					}
				}
			//	const vector<int>& vout = out.find(v[k].out & m)->second;
				const vector<int>& vout = out[v[k].out & m];
				for (vector<int>::const_iterator j = vout.begin(); j != vout.end(); ++j) {
					if (tag[*j] == 0) {
						tag[*j] = -tag[k];
						q.push(*j);
					}
				}
			}
		}

		gao(n, b, lo);
		gao(n, b ^ (1 << n), hi);
	}
}

int main() {
	int re, n, m;
	Rec rec;
	vector<Rec> v;

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d%d", &n, &m);
		v.clear();
		for (int i = 0; i < m; ++i) {
			scanf("%d%d", &rec.in, &rec.out);
			rec.id = i;
			v.push_back(rec);
		}
		gao(n, 0, v);
		for (int i = 0; i < m; ++i) {
			printf("%d%c", ans[i], i == m - 1 ? '\n' : ' ');
		}
	}

	return 0;
}

//TLE
//
//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//881091 	4952 	Telephone Network 	Accepted 	C++ 	2.708 	2011-09-13 09:44:39
/*
id => 1174278
pid => 4952
pname => Telephone Network
status => Accepted
lang => C++
time => 2.335
date => 2012-12-14 17:47:54
*/
