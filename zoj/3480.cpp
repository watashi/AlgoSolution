#include <set>
#include <map>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <algorithm>

using namespace std;

static int class_defined;
static int class_parent_error;
static int class_no_parent;
static int class_with_parent;
static int def_method;
static int redef_method;
static int undef_method;
static int def_no_class;
static int undef_no_class;
static int undef_no_method;
static int call_no_class;
static int call_no_method;
static int call_ok;
static int call_redirect_ok;

struct Class {
    const int depth;
    const string name;
    Class* const parent;
    set<string> methods;

    Class(const string& name, Class* parent = NULL)
        : depth(parent == NULL ? 0 : parent->depth + 1), name(name), parent(parent) {
        assert(depth <= 20);
        {
            if (parent == NULL) {
                ++class_no_parent;
            } else {
                ++class_with_parent;
            }
        }
//      fprintf(stderr, "%d\n", depth);
        printf("class %s%s%s\n", name.c_str(),
            parent == NULL ? "" : ":",
            parent == NULL ? "" : parent->name.c_str());
    }

    void def(const string& method) {
        {
            if (methods.count(method) == 0) {
                ++def_method;
            } else {
                ++redef_method;
            }
        }
        printf("%s %s.%s\n", methods.count(method) == 0 ? "def" : "redef",
            name.c_str(), method.c_str());
        methods.insert(method);
    }

    void undef(const string& method) {
        {
            if (methods.count(method) > 0) {
                ++undef_method;
            } else {
                ++undef_no_method;
            }
        }
        if (methods.count(method) > 0) {
            methods.erase(method);
            printf("undef %s.%s\n", name.c_str(), method.c_str());
        } else {
            puts("oops!");
        }
    }

    void call(const string& method, int d = 0) const {
        if (methods.count(method) > 0) {
            {
                if (depth == 0) {
                    ++call_ok;
                } else {
                    ++call_redirect_ok;
                }
            }
            printf("invoke %s.%s\n", name.c_str(), method.c_str());
        } else if (parent != NULL) {
            parent->call(method, d + 1);
        } else {
            {
                ++call_no_method;
            }
            puts("oops!");
        }
    }
};

map<string, Class*> classes;

void check(const string& name) {
    assert(0 < name.length() && name.length() <= 20);
    for (int i = 0; i < (int)name.length(); ++i) {
        assert(name[i] == '_' || isalnum(name[i]));
    }
    assert(!isdigit(name[0]));
}

int main() {
    int re, cnt;
    char buf[4096], tok[4][1024], sep, end;
    string op, fst, snd;

    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        fgets(buf, sizeof(buf), stdin);
        assert(strcmp(buf, "begin\n") == 0);
        while (true) {
            fgets(buf, sizeof(buf), stdin);
            if (strcmp(buf, "end\n") == 0) {
                break;
            }
            cnt = sscanf(buf, "%s %[^.:\n]%c%s%c", tok[0], tok[1], &sep, tok[2], &end);
            assert((cnt == 3 && sep == '\n') || (cnt == 5 && end == '\n'));
            check(op = tok[0]);
            check(fst = tok[1]);
            if (cnt == 5) {
                check(snd = tok[2]);
            }

            if (op == "class") {
                if (classes.count(fst) > 0) {
                    {
                        ++class_defined;
                    }
                    goto OOPS;
                }
                if (cnt == 5) {
                    assert(sep == ':');
                    if (classes.count(snd) == 0) {
                        {
                            ++class_parent_error;
                        }
                        goto OOPS;
                    }
                    classes[fst] = new Class(fst, classes[snd]);
                } else {
                    classes[fst] = new Class(fst);
                }
            } else if (cnt == 5) {
                assert(sep == '.');
                if (classes.count(fst) == 0) {
                    {
                        if (op == "def") {
                            ++def_no_class;
                        } else if (op == "undef") {
                            ++undef_no_class;
                        } else if (op == "call") {
                            ++call_no_class;
                        }
                    }
                    goto OOPS;
                }
                if (op == "def") {
                    classes[fst]->def(snd);
                } else if (op == "undef") {
                    classes[fst]->undef(snd);
                } else if (op == "call") {
                    classes[fst]->call(snd);
                } else {
                    assert(false);
                }
            } else {
                assert(false);
            }
            continue;

OOPS:
            puts("oops!");
            continue;
        }
        fgets(buf, sizeof(buf), stdin);
        assert(strcmp(buf, "\n") == 0);

        for (map<string, Class*>::const_iterator it = classes.begin(); it != classes.end(); ++it) {
            delete it->second;
        }
        classes.clear();
        puts("");
    }
    assert(fgets(buf, sizeof(buf), stdin) == NULL);
/*
printf("class_defined = %d\n", class_defined);
printf("class_parent_error = %d\n", class_parent_error);
printf("class_no_parent = %d\n", class_no_parent);
printf("class_with_parent = %d\n", class_with_parent);
printf("def_method = %d\n", def_method);
printf("redef_method = %d\n", redef_method);
printf("undef_method = %d\n", undef_method);
printf("def_no_class = %d\n", def_no_class);
printf("undef_no_class = %d\n", undef_no_class);
printf("undef_no_method = %d\n", undef_no_method);
printf("call_no_class = %d\n", call_no_class);
printf("call_no_method = %d\n", call_no_method);
printf("call_ok = %d\n", call_ok);
printf("call_redirect_ok = %d\n", call_redirect_ok);
*/
    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//213   2011-04-03 01:07:46     Accepted    D   C++     110     444     watashi     Source

// 2012-09-07 16:00:21 | Accepted | 3480 | C++ | 60 | 444 | watashi | Source
