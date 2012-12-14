#include <set>
#include <vector>
#include <string>
#include <cctype>
#include <cstdio>

using namespace std;

int main() {
    int re;
    int n, m;
    char buf[1024], *p, *q;

//    freopen("b.in", "r", stdin);
    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d", &n);
        vector<string> v;
        for (int i = 0; i < n; ++i) {
            scanf("%s", buf);
            v.push_back(buf);
        }
        scanf("%d", &m);
        set<string> s;
        fgets(buf, sizeof(buf), stdin);
        for (int i = 0; i < m; ++i) {
            fgets(buf, sizeof(buf), stdin);
            p = buf;
            while (isspace(*p)) {
                ++p;
            }
            while (*p != '\0') {
                q = p;
                while (isalnum(*q)) {
                    ++q;
                }
                s.insert(string(p, q));
                p = q;
                while (isspace(*p)) {
                    ++p;
                }
            }
        }
   //     for (set<string>::iterator it = s.begin(); it != s.end(); ++it) {
   //         printf("%s\n", it->c_str());
   //     }
        printf("Test set %d:\n", ri);
        for (int i = 0; i < n; ++i) {
            printf("%s is %s\n", v[i].c_str(), s.count(v[i]) == 0 ? "absent" : "present");
        }
        puts("");
    }

    return 0;
}
//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//727363  	2011-01-29 12:21:50 	Accepted	0.002	Minimum	26909	C++	4433 - "Robot Roll Call -- Cambot...Servo...Gypsy...Croooow"
/*
id => 1174032
pid => 4433
pname => "Robot Roll Call -- Cambot...Servo...Gypsy...Croooow"
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:12:59
*/
