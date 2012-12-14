#include <cctype>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int vTab;

inline int _C(int a, int b) {
    static int v[] = {1, 1, 0, 1};
    return v[(a << 1) ^ b];
}

inline int _D(int a, int b) {
    static int v[] = {1, 1, 1, 0};
    return v[(a << 1) ^ b];
}

inline int _E(int a, int b) {
    static int v[] = {1, 0, 0, 1};
    return v[(a << 1) ^ b];
}

struct Node {
    char c;
    const Node *l, *r;
    int eval() const {
        switch (c) {
        case 'C': return _C(l->eval(), r->eval());
        case 'N': return 1 - l->eval();
        case 'K': return l->eval() && r->eval();
        case 'A': return l->eval() || r->eval();
        case 'D': return _D(l->eval(), r->eval());
        case 'E': return _E(l->eval(), r->eval());
        case 'J': return l->eval() ^ r->eval();
        default:/* putchar(c);*/ return ((1 << (c - 'a')) & vTab) == 0 ? 0 : 1;
        }
    }
};

int end;
Node mem[1024];
int id;
char mp[128];

char getId(char ch) {
    if (mp[ch] == '\0') {
        mp[ch] = 'a' + id++;
    }
   // printf("[%c] -> [%c]\n", ch, mp[ch]);
    return mp[ch];
}

Node* readNode(char*&p) {
    Node* ret = &mem[end++];
    if (islower(*p)) {
        ret->c = getId(*p);
        ++p;
    } else {
        ret->c = *p;
        switch (*p) {
            case 'N':
                ret->l = readNode(++p);
                break;
            case 'C':
            case 'K':
            case 'A':
            case 'D':
            case 'E':
            case 'J':
                ++p;
                ret->l = readNode(p);
                ret->r = readNode(p);
                break;
            case '\0': throw string("insufficient operands");
            default: throw string("invalid character");
        }
    }
    return ret;
}

int main() {
    char buf[1024], *p;

    // freopen("g.in", "r", stdin);
    while (gets(buf) != NULL && isalnum(buf[0])) {
        printf("%s is ", buf);
        try {
            memset(mp, 0, sizeof(mp));
            end = id = 0;
            Node* root = readNode(p = buf);
            if (*p != '\0') {
                throw string("extraneous text");
            }
            int c[2] = {1, 1};
            for (vTab = 0; (c[0] || c[1]) && vTab < (1 << id); ++vTab) {
           //     printf("%d->%d\n", vTab, root->eval());
                c[root->eval()] = 0;
            }
            printf("valid: ");
            if (c[0]) {
                puts("tautology");
            } else if (c[1]) {
                puts("contradiction");
            } else {
                puts("contingent");
            }
        } catch (string e) {
            puts(("invalid: " + e).c_str());
        }
    }

    return 0;
}
//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//727367  	2011-01-29 12:25:59 	Accepted	0.002	Minimum	26909	C++	4437 - Symbolic Logic Mechanization
/*
id => 1174031
pid => 4437
pname => Symbolic Logic Mechanization
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:12:55
*/
