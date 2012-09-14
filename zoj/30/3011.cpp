#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

class TreeFormatConverter
{
private:
    enum __format
    {
        CL,     //Children list
        PS,     //Parent sequence
        PP,     //Preorder and postorder sequences
        PD,     //Preorder and depth sequence
        PL,     //Parentheses language
        PC      //Parentheses and commas
    };
public:
    typedef __format Format;
private:
    char ch;
    int p, c, n;
    int *pre, *post, *index;
protected:
    static const int MAXN = 32768;
    int root;
    vector<int> parent;
    vector<vector<int> > child;
    FILE* fp;
private:
    void clear();
    void readCL();
    void readPS();
    void readPP();
    void readPD();
    int readPL();
    int readPC();
    void writeCL(int node);
    void writePS(int node);
    void writePP();
    void writePre(int node);
    void writePost(int node);
    void writePD(int node, int depth);
    void writePL(int node);
    void writePC(int node);
    int buildPP(int prel, int prer, int postl);
public:
    TreeFormatConverter();
    ~TreeFormatConverter();
    void read(Format format, FILE* fin = stdin);
    void write(Format format, FILE* fout = stdout);
    static Format toFormat(const char* str);
};

TreeFormatConverter::TreeFormatConverter()
: parent(MAXN), child(MAXN)
{
    fp = NULL;
    pre = new int[MAXN];
    post = new int[MAXN];
    index = new int[MAXN];
    clear();
}

TreeFormatConverter::~TreeFormatConverter()
{
    delete[] pre;
    delete[] post;
    delete[] index;
}

void TreeFormatConverter::read(Format format, FILE* fin)
{
    clear();
    fp = fin;
    switch (format)
    {
    case CL: readCL(); break;
    case PS: readPS(); break;
    case PP: readPP(); break;
    case PD: readPD(); break;
    case PL: while (fgetc(fp) != '('); root = readPL(); break;
    case PC: root = readPC(); break;
    }
    fp = NULL;
}

void TreeFormatConverter::write(Format format, FILE* fout)
{
    fp = fout;
    switch (format)
    {
    case CL: writeCL(root); fputs("-1\n", fp); break;
    case PS: writePS(root); fputs("-1\n", fp); break;
    case PP: writePP(); break;
    case PD: writePD(root, 0); fputs("-1\n", fp); break;
    case PL: fputc('(', fp); writePL(root); fputc('\n', fp); break;
    case PC: writePC(root); fputc('\n', fp); break;
    }
    fp = NULL;
}

void TreeFormatConverter::clear()
{
    root = -1;
    for (int i = 0; i < MAXN; i++) {
        parent[i] = -1;
        child[i].clear();
    }
}

//Children list
void TreeFormatConverter::readCL()
{
    while (fscanf(fp, "%d", &p) != EOF && p != -1) {
        if (root == -1) {
            root = p;
        }
        fscanf(fp, "%d", &n);
        while (n--) {
            fscanf(fp, "%d", &c);
            parent[c] = p;
            child[p].push_back(c);
        }
    }
}

void TreeFormatConverter::writeCL(int node)
{
    if (node != root && child[node].size() == 0) { //There's a line for the *root* and each internal node
        return;
    }
    fprintf(fp, "%d %u", node, child[node].size());
    for (size_t i = 0; i < child[node].size(); i++) {
        fprintf(fp, " %d", child[node][i]);
    }
    fprintf(fp, "\n");
    for (size_t i = 0; i < child[node].size(); i++) {
        writeCL(child[node][i]);
    }
}

//Parent sequence
void TreeFormatConverter::readPS()
{
    while (fscanf(fp, "%d", &c) != EOF && c != -1) {
        fscanf(fp, "%d", &p);
        if (p == -1) {
            root = c;
        }
        else {
            parent[c] = p;
            child[p].push_back(c);
        }
    }
}

void TreeFormatConverter::writePS(int node)
{
    fprintf(fp, "%d %d\n", node, parent[node]);
    for (size_t i = 0; i < child[node].size(); i++) {
        writePS(child[node][i]);
    }
}

//Preorder and postorder sequences
void TreeFormatConverter::readPP()
{
    for (int i = 0; fscanf(fp, "%d", &pre[i]) != EOF && pre[i] != -1; i++);
    for (int i = 0; fscanf(fp, "%d", &post[i]) != EOF && post[i] != -1; i++) {
        index[post[i]] = n = i;
    }
    root = buildPP(0, n, 0);
}

int TreeFormatConverter::buildPP(int prel, int prer, int postl)
{
    int ret = pre[prel];

    for (int i = prel + 1; i <= prer; i = n + 1) {
        n = i + index[pre[i]] - postl;
        c = buildPP(i, n, postl);
        parent[c] = ret;
        child[ret].push_back(c);
        postl = index[pre[i]] + 1;
    }

    return ret;
}

void TreeFormatConverter::writePP()
{
    bool blank;

    writePre(root);
    fputs("-1\n", fp);
    writePost(root);
    fputs("-1\n", fp);
}

void TreeFormatConverter::writePre(int node)
{
    fprintf(fp, "%d ", node);
    for (size_t i = 0; i < child[node].size(); i++) {
        writePre(child[node][i]);
    }
}

void TreeFormatConverter::writePost(int node)
{
    for (size_t i = 0; i < child[node].size(); i++) {
        writePost(child[node][i]);
    }
    fprintf(fp, "%d ", node);
}

//Preorder and depth sequence
void TreeFormatConverter::readPD()
{
    while(fscanf(fp, "%d", &p) != EOF && p != -1) {
        fscanf(fp, "%d", &c);
        index[c] = p;
        if (c == 0) {
            root = p;
        }
        else {
            parent[index[c]] = index[c - 1];
            child[index[c - 1]].push_back(index[c]);
        }
    }
}

void TreeFormatConverter::writePD(int node, int depth)
{
    fprintf(fp, "%d %d\n", node, depth);
    for (size_t i = 0; i < child[node].size(); i++) {
        writePD(child[node][i], depth + 1);
    }
}

//Parentheses language
int TreeFormatConverter::readPL()
{
    int ret;

    fscanf(fp, "%d", &ret);
    while (fscanf(fp, " %c", &ch) != EOF && ch == '(') {
        c = readPL();
        parent[c] = ret;
        child[ret].push_back(c);
    }

    return ret;
}

void TreeFormatConverter::writePL(int node)
{
    fprintf(fp, "%d", node);
    for (size_t i = 0; i < child[node].size(); i++) {
        fprintf(fp, " (");
        writePL(child[node][i]);
    }
    fprintf(fp, ")");
}

//Parentheses and commas
int TreeFormatConverter::readPC()
{
    static char buf[16];
    int ret;

    fscanf(fp, "%d", &ret);
    if (fscanf(fp, "%[ (]", buf) == 1) {
        do {
            c = readPC();
            parent[c] = ret;
            child[ret].push_back(c);
        } while (fscanf(fp, "%[ ,]", buf) == 1);
        while (fgetc(fp) != ')');
    }

    return ret;
}

void TreeFormatConverter::writePC(int node)
{
    fprintf(fp, "%d", node);
    if (child[node].size() == 0) {
        return;
    }
    fprintf(fp, " (");
    for (size_t i = 0; i < child[node].size(); i++) {
        if (i > 0) {
            fprintf(fp, ", ");
        }
        writePC(child[node][i]);
    }
    fprintf(fp, ")");
}

//

TreeFormatConverter::Format TreeFormatConverter::toFormat(const char* str)
{
    const static char* pf[] = {"CL", "PS", "PP", "PD", "PL", "PC"};
    const static TreeFormatConverter::Format f[] = {CL, PS, PP, PD, PL, PC};

    for (int i = 0; i < sizeof(pf) / sizeof(char*); i++) {
        if (strcmp(str, pf[i]) == 0) {
            return f[i];
        }
    }
}

int main(void)
{
    static char from[16], to[16];
    bool blank = false;
    typedef TreeFormatConverter TFC;
    TFC tfc;

    while (scanf("%s -> %s", from, to) != EOF) {
        if (blank) {
            putchar('\n');
        }
        else {
            blank = true;
        }
        tfc.read(TFC::toFormat(from));
        tfc.write(TFC::toFormat(to));
    }

    return 0;
}

// fputs不会自己换行

/*
CL -> PS
1 2 2 3
2 2 4 5
3 1 6
-1
PP -> PD
1 2 4 5 3 6 -1
4 5 2 6 3 1 -1
PL -> PC
(1 (2 (4) (5)) (3 (6)))
PS -> CL
1 -1
2 1
4 2
5 2
3 1
6 3
-1
PD -> PP
1 0
2 1
4 2
5 2
3 1
6 2
-1
PC -> PL
1 (2 (4, 5), 3 (6))
PP -> PS
1 -1
1 -1
PP -> PD
1 -1
1 -1
PL -> PC
(1)
PS -> CL
1 -1
-1
PD -> PP
1 0
-1
PC -> PL
1
*/

/*
PC -> CL
0
*/

//3015994   2008-08-01 00:02:21     Accepted    3011    C++     00:00.56    1764K   Re:ReJudge

// 2012-09-07 01:54:47 | Accepted | 3011 | C++ | 130 | 1624 | watashi | Source
