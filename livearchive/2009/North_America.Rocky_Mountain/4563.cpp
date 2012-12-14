#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

stack<string> s;

inline void gaotag(const char* &p) {
	// *p == '<';
	++p;
	bool isend = false;
	if (*p == '/') {
		isend = true;
		++p;
	}

	const char* q = p;
	if (*q == '>') {
		throw "empty tag!";
	}
	while (islower(*q) || isdigit(*q)) {
		++q;
	}

	if (strncmp(q, "/>", 2) == 0) {
		p = q + 2;
	} else if (*q != '>') {
		throw "invalid tag!";
	} else if (isend) {
		if (s.empty() || s.top() != string(p, q)) {
			throw "not matched!";
		}
		s.pop();
		p = q + 1;
	} else {
		s.push(string(p, q));
		p = q + 1;
	}
}

inline void gaotok(const char* &p) {
	// *p == '&';
	++p;
//	fprintf(stderr, "TOK[%c]", *p);
	if (strncmp(p, "lt;", 3) == 0) {
		p += 3;
	} else if (strncmp(p, "gt;", 3) == 0) {
		p += 3;
	} else if (strncmp(p, "amp;", 4) == 0) {
		p += 4;
	} else if (*p == 'x' && isxdigit(1[p])) {
		++p;
		while (isxdigit(*p) && isxdigit(1[p])) {
			p += 2;			
		}
		if (*p == ';') {
			++p;
		} else {
			throw "unexpected end of &x";
		}
	} else {
		throw "invlid tok!";
	}
}

inline void gaochr(const char* &p) {
	if (32 <= *p && *p <= 127 && *p != '>'/* && *p != '<' && *p != '&'*/) {
		++p;
	} else {
		throw "invalid chr!";
	}
}

void gao(const char* p) {
	while (!s.empty()) {
		s.pop();
	}

	while (*p != '\0') {
		switch (*p) {
			case '&': gaotok(p); break;
			case '<': gaotag(p); break;
			default: gaochr(p); break;
		}
	}

	if (!s.empty()) {
		throw "not balanced!";
	}
}

int main() {
	static char str[10000000];

	while (gets(str) != NULL) {
		try {
			gao(str);
			puts("valid");
		} catch (...) {
			puts("invalid");
		}
	}	

	return 0;
}
//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//714988  	2011-01-04 06:23:56 	Accepted	0.014	Minimum	26909	C++	4563 - XML
/*
id => 1174240
pid => 4563
pname => XML
status => Accepted
lang => C++
time => 0.012
date => 2012-12-14 17:43:32
*/
