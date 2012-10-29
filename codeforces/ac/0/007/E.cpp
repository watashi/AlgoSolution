#include <map>
#include <stack>
#include <string>
#include <cctype>
#include <cstdio>
#include <cstdlib>

using namespace std;

enum Token {
	Expr,
	Factors,
	Terms,
	Suspicious
};

map<char, int> pr;
map<string, Token> def;

void init() {
	pr['\0'] = 0;
	pr[')'] = 1;
	pr['+'] = 3;
	pr['-'] = 3;
	pr['*'] = 5;
	pr['/'] = 5;
}

template<int P(int)>
inline void skip(const char* &p) {
	while (*p != '\0' && P(*p)) {
		++p;
	}
}

inline Token invoke(char op, Token lhs, Token rhs) {
	if (lhs == Suspicious || rhs == Suspicious) {
		return Suspicious;
	} else if (op == '+' || op == '-') {
		if (op == '-' && rhs == Terms) {
			return Suspicious;
		} else {
			return Terms;
		}
	} else if (op == '*' || op == '/') {
		if (lhs == Terms || rhs == Terms) {
			return Suspicious;
		} else if (op == '/' && rhs == Factors) {
			return Suspicious;
		} else {
			return Factors;
		}
	} else {
		return Suspicious;
	}
}

Token parse(const char* &p) {
	string id;
	const char *q;
	stack<char> op;
	stack<Token> val;

	while (true) {
		skip<isblank>(p);
		if (*p == '(') {
			Token ret = parse(++p);
			val.push(ret == Suspicious ? Suspicious : Expr);
			++p;
		} else {
			skip<isalnum>(q = p);
			id = string(p, q);
			val.push(def.count(id) > 0 ? def[id] : Expr);
			p = q;
		}

		skip<isblank>(p);
		while (!op.empty() && pr[op.top()] >= pr[*p]) {
			Token rhs = val.top();
			val.pop();
			Token lhs = val.top();
			val.pop();
			val.push(invoke(op.top(), lhs, rhs));
			op.pop();
		}
		if (*p == '\0' || *p == ')') {
			return val.top();
		} else {
			op.push(*p++);
		}
	}
}

int main() {
	int n;
	const char *ptr;
	char name[80], expr[4096];

	init();
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
//		scanf("%*s%s%[^\n]", name, expr);	// => WA139
		scanf(" # define %s %[^\n]", name, expr);
		def[name] = parse(ptr = expr);
	}
	scanf(" %[^\n]", expr);
	puts(parse(ptr = expr) == Suspicious ? "Suspicious" : "OK");

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//268121 	Jan 31, 2011 10:55:08 AM 	watashi 	7E - Defining Macros 	GNU C++ 	Accepted 	30 ms 	1300 KB 
