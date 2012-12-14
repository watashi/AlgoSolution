#include <cctype>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

char tocap(char c) {
	if (isalpha(c)) {
		c ^= 32;
	}
	return c;
}

string capslock(string s) {
	transform(s.begin(), s.end(), s.begin(), tocap);
	return s;
}

bool isnum(char c) {
	return isdigit(c);
}

string numlock(string s) {
	s.erase(remove_if(s.begin(), s.end(), isnum), s.end());
	return s;
}

int main() {
	int re;
	string a, b;

	cin >> re;
	for (int ri = 1; ri <= re; ++ri) {
		cin >> a >> b;
		cout << "Case " << ri << ": ";
		if (a == b) {
			cout << "Login successful." << endl;
		} else if (capslock(a) == b) {
			cout << "Wrong password. Please, check your caps lock key." << endl;
		} else if (numlock(a) == b) {
			cout << "Wrong password. Please, check your num lock key." << endl;
		} else if (capslock(numlock(a)) == b) {
			cout << "Wrong password. Please, check your caps lock and num lock keys." << endl;
		} else {
			cout << "Wrong password." << endl;
		}
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//716023  	2011-01-06 09:14:40 	Accepted	0.002	Minimum	26909	C++	5047 - Arbiter Login
/*
id => 1174141
pid => 5047
pname => Arbiter Login
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:29:38
*/
