class Solution {
public:
    vector<vector<int> > ans;
    
    void getCombinations(vector<int> &curr, int cnt, int pos, int k, vector<int> &S) {
        if (cnt == k) {
            ans.push_back(curr);
            return;
        }
        
        if (pos >= S.size()) return;
        
        for (int i = pos; i < S.size(); i ++) {
            curr.push_back(S[i]);
            getCombinations(curr, cnt + 1, i + 1, k, S);
            curr.pop_back();
        }
    }
    
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ans.clear();
        sort(S.begin(), S.end());
        
        vector<int> curr;
        
        for (int i = 0; i <= S.size(); i ++) {
            getCombinations(curr, 0, 0, i, S);
        }
        
        return ans;
    }
};