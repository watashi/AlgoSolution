class Solution {
public:

    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
        if (L.size() <= 0 || S.length() < L.size() * L[0].length()) return ret;
        
        map<string, int> wordsCnt;
        
        for (int i = 0; i < L.size(); i ++) {
            wordsCnt[L[i]] ++;
        }
        
        map<string, int> currCnt;
        
        for (int i = 0; i <= S.length() - L.size() * L[0].length(); i ++) {
             currCnt.clear();
            
            int j = 0;
            for (j = 0; j < L.size(); j ++) {
                int currIndex = i + j * L[0].length();
                
                string currString = S.substr(currIndex, L[0].length());
                currCnt[currString] ++;
                if (currCnt[currString] > wordsCnt[currString]) break;
            }
            
            if (j == L.size()) ret.push_back(i);
        }
        
        return ret;
    }
};