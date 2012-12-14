#include <set>
#include <stack>
#include <string>
#include <cctype>
#include <cstdio>
#include <cstring>

using namespace std;

#define SKIP(p) while (*p != '\0' && *p != '>' && *p != '/' && isspace(*p)) { ++p; }
#define GET(p) while (*p != '\0' && *p != '>' && *p != '/' && (isalnum(*p) || *p == '-')) { ++p; }
#define EAT(p) while (*p != '\0' && *p != '"') { ++p; }
#define ERROR error = true; return NULL;

struct XML {
	bool empty;
	bool error;
	set<string> x;
	stack<string> s;

	XML() : empty(true), error(false) {
	}

	void push(const string& tag) {
		if (!empty && s.empty()) {
			error = true;
		} else if (x.count(tag) > 0) {
			error = true;
		} else {
			empty = false;
			x.insert(tag);
			s.push(tag);
		}
	}

	void pop(const string& tag) {
		if (s.empty() || s.top() != tag) {
			error = true;
		} else {
			x.erase(s.top());
			s.pop();
		}
	}

	const char *gao(const char *p) {
		bool end = false;
		const char* q;
		set<string> prop;

		SKIP(p)
		if (*p == '/') {
			end = true;
			++p;
			SKIP(p)
		}

		q = p;
		GET(q)
	//	fprintf(stderr, "[%d] <%s>\n", (int)end, string(p, q).c_str());
		if (end) {
			pop(string(p, q));
		} else {
			push(string(p, q));
		}
		if (error) {
			return NULL;
		}

		p = q;
		SKIP(p);
		while (*p != '\0' && *p != '>' && *p != '/') {
			q = p;
			GET(q)
	//		fprintf(stderr, "\t%s\n", string(p, q + 1).c_str());
			if (prop.count(string(p, q)) > 0) {
				ERROR
			} else {
				prop.insert(string(p, q));
			}
			SKIP(q)
			if (*q != '=') {
				ERROR
			}
			++q;
			SKIP(q)
			if (*q != '"') {
				ERROR
			}
			++q;
			EAT(q)
			if (*q == '\0') {
				ERROR
			}
			p = q + 1;
			SKIP(p)
		}

		if (*p == '/') {
			x.erase(s.top());
			s.pop();
			++p;
			SKIP(p)
		}
		if (*p != '>') {
			ERROR
		}

		return p + 1;
	}

	void feed(const char *p) {
		while (!error && *p != '\0') {
			if (*p == '<') {
				p = gao(p + 1);
			} else {
				++p;
			}
		}
	}
};

int main() {
	bool noteof = true;
	char buf[65536];

	fgets(buf, sizeof(buf), stdin);
	do {
		XML xml;
		while ((noteof &= fgets(buf, sizeof(buf), stdin) != NULL)
				&& strncmp(buf, "<?xml", 5) != 0
				&& strncmp(buf, "<?end", 5) != 0) {
			xml.feed(buf);
		}
		puts(!xml.empty && !xml.error && xml.s.empty() ? "well-formed" : "non well-formed");
	} while (noteof && strncmp(buf, "<?end", 5) != 0);

	return 0;
}

//Run ID  	Submit Time  	Judge Status  	Problem ID  	Language  	Run Time(ms)  	Run Memory(KB)  	User Name  	Admin
//256 	2010-06-24 23:20:31 	Accepted 	1010 	C++ 	10 	180 	anotherpeg 	Source
//
//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//805936 	2087 	A Well-Formed Problem 	Accepted 	C++ 	0.008 	2011-05-23 15:34:53
/*
id => 1174127
pid => 2087
pname => A Well-Formed Problem
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:27:34
*/
