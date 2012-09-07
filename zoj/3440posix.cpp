#include <cstdio>
#include <map>
#include <string>
#include <sys/types.h>
#include <regex.h>

using std::map;
using std::string;

static const string virus = "virus";
static map<string, string> r;

const string& gao(const string& label) {
    string& ret = r[label];
    if (ret[0] != '(') {
        string::size_type begin, end;
        string sublabel, subcontent;
        while ((begin = ret.find('[')) != string::npos) {
            ++begin;
            end = ret.find(']', begin);
            sublabel = ret.substr(begin, end - begin);
            subcontent = gao(sublabel);
            sublabel = "[" + sublabel + "]";
            while ((begin = ret.find(sublabel)) != string::npos) {
                ret.replace(begin, sublabel.length(), subcontent);
            }
        }
        ret = "(" + ret + ")";
    }
    return ret;
}

int main() {
    int n, m;
    char label[80], content[4096];
    regex_t re;

    while (scanf("%d", &n) != EOF) {
        r.clear();
        for (int i = 0; i < n; ++i) {
            scanf(" %[a-z]:=%s", label, content);
            r[label] = content;
        }

        scanf("%d", &m);
        regcomp(&re, gao(virus).c_str(), REG_EXTENDED | REG_NOSUB);
        for (int i = 0; i < m; ++i) {
            scanf("%s", content);
            puts(regexec(&re, content, 1, NULL, 0) == 0 ? "YES" : "NO");
        }
        puts("");
        regfree(&re);
    }

    return 0;
}

// 2012-09-07 16:50:20 | Accepted | 3440 | C++ | 350 | 3048 | watashi | Source
