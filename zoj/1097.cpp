//规模大要用c_str，而且要优先队列~
//可以改造一下
#include <set>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;
class Node
{
friend class Prufer;
private:
    set<int> edges;
};
class Prufer
{
private:
    static const int MAXN = 55;
    static const int MAXL = 256;
    Node node[MAXN];
    vector<int> code;
    void clear()
    {
        for (int i = 0; i < MAXN; i++)
            node[i].edges.clear();
        code.clear();
    }
    void setup(string str, int pre)
    {
        istringstream iss(str);
        iss.get();
        int tmp;
        iss >> tmp;
        if(pre != -1) {
            node[pre].edges.insert(tmp);
            node[tmp].edges.insert(pre);
        }
        while(true) {
            char ch;
            while((ch = iss.get()) == ' ');
            if(ch != '(') break;
            int cnt = 1;
            string cur = "(";
            do {
                ch = iss.get();
                if(ch == '(') cnt++;
                else if(ch == ')') cnt--;
                cur += ch;
            }while(cnt);
            setup(cur, tmp);
        }
    }
    void codeit()
    {
        while(true) {
            int i;
            for (i = 1; i < MAXN; i++) {
                if(node[i].edges.size() == 1) {
                    int j = *node[i].edges.begin();
                    code.push_back(j);
                    node[i].edges.erase(j);
                    node[j].edges.erase(i);
                    break;
                }
            }
            if (i == MAXN) break;
        }
    }
public:
    friend inline istream& operator>>(istream& is, Prufer& that)
    {
        that.clear();
        string cur;
        getline(cin, cur);
        that.setup(cur, -1);
        return is;
    }
    friend inline ostream& operator<<(ostream& os, const Prufer& that)
    {
        Prufer it = that;
        it.codeit();
        for (vector<int>::iterator itr = it.code.begin(); itr != it.code.end(); itr++){
            if(itr != it.code.begin()) os << " ";
            os << *itr;
        }
        return os;
    }
};
int main()
{
    Prufer prufer;
    while(cin >> prufer)
        cout << prufer << endl;
    return 0;
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2715749 2007-12-29 07:58:05 Accepted 1097 C++ 00:00.03 900K わたし

// 2012-09-07 00:36:39 | Accepted | 1097 | C++ | 10 | 188 | watashi | Source
