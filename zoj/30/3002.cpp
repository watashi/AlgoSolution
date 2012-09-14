#include <map>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

vector<vector<int> > dependency;
map<string, int> s2i, p2i;
vector<string> i2s, i2p;
vector<int> sc, pc;

void install(int id, bool show = false)
{
    if (sc[id] > 0) {
        if (show) {
            printf("%s has been already installed\n", i2s[id].c_str());
        }
        return;
    }
    ++sc[id];
    if (show) {
        printf("install");
    }
    for (size_t i = 0; i < dependency[id].size(); i++) {
        if (dependency[id][i] < 0) {
            if (sc[-1 - dependency[id][i]] == 0) {
                install(-1 - dependency[id][i]);
                if (show) {
                    printf(" %s", i2s[-1 - dependency[id][i]].c_str());
                }
            }
            ++sc[-1 - dependency[id][i]];
        }
        else {
            if (pc[dependency[id][i]] == 0) {
                if (show) {
                    printf(" %s", i2p[dependency[id][i]].c_str());
                }
            }
            ++pc[dependency[id][i]];
        }
    }
    if (show) {
        printf("\n");
    }
}

void uninstall(int id, bool show = false)
{
    if (sc[id] == 0) {
        if (show) {
            printf("%s has been already uninstalled\n", i2s[id].c_str());
        }
        return;
    }
    if (sc[id] > 1) {
        if (show) {
            printf("uninstall failed: %s is used by other software\n", i2s[id].c_str());
        }
        return;
    }
    --sc[id];
    if (show) {
        printf("uninstall");
    }
    for (size_t i = 0; i < dependency[id].size(); i++) {
        if (dependency[id][i] < 0) {
            --sc[-1 - dependency[id][i]];
        }
        else {
            if (pc[dependency[id][i]] == 1) {
                if (show) {
                    printf(" %s", i2p[dependency[id][i]].c_str());
                }
            }
            --pc[dependency[id][i]];
        }
    }
    if (show) {
        printf("\n");
    }
}

int main(void)
{
    static char ch, buf[256];
    int ri = 0, ns, np, n;

    while (scanf("%d", &ns) != EOF) {
        s2i.clear();
        i2s.resize(ns);
        sc.resize(ns);
        for (int i = 0; i < ns; i++) {
            scanf("%s", buf);
            s2i[buf] = i;
            i2s[i] = buf;
            sc[i] = 0;
        }
        scanf("%d", &np);
        p2i.clear();
        i2p.resize(np);
        pc.resize(np);
        for (int i = 0; i < np; i++) {
            scanf("%s", buf);
            p2i[buf] = i;
            i2p[i] = buf;
            pc[i] = 0;
        }
        dependency.resize(ns);
        for (int i = 0; i < ns; i++) {
            scanf("%d", &n);
            dependency[i].resize(n);
            for (int j = 0; j < n; j++) {
                scanf("%s", buf);
                dependency[i][j] = ((s2i.find(buf) == s2i.end()) ? p2i[buf] : (-1 - s2i[buf]));
            }
        }
        scanf("%d", &n);
        printf("case %d:\n", ++ri);
        while (n--) {
            scanf(" %c%*s%s", &ch, buf);
            if (s2i.find(buf) == s2i.end()) {
                printf("%s is not found\n", buf);
            }
            else if (ch == 'i') {
                install(s2i[buf], true);
            }
            else {
                uninstall(s2i[buf], true);
            }
        }
        putchar('\n');
    }

    return 0;
}

//3016518 2008-08-01 14:21:58 Accepted 3002 C++ 00:00.13 896K Re:ReJudge

// 2012-09-07 01:53:52 | Accepted | 3002 | C++ | 50 | 180 | watashi | Source
