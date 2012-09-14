#include <algorithm> // auto fix CE
#include <map>
#include <algorithm> // auto fix CE
#include <stack>
#include <algorithm> // auto fix CE
#include <cctype>
#include <algorithm> // auto fix CE
#include <cstdio>
#include <algorithm> // auto fix CE
#include <vector>
#include <algorithm> // auto fix CE
#include <string>
#include <algorithm> // auto fix CE
#include <numeric>
#include <algorithm> // auto fix CE
#include <utility>
#include <algorithm> // auto fix CE
#include <cassert>

using namespace std;

// #define WATASHI_PC

#ifdef WATASHI_PC
# define ferr(...) do {\
    fprintf(stderr, __VA_ARGS__);\
} while (false);
#else
# define ferr(...)
#endif

// result = left_operand operator right_operand

typedef int F(int);

inline int isop(int ch) {
    return ispunct(ch) && ch != '(' && ch != ')';
}

template<F f>
void skip(const char* &p) {
    while (f(*p)) {
        ++p;
    }
}

struct Parser {
    enum Associativity {
        LeftToRight,
        RightToLeft,
        None
    };

    static const int HIGHEST = -1;
    static const int LOWEST = 1000000000;
    map<string, int> precedence;
    map<string, Associativity> associativity;

    struct Node {
        const string s;
        const Node* lhs;
        const Node* rhs;
        mutable vector<long long> c;    // avoid `Segmentation fault`

        Node(const string& s) : s(s), lhs(NULL), rhs(NULL) {
        }

        Node(const string& s, const Node* lhs, const Node* rhs) : s(s), lhs(lhs), rhs(rhs) {
        }

        ~Node() {
            delete lhs;
            delete rhs;
        }
    };

    Parser() {
        precedence["\\"] = HIGHEST;
        associativity["\\"] = LeftToRight;
        precedence["EOL"] = LOWEST;
        associativity["EOL"] = None;
    }

    void addOperator(const string& op, int p, Associativity a) {
        precedence[op] = p;
        associativity[op] = a;
    }

    bool _cmpOperator(const string& lhs, const string& rhs) const {
        if (precedence.find(lhs)->second == precedence.find(rhs)->second) {
            assert(associativity.find(lhs)->second == associativity.find(rhs)->second);
            return associativity.find(lhs)->second == LeftToRight;
        } else {
            return precedence.find(lhs)->second < precedence.find(rhs)->second;
        }
    }

    struct SegmentFault {
        bool loop;
        const char* p;
        const Node* ret;
        string op;
        stack<string> ops;
        stack<const Node*> s;
    };

    const Node* parse(const char* &q) const {
        const Node* ret;
        SegmentFault* sf = new SegmentFault();

        sf->loop = true;

        // skip space
        skip<isspace>(q);
        while (sf->loop) {
            ferr(q);
            // get operand
            if (*q == '(') {
                ++q;
                sf->s.push(parse(q));
            } else {
                sf->p = q;
                skip<isalnum>(q);
                sf->s.push(new Node(string(sf->p, q)));
            }
            // skip space
            skip<isspace>(q);

            ferr(q);
            // get operator
            sf->op = "EOL";
            if (*q == '\0') {
                sf->loop = false;
            } else if (*q == ')') {
                sf->loop = false;
                ++q;
            } else if (*q != '\0') {
                sf->p = q;
                skip<isop>(q);
                sf->op = string(sf->p, q);
            }
            // skip space
            skip<isspace>(q);

            while (!sf->ops.empty() && _cmpOperator(sf->ops.top(), sf->op)) {
                const Node* rhs = sf->s.top();
                sf->s.pop();
                const Node* lhs = sf->s.top();
                sf->s.pop();
//              ferr("do (%s) %s (%s)\n", lhs->s.c_str(), ops.top().c_str(), rhs->s.c_str());
                sf->s.push(new Node(sf->ops.top(), lhs, rhs));
                sf->ops.pop();
            }
            sf->ops.push(sf->op);
        }

        assert(sf->s.size() == 1);
        ret = sf->s.top();
        delete sf;
        return ret;
    }
};

static long long MOD;

vector<string> _types;
map<string, int> types;

struct Eq {
    int a, b, c;
};

map<string, vector<Eq> > equations;

void gao(const Parser::Node* p) {
    vector<const Parser::Node*> s;

    s.push_back(p);
    for (int i = 0; i < (int)s.size(); ++i) {
        if (s[i]->lhs != NULL && s[i]->rhs != NULL) {
            s.push_back(s[i]->lhs);
            s.push_back(s[i]->rhs);
        }
    }

    for (vector<const Parser::Node*>::const_reverse_iterator i = s.rbegin(); i != s.rend(); ++i) {
        p = *i;
        vector<long long>(types.size()).swap(p->c);
        if (p->lhs == NULL && p->rhs == NULL) {
            ferr("type %s [%d]\n", p->s.c_str(), types.find(p->s)->second);
            p->c[types.find(p->s)->second] = 1 % MOD;
        } else if (p->s == "\\") {
            for (int i = 0; i < (int)p->c.size(); ++i) {
                p->c[i] = (p->lhs->c[i] + p->rhs->c[i]) % MOD;
            }
        } else {
            const vector<Eq> &eq = equations[p->s];
            for (vector<Eq>::const_iterator i = eq.begin(); i != eq.end(); ++i) {
                ferr("todo %d %d %d\n", i->a, i->b, i->c);
                p->c[i->c] = (p->c[i->c] + p->lhs->c[i->a] * p->rhs->c[i->b]) % MOD;
            }
        }
    }
/*
    ferr("out (%s) %s (%s):", p->lhs == NULL ? "NULL" : p->lhs->s.c_str(),
        p->s.c_str(), p->rhs == NULL ? "NULL" : p->rhs->s.c_str());
    for (int i = 0; i < (int)p->c.size(); ++i) {
        ferr(" %lld", p->c[i]);
    }
    ferr("\n");
*/
}

int main() {
    Eq eq;
    const char* pbuf;
    int ntype, nop, neq, ncase, p;
    static char buf[4 * 1024 * 1024], op[80];

    while (scanf("%d%d%d%d%lld", &ntype, &nop, &neq, &ncase, &MOD) != EOF) {
        Parser parser;

        _types.clear();
        types.clear();
        for (int i = 0; i < ntype; ++i) {
            assert(scanf("%s", buf) == 1);
            ferr("<%s>", buf);
            _types.push_back(buf);
            types[buf] = i;
        }

        equations.clear();
        for (int i = 0; i < nop; ++i) {
            assert(scanf("%s%d%s", buf, &p, op) == 3);
            ferr("{%s}", buf);
            equations[buf];
            parser.addOperator(buf, p, op[0] == 'l' ? Parser::LeftToRight : Parser::RightToLeft);
        }

        for (int i = 0; i < neq; ++i) {
            assert(scanf("%s", buf) == 1);
            ferr("add /%s/\n", buf);
            eq.c = types.find(buf)->second;
            assert(scanf("%*s") == 0);  // "="
            assert(scanf("%s", buf) == 1);
            eq.a = types.find(buf)->second;
            assert(scanf("%s", op) == 1);
            assert(scanf("%s", buf) == 1);
            eq.b = types.find(buf)->second;
            equations.find(op)->second.push_back(eq);
        }

        assert(fgets(buf, sizeof(buf), stdin) != NULL);
        for (int i = 0; i < ncase; ++i) {
            assert(fgets(buf, sizeof(buf), stdin) != NULL);
            ferr("[gao] %s", buf);
            const Parser::Node* root = parser.parse(pbuf = buf);
            gao(root);
            vector<long long> ans = root->c;
            delete root;
            printf("#%d:\n", i + 1);
            for (int j = 0; j < ntype; ++j) {
                printf("%s: %lld\n", _types[j].c_str(), ans[j]);
            }
        }
        puts("");
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//906   2010-07-21 21:54:03     Accepted    1109    C++     3030    29896   anotherpeg  Source

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//225   2010-08-12 15:20:08     Accepted    sakuya  C++     1530    29900   watashi@Zodiac  Source

// 2012-09-07 15:51:04 | Accepted | 3382 | C++ | 1380 | 29896 | watashi | Source
