/**
    Given a collection of integers that might contain duplicates, S, return all possible subsets.

    Note:

    Elements in a subset must be in non-descending order.
    The solution set must not contain duplicate subsets.
    For example,
    If S = [1,2,2], a solution is:

    [
        [2],
        [1],
        [1,2,2],
        [2,2],
        [1,2],
        []
    ]
  
  */

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
            // Only one line is different from subsets without duplicates
            if (i > pos && S[i] == S[i - 1]) continue;
            
            curr.push_back(S[i]);
            getCombinations(curr, cnt + 1, i + 1, k, S);
            curr.pop_back();
        }
    }
    
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
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