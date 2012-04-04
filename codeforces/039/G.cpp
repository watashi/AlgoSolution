#include <map>
#include <cctype>
#include <cstdio>
#include <vector>
#include <string>
#include <cstdlib>
#include <utility>
#include <algorithm>

using namespace std;

const int MOD = 32768;

inline int _add(int a, int b) {
	return (a + b) % MOD;
}

inline int _sub(int a, int b) {
	return (a - b + MOD) % MOD;
}

inline int _mul(int a, int b) {
	return a * b % MOD;
}

inline int _div(int a, int b) {
	return a / b;
}

struct Func;

struct Node {
	enum Op {
		NUM,
		ADD,
		SUB,
		MUL,
		DIV,
		VAR,
		FUN,
	};
	Op op;
	int val;
	Node* lhs;
	Node* rhs;
	Node(Op op, int val = 0);
	Node(Op op, Node* lhs, Node* rhs = NULL);
	int eval(int var, const Func* fun) const;
};

struct Expr {
	Node* expr;
	Expr(string str);
	int eval(int var, const Func* fun) const;
};

struct Cond {
	enum Cmp {
		LT,
		EQ,
		GT,
	};
	Cmp cmp;
	Expr *lhs, *rhs;
	Cond(string str);
	bool eval(int var, const Func* fun) const;
};

struct Func {
	static map<int, int> tab;
	vector<pair<Cond*, Expr*> > stat;
	Func(string Func);
	int eval(int var) const;
};

map<int, int> Func::tab;

/**** ****/

string trim(string s) {
	s.erase(0, s.find_first_not_of(' '));
	if (!s.empty()) {
		s.erase(s.find_last_not_of(' ') + 1);
	}
	return s;
}

string skip(string s, string t) {
	string::size_type pos = 0;
	for (string::iterator c = t.begin(); c != t.end(); ++c) {
		pos = s.find(*c, pos) + 1;
	}
	return s.substr(pos);
}

string::size_type paren(string s, string::size_type pos) {
	int c = 1;
	while (c > 0) {
		if (s[pos] == '(') {
			++c;
		} else if (s[pos] == ')') {
			--c;
		}
		++pos;
	}
	return pos;
}

/**** Node ****/
Node::Node(Op op, int val) : op(op), val(val) {
}

Node::Node(Op op, Node* lhs, Node* rhs) : op(op), lhs(lhs), rhs(rhs) {
}

int Node::eval(int var, const Func* fun) const {
	switch (op) {
	case NUM: return val;
	case ADD: return _add(lhs->eval(var, fun), rhs->eval(var, fun));
	case SUB: return _sub(lhs->eval(var, fun), rhs->eval(var, fun));
	case MUL: return _mul(lhs->eval(var, fun), rhs->eval(var, fun));
	case DIV: return _div(lhs->eval(var, fun), rhs->eval(var, fun));
	case VAR: return var;
	case FUN: return fun->eval(lhs->eval(var, fun));
	default: throw 1;
	}
}

/**** Expr ****/
Expr::Expr(string str) {
//	puts(("a expr ? " + str).c_str());
	char* ptr;
	string::size_type pos;
	vector<Node::Op> op;
	vector<Node*> val;
	while (true) {
		str = trim(str);
		if (str[0] == 'n') {
			val.push_back(new Node(Node::VAR));
			str = str.substr(1);
		} else if (str[0] == 'f') {
			str = str.substr(str.find('(') + 1);
	//		puts(("str =  " + str).c_str());
			pos = paren(str, 0);
	//		puts(("paren " + str.substr(0, pos - 1) + "#" + str.substr(pos)).c_str());
			val.push_back(new Node(Node::FUN, (new Expr(str.substr(0, pos - 1)))->expr));
			str = str.substr(pos);
		} else {
			val.push_back(new Node(Node::NUM, strtol(str.c_str(), &ptr, 0)));
			str = str.substr(ptr - str.c_str());
		}
		
		str = trim(str);
		if (str.empty()) {
			while (!op.empty()) {
				Node* rhs = val.back();
				val.pop_back();
				Node* lhs = val.back();
				val.pop_back();
				val.push_back(new Node(op.back(), lhs, rhs));
				op.pop_back();
			}
			break;
		} else if (str[0] == '*' || str[0] == '/') {
			while (!op.empty() && (op.back() == Node::MUL || op.back() == Node::DIV)) {
				Node* rhs = val.back();
				val.pop_back();
				Node* lhs = val.back();
				val.pop_back();
				val.push_back(new Node(op.back(), lhs, rhs));
				op.pop_back();
			}
			op.push_back(str[0] == '*' ? Node::MUL : Node::DIV);
		} else if (str[0] == '+' || str[0] == '-') {
			while (!op.empty()) {
				Node* rhs = val.back();
				val.pop_back();
				Node* lhs = val.back();
				val.pop_back();
				val.push_back(new Node(op.back(), lhs, rhs));
				op.pop_back();
			}
			op.push_back(str[0] == '+' ? Node::ADD : Node::SUB);
		}
		str = str.substr(1);
	}
	expr = val[0];
}

int Expr::eval(int var, const Func* fun) const {
	return expr->eval(var, fun);
}

/**** Cond ****/
Cond::Cond(string str) {
//	puts(("do cond ? " + str).c_str());
	string::size_type pos;
	if ((pos = str.find("<")) != string::npos) {
		cmp = LT;
		lhs = new Expr(str.substr(0, pos));
		rhs = new Expr(str.substr(pos + 1));
	} else if ((pos = str.find(">")) != string::npos) {
		cmp = GT;
		lhs = new Expr(str.substr(0, pos));
		rhs = new Expr(str.substr(pos + 1));
	} else {
		pos = str.find("==");
		cmp = EQ;
		lhs = new Expr(str.substr(0, pos));
		rhs = new Expr(str.substr(pos + 2));
	}
}

bool Cond::eval(int var, const Func* fun) const {
	int l = lhs->eval(var, fun);
	int r = rhs->eval(var, fun);
	switch (cmp) {
		case LT: return l < r;
		case GT: return l > r;
		case EQ: return l == r;
		default: throw 2;
	}
}

/**** Func ****/
Func::Func(string str) {
	string::size_type pos;
	string tmp;
	str = str.substr(str.find('{') + 1);
	str = str.substr(0, str.find('}'));
	str = trim(str);
//	puts((str + "EOF").c_str());
	while ((pos = str.find(';')) != string::npos) {
		tmp = str.substr(0, pos);
		str = str.substr(pos + 1);
		tmp = trim(tmp);
	//	puts(("<" + tmp + ">").c_str());
	
		string cond;
		string expr;
		if (tmp.substr(0, 2) == "if") {
			pos = tmp.find('(');
			tmp = tmp.substr(pos + 1);
			pos = paren(tmp, 0);
			cond = tmp.substr(0, pos - 1);	// '('
			tmp = tmp.substr(pos);	// ')'
		} else {
			cond = "0 == 0";
		}
		expr = skip(tmp, "return");
		stat.push_back(make_pair(new Cond(cond), new Expr(expr)));
	}
}

int Func::eval(int var) const {
	if (tab.count(var) != 0) {
		return tab[var];
	}
	int& ret = tab[var];
	for (vector<pair<Cond*, Expr*> >::const_iterator it = stat.begin(); it != stat.end(); ++it) {
		if (it->first->eval(var, this)) {
			return ret = it->second->eval(var, this);
		}
	}
	throw 3;
}

int main() {
	int x, y;
	string code;
	char buf[4096];

	x = -1;
	scanf("%d", &y);
	while (scanf("%s", buf) != EOF) {
		code += buf;
		code += ' ';
	}
	Func f(code);
	try {
		for (int i = 0; i < MOD; ++i) {
	//		printf("%d => %d\n", i, f.eval(i));
			if (f.eval(i) == y) {
				x = i;
			}
		}
		printf("%d\n", x);
	} catch (int ex) {
		printf("ex = %d\n", ex);
		throw;
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//420313 	May 1, 2011 12:19:04 AM 	watashi 	39G - Inverse Function 	GNU C++ 	Accepted 	110 ms 	2400 KB 
