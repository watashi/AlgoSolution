class Encrypter {
public:
    Encrypter(vector<char>& k, vector<string>& v, vector<string>& d) {
        int n = (int)k.size();
        mp.clear();
        for (int i = 0; i < n; ++i) {
            mp[k[i]] = v[i];
        }
        c.clear();
        for (const string& s: d) {
            ++c[encrypt(s)];
        }
    }
    
    string encrypt(string word1) {
        string ret;
        ret.reserve(word1.length() * 2);
        for (char c: word1) {
            auto it = mp.find(c);
            if (it == mp.end()) {
                ret.clear();
                break;
            } else {
                ret += it->second;
            }
        }
        return ret;
    }
    
    int decrypt(string word2) {
        auto it = c.find(word2);
        if (it == c.end()) {
            return 0;
        } else {
            return it->second;
        }
    }
    
    map<char, string> mp;
    map<string, int> c;
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */
