#include <cmath> // auto fix CE
#include <algorithm> // auto fix CE
#include <cmath> // auto fix CE
#include <vector>
#include <cmath> // auto fix CE
#include <algorithm> // auto fix CE
#include <cmath> // auto fix CE
#include <cctype>
#include <cmath> // auto fix CE
#include <algorithm> // auto fix CE
#include <cmath> // auto fix CE
#include <cstdio>
#include <cmath> // auto fix CE
#include <algorithm> // auto fix CE
#include <cmath> // auto fix CE
#include <cstdlib>
#include <cmath> // auto fix CE
#include <algorithm> // auto fix CE
#include <cmath> // auto fix CE
#include <utility>

using namespace std;

struct Node {
    virtual int eval() const = 0;
    virtual void print() const = 0;
    virtual ~Node() { };
};

struct ParenNode : public Node {
    const Node* child;
    ParenNode(const Node* child) : child(child) { }
    int eval() const {
        return child->eval();
    }
    void print() const {
        putchar('(');
        child->print();
        putchar(')');
    }
    ~ParenNode() {
        delete child;
    }
};

struct OpNode : public Node {
    char op;
    const Node* lhs;
    const Node* rhs;
    OpNode(const Node* lhs, const Node* rhs) : lhs(lhs), rhs(rhs) { }
    int eval() const {
        switch (op) {
            case '+': return lhs->eval() + rhs->eval();
            case '-': return lhs->eval() - rhs->eval();
            case '*': return lhs->eval() * rhs->eval();
        }
    }
    void print() const {
        lhs->print();
        putchar(op);
        rhs->print();
    }
    ~OpNode() {
        delete lhs;
        delete rhs;
    }
};

struct ValNode : public Node {
    const int val;
    ValNode(int val) : val(val) { }
    int eval() const {
        return val;
    }
    void print() const {
        printf("%d", val);
    }
};

void skip(char* &p) {
    while (isspace(*p)) {
        ++p;
    }
}

vector<OpNode*> ops;

Node* parse(char* &p) {
    Node *tmp = NULL, *ret = NULL;
    while (true) {
        skip(p);
        if (*p == '\0' || *p == ')') {
            break;
        } else if (*p == '(') {
            ++p;
            tmp = new ParenNode(parse(p));
            ++p;
        } else {    // isdigit(*p)
            tmp = new ValNode(strtol(p, &p, 10));
        }
        if (ret == NULL) {
            ret = tmp;
        } else {
            OpNode* op = new OpNode(ret, tmp);
            ops.push_back(op);
            ret = op;
        }
    }
    return ret;
}

int val;
Node* expr;

void gao(vector<OpNode*>::const_iterator it) {
    if (it == ops.end()) {
        if (expr->eval() == val) {
            throw 1;
        }
    } else {
        (*it)->op = '+';
        gao(it + 1);
        (*it)->op = '-';
        gao(it + 1);
        (*it)->op = '*';
        gao(it + 1);
    }
}

int main() {
    int ri = 0;
    char *p, buf[80];

    while (scanf("%d = %[^\n]", &val, buf) == 2) {
        ops.clear();
        expr = parse(p = buf);

        printf("Equation #%d:\n", ++ri);
        try {
            gao(ops.begin());
            puts("Impossible");
        } catch (...) {
            printf("%d=", val);
            expr->print();
            puts("");
        }
        puts("");

        delete expr;
    }
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//349   2010-06-29 06:10:43     Accepted    1014    C++     190     180     anotherpeg  Source

// 2012-09-30 23:38:33 | Accepted | 1145 | C++ | 140 | 180 | watashi | Source
