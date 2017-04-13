class Solution {
public:

    string getString(vector<int> &n, vector<string> &words, int L, bool isLastLine) {
        if (n.size() <= 0) return "";
        if (n.size() == 1) {
            return words[n[0]] + string(L - words[n[0]].length(), ' ');
        }
        
        int len = 0;
        for (int i = 0; i < n.size(); i ++) {
            len += words[n[i]].length();
        }
        
        int delta = (L - len) % (n.size() - 1);
        int subLen = (L - len - delta) / (n.size() - 1);
        
        if (isLastLine) delta = 0, subLen = 1;
        
        string ret = words[n[0]];
        for (int i = 1; i < n.size(); i ++) {
            ret += string(subLen, ' ');
            if (delta > 0) {
                ret += string(1, ' ');
                delta --;
            }
            ret += words[n[i]];
        }
        
        if (ret.length() < L) ret += string(L - ret.length(), ' ');
        
        return ret;
    }
    
    vector<string> fullJustify(vector<string> &words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<string> ans;
        if (words.size() <= 0) return ans;
        
        vector<vector<int> > mp;
        vector<int> tmp(1, 0);
        int len = words[0].length();
        
        for (int i = 1; i < words.size(); i ++) {
            if (len + words[i].length() + 1 > L) {
                mp.push_back(tmp);
                tmp.assign(1, i);
                len = words[i].length();
            } else {
                len = len + words[i].length() + 1;
                tmp.push_back(i);
            }
        }
        
        if (tmp.size() > 0) mp.push_back(tmp);
        
        for (int i = 0; i < mp.size() - 1; i ++) {
            ans.push_back(getString(mp[i], words, L, false));
        }
        
        ans.push_back(getString(mp.back(), words, L, true));
        
        return ans;
    }
};