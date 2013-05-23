/**
  Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

  Each number in C may only be used once in the combination.

  Note:

  All numbers (including target) will be positive integers.
  Elements in a combination (a1, a2, � , ak) must be in non-descending order. (ie, a1 ? a2 ? � ? ak).
  The solution set must not contain duplicate combinations.
  For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
  A solution set is: 
  [1, 7] 
  [1, 2, 5] 
  [2, 6] 
  [1, 1, 6]
  */

class Solution {
public:
    vector<vector<int> > ans;
    
    void dfs(vector<int> &curr, int target, int pos, vector<int> &num) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }
        
        int pre = -1;
        for (int i = pos; i < num.size(); i ++) {
            if (target < num[i]) return;
            if (pre == num[i]) continue;
            
            pre = num[i]; // Easy to forget
            curr.push_back(num[i]);
            dfs(curr, target - num[i], i + 1, num);
            curr.pop_back();
        }
    }  
    
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        ans.clear();
        if (num.size() <= 0) return ans;
        
        sort(num.begin(), num.end());
        vector<int> curr;
        dfs(curr, target, 0, num);
        
        return ans;
    }
};