#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

map<string, int> def;

int main() {
	int n, c;
	string op, a, b;

	cin >> n;
	def["void"] = 0;
	for (int i = 0; i < n; ++i) {
		cin >> op >> a;
		c = 0;
		c += count(a.begin(), a.end(), '*');
		c -= count(a.begin(), a.end(), '&');
		a.erase(remove(a.begin(), a.end(), '*'), a.end());
		a.erase(remove(a.begin(), a.end(), '&'), a.end());
	//	cerr << "[" << a << "]" << endl;
		if (op == "typeof") {
			if (def.count(a) == 0 || def[a] < 0) {
				cout << "errtype" << endl;
			} else {
				c += def[a];
				if (c < 0) {
					cout << "errtype" << endl;	
				} else {
					cout << "void";
					for (int i = 0; i < c; ++i) {
						cout << '*';
					}
					cout << endl;
				}
			}
		} else {
			cin >> b;
			if (def.count(a) == 0 || def[a] < 0) {
				def[b] = -1;
			} else {
				def[b] = def[a] + c;
			}
		}
	}

	return 0;
}

