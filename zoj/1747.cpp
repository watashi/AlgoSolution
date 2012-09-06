#include <set>
#include <map>
#include <cctype>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

const int SS = 1, MM = 60 * SS, HH = 60 * MM, DD = 24 * HH, TEN = 10;
const int DIFF = 6 * HH;

inline int CharToInt(const char ch)
{
    return ch - '0';
}

inline int TimeToInt(const char* const Time)
{
    return  CharToInt(Time[0]) * TEN * DD + CharToInt(Time[1]) * DD +
        CharToInt(Time[3]) * TEN * HH + CharToInt(Time[4]) * HH +
        CharToInt(Time[6]) * TEN * MM + CharToInt(Time[7]) * MM +
        CharToInt(Time[9]) * TEN * SS + CharToInt(Time[10]) * SS;
}

inline void ToLower(string& str)
{
    for (size_t i = 0; i < str.length(); i++)
        if(isupper(str[i]))
            str[i] = tolower(str[i]);
}

struct Address
{
    const string topDomain;
    const string Domain;
    map<string, pair<int, pair<int, int> > >* const Records;
    Address(const string& atopDomain, const string& aDomain) : topDomain(atopDomain), Domain(aDomain),
        Records(new map<string, pair<int, pair<int ,int> > >)
    {
    }
    ~Address()
    {
        delete Records;
    }
    bool operator<(const Address& rhs) const
    {
        if(topDomain == rhs.topDomain)
            return Domain < rhs.Domain;
        else
            return topDomain < rhs.topDomain;
    }
    void insert(const string& cur, const int atime) const
    {
        map<string, pair<int, pair<int, int> > >::iterator it = Records->find(cur);

        if(it == Records->end())
            (*Records)[cur] = make_pair(atime, make_pair(1, 0));
        else if(atime < it->second.first + DIFF)
            ++it->second.second.second;
        else {
            ++it->second.second.first;
            it->second.first = atime;
        }
    }
    void show() const
    {
        printf("Second level domain = %s\n", Domain.c_str());
        for (map<string, pair<int, pair<int, int> > >::const_iterator it = Records->begin(); it != Records->end(); ++it)
            printf("%-65s%4d%4d\n", it->first.c_str(), it->second.second.first, it->second.second.second);
    }
};

char buf[88];

int main(void)
{
    string::size_type pre, pos;
    int atime;
    string cur, topDomain, Domain;
    Address *add;
    set<Address> st;
    set<Address>::iterator it;

    while(gets(buf)) {
        if(buf[0] == '3' && buf[1] == '2')
            break;

        atime = TimeToInt(buf);
        cur = string(buf + 12);
        ToLower(cur);
        pre = cur.rfind('.');
        topDomain = cur.substr(pre + 1);
        pos = cur.rfind('.', pre - 1);
        if(pos == string::npos)
            pos = cur.rfind('@', pre - 1);
        else
            pos = max(pos, cur.rfind('@', pre - 1)); // WA // @@
        Domain = cur.substr(pos + 1, pre - pos - 1);
        add = new Address(topDomain, Domain);
        //printf("%s %s %s\n", topDomain.c_str(), Domain.c_str(), cur.c_str());
        it = st.find(*add);
        if(it == st.end()) {
            st.insert(*add);
            it = st.find(*add);
        }
        else {
            delete add;
            add = NULL;
        }
        it->insert(cur, atime);
    }

    //printf("why?");
    topDomain = "";
    for (it = st.begin(); it != st.end(); ++it) {
        if(it->topDomain != topDomain) {
            topDomain = it->topDomain;
            if(it != st.begin())
                puts("\n");
            printf("TOP-LEVEL DOMAIN = %s\n", topDomain.c_str());
        }
        else if(it != st.begin())
            puts("");
        it->show();
    }

    return 0;
}

//2838895   2008-04-11 21:43:44     Accepted    1747    C++     00:00.23    1000K   わたし

/*
Rank    Submit time     Run time    Run memory      Language    User
1   2008-04-11 21:43:44     00:00.23    1000K   C++     わたし
2   2006-02-02 10:13:45     00:00.29    528K    C++     wcm
3   2005-09-13 22:07:19     00:00.30    480K    C   Leave me alone
4   2006-06-17 00:07:34     00:00.40    976K    C++     neal
*/

// 2012-09-07 00:59:49 | Accepted | 1747 | C++ | 100 | 312 | watashi | Source
