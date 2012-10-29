#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAXN = 100100;
const int INF = 1000000000;

struct Node {
        Node *l, *r;
        int a;
        int size, maxa;
        const int h;
        Node(int a) : l(NULL), r(NULL), a(a), size(0), maxa(-INF), h(rand()) { }
       
        static int psize(Node* p) { return p == NULL ? 0 : p->size; }
       
        static int pmaxa(Node* p) { return p == NULL ? -INF : p->maxa; }

        void update() {
                size = 1 + psize(l) + psize(r);
                maxa = max(a, max(pmaxa(l), pmaxa(r)));
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
        p->update();
        t->update();
        return t;
}

Node* zag(Node* p) {
        Node* t = p->r;
        p->r = t->l;
        t->l = p;
        p->update();
        t->update();
        return t;
}

Node* insert(Node* p, int a, int c) {
        if (p == NULL) {
                p = new Node(a);
        } else if (a > p->a && a > Node::pmaxa(p->r) && c > Node::psize(p->r)) {
                p->l = insert(p->l, a, c - Node::psize(p->r) - 1);
                if (p->l->h < p->h) {
                        p = zig(p);
                }
        } else {
                p->r = insert(p->r, a, c);
                if (p->r->h < p->h) {
                        p = zag(p);
                }
        }
        p->update();
        return p;
}

int id[MAXN];

void dump(Node* p) {
        if (p == NULL) {
                return;
        } else {
                dump(p->l);
                printf("%d ", id[p->a]);
                dump(p->r);
        }
}

int main() {
        int n, a, c;
        Node* p = NULL;

        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
                scanf("%d%d", &a, &c);
                id[a] = i;
                p = insert(p, a, c);
        }
        dump(p);

        return 0;
}
