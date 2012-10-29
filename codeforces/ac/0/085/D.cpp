#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct Node {
	Node *l, *r;
	int a;
	const int h;
	int size;
	long long sum[5];
	Node(int a) : l(NULL), r(NULL), a(a), h(rand()), size(0) {
		for (int i = 0; i < 5; ++i) {
			sum[i] = 0LL;
		}
	}

	static int psize(Node* p) { return p == NULL ? 0 : p->size; }
	static long long psum(Node* p, int i) { return p == NULL ? 0 : p->sum[i]; }

	void upd() {
		size = 1 + psize(l) + psize(r);
		for (int i = 0; i < 5; ++i) {
			sum[i] = psum(l, i);
		}
		sum[psize(l) % 5] += a;
		for (int i = 0; i < 5; ++i) {
			sum[(i + psize(l) + 1) % 5] += psum(r, i);
		}
	}

	~Node() {
		delete l;
		delete r;
	}
};

Node* zig(Node* p) {
	Node* t = p->l;
	p->l = t->r;
	t->r = p;
	p->upd();
	t->upd();
	return t;
}

Node* zag(Node* p) {
	Node* t = p->r;
	p->r = t->l;
	t->l = p;
	p->upd();
	t->upd();
	return t;
}

Node* insert(Node* p, int a) {
	if (p == NULL) {
		p = new Node(a);
	} else if (a < p->a) {
		p->l = insert(p->l, a);
		if (p->l->h < p->h) {
			p = zig(p);
		}
	} else {
		p->r = insert(p->r, a);
		if (p->r->h < p->h) {
			p = zag(p);
		}
	}
	p->upd();
	return p;
}

Node* merge(Node* l, Node* r) {
	if (l == NULL) {
		return r;
	} else if (r == NULL) {
		return l;
	} else if (l->h < r->h) {
		l->r = merge(l->r, r);
		l->upd();
		return l;
	} else {
		r->l = merge(l, r->l);
		r->upd();
		return r;
	}
}

Node* remove(Node* p, int a) {
	if (p == NULL) {
		return NULL;
	} else if (a < p->a) {
		p->l = remove(p->l, a);
		p->upd();
	} else if (a > p->a) {
		p->r = remove(p->r, a);
		p->upd();
	} else {
		Node* t = p;
		p = merge(p->l, p->r);
		t->l = t->r = NULL;
		delete t;
	}
	return p;
}

int main() {
	int n, x;
	char op[80];
	Node* p = NULL;

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", op);
		if (op[0] == 'a') {
			scanf("%d", &x);
			p = insert(p, x);
		} else if (op[0] == 'd') {
			scanf("%d", &x);
			p = remove(p, x);
		} else {
			printf("%I64d\n", p == NULL ? 0LL : p->sum[2]);
		}
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//464723 	May 20, 2011 10:46:08 PM 	watashi 	85D - Sum of Medians 	GNU C++ 	Accepted 	310 ms 	8400 KB 
