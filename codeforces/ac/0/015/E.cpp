#include <numeric>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

const int MAXN = 1 << 19;
const long long MOD = 1000000009;

template<class Op, class Int>
struct _mod {
	const Op op;
	const Int m;
	_mod(Op op, Int m) : op(op), m(m) { }
	Int operator()(Int x, Int y) const { return op(x, y) % m; }
};

template<class Op, class Int>
_mod<Op, Int> mod(const Op& op, const Int& m) {
	return _mod<Op, Int>(op, m);
}

long long a[MAXN];

int main() {
	fill(a + 1, a + MAXN, 2);
	partial_sum(a + 1, a + MAXN, a + 1, mod(multiplies<long long>(), MOD));
	a[1] = 1;
	partial_sum(a + 1, a + MAXN, a + 1, mod(plus<long long>(), MOD));
	partial_sum(a + 1, a + MAXN, a + 1, mod(multiplies<long long>(), MOD));
	transform(a + 1, a + MAXN, a + 1, bind2nd(multiplies<long long>(), 4));
	a[0] = 1;
	partial_sum(a, a + MAXN, a, mod(plus<long long>(), MOD));

	long long n;

	cin >> n;
	n = a[n / 2 - 1];
	cout << ((2 * n + 4) * n + 4) % MOD << endl;

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//277701 	Feb 9, 2011 4:13:29 PM 	watashi 	15E - Triangles 	GNU C++ 	Accepted 	80 ms 	5400 KB
