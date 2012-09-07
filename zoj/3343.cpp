#include <map>
#include <cstdio>
#include <string>
#include <vector>
#include <utility>
#include <cassert>

using namespace std;

char buf[1024];

struct Node {
    virtual ~Node() {
    }
    virtual bool eval() const = 0;
};

struct UniNode : public Node {
};

struct Leaf : public UniNode {
    const int& mask;
    const int i;
    Leaf(const int& mask, int i) : mask(mask), i(i) {
    }
    bool eval() const {
        return ((1 << i) & mask) != 0;
    }
};

struct OpNode : public Node {
    vector<const Node*> p;
    void add(const Node* node) {
        p.push_back(node);
    }
    ~OpNode() {
        for (size_t i = 0; i < p.size(); ++i) {
            delete p[i];
        }
    }
};

struct Or : public OpNode {
    bool eval() const {
        bool ret = false;
        for (size_t i = 0; i < p.size(); ++i) {
            ret |= p[i]->eval();
        }
        return ret;
    }
};

struct And : public OpNode {
    bool eval() const {
        bool ret = true;
        for (size_t i = 0; i < p.size(); ++i) {
            ret &= p[i]->eval();
        }
        return ret;
    }
};

map<string, int> mp;
vector<double> vp;
int mask;

Node* gaoLeaf() {
    int i;
    double p;

    assert(scanf(" <name>%[^<]</name>", buf) == 1);
    assert(scanf(" <probability>%lf</probability>", &p) == 1);
    assert(scanf(" </leaf>") == 0);
    if (mp.count(buf) == 0) {
        i = mp.size();
        mp[buf] = i;
        vp.push_back(p);
    } else {
        i = mp[buf];
    }

    return new Leaf(mask, i);
}

Node* gaoNode() {
    OpNode* ret = NULL;

    assert(scanf(" <value>%[^<]</value>", buf) == 1);
    switch (buf[0]) {
        case 'o': ret = new Or(); break;
        case 'a': ret = new And(); break;
    }
    while (scanf(" <%[^>]>", buf) == 1 && buf[0] != '/') {
        switch (buf[0]) {
            case 'n': ret->add(gaoNode()); break;
            case 'l': ret->add(gaoLeaf()); break;
        }
    }

    return ret;
}

int main() {
    int n;
    double tmp, ans;

//  while (scanf(" %[#]", buf) == 0) {
    while (scanf(" <root>") == 0) {
        mp.clear();
        vp.clear();
//      assert(scanf(" <root>") == 0);
        Node* root = gaoNode();
//      assert(scanf(" </root> %*[#]") == 0);
        assert(scanf(" %*[#]") == 0);
        n = mp.size();
        ans = 0;
        for (::mask = 0; ::mask < (1 << n); ++::mask) {
            if (root->eval()) {
                tmp = 1;
                for (int i = 0; i < n; ++i) {
                    if ((1 << i) & mask) {
                        tmp *= vp[i];
                    } else {
                        tmp *= 1 - vp[i];
                    }
                }
                ans += tmp;
            }
        }
        printf("%.3lf\n", ans);
        delete root;
    }

    return 0;
}

// 2012-09-07 16:49:40 | Accepted | 3343 | C++ | 0 | 180 | watashi | Source
