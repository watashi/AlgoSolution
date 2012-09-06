#include <set>
#include <map>
#include <vector>
#include <string>
#include <cctype>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(void)
{
    int k, p = 0, n, m;
    char cId[20], cTitle[80];
    string sId, sTitle;
    map<string, int> id, title;
    map<string, int>::iterator it;
    vector<int> del, exp, num, post_id, post_title;
    vector<set<int> > id_post, title_post;
    set<int>::iterator itr, begin, end;

    while(scanf("%d", &n) != EOF && n > 0) {
        id.clear();
        id_post.clear();
        title.clear();
        title_post.clear();
        exp.clear();
        num.resize(n);
        post_id.resize(n);
        post_title.resize(n);
        for (int i = 0; i < n; i++)
            num[i] = i;

        for (int i = 0; i < n; i++) {
            scanf(" %s %*s %[^\n] ", cId, cTitle);
            sId = cId;
            sTitle = cTitle;

            it = id.find(sId);
            if(it == id.end()) {
                k = id.size();
                id[sId] = k;
                id_post.push_back(set<int>());
                exp.push_back(50);
            }
            else k = it->second;
            id_post[k].insert(i);
            post_id[i] = k;

            it = title.find(sTitle);
            if(it == title.end()) {
                k = title.size();
                title[sTitle] = k;
                title_post.push_back(set<int>());
            }
            else k = it->second;
            title_post[k].insert(i);
            post_title[i] = k;
        }

        scanf("%d", &m);
        while(m--) {
            scanf("%s", cId);
            if(isdigit(cId[0])) {
                k = atoi(cId) - 1;
                scanf("%s", cTitle);
                if(k >= (int)num.size()) {
                    printf("0\n");
                    continue;
                }
                del.clear();
                //
                if(cTitle[2] == '1') p = -1;
                else if(cTitle[2] == '6') p = -2;
                if(cTitle[1] == '1') {
                    end = title_post[post_title[num[k]]].end();
                    if(cTitle[3] == 'y') {
                        begin = title_post[post_title[num[k]]].begin();
                    }
                    else if(cTitle[3] == 'n') {
                        begin = title_post[post_title[num[k]]].find(num[k]);
                    }
                }
                else if(cTitle[1] == '2') {
                    end = id_post[post_id[num[k]]].end();
                    if(cTitle[3] == 'y') {
                        begin = id_post[post_id[num[k]]].begin();
                    }
                    else if(cTitle[3] == 'n') {
                        begin = id_post[post_id[num[k]]].find(num[k]);
                    }
                }
                //
                for(itr = begin; itr != end; ++itr)
                    del.push_back(*itr);
                printf("%d\n", del.size());
                k = -1;
                for (size_t i = 0; i < del.size(); i++) {
                    while(num[++k] < del[i])
                        num[k - i] = num[k];
                    exp[post_id[del[i]]] += p;
                    id_post[post_id[del[i]]].erase(del[i]);
                    title_post[post_title[del[i]]].erase(del[i]);
                }
                while(++k < (int)num.size())
                    num[k - del.size()] = num[k];
                num.erase(num.end() - del.size(), num.end());
                //
            }
            else {
                sId = cId;
                it = id.find(sId);
                if(it == id.end())
                    printf("not exist\n");
                else
                    printf("%d\n", exp[it->second]);
            }
        }
        printf("\n");
    }

    return 0;
}

//2839722   2008-04-12 12:45:02     Accepted    2732    C++     00:00.04    1000K   Re:ReJudge

// 2012-09-07 01:36:48 | Accepted | 2732 | C++ | 10 | 312 | watashi | Source
