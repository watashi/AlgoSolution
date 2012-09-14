#include <set>
#include <list>
#include <cstdio>
#include <string>
using namespace std;
inline int char2int(const char ch)
{
    return ch - 'a';
}
inline int str2begin(const string &str)
{
    return char2int(str[0]);
}
inline int str2end(const string &str)
{
    return char2int(str[str.length() - 1]);
}
list<string> findEuler(int b, int e, set<string> st[26])
{
    list<string> res;
    if (st[b].empty()) return res;
    int tmp = b;
    do {
        set<string>::iterator itr = st[tmp].begin();
        res.push_back(*itr);
        tmp = str2end(*itr);
        st[str2begin(*itr)].erase(itr);
    }while(tmp != e);
    // choose the right method to add the list is important
    list<string>::iterator itr = res.end();
    while (itr != res.begin()){
        list<string>::iterator post = itr;
        --itr;
        int cur = str2end(*itr);
        list<string> lt = findEuler(cur, cur, st);
        res.insert(post, lt.begin(), lt.end());
    }
    itr = res.begin();
    int cur = str2begin(*itr);
    list<string> lt = findEuler(cur, cur, st);
    res.insert(itr, lt.begin(), lt.end());
    return res;
}
int main()
{
    int re;
    scanf("%d", &re);
    while(re--){
        int n;
        scanf("%d", &n);
        set<string> st[26];
        int in[26] = {0}, out[26] = {0};
        while(n--){
            char str[22];
            scanf("%s", str);
            string cur(str);
            st[str2begin(str)].insert(str);
            in[str2begin(str)]++;
            out[str2end(str)]++;
        }
        int f = -1, t = -1;
        for (int i = 0; i < 26; i++){
            switch(in[i] - out[i]){
            case 1: f = (f == -1) ? i : 26; break;
            case 0: break;
            case -1: t = (t == -1) ? i : 26; break;
            default: f = t = 26; break;
            }
        }
        if (f == -1 && t == -1){
            for (int i = 0; i < 26; i++)
                if(in[i] && out[i]){
                    f = t = i;
                    break;
                }
        }
        if (f == -1 || t == -1 || f == 26 || t == 26){
            printf("***\n");
        }
        else {
            list<string> ans = findEuler(f, t, st);
            bool flag = true;
            for (int i = 0; i < 26; i++){
                if(!st[i].empty()){
                    flag = false;
                    break;
                }
            }
            if (flag == true){
                for (list<string>::iterator itr = ans.begin(); itr != ans.end(); ++itr){
                    if (itr != ans.begin()) putchar('.');
                    printf("%s", (*itr).c_str());
                }
                putchar('\n');
            }
            else{
                printf("***\n");
            }
        }
    }
}
//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2707784   2007-12-20 22:35:44     Accepted    1919    C++     00:00.06    992K    ¤ï¤¿¤·

// 2012-09-07 01:06:19 | Accepted | 1919 | C++ | 30 | 180 | watashi | Source
