#include <cmath> // auto fix CE
#include <algorithm> // auto fix CE
#include <cmath> // auto fix CE
#include <set>
#include <cmath> // auto fix CE
#include <algorithm> // auto fix CE
#include <cmath> // auto fix CE
#include <map>
#include <cmath> // auto fix CE
#include <algorithm> // auto fix CE
#include <cmath> // auto fix CE
#include <queue>
#include <cmath> // auto fix CE
#include <algorithm> // auto fix CE
#include <cmath> // auto fix CE
#include <stack>
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
#include <vector>
#include <cmath> // auto fix CE
#include <algorithm> // auto fix CE
#include <cmath> // auto fix CE
#include <string>
#include <cmath> // auto fix CE
#include <algorithm> // auto fix CE
#include <cmath> // auto fix CE
#include <cstdlib>
#include <cmath> // auto fix CE
#include <algorithm> // auto fix CE
#include <cmath> // auto fix CE
#include <numeric>
#include <cmath> // auto fix CE
#include <algorithm> // auto fix CE
#include <cmath> // auto fix CE
#include <utility>
#include <cmath> // auto fix CE
#include <algorithm> // auto fix CE
#include <cmath> // auto fix CE
#include <cassert>

using namespace std;

#ifdef __WATASHI__
# define ferr(...) do {\
    fprintf(stderr, __VA_ARGS__);\
} while (false)
#else
# define ferr(...)
#endif

// result = left_operand operator right_operand

vector<string> _types;
vector<vector<int> > e;
map<string, int> types;

inline void clear() {
    _types.clear();
    e.clear();
    types.clear();
}

inline int getId(const string& s) {
    if (types.count(s) == 0) {
        types[s] = _types.size();
        _types.push_back(s);
        e.push_back(vector<int>());
    }
    return types[s];
}

typedef unsigned long long ULL;
const ULL ULL_MAX = 0xffffffffffffffffULL;

inline ULL add(ULL lhs, ULL rhs) {
    if (rhs > ULL_MAX - lhs) {
        throw "OVERFLOW";
    } else {
        return lhs + rhs;
    }
}

inline ULL mul(ULL lhs, ULL rhs) {
    if (lhs != 0 && rhs > ULL_MAX / lhs) {
        throw "OVERFLOW";
    } else {
        return lhs * rhs;
    }
}

vector<ULL> val;

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

    static set<string> st;

    struct Node {
        const string s;
        const Node* lhs;
        const Node* rhs;
        mutable vector<long long> c;    // avoid `Segmentation fault`

        Node(const string& s) : s(s), lhs(NULL), rhs(NULL) {
            if (!isdigit(s[0])) {
                st.insert(s);
            }
        }

        Node(const string& s, const Node* lhs, const Node* rhs) : s(s), lhs(lhs), rhs(rhs) {
        }

        ~Node() {
            delete lhs;
            delete rhs;
        }

        ULL eval() const {
            if (lhs == NULL) {
                return isdigit(s[0]) ? atoi(s.c_str()) : val[getId(s)];
            } else if (s[0] == '+') {
                return add(lhs->eval(), rhs->eval());
            } else if (s[0] == '*') {
                return mul(lhs->eval(), rhs->eval());
            } else {
                throw "beiju!";
            }
        }
    };

    Parser() {
        precedence["+"] = 6;
        associativity["+"] = LeftToRight;
        precedence["*"] = 5;
        associativity["*"] = LeftToRight;
        precedence["EOL"] = LOWEST;
        associativity["EOL"] = None;
    }
    /*
       void addOperator(const string& op, int p, Associativity a) {
       precedence[op] = p;
       associativity[op] = a;
       }
       */
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
            //          ferr(q);
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

            //          ferr(q);
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

set<string> Parser::st;

int main() {
    int n, m, x;
    Parser parser;
    const char* pbuf;
    vector<int> d;
    vector<int> var;
    vector<string> s;
    vector<const Parser::Node*> p;
    static char buf[4096], op[80];

    while (scanf("%d", &n) != EOF) {
        clear();
        d.resize(n);
        var.resize(n);
        s.resize(n);
        p.resize(n);

        priority_queue<pair<ULL, int>, vector<pair<ULL, int> >, greater<pair<ULL, int> > > pq;

        for (int i = 0; i < n; ++i) {
            scanf("%s = %[^\n]", op, buf);
            s[i] = (string)op + " = " + (string)buf;
            Parser::st.clear();
            p[i] = parser.parse(pbuf = buf);
            var[i] = getId(op);
            d[i] = Parser::st.size();
            for (set<string>::const_iterator j = Parser::st.begin(); j != Parser::st.end(); ++j) {
                x = getId(*j);
                e[x].push_back(i);
            }
            if (d[i] == 0) {
                pq.push(make_pair(p[i]->eval(), i));
            }
        }
        m = types.size();
        val.resize(m);
        fill(val.begin(), val.end(), 0ULL);

        vector<string> ans;

        while (!pq.empty()) {
            pair<ULL, int> pui = pq.top();
            pq.pop();
            ferr("gao [%s] => %llu (%llu)\n", s[pui.second].c_str(), pui.first, val[var[pui.second]]);
            if (val[var[pui.second]] != 0) {
                continue;
            }
            val[var[pui.second]] = pui.first;
            ans.push_back(s[pui.second]);
            pui.second = var[pui.second];
            for (vector<int>::const_iterator i = e[pui.second].begin(); i != e[pui.second].end(); ++i) {
                if (--d[*i] == 0) {
                    ULL tmp;
                    try {
                        tmp = p[*i]->eval();
                        ferr("try [%s] => %llu\n", s[*i].c_str(), tmp);
                        pq.push(make_pair(tmp, *i));
                    } catch (...) {
                    }
                }
            }
            ferr("pq.size() = %d\n", pq.size());
        }

        try {
            if ((int)ans.size() != m) {
                throw "555";
            }
            ULL sum = 0;
            for (int i = 0; i < m; ++i) {
                sum = add(sum, val[i]);
            }
            printf("%llu\n", sum);
            for (int i = 0; i < m; ++i) {
                puts(ans[i].c_str());
            }
        } catch (...) {
            puts("stupid expressions!");
        }

        for (int i = 0; i < n; ++i) {
            delete p[i];
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//1005  2010-07-24 21:39:09     Accepted    1119    C++     750     6344    anotherpeg  Source

// 2012-09-07 16:03:31 | Accepted | 3510 | C++ | 490 | 6332 | watashi | Source
