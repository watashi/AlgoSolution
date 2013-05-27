#include <map>
#include <stack>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int SIGMA = 10 + 26;

#ifdef WATASHI_PC
#  define errf(...) do { fprintf(stderr, "%d:\t", __LINE__); fprintf(stderr, __VA_ARGS__); } while (false)
#else
#  define errf(...) do { } while (false)
#endif

inline int c2i(char c) {
  if (isdigit(c)) {
    return c - '0';
  } else if (islower(c)) {
    return c - 'a' + 10;
  } else {
    return -1;
  }
}

struct Trie {
  Trie* const pp;
  const char ch;
  int tag;
  Trie* p[SIGMA];

  Trie(Trie* pp, int ch) : pp(pp), ch(ch), tag(-1) {
    fill(p, p + SIGMA, (Trie*)NULL);
  }

  ~Trie() {
    for (int i = 0; i < SIGMA; ++i) {
      delete p[i];
    }
  }

  Trie* insert(char* s) {
    Trie* p = this;
    for (int i = c2i(*s); i != -1; i = c2i(*++s)) {
      if (p->p[i] == NULL) {
        p->p[i] = new Trie(p, *s);
      }
      p = p->p[i];
    }
    return p;
  }

  Trie* find(char* s) {
    Trie* p = this;
    for (int i = c2i(*s); p && i != -1; i = c2i(*++s)) {
      p = p->p[i];
    }
    return p;
  }
};

static void skip(char*& s, int f(int)) {
  while (f(*s)) {
    ++s;
  }
}

inline int _div(int b, int a) {
  int sign = (((b > 0) ^ (a > 0)) == 0) ? 1 : -1;
  return abs(b) / abs(a) * sign;
}

inline int _mod(int b, int a) {
  int sign = (((b > 0) ^ (a > 0)) == 0) ? 1 : -1;
  return abs(b) % abs(a) * sign;
}

inline int _pow(int b, int a) {
  int ret = 1;
  while (a > 0) {
    if (a & 1) {
      ret *= b;
    }
    a >>= 1;
    b = b * b;
  }
  return ret;
}

struct PC_Cool {
  int size;
  Trie* trie;
  vector<int> a;
  vector<Trie*> b;

  PC_Cool() {
    size = 0;
    trie = new Trie(NULL, '\0');
  }

  ~PC_Cool() {
    delete trie;
  }

  int _root(int i) {
    return i == a[i] ? i : a[i] = _root(a[i]);
  }

  int _insert(char s[]) {
    Trie* p = trie->insert(s);
    if (p->tag == -1) {
      p->tag = size;
      a.push_back(size);
      b.push_back(p);
      ++size;
    }
    return p->tag;
  }

  void define(char s[]) {
    skip(s, isspace);
    errf(s);
    int op1 = _insert(s);
    skip(s, isalnum);
    skip(s, isspace);
    errf(s);
    int op2 = _insert(s);
    // skip(s, isalnum);
    if (a[op1] == op1) {
      // An attempt to redefine some variable or constant is ignored.
      op2 = _root(op2);
      if (op2 != op1) {
        // An attempt to make a definition that leads to circular dependence is also ignored.
        a[op1] = op2;
        errf("%d->%d\n", op1, op2);
      }
    }
  }

  static void _op(stack<int>& operands, stack<char>& operators) {
    int a = operands.top();
    operands.pop();
    int b = operands.top();
    operands.pop();
    char c = operators.top();
    operators.pop();
    int d = -1;
    switch (c) {
    case '+': d = b + a; break;
    case '-': d = b - a; break;
    case '*': d = b * a; break;
    case '/': d = _div(b, a); break;
    case '%': d = _mod(b, a); break;
    case '^': d = _pow(b, a); break;
    }
    errf("%d %c %d = %d\n", b, c, a, d);
    operands.push(d);
  }

  static bool _pr(char lhs, char rhs) {
    static pair<char, int> lpci[] = {
      make_pair('+', 8),
      make_pair('-', 8),
      make_pair('*', 5),
      make_pair('/', 5),
      make_pair('%', 5),
      make_pair('^', 4),
    };
    static pair<char, int> rpci[] = {
      make_pair('+', 9),
      make_pair('-', 9),
      make_pair('*', 6),
      make_pair('/', 6),
      make_pair('%', 6),
      make_pair('^', 3),
    };
    static map<char, int> lmci(lpci, lpci + sizeof(lpci) / sizeof(lpci[0]));
    static map<char, int> rmci(rpci, rpci + sizeof(rpci) / sizeof(rpci[0]));
    return lmci[lhs] < rmci[rhs];
  }

  int _find(char s[]) {
    static char buf[64];
    Trie* p = trie->find(s);
    if (p == NULL || p->tag == -1) {	// p->tag == -1 // Runtime Error on test 16
      char* t = s;
      skip(t, isalnum);
      copy(s, t, buf);
      buf[t - s] = '\0';
    } else {
      int l = 0;
      /*
       * 居然能在某些环境过测试数据-_-b
       for (Trie* p = b[_root(p->tag)]; p->pp != NULL; p = pp->pp) {
       buf[l++] = p->ch;
       }
       */
      for (Trie* pp = b[_root(p->tag)]; pp->pp != NULL; pp = pp->pp) {
        buf[l++] = pp->ch;
      }
      buf[l] = '\0';
      errf("%d[%s]\n", l, buf);
      reverse(buf, buf + l);
      errf("%d[%s]\n", l, buf);
    }
    errf("%s\n", buf);
    int ret = 0;
    for (int i = 0; buf[i] != '\0'; ++i) {
      if (isdigit(buf[i])) {
        ret *= 10;
        ret += buf[i] - '0';
      } else {
        // If some identifier is used in the expression that is not yet defined to be substituted by some integer constant, its value is set to zero.
        return 0;
      }
    }
    return ret;
  }

  int _eval(char*& s) {
    stack<int> operands;
    stack<char> operators;
    while (true) {
      // get_operand
      skip(s, isspace);
      errf(s);
      if (*s == '(') {
        ++s;
        operands.push(_eval(s));
      } else {
        int sign = 1;
        while (*s == '+' || *s == '-') {
          // Unary minus and plus are allowed, their priority in this case is the highest.
          if (*s == '-') {
            sign = -sign;
          }
          ++s;
          skip(s, isspace);
        }
        operands.push(sign * _find(s));
        skip(s, isalnum);
      }
      // get_operator
      skip(s, isspace);
      errf(s);
      if (*s == '\0' || *s == ')') {
        while (!operators.empty()) {
          _op(operands, operators);
        }
        ++s;
        break;
      } else {
        while (!operators.empty() && _pr(operators.top(), *s)) {
          _op(operands, operators);
        }
        operators.push(*s);
        ++s;
      }
      // process
    }
    return operands.top();
  }

  void print(char s[]) {
    errf(s);
    printf("%d\n", _eval(s));
  }

  void feed(char s[]) {
    if (s[0] == 'd') {
      // if (strncmp(s, "define", 6) == 0)
      define(s + 6);
    } else {
      // if (strncmp(s, "print", 5) == 0)
      print(s + 5);
    }
  }
};

int main() {
  char buf[1024];

  freopen("plcool.in", "r", stdin);
  freopen("plcool.out", "w", stdout);
  PC_Cool pc;
  while (fgets(buf, sizeof(buf), stdin) != NULL && buf[0] != '\n') {
    for (int i = 0; buf[i] != '\0'; ++i) {
      buf[i] = tolower(buf[i]);
    }
    pc.feed(buf);
  }

  return 0;
}

