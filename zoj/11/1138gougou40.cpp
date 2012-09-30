#include <cmath> // auto fix CE
#include <algorithm> // auto fix CE
#include <cmath> // auto fix CE
#include <stack>
#include <cmath> // auto fix CE
#include <algorithm> // auto fix CE
#include <cmath> // auto fix CE
#include <string>
#include <cmath> // auto fix CE
#include <algorithm> // auto fix CE
#include <cmath> // auto fix CE
#include <cstdio>
#include <cmath> // auto fix CE
#include <algorithm> // auto fix CE
#include <cmath> // auto fix CE
#include <cstdlib>

using namespace std;

inline string _paren(const string& s) {
    return "(" + s + ")";
}

// abstract
struct Node {
    mutable string e;
    mutable string d;
    virtual bool _safe() const = 0;
    string safeexpr() const {
        return _safe() ? expr() : _paren(expr());
    }
    virtual void _expr() const = 0;
    string expr() const {
        if (e == "") {
            _expr();
        }
        return e;
    }
    virtual void _derivation() const = 0;
    string derivation() const {
        if (d == "") {
            _derivation();
        }
        return d;
    }
    virtual ~Node() { }
};

struct ValNode : public Node {
    ValNode(const string& e) { this->e = e; }
    bool _safe() const { return true; }
    void _expr() const { }
    void _derivation() const { d = e == "x" ? "1" : "0"; }
};

// abstract
struct UnNode : public Node {
    const Node* child;
    bool _safe() const { return true; }
    UnNode(const Node* child) : child(child) { }
    ~UnNode() { delete child; }
};

struct ParenNode : public UnNode {
    ParenNode(const Node* child) : UnNode(child) { }
    void _expr() const { e = _paren(child->expr()); }
    void _derivation() const { d = _paren(child->derivation()); }
};

struct LnNode : public UnNode {
    LnNode(const Node* child) : UnNode(child) { }
    void _expr() const { e = "ln(" + child->expr() + ")"; }
    void _derivation() const { d = "(" + child->derivation() + ")/(" + child->expr() + ")"; }
};

// abstract
struct BinNode : public Node {
    const Node* lhs;
    const Node* rhs;
    BinNode(const Node* lhs, const Node* rhs) : lhs(lhs), rhs(rhs) { }
    ~BinNode() { delete lhs; delete rhs; }
};

struct AddNode : public BinNode {
    AddNode(const Node* lhs, const Node* rhs) : BinNode(lhs, rhs) { }
    bool _safe() const { return false; }
    void _expr() const { e = lhs->expr() + "+" + rhs->expr(); }
    void _derivation() const { d = lhs->derivation() + "+" + rhs->derivation(); }
};

struct SubNode : public BinNode {
    SubNode(const Node* lhs, const Node* rhs) : BinNode(lhs, rhs) { }
    bool _safe() const { return false; }
    void _expr() const { e = lhs->expr() + "-" + rhs->expr(); }
    void _derivation() const { d = lhs->derivation() + "-" + rhs->derivation(); }
};

struct MulNode : public BinNode {
    MulNode(const Node* lhs, const Node* rhs) : BinNode(lhs, rhs) { }
    bool _safe() const { return true; }
    void _expr() const { e = lhs->safeexpr() + "*" + rhs->safeexpr(); }
    void _derivation() const {
        d = '(';
        d += lhs->derivation() + "*" + rhs->safeexpr() + "+";
        d += lhs->safeexpr() + "*" + rhs->derivation() + ")";
    }
};

struct DivNode : public BinNode {
    DivNode(const Node* lhs, const Node* rhs) : BinNode(lhs, rhs) { }
    bool _safe() const { return true; }
    void _expr() const { e = lhs->safeexpr() + "/" + rhs->safeexpr(); }
    void _derivation() const {
        d = "(";
        d += lhs->derivation() + "*" + rhs->safeexpr() + "-";
        d += lhs->safeexpr() + "*" + rhs->derivation() + ")";
        d += "/" + rhs->safeexpr() + "^2";
    }
};

inline bool _pr(char lhs, char rhs) {
    return (lhs == '*' || lhs == '/') || (rhs == '+' || rhs == '-');
}

inline void _op(stack<const Node*>& val, stack<char>& ops) {
    const Node* a = val.top();
    val.pop();
    const Node* b = val.top();
    val.pop();
    char c = ops.top();
    ops.pop();
    switch (c) {
        case '+': val.push(new AddNode(b, a)); break;
        case '-': val.push(new SubNode(b, a)); break;
        case '*': val.push(new MulNode(b, a)); break;
        case '/': val.push(new DivNode(b, a)); break;
        // defalut: throw 1;
    }
}

const Node* parse(char* &p) {
    stack<const Node*> val;
    stack<char> ops;

    while (true) {
        if (*p == '(') {
            ++p;
            val.push(new ParenNode(parse(p)));
        } else if (*p == 'x') {
            ++p;
            val.push(new ValNode("x"));
        } else if (*p == 'l') { // s[0 .. 2] = "ln("
            p += 3;
            val.push(new LnNode(parse(p)));
        } else {    // [+-]?[.0-9]+
            char* q = p;
            strtod(p, &p);
            val.push(new ValNode(string(q, p)));
        }

        if (*p == ')' || *p == '\n' || *p == '\0') {
            ++p;
            while (!ops.empty()) {
                _op(val, ops);
            }
            break;
        } else {
            while (!ops.empty() && _pr(ops.top(), *p)) {
                _op(val, ops);
            }
            ops.push(*p++);
        }
    }

    return val.top();   // val.size() = 1
}

int main() {
    char buf[4096], *ptr;

    while (fgets(buf, sizeof(buf), stdin) != NULL) {
        const Node* expr = parse(ptr = buf);
        string derivation = expr->derivation();
        string ans;

        for (string::const_iterator i = derivation.begin(); i != derivation.end(); ++i) {
            if (*i == '-' && !ans.empty() && (*ans.rbegin() == '+' || *ans.rbegin() == '-')) {
                *ans.rbegin() = '+' + '-' - *ans.rbegin();
            } else {
                ans.push_back(*i);
            }
        }
        puts(ans.c_str());
        delete expr;
    }

    return 0;
}

// expr部分描述没怎么解释，太e了

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//351   2010-07-01 04:14:04     Accepted    1012    C++     0   180     anotherpeg  Source

// 2012-09-30 23:38:21 | Accepted | 1138 | C++ | 0 | 180 | watashi | Source
