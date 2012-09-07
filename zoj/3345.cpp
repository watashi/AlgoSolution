#include <set>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

vector<string> split(const string& s) {
    istringstream iss(s);
    vector<string> ret;
    string t;

    while (iss >> t) {
        ret.push_back(t);
    }

    return ret;
}

const int CATN = 5;
const string cat[CATN] = {"[pn]", "[n]", "[adj]", "[vi]", "[vt]"};

struct Language {
    vector<vector<string> > pat;
    set<string> dic[CATN];
    string name;

    Language(const string& name) : name(name) { }

    bool judge(const vector<string>& v, const vector<string>& pattern) {
        if (v.size() != pattern.size()) {
            return false;
        }
        for (int i = 0; i < (int)v.size(); ++i) {
        // cerr << name << ": string[i] = " << v[i] << "; pattern[i] = " << pattern[i] << endl;
            if (pattern[i][0] != '[' && v[i] != pattern[i]) {
                return false;
            }
            for (int j = 0; j < CATN; ++j) {
                if (cat[j] == pattern[i] && dic[j].count(v[i]) == 0) {
                    return false;
                }
            }
        }
        return true;
    }

    bool judge(const string& s) {
        vector<string> v = split(s);
        for (vector<vector<string> >::const_iterator i = pat.begin(); i != pat.end(); ++i) {
            if (judge(v, *i)) {
                return true;
            }
        }
        return false;
    }

    void addp(const string& s) {
        pat.push_back(split(s));
    }

    void addw(const string& c, const string& s) {
        for (int i = 0; i < CATN; ++i) {
            if (c == cat[i]) {
                dic[i].insert(s);
            }
        }
    }

    void clearw() {
        for (int i = 0; i < CATN; ++i) {
            dic[i].clear();
        }
    }
};

int main() {
    int re, n, m;
    string s;
    vector<string> v;
    Language chn("Chinese"), jap("Japanese"), eng("English"), ger("German");
    Language* lang[4] = {&chn, &jap, &eng, &ger};

    chn.addp("[pn] shi [n]");
    chn.addp("[pn] [vi]");
    chn.addp("[pn] [vt] [n]");
    chn.addp("ni hao");
    eng.addp("[pn] [vi]");
    eng.addp("[pn] [vt] [n]");
    eng.addp("There is a [n]");
    eng.addp("Happy new year");
    jap.addp("[pn] ha [n] desu");
    jap.addp("[pn] ha [n] da");
    jap.addp("[pn] ha [n] ga [adj] desu");
    jap.addp("[n] saikou");
    jap.addp("yoi otoshiwo");
    ger.addp("Ich habe ein [n]");
    ger.addp("Ich bin [n]");
    ger.addp("Ich heisse [n]");
    ger.addp("Du hast [n]");

    cin >> re;
    for (int ri = 1; ri <= re; ++ri) {
        cout << "Case #" << ri << ":\n";
        cin >> n >> m;
        getline(cin, s);
        for (int j = 0; j < 4; ++j) {
            lang[j]->clearw();
        }
        for (int i = 0; i < n; ++i) {
            getline(cin, s);
            v = split(s);
            for (int j = 0; j < 4; ++j) {
                if (v[0] == lang[j]->name) {
                    lang[j]->addw(v[1], v[2]);
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            getline(cin, s);
            for (int j = 0; j < 5; ++j) {
                if (j == 4) {
                    cout << "I don't know.\n";
                    break;
                } else if (lang[j]->judge(s)) {
                    cout << lang[j]->name << "\n";
                    break;
                }
            }
        }
    }

    return 0;
}

// 2012-09-07 15:47:13 | Accepted | 3345 | C++ | 0 | 188 | watashi | Source
