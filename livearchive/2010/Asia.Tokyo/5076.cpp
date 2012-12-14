#include <map>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

int neg(int x) {
	return 0x8000 - x;
}

int add(int x, int y) {
	return (x + y) & 0x7fff;
}

int sub(int x, int y) {
	return add(x, neg(y));
}

int mul(int x, int y) {
	return (x * y) & 0x7fff;
}

struct Matrix {
	vector<vector<int> > a;
	bool b;

	explicit Matrix(int x = 0) : a(1, vector<int>(1, x)), b(true) {
	}

	Matrix(int r, int c) : a(r, vector<int>(c, 0)), b(true) {
	}

	Matrix(const Matrix& m) : a(m.a) {
	}

	const vector<int>& operator[](int i) const {
		return a[i];
	}

	vector<int>& operator[](int i) {
		return a[i];
	}

	int row() const {
		return a.size();
	}

	int col() const {
		return a[0].size();
	}

	void addrow() {
		b = true;
	}

	void addcol(const Matrix& m) {
		if (b) {
			for (int i = 0; i < m.row(); ++i) {
				a.push_back(m[i]);
			}
			b = false;
		} else {			
			for (int i = 0, j = row() - m.row(); i < m.row(); ++i, ++j) {
				a[j].insert(a[j].end(), m[i].begin(), m[i].end());
			}
		}
	}

	Matrix operator-() const {
		Matrix ret(row(), col());
		for (int i = 0; i < ret.row(); ++i) {
			for (int j = 0; j < ret.col(); ++j) {
				ret[i][j] = neg((*this)[i][j]);
			}
		}
		return ret;
	}

	Matrix transpose() const {
		Matrix ret(col(), row());
		for (int i = 0; i < ret.row(); ++i) {
			for (int j = 0; j < ret.col(); ++j) {
				ret[i][j] = (*this)[j][i];
			}
		}
		return ret;
	}

	Matrix sub(const Matrix& rsub, const Matrix& csub) const {
		Matrix ret(rsub.col(), csub.col());
		for (int i = 0; i < ret.row(); ++i) {
			for (int j = 0; j < ret.col(); ++j) {
				ret[i][j] = (*this)[rsub[0][i] - 1][csub[0][j] - 1];
			}
		}
		return ret;
	}

	void dump() const {
		for (int i = 0; i < row(); ++i) {
			for (int j = 0; j < col(); ++j) {
				printf("%d%c", (*this)[i][j], j == col() - 1 ? '\n' : ' ');
			}
		}
	}
};

Matrix operator+(const Matrix& lhs, const Matrix& rhs) {
	Matrix ret(lhs.row(), lhs.col());
	for (int i = 0; i < ret.row(); ++i) {
		for (int j = 0; j < ret.col(); ++j) {
			ret[i][j] = add(lhs[i][j], rhs[i][j]);
		}
	}
	return ret;
}

Matrix operator-(const Matrix& lhs, const Matrix& rhs) {
	Matrix ret(lhs.row(), lhs.col());
	for (int i = 0; i < ret.row(); ++i) {
		for (int j = 0; j < ret.col(); ++j) {
			ret[i][j] = sub(lhs[i][j], rhs[i][j]);
		}
	}
	return ret;
}

Matrix operator*(const Matrix& lhs, const Matrix& rhs) {
	if (lhs.row() == 1 && lhs.col() == 1) {
		Matrix ret(rhs.row(), rhs.col());
		for (int i = 0; i < ret.row(); ++i) {
			for (int j = 0; j < ret.col(); ++j) {
				ret[i][j] = mul(lhs[0][0], rhs[i][j]);
			}
		}
		return ret;
	} else if (rhs.row() == 1 && rhs.col() == 1) {
		return rhs * lhs;
	} else {
		Matrix ret(lhs.row(), rhs.col());
		for (int i = 0; i < ret.row(); ++i) {
			for (int j = 0; j < ret.col(); ++j) {
				for (int k = 0; k < lhs.col(); ++k) {
					ret[i][j] = add(ret[i][j], mul(lhs[i][k], rhs[k][j]));
				}
			}
		}
		return ret;
	}
}

map<char, Matrix> vartab;

Matrix eval(char* &p);

Matrix read(char* &p) {
	Matrix ret(0, 0);
	bool isneg = false;
	while (*p == '-') {
		isneg = !isneg;
		++p;
	}

	if (isdigit(*p)) {
		ret = Matrix(strtol(p, &p, 10));
	} else if (isalpha(*p)) {
		ret = vartab[*p++];
	} else if (*p == '(') {
		++p;
		ret = eval(p);
		assert(*p == ')');
		++p;
	} else if (*p == '[') {
		while (true) {
			++p;
			ret.addcol(eval(p));
			if (*p == ']') {
				break;
			} else if (*p == ';') {
				ret.addrow();
			} else {
				assert(*p == ' ');
			}
		}
		++p;
	} else {
		assert(false);
	}

	while (*p == '\'' || *p == '(') {
		if (*p == '\'') {
			++p;
			ret = ret.transpose();
		} else {
			++p;
			Matrix rsub = eval(p);
			assert(*p == ',');
			++p;
			Matrix csub = eval(p);
			assert(*p == ')');
			++p;
			ret = ret.sub(rsub, csub);
		}
	}
	
	return isneg ? -ret : ret;
}

Matrix eval(char* &p) {
	vector<char> op;
	vector<Matrix> val;

//	printf("eval[in] %s\n", p);
	do {
		val.push_back(read(p));
//		printf("eval[read] %s\n", p);
		while (!op.empty() && (*p != '*' || op.back() == '*')) {
			Matrix rhs = val.back();
			val.pop_back();
			Matrix lhs = val.back();
			val.pop_back();
			switch (op.back()) {
			case '+': val.push_back(lhs + rhs); break;
			case '-': val.push_back(lhs - rhs); break;
			case '*': val.push_back(lhs * rhs); break;
			default: assert(false); break;
			}
			op.pop_back();
		}
		op.push_back(*p++);
	} while (op.back() == '+' || op.back() == '-' || op.back() == '*');
	--p;
//	printf("eval[out] %s\n", p);

	return val[0];
}

int main() {
	int n;
	char buf[4096];
	char* ptr;

	while (scanf("%d ", &n) != EOF && n > 0) {
		vartab.clear();
		for (int i = 0; i < n; ++i) {
			fgets(buf, sizeof(buf), stdin);
			ptr = buf + 2;
			(vartab[buf[0]] = eval(ptr)).dump();
		}
		puts("-----");
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//772363  	2011-04-29 06:56:37 	Accepted	0.646	848	26909	C++	5076 - Matrix Calculator
/*
id => 1174081
pid => 5076
pname => Matrix Calculator
status => Accepted
lang => C++
time => 0.028
date => 2012-12-14 17:19:44
*/
