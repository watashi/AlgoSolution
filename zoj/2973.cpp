#include <vector>
#include <string>
#include <cctype>
#include <cstdio>
#include <cstring>
using namespace std;

#define TAGID "[^> ]"
#define ATTID "[^=]"
#define DATASTR "[^<]"
#define NOREPLY "__NOREPLY__@#"

#pragma warning(disable:4996)

class Random
{
public:
    Random() : nextNum(1)
    {

    }
    int operator()()
    {
        nextNum = (nextNum * 32771 + 12347) % 32768;
        return nextNum;
    }
private:
    int nextNum;
};

string toLower(const string& str)
{
    string ret = "";

    for (size_t i = 0; i < str.size(); ++i)
        ret += tolower(str[i]);

    return ret;
}

class Rule
{
public:
    Rule(FILE* myin)
    {
        constructor(myin);
    }
    bool isDefault() const
    {
        return _isDefault;
    }
    int getInterval() const
    {
        return interval;
    }
    int getWait() const
    {
        return wait;
    }
    string getKey() const
    {
        return key;
    }
    size_t size() const
    {
        return reply.size();
    }
    string operator[](int i) const
    {
        return reply[i];
    }
private:
    void constructor(FILE* myin)
    {
        static char buf[256]; // 555 128 RE + 1
        static int tmp;

        fscanf(myin, " <%"TAGID, buf);
        _isDefault = (strcmp(buf, "default") == 0);
        interval = wait = -1;
        while(fgetc(myin) == ' ') {
            fscanf(myin, " %"ATTID"=\"%d\"", buf, &tmp);
            if(strcmp(buf, "interval") == 0)
                interval = tmp;
            if(strcmp(buf, "wait") == 0)
                wait = tmp;
        }
        while(fscanf(myin, " %"TAGID, buf) != EOF && strcmp(buf, "</rule") && strcmp(buf, "</default")) {
            if(strcmp(buf, "<keyword") == 0) {
                fscanf(myin, ">%"DATASTR"</keyword>", buf);
                key = toLower(buf);
            }
            else if(strcmp(buf, "<reply") == 0) {
                fscanf(myin, ">%"DATASTR"</reply>", buf);
                reply.push_back(buf);
            }
            else if(strcmp(buf, "<noreply") == 0){
                fscanf(myin, " />");
                reply.push_back(NOREPLY);
            }
        }
        fgetc(myin);
    }
    bool _isDefault;
    int interval, wait;
    string key;
    vector<string> reply;
};

class Config
{
public:
    Config(FILE* myin)
    {
        constructor(myin);
    }
    int getInterval() const
    {
        return rules.back().getInterval();
    }
    int getWait() const
    {
        return rules.back().getWait();
    }
    const Rule* getRule(const string& msg) const
    {
        string pat = toLower(msg);

        for (size_t i = 0; i < rules.size() - 1; ++i)
            if(pat.find(rules[i].getKey()) != string::npos)
                return &rules[i];

        return &rules.back();
    }
private:
    void constructor(FILE* myin)
    {
        fscanf(myin, " <config>");
        do {
            rules.push_back(Rule(stdin));
        } while(!rules.back().isDefault());
        fscanf(myin, " </config>");
    }
    vector<Rule> rules;
};

class PouringRobot
{
public:
    PouringRobot(const Config* config, FILE* myout) : config(config), lastTime(-1), myout(myout)
    {

    }
    ~PouringRobot()
    {
        delete config;
    }
    void doit(const string& msg, int tim)
    {
        const Rule *rule = config->getRule(msg);
        int interval = rule->getInterval(), wait = rule->getWait(), r;

        if(interval == -1)
            interval = config->getInterval();
        if(wait == -1)
            wait = config->getWait();
        if(tim + wait < lastTime)
            return;
        if(rule->size() == 1)
            r = 0;
        else
            r = genRand() % (int)rule->size();
        if((*rule)[r] == NOREPLY)
            return;
        else {
            lastTime = tim + interval + wait;
            showTime(tim + wait);
            fprintf(myout, " %s\n", (*rule)[r].c_str());
        }
    }
private:
    void showTime(int tim) const
    {
        int hh, mm, ss;

        ss = tim % 60;
        tim /= 60;
        mm = tim % 60;
        tim /= 60;
        hh = tim % 24;
        fprintf(myout, "%02d:%02d:%02d", hh, mm, ss);
    }
    int lastTime;
    Random genRand;
    const Config *config;
    FILE *myout;
};

char buf[1024];

int main(void)
{
    int re;
    int n, dd, hh, mm, ss, tim, pretim;

    scanf("%d", &re);
    while(re--) {
        PouringRobot *pouringRobot = new PouringRobot(new Config(stdin), stdout);

        scanf("%d", &n);
        dd = 0;
        pretim = -1;
        for (int i = 0; i < n; i++) {
            scanf("%d:%d:%d%*c%[^\n]", &hh, &mm, &ss, buf);
            tim = dd + hh * 3600 + mm * 60 + ss;
            if(pretim > tim) {
                tim += 24 * 3600;
                dd += 24 * 3600;
            }
            pretim = tim;
            pouringRobot->doit(buf, tim);
        }
        if(re > 0)
            printf("\n");

        delete pouringRobot;
    }
}


/*
Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
2922180 2008-05-18 22:55:41 Accepted 2973 C++ 00:00.73 1060K Re:ReJudge
2922179 2008-05-18 22:54:53 Runtime Error
SIGSEGV 2973 C++ 00:00.02 0K Re:ReJudge
*/

// 2012-09-07 01:51:26 | Accepted | 2973 | C++ | 90 | 312 | watashi | Source
