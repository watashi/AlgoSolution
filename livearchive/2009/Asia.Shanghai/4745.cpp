#include <cctype>
#include <cstdio>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <algorithm>

using namespace std;

template<long long MOD>
long long pow(long long a, long long b) {
	long long c = 1;
	while (b > 0) {
		if (b & 1) {
			c = c * a % MOD;
		}
		a = a * a % MOD;
		b >>= 1;
	}
	return c;
}

template<long long MOD>
long long powsum(long long a, long long b) {
	if (b == 0) {
		return 0;
	} else if (b % 2 == 0) {
		return powsum<MOD>(a, b / 2) * (1 + pow<MOD>(a, b / 2)) % MOD;
	} else {
		return (powsum<MOD>(a, b - 1) * a + 1) % MOD;
	}
}

template<long long BASE, long long MOD>
struct Hash {
	long long hash;

	Hash(long long h = 0) {
		hash = h;
	}

	void feed(char ch) {
		hash = (hash * BASE + ch - 'a') % MOD;
	}

	void shift(long long width) {
		hash = hash * pow<MOD>(BASE, width) % MOD;
	}
	
	void push(long long width, long long h) {
		shift(width);
		hash = (hash + h) % MOD;
	}

	void repeat(long long count, long long width) {
		hash = hash * powsum<MOD>(pow<MOD>(BASE, width), count) % MOD;
	}
};

typedef Hash<29, 1000000007> Hash1;
typedef Hash<31, 1000000009> Hash2;

struct Node {
	long long repeat, length;
	pair<long long, long long> unit_hash, full_hash;
	string data;
	vector<Node*> child;

	Node(long long r, Node* c) {
		repeat = r;
		length = c->repeat * c->length;
		data = "*";
		child.push_back(c);
		Hash1 h1(c->full_hash.first);
		Hash2 h2(c->full_hash.second);
		unit_hash = make_pair(h1.hash, h2.hash);
		h1.repeat(repeat, length);
		h2.repeat(repeat, length);
		full_hash = make_pair(h1.hash, h2.hash);
	}

	Node(const string& s) {
		repeat = 1;
		length = s.length();
		data = s;
		Hash1 h1;
		Hash2 h2;
		for (int i = 0; i < (int)s.length(); ++i) {
			h1.feed(s[i]);
			h2.feed(s[i]);
		}
		unit_hash = full_hash = make_pair(h1.hash, h2.hash);
	}

	Node(vector<Node*> c) {
		repeat = 1;
		length = 0;
		data = "#";
		child = c;
		Hash1 h1;
		Hash2 h2;
		for (int i = 0; i < (int)c.size(); ++i) {
			length += c[i]->repeat * c[i]->length;
			h1.push(c[i]->repeat * c[i]->length, c[i]->full_hash.first);
			h2.push(c[i]->repeat * c[i]->length, c[i]->full_hash.second);
		}
		unit_hash = full_hash = make_pair(h1.hash, h2.hash);
	}

	~Node() {
		for (int i = 0; i < (int)child.size(); ++i) {
			delete child[i];
		}
	}
};

int skip(const string& s, int i, int f(int)) {
	while (i < (int)s.length() && f(s[i])) {
		++i;
	}
	return i;
}

int skippair(const string& s, int i, char open, int close) {
	int c = 0;
	do {
		if (s[i] == open) {
			++c;
		} else if (s[i] == close) {
			--c;
		}
		++i;
	} while (i < (int)s.length() && c > 0);
	return i;
}

Node* parse(const string& s) {
//	puts(s.c_str());
	vector<string> v;
	for (int i = 0, j; i < (int)s.length(); i = j) {
		if (isalpha(s[i])) {
			j = skip(s, i, isalpha);
		} else {
			j = skip(s, skippair(s, i, '[', ']'), isdigit);
		}
		v.push_back(s.substr(i, j - i));
	}
	if (v.size() == 1) {
		if (isalpha(s[0])) {
			return new Node(s);
		} else {
			int k = skippair(s, 0, '[', ']');
			Node* p = parse(s.substr(1, k - 2));
			return new Node(strtoll(s.c_str() + k, NULL, 10), p);
		}
	} else {
		vector<Node*> c;
		for (int i = 0; i < (int)v.size(); ++i) {
			c.push_back(parse(v[i]));
		}
		return new Node(c);
	}
}

pair<long long, long long> hashCode(Node* p, long long n) {
	Hash1 h1;
	Hash2 h2;
	if (p->data == "*") {
		h1.hash = p->unit_hash.first;
		h2.hash = p->unit_hash.second;
		h1.repeat(n / p->length, p->length);
		h2.repeat(n / p->length, p->length);
		pair<long long, long long> h = hashCode(p->child[0], n % p->length);
		h1.push(n % p->length, h.first);
		h2.push(n % p->length, h.second);
	} else if (p->data == "#") {
		for (int i = 0; i < (int)p->child.size(); ++i) {
			if (n <= p->child[i]->repeat * p->child[i]->length) {
				pair<long long, long long> h = hashCode(p->child[i], n);
				h1.push(n, h.first);
				h2.push(n, h.second);
				break;
			} else {
				n -= p->child[i]->repeat * p->child[i]->length;
				h1.push(p->child[i]->repeat * p->child[i]->length, p->child[i]->full_hash.first);
				h2.push(p->child[i]->repeat * p->child[i]->length, p->child[i]->full_hash.second);
			}
		}
	} else {
		for (int i = 0; i < n; ++i) {
			h1.feed(p->data[i]);
			h2.feed(p->data[i]);
		}
	}
	return make_pair(h1.hash, h2.hash);
}

int main() {
	int re;
	char buf[80];
	Node *pa, *pb;
	long long l, r, m;

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%s", buf);
		pa = parse(buf);
		scanf("%s", buf);
		pb = parse(buf);
		l = 0;
		r = min(pa->repeat * pa->length, pb->repeat * pb->length) + 1;
		while (l < r) {
			m = (l + r) / 2;
			if (hashCode(pa, m) == hashCode(pb, m)) {
				l = m + 1;
			} else {
				r = m;
			}
		}
		printf("Case #%d: ", ri);
		if (r > pa->repeat * pa->length && r > pb->repeat * pb->length) {
			printf("YES\n");
		} else {
			printf("NO %lld\n", r);
		}
		delete pa;
		delete pb;
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//898518 	4745 	Compressed String 	Accepted 	C++ 	0.020 	2011-10-05 07:27:16
/*
id => 1174248
pid => 4745
pname => Compressed String
status => Accepted
lang => C++
time => 0.016
date => 2012-12-14 17:44:49
*/
