// Disjoint Set
// Leftist Tree

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct DisjointSet
{
    int n, *p;
    DisjointSet(int maxsize)
    {
        n = maxsize;
        p = new int[maxsize];
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
    }
    ~DisjointSet()
    {
        delete[] p;
    }
    int root(int i)
    {
        return (p[i] == i) ? i : p[i] = root(p[i]);
    }
    void set_friend(int i, int j)
    {
        p[root(j)] = root(i);
    }
    bool is_friend(int i, int j)
    {
        return root(i) == root(j);
    }
};

// MAX-TOP
struct LeftistTree
{
    struct __leftist_tree_node
    {
        int v, d;
        __leftist_tree_node *l, *r;
        __leftist_tree_node(int v, int d)
        {
            this->v = v;
            this->d = d;
            l = NULL;
            r = NULL;
        }
        ~__leftist_tree_node()
        {
            delete l;
            delete r;
        }
    } *root;
    typedef __leftist_tree_node node_type;

    LeftistTree()
    {
        root = NULL;
    }
    ~LeftistTree()
    {
        delete root;
    }
    static node_type* merge(node_type* l, node_type* r)
    {
        if (l == NULL) {
            return r;
        }
        if (r == NULL) {
            return l;
        }

        if (l->v < r->v) {
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
    void merge(LeftistTree& t)
    {
        root = merge(root, t.root);
        t.root = NULL;
    }
    void push(int v)
    {
        root = merge(root, new node_type(v, 0));
    }
    void pop()
    {
        node_type *l = root->l, *r = root->r;

        root->l = NULL;
        root->r = NULL;
        delete root;
        root = merge(l, r);
    }
    int front()
    {
        return root->v;
    }
};

int main(void)
{
    int n, m, a, b;

    while (scanf("%d", &n) != EOF) {
        DisjointSet ds(n);
        vector<LeftistTree> v(n);

        for (int i = 0; i < n; i++) {
            scanf("%d", &m);
            v[i].push(m);
        }
        scanf("%d", &m);
        while (m--) {
            scanf("%d%d", &a, &b);
            a = ds.root(a - 1);
            b = ds.root(b - 1);
            if (a == b) {
                puts("-1");
                continue;
            }
            v[a].push(v[a].front() / 2);
            v[a].pop();
            v[b].push(v[b].front() / 2);
            v[b].pop();
            v[a].merge(v[b]);
            ds.set_friend(a, b);
            printf("%d\n", v[a].front());
        }
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//3018481 2008-08-02 18:20:05 Accepted 2334 C++ 00:03.04 3968K Re:ReJudge

// 2012-09-07 01:19:17 | Accepted | 2334 | C++ | 930 | 3208 | watashi | Source
