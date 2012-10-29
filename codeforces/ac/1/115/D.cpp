#include <algorithm>

using namespace std;

const int MAXN = 4096;
const long long MOD = 1000003;

vector<int> gao(const string& str) {
	vector<int> ret;
	string op = "*";
	for (string::const_iterator it = str.begin(); it != str.end(); ++it) {
		if (*it == '+' || *it == '-') {
			op += '+';
		} else if (*it == '*' || *it == '/') {
			op += '*';
		} else if (op != "") {
			ret.push_back(op.length() - 1);
			if (op.find_first_not_of('+', 1) != string::npos) {
				throw 1;
			}
			op = "";
		}
	}
	if (op != "") {
		throw 1;
	}
	return ret;
}

int add(int lhs, int rhs) {
	return (lhs + rhs) % MOD;
}

int main() {
	char str[MAXN];
	vector<int> v;

	scanf("%s", str);
	try {
		v = gao(str);
	} catch (...) {
		puts("0");
		return 0;
	}

	vector<int> val(MAXN, 1);
	for (int i = (int)v.size() - 1; i > 0; --i) {
		val.erase(val.begin(), val.begin() + v[i] + 1);
		partial_sum(val.begin(), val.end(), val.begin(), add);
	}
	printf("%d\n", val[v[0]]);

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//702440 	Sep 15, 2011 10:16:56 PM 	watashi 	D - Unambiguous Arithmetic Expression 	GNU C++0x 	Accepted 	50 ms 	1400 KB
