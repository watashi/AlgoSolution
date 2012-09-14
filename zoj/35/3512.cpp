#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cassert>
#include <algorithm>    // swap
#include <functional>   // less

using namespace std;

// ???????????????
template<typename T = int, typename Pred = less<T> >
struct LeftistTree
{
    struct Node {
        T v;
        int d;
        Node *l, *r;

        Node(T v, int d) : v(v), d(d), l(NULL), r(NULL) {
        }

        ~Node() {
            delete l;
            delete r;
        }
    };

    Node* root;

    static Pred pr;

    static Node* merge(Node* l, Node* r)
    {
        if (l == NULL) {
            return r;
        }
        if (r == NULL) {
            return l;
        }

        if (pr(r->v, l->v)) {
            swap(l, r);
        }
        l->r = merge(l->r, r);
        if (l->r != NULL && (l->l == NULL || l->r->d > l->l->d)) {
            swap(l->l, l->r);
        }
        if (l->r == NULL) {
            l->d = 0;
        }
        else {
            l->d = l->r->d + 1;
        }

        return l;
    }

    LeftistTree() : root(NULL) {
        root = NULL;
    }

    ~LeftistTree() {
        delete root;
    }

    void merge(LeftistTree& t) {
        root = merge(root, t.root);
        t.root = NULL;
    }

    void push(T v) {
        root = merge(root, new Node(v, 0));
    }

    void pop() {
        Node *l = root->l, *r = root->r;

        root->l = NULL;
        root->r = NULL;
        delete root;
        root = merge(l, r);
    }

    T top() const {
        return root->v;
    }
};

const int MAXN = 65536;

struct Segment {
    LeftistTree<int, greater<int> > lt;
    int s, x;

    Segment(int h) : s(1), x(0) {
        lt.push(h);
    }

    void merge(Segment& r) {
        lt.merge(r.lt);
        s += r.s;
        x += r.x;
        while (x + x + 2 < s) {
            lt.pop();
            ++x;
        }
    }

    int height() const {
        return lt.top();
    }
};

int main() {
    int n, k, a[MAXN];
    long long ans;
    vector<Segment*> b;

    while (scanf("%d", &n) != EOF && n > 0) {
        b.clear();
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            Segment* s = new Segment(a[i]);
            while (!b.empty() && b.back()->height() > s->height()) {
                b.back()->merge(*s);
                delete s;
                s = b.back();
                b.pop_back();
            }
            b.push_back(s);
        }

        k = 0;
        ans = 0;
        for (vector<Segment*>::const_iterator i = b.begin(); i != b.end(); ++i) {
            for (int j = 0; j < (*i)->s; ++j) {
                ans += abs((*i)->height() - a[k++]);
            }
            delete *i;
        }
        printf("%lld\n", ans);
    }

    return 0;
}

// 2012-09-07 16:03:49 | Accepted | 3512 | C++ | 370 | 2308 | watashi | Source
