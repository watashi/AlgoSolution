#include <map>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <sstream>
#include <cassert>
#include <iostream>
#include <algorithm>

using namespace std;

typedef int binop(int, int);

int _plus(int lhs, int rhs) {
	return lhs + rhs;
}

int _minus(int lhs, int rhs) {
	return lhs - rhs;
}

int _times(int lhs, int rhs) {
	return lhs * rhs;
}

const string ops = "+-*";
const binop *funcs[] = {_plus, _minus, _times};

struct Matrix {
	vector<int> dim;
	vector<int> val;
	// len(val) == prod(dim)

	Matrix() {
		dim.push_back(0);
	}
	
	explicit Matrix(int x) {
		dim.push_back(1);
		val.push_back(x);
	}

	void append(int x) {
		assert(dim.size() == 1);

		++dim[0];
		val.push_back(x);
	}

	void repeat(int x) {
		assert(dim.size() == 1);
		assert(dim[0] > 0);

		int d = dim[0];
		for (int i = d; i < x; ++i) {
			val.push_back(val[i - d]);
		}
		dim[0] = x;
		val.resize(x);
	}

	void itoa() {
		assert(dim == vector<int>(1, 1));
		assert(val[0] > 0);
		
		int n = val[0];
		dim[0] = n;
		val.resize(n);
		for (int i = 0; i < n; ++i) {
			val[i] = i + 1;
		}
	}

	void rho(const Matrix& x) {
		assert(x.dim.size() == 1);
		assert(x.val.size() <= 3);
	
		int d = 1;
		for (int i = 0; i < (int)x.val.size(); ++i) {
			d *= x.val[i];
		}
		repeat(d);
		dim = x.val;
	}

	void drop(const Matrix& x) {
		assert(dim.size() == 1);
		assert(x.dim == vector<int>(1, 1));
		assert(dim[0] > x.val[0]);
		dim[0] -= x.val[0];
		val.erase(val.begin(), val.begin() + x.val[0]);
	}

	void apply(Matrix x, binop op) {
		if (dim == x.dim) {
		} else if (dim == vector<int>(1, 1)) {
			val = vector<int>(x.val.size(), val[0]);
			dim = x.dim;
		} else if (x.dim == vector<int>(1, 1)) {
			x.val = vector<int>(val.size(), x.val[0]);
			x.dim = dim;
		} else {
			assert(false);
		}
		for (int i = 0; i < (int)val.size(); ++i) {
			val[i] = op(x.val[i], val[i]);
		}
	}

	void reduce(binop op) {
		vector<int> d = dim;
		d.pop_back();
		if (d.empty()) {
			d.push_back(1);
		}
		vector<int> v(val.size() / dim.back());
		for (int i = 0; i < (int)v.size(); ++i) {
			v[i] = val[i * dim.back() + dim.back() - 1];
			for (int j = dim.back() - 2; j >= 0; --j) {
				v[i] = op(val[i * dim.back() + j], v[i]);
			}
		}	
		dim = d;
		val = v;
	}

	void dump() const {
		if (dim.size() == 1) {
			assert(dim[0] > 0);
			for (int i = 0; i < dim[0]; ++i) {
				printf("%d%c", val[i], i == dim[0] - 1 ? '\n' : ' ');
			}
		} else if (dim.size() == 2) {
			assert(dim[0] > 0 && dim[1] > 0);
			for (int i = 0; i < dim[0]; ++i) {
				for (int j = 0; j < dim[1]; ++j) {
					printf("%d%c", val[i * dim[1] + j], j == dim[1] - 1 ? '\n' : ' ');
				}
			}
		} else if (dim.size() == 3) {
			assert(dim[0] > 0 && dim[1] > 0 && dim[2] > 0);
			for (int i = 0; i < dim[0]; ++i) {
				if (i > 0) {
					puts("");
				}
				for (int j = 0; j < dim[1]; ++j) {
					for (int k = 0; k < dim[2]; ++k) {
						printf("%d%c", val[((i * dim[1] + j) * dim[2]) + k], k == dim[2] - 1 ? '\n' : ' ');
					}
				}
			}
		}
	}
};

map<string, Matrix> vartab;

Matrix get(stack<string>& s);
Matrix gao(stack<string>& s);

Matrix get(stack<string>& s) {
	if (s.top() == ")") {	// (...)
		s.pop();
		return gao(s);
	} else {
		int x;
		Matrix ret;
		while (true) {
			istringstream iss(s.top());
			if (iss >> x) {
				ret.append(x);
				s.pop();
			} else {
				break;
			}
		}	// [a b c d]
		if (ret.val.empty()) {	// var
//			printf("GET_VAR: %s\n", s.top().c_str());
			ret = vartab[s.top()];
//			ret.dump();
			s.pop();
		} else {
			reverse(ret.val.begin(), ret.val.end());
		}
		return ret;
	}
}

Matrix gao(stack<string>& s) {
	string op;
	Matrix val = get(s);
	while (true) {
		op = s.top();
		s.pop();
//		printf("NEXT_TODO = %s\n", op.c_str());
//		val.dump();
		if (op == "(") {
			return val;
		} else if (op == "iota") {
			val.itoa();
		} else if (op == "drop") {
			val.drop(get(s));
		} else if (op == "rho") {
			val.rho(get(s));
		} else if (op == "=") {
			vartab[s.top()] = val;
			s.pop();
		} else if (op == "/") {
			val.reduce(funcs[ops.find(s.top())]);
			s.pop();
		} else {
			val.apply(get(s), funcs[ops.find(op)]);
		}
	}
	return val;
}

int main() {
	int ri = 0;
	string tok;

	while (getline(cin, tok) && tok != "#") {
	//	cout << "Case " << ++ri << ": " << tok << endl;
	//	puts("");
		assert(!isblank(tok[0]));
		assert(!isblank(tok[tok.length() - 1]));
		assert(tok.find("  ") == string::npos);
		printf("Case %d: %s\n", ++ri, tok.c_str());
		istringstream iss("( " + tok);
		stack<string> s;
		while (iss >> tok) {
			s.push(tok);
		}
		gao(s).dump();
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//805853 	4785 	APL Lives! 	Presentation error 	C++ 	0.032 	2011-05-23 13:45:09

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//805884 	4785 	APL Lives! 	Accepted 	C++ 	0.040 	2011-05-23 14:25:50 // 囧
/*
id => 1174404
pid => 4785
pname => APL Lives!
status => Accepted
lang => C++
time => 0.015
date => 2012-12-14 19:02:34
*/
