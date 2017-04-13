class Solution {
public:
    vector<vector<int> > ans;
    
    void getCombinations(vector<int> &curr, int cnt, int n, int pos, int k) {
        if (cnt == k) {
            ans.push_back(curr);
            return;
        }
        
        if (pos > n) return;
        
        for (int i = pos; i <= n; i ++) {
            curr.push_back(i);
            getCombinations(curr, cnt + 1, n, i + 1, k);
            curr.pop_back();
        }
    }
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ans.clear();
        vector<int> curr;
        getCombinations(curr, 0, n, 1, k);
        return ans;
    }
};