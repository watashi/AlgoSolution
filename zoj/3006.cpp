#include <map>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#pragma warning(disable:4996)

#if 0
#   ifdef NDEBUG
#   undef NDEBUG
#   endif
#else
#   ifndef NDEBUG
#   define NDEBUG
#   endif
#endif

class Hasher
{
private:
#ifndef NDEBUG
    string buf;
#endif
    unsigned int hashVal, i;
    inline void hash(char ch)
    {
#ifndef NDEBUG
        buf += ch;
#endif
        hashVal += ch * (i++);
        hashVal %= 0x8000000B;
        hashVal *= 0xFFFFFFEF;
    }

public:
    Hasher()
    {
        reset();
    }
    void reset()
    {
#ifndef NDEBUG
        buf = "";
#endif
        hashVal = 0;
        i = 1;
    }
    inline unsigned int operator()() const
    {
        return hashVal;
    }
    inline unsigned int operator()(const char* p)
    {
        while (*p != '\\' && *p != '\0') {
            hash(*p++);
        }
        hash('\n');

        return hashVal;
    }
    inline unsigned int operator()(size_t c, char ch = '\t')
    {
        while (c--) {
            hash(ch);
        }

        return hashVal;
    }
#ifndef NDEBUG
    string str() const
    {
        return buf;
    }
#endif
};

struct Dir
{
    size_t pos;
    string name;
    vector<string> file;
    bool in(const string& path) const
    {
        return strncmp(name.c_str(), path.c_str() + pos, name.length()) == 0;
    }
};

vector<string> path;
vector<Dir> dir;
Hasher hasher;

int main(void)
{
    int n;
    size_t p, l, c;
    static char buf[1024];

//  freopen("input", "r", stdin);
    while (scanf("%d", &n) != EOF) {
        gets(buf);
        path.resize(n);
        for (int i = 0; i < n; i++) {
            gets(buf);
            path[i] = buf;
        }
        sort(path.begin(), path.end());
        hasher.reset();
        hasher("root");
        dir.clear();
        dir.push_back(Dir());
        for (int i = 0; i < n; i++) {
            p = 0;
            c = 1;
            while (c < dir.size() && dir[c].in(path[i])) {
                p += dir[c++].name.length();
            }
            while (dir.size() > c) {
                for (size_t j = 0; j < dir.back().file.size(); j++) {
                    hasher(dir.size());
                    hasher(dir.back().file[j].c_str());
                }
                dir.pop_back();
            }
            do {
                l = p;
                while (l < path[i].length() && path[i][l] != '\\') {
                    ++l;
                }
                if (l == path[i].length()) {
                    dir.back().file.push_back(path[i].substr(p));
                }
                else {
                    hasher(dir.size());
                    dir.push_back(Dir());
                    dir.back().pos = p;
                    dir.back().name = path[i].substr(p, l - p + 1);
                    hasher(dir.back().name.c_str());
                }
                p = l + 1;
            } while (p < path[i].length());
        }
        while (dir.size() > 0) {
            for (size_t j = 0; j < dir.back().file.size(); j++) {
                hasher(dir.size());
                hasher(dir.back().file[j].c_str());
            }
            dir.pop_back();
        }
        //printf("########\n%s########\n", hasher.str().c_str());
        printf("%u\n", hasher());
    }

    return 0;
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//3010678   2008-07-28 16:27:05     Accepted    3006    C++     00:00.61    3348K   Re:ReJudge
//3010677   2008-07-28 16:26:55     Accepted    3006    C++     00:00.63    3352K   Re:ReJudge

/*
#include <map>
#include <cstdio>
#include <string>

using namespace std;

#pragma warning(disable:4996)

#if 0
#   ifdef NDEBUG
#   undef NDEBUG
#   endif
#else
#   ifndef NDEBUG
#   define NDEBUG
#   endif
#endif

class Hasher
{
private:
#ifndef NDEBUG
    string buf;
#endif
    unsigned int hashVal, i;
    inline void hash(char ch)
    {
#ifndef NDEBUG
        buf += ch;
#endif
        hashVal += ch * (i++);
        hashVal %= 0x8000000B;
        hashVal *= 0xFFFFFFEF;
    }

public:
    Hasher()
    {
        reset();
    }
    void reset()
    {
#ifndef NDEBUG
        buf = "";
#endif
        hashVal = 0;
        i = 1;
    }
    inline unsigned int operator()() const
    {
        return hashVal;
    }
    inline unsigned int operator()(const char* p)
    {
        if (*p == '\0') {
            ++p;
        }
        while (*p) {
            hash(*p++);
        }
        hash('\n');

        return hashVal;
    }
    inline unsigned int operator()(int c, char ch = '\t')
    {
        while (c--) {
            hash(ch);
        }

        return hashVal;
    }
#ifndef NDEBUG
    string str() const
    {
        return buf;
    }
#endif
};

class DirTree
{
    class __dir_tree_node
    {
        friend class DirTree;
    private:
        map<string, __dir_tree_node*> dirs;
    public:
        __dir_tree_node* add(const string& name)
        {
            map<string, __dir_tree_node*>::iterator it = dirs.find(name);

            if (it == dirs.end()) {
                return dirs[name] = new __dir_tree_node();
            }
            else {
                return it->second;
            }
        }
    };

private:
    __dir_tree_node root;
    Hasher hasher;
    int level;
    void dfs(__dir_tree_node* p)
    {
        for (map<string, __dir_tree_node*>::const_iterator i = p->dirs.begin(); i != p->dirs.end(); ++i) {
            hasher(level);
            hasher(i->first.c_str());
            ++level;
            dfs(i->second);
            delete i->second;
            --level;
        }
        p->dirs.clear();
    }

public:
    ~DirTree()
    {
        dfs(&root);
    }
    void add(const char* p)
    {
        const char* pc;
        __dir_tree_node* pn = &root;

        do {
            pc = p;
            do {
                ++p;
            } while (*p != '\\' && *p != '\0');
            if (*p == '\\') {
                pn = pn->add('\0' + string(pc, p));
                ++p;
            }
            else {
                pn = pn->add(string(pc, p));
            }
        } while (*p != '\0');
    }
    unsigned int hash()
    {
        hasher.reset();
        hasher("root");
        level = 1;
        dfs(&root);
#ifndef NDEBUG
        printf("########\n%s########\n", hasher.str().c_str());
#endif
        return hasher();
    }
};

int main(void)
{
    int n;
    static char buf[1024];

    freopen("input", "r", stdin);
    while (scanf("%d", &n) != EOF) {
        DirTree dirTree;

        gets(buf);
        for (int i = 0; i < n; i++) {
            gets(buf);
            dirTree.add(buf);
        }
        printf("%u\n", dirTree.hash());
    }

    return 0;
}

// TLE

// so xe, too naive

*/

// 2012-09-07 01:54:16 | Accepted | 3006 | C++ | 260 | 1500 | watashi | Source
