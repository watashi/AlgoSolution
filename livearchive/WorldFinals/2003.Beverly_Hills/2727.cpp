#include <map>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <utility>
#include <algorithm>

using namespace std;

struct Module {
	int begin, end;
	vector<pair<string, int> > tab;
	vector<string> ex;
	vector<int> bytes;
};

vector<Module> v;

int main() {
	int ri = 0, n, x;
	char op, buf[1024];
	map<string, vector<int> > tab;

	while (scanf(" %c", &op) != EOF && op != '$') {
		v.clear();
		while (op != '$') {
		//	printf("gao!\n");
			v.push_back(Module());
			while (op != 'Z') {
		//		printf("gao(%c)\n", op);
				if (op == 'D') {
					scanf("%s%x", buf, &x);
					v.back().tab.push_back(make_pair(string(buf), x));
				} else if (op == 'E') {
					scanf("%s", buf);
					v.back().ex.push_back(buf);
				} else if (op == 'C') {
					scanf("%x", &n);
					for (int i = 0; i < n; ++i) {
						scanf("%s", buf);
						if (buf[0] == '$') {
							v.back().bytes.push_back(-1);
						} else {
						//	strtol(buf, NULL, 16);
							sscanf(buf, "%x", &x);
							v.back().bytes.push_back(x);
						}
					}
				}
				scanf(" %c", &op);
			}
			scanf(" %c", &op);
		}

		tab.clear();
		for (int i = 0; i < (int)v.size(); ++i) {
			v[i].begin = (i == 0 ? 0x100 : v[i - 1].end);
			v[i].end = v[i].begin + v[i].bytes.size();
			for (vector<pair<string, int> >::const_iterator it = v[i].tab.begin(); it != v[i].tab.end(); ++it) {
				tab[it->first].push_back(v[i].begin + it->second);
			}
			for (vector<string>::const_iterator it = v[i].ex.begin(); it != v[i].ex.end(); ++it) {
				tab[*it];
			}
		}
	//	for (map<string, vector<int> >::iterator it = tab.begin(); it != tab.end(); ++it) {
	//		sort(it->second.begin(), it->second.end());
	//	}

		n = 0;
		for (int i = 0; i < (int)v.size(); ++i) {
			for (int j = 0; j < (int)v[i].bytes.size(); ++j) {
				if (v[i].bytes[j] == -1) {
					if (v[i].bytes[j + 1] >= v[i].ex.size() || tab[v[i].ex[v[i].bytes[j + 1]]].empty()) {
						x = 0;
					} else {
						x = tab[v[i].ex[v[i].bytes[j + 1]]][0];
					}
				//	printf("==== %X\n", x);
					v[i].bytes[j] = (x / 0x100) & 0xff;
					v[i].bytes[j + 1] = (x & 0xff);
					--j;
				} else {
					n = (n * 2 + n / 0x8000 + v[i].bytes[j]) & 0xffff;
				}
			}
		}
		
		if (ri > 0) {
			puts("");
		}
		printf("Case %d: checksum = %04X\n", ++ri, n);
		puts(" SYMBOL   ADDR\n--------  ----");
		for (map<string, vector<int> >::const_iterator it = tab.begin(); it != tab.end(); ++it) {
			printf("%-10s", it->first.c_str());
			if (it->second.empty()) {
				printf("????");
			} else {
				printf("%04X%s", it->second[0], it->second.size() == 1 ? "" : " M");
			}
			puts("");
		}
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//723407  	2011-01-21 17:19:36 	Accepted	0.002	Minimum	26909	C++	2727 - A Linking Loader
/*
id => 1174157
pid => 2727
pname => A Linking Loader
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:31:10
*/
