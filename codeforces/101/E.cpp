#include <cstdio>
#include <algorithm>

using namespace std;

const int POOL_SIZE = 1 << 21;
const int MAXN = 20002;

struct Node {
	bool flag;
	short prev;
	Node* next;
} pool[POOL_SIZE], nil, *head, *tail, *how[MAXN];

int x[MAXN], y[MAXN], dp[MAXN];

void init() {
	head = &pool[0];
	tail = &pool[POOL_SIZE - 1];
	for (int i = 1; i < POOL_SIZE; ++i) {
		pool[i - 1].next = &pool[i];
	}
}

inline
Node* newNode(bool flag, Node* next) {
	Node* p = head;
	head = head->next;
	p->flag = flag;
	p->prev = 0;
	p->next = next;
	++next->prev;
	return p;
}

void deleteNode(Node* p) {
	if (p->prev == 0) {
		tail->next = p;
		tail = p;
		p = p->next;
		--p->prev;
		deleteNode(p);
	}
}

inline
int fab(int a, int b, int p) {
	a += b;
	if (a >= p) {
		a -= p;
	}
	return a;
}

void dump(Node *p) {
	if (p->next != &nil) {
		dump(p->next);
		putchar(p->flag ? 'S' : 'C');
	}
}

int main() {
	int n, m, p;
	
	init();
	scanf("%d%d%d", &n, &m, &p);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &x[i]);
		x[i] %= p;
	}
	for (int j = 0; j < m; ++j) {
		scanf("%d", &y[j]);
		y[j] %= p;
	}

	dp[0] = fab(x[0], y[0], p);
//	how[0] = newNode(true, &nil);
	for (int j = 1; j < m; ++j) {
		dp[j] = dp[j - 1] + fab(x[0], y[j], p);
//		how[j] = newNode(true, how[j - 1]);
	}
	for (int i = 1; i < n; ++i) {
		dp[0] += fab(x[i], y[0], p);
//		how[0] = newNode(false, how[0]);
		for (int j = 1; j < m; ++j) {
			if (dp[j] >= dp[j - 1]) {
				dp[j] += fab(x[i], y[j], p);
//				how[j] = newNode(false, how[j]);
			} else {
				dp[j] = dp[j - 1] + fab(x[i], y[j], p);
//				deleteNode(how[j]);
//				how[j] = newNode(true, how[j - 1]);
			}
		}
	}
	printf("%d\n", dp[m - 1]);
//	dump(how[m - 1]);
	puts("");

	return 0;
}

