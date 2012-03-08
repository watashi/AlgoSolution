#include <cstdio>
#include <algorithm>

using namespace std;

struct Node {
	const int h, v;
	long long e, s;
	Node *l, *r;
	
	Node(int h, int v) : h(h), v(v), e(0), s(0), l(NULL), r(NULL) {
	}
	
	Node* left() {
		if (l == NULL) {
			l = new Node(h + 1, v * 2);
		}
		return l;
	}
	
	Node* right() {
		if (r == NULL) {
			r = new Node(h + 1, v * 2 + 1);
		}
		return r;
	}

	void upd() {
		s = left()->s + right()->s + e;
	}

	void add(int d, int w, int f) {
		// printf("@<%d, %d>\n", h, v);
		if (v == w) {
			e += f;
		} else if ((w & (1 << (d - h - 1))) == 0) {
			left()->add(d, w, f);
		} else {
			right()->add(d, w, f);
		}
		upd();
	}

	double gao(long long m) {
		double ret;
		if (s <= m) {
			ret = m;
		} else if (left()->s > right()->s) {
			ret = left()->gao(max(m, right()->s + e));
			ret = (ret + max(m, left()->s + e)) / 2;
		} else if (left()->s < right()->s) {
			ret = right()->gao(max(m, left()->s + e));
			ret = (ret + max(m, right()->s + e)) / 2;
		} else {
			ret = max(m, left()->s + e);
		}
		return ret;
	}
};

inline int bitlength(int n) {
	int d = 0;
	while (n > 0) {
		++d;
		n >>= 1;
	}
	return d;
}

int main() {
	int h, q, v, e;
	char op[80];
	Node* r = new Node(1, 1);

	scanf("%d%d", &h, &q);
	for (int i = 0; i < q; ++i) {
		scanf("%s", op);
		if (op[0] == 'a') {
			scanf("%d%d", &v, &e);
			r->add(bitlength(v), v, e);
		} else {
			printf("%.10lf\n", r->gao(0));
		}
	}

	return 0;
}
