#include <cstdio>
#include <algorithm>

using namespace std;

struct Node {
    long long l, r, m;
    Node *pl, *pr;

    double a, b;

    Node(long long l, long long r):
        l(l), r(r), m((l + r) / 2),
        pl(NULL), pr(NULL),
        a(1.0), b(0.0) {
    }

    ~Node() {
        delete pl;
        delete pr;
    }

    Node* lsub() {
        if (pl == NULL) {
            pl = new Node(l, m);
        }
        return pl;
    }

    Node* rsub() {
        if (pr == NULL) {
            pr = new Node(m, r);
        }
        return pr;
    }

    void upd(long long k, double a, double b) {
        if (r - l == 1) {
            this->a = a;
            this->b = b;
        } else {
            if (k < m) {
                lsub()->upd(k, a, b);
            } else {
                rsub()->upd(k, a, b);
            }
            this->a = lsub()->a * rsub()->a;
            this->b = lsub()->b * rsub()->a + rsub()->b;
        }
    }
};

int main() {
    int m;
    long long n, k;
    double a, b, x, y;
    Node* st = new Node(0, 1LL << 40);

    scanf("%lld%d", &n, &m);
    x = y = 1.0;
    for (int i = 0; i < m; ++i) {
        scanf("%lld%lf%lf", &k, &a, &b);
        st->upd(k, a, b);
        x = min(x, st->a + st->b);
        y = max(y, st->a + st->b);
    }
    printf("%.10lf\n%.10lf\n", x, y);
    delete st;

    return 0;
}

