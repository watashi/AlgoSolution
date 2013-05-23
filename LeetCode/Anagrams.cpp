class Solution {
public:

    int cmp(string a, string b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        if (a < b) return 2;
        else if (a == b) return 1;
        return 0;
    }
    
    // The comparator of vector's sort()...
    bool operator () (const string & a, const string & b) {
        return cmp(a, b) > 0;
    }
    
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ans;
        
        sort(strs.begin(), strs.end(), Solution());
        
        for (int i = 0; i < strs.size() - 1;) {
            
            if (cmp(strs[i], strs[i + 1]) == 1) {
                ans.push_back(strs[i ++]);
                while (i < strs.size() && cmp(strs[i], strs[i - 1]) == 1) {
                    ans.push_back(strs[i ++]);
                }
            } else {
                i ++;  // Be careful you increment the i here...
            }
        }
        
        return ans;
    }
};