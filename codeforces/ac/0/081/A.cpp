#include <list>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	string s;
	cin >> s;

	list<char> x(s.begin(), s.end());
	for (list<char>::iterator it = x.begin(); it != x.end(); ) {
		if (it == x.begin()) {
			++it;
		} else {
			list<char>::iterator jt = it;
			--jt;
			if (*it == *jt) {
				x.erase(jt);
				it = x.erase(it);
			} else {
				++it;
			}
		}
	}
	
	cout << string(x.begin(), x.end()) << endl;
	return 0;
}

