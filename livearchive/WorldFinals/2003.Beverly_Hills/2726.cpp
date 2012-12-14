#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

const string xdigits = "0123456789ABCDEF";

struct Node {
	char color;
	Node* p[4];
	Node(char color) : color(color) {
		for (int i = 0; i < 4; ++i) {
			p[i] = NULL;
		}
	}
	~Node() {
		for (int i = 0; i < 4; ++i) {
			delete p[i];
		}
	}
};

Node* decode(const char* &p) {
	if (*p++ == '1') {
		return new Node(*p++);
	} else {
		Node* q = new Node('?');
		for (int i = 0; i < 4; ++i) {
			q->p[i] = decode(p);
		}
		return q;
	}
}

string encode(const Node* p, const Node* q) {
	if (p->color == '0' || q->color == '0') {
		return "10";
	} else if (p->color == '1' && q->color == '1') {
		return "11";
	} else {
		string ret = "0";
		string tmp[4];
		bool flag = true;
		for (int i = 0; i < 4; ++i) {
			tmp[i] = encode(p->color == '?' ? p->p[i] : p, q->color == '?' ? q->p[i] : q);
			ret += tmp[i];
			if (flag && (tmp[i].length() != 2 || tmp[i] != tmp[0])) {
				flag = false;
			}
		}
		if (flag) {
			ret = tmp[0];
		}
		return ret;
	}
}

string x2b(const string& s) {
	string ret = "";
	for (int i = 0; i < (int)s.length(); ++i) {
		int t = xdigits.find(s[i]);
		for (int j = 8; j > 0; j /= 2) {
			ret += (t & j) ? '1' : '0';
		}
	}
	return ret.substr(ret.find('1'));
}

string b2x(string s) {
	string ret = "";
	s = "1" + s;
	while (s.length() % 4 != 0) {
		s = "0" + s;
	}
	for (int i = 0; i < (int)s.length(); i += 4) {
		int t = 0;
		for (int j = 0; j < 4; ++j) {
			t *= 2;
			if (s[i + j] == '1') {
				++t;
			}
		}
		ret += xdigits[t];
	}
	return ret;
}

int main() {
	int ri = 0;
	const char *ptr;
	static char buf[65536];
	
	while (scanf("%s", buf) != EOF && buf[0] != '0') {
		ptr = strcpy(buf, x2b(buf).substr(1).c_str());
		Node* p = decode(ptr);
		scanf("%s", buf);
		ptr = strcpy(buf, x2b(buf).substr(1).c_str());
		Node* q = decode(ptr);
		if (ri > 0) {
			puts("");
		}
		printf("Image %d:\n%s\n", ++ri, b2x(encode(p, q)).c_str());
		delete p;
		delete q;
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//723406  	2011-01-21 17:18:34 	Accepted	0.199	552	26909	C++	2726 - Combining Images
/*
id => 1174156
pid => 2726
pname => Combining Images
status => Accepted
lang => C++
time => 0.052
date => 2012-12-14 17:31:06
*/
