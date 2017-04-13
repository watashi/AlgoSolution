/**
    Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
    
    The same repeated number may be chosen from C unlimited number of times.

    Note:

    All numbers (including target) will be positive integers.
    Elements in a combination (a1, a2, � , ak) must be in non-descending order. (ie, a1 ? a2 ? � ? ak).
    The solution set must not contain duplicate combinations.
    For example, given candidate set 2,3,6,7 and target 7, 
    A solution set is: 
    [7] 
    [2, 2, 3]
  
  */
  
class Solution {
public:
    vector<vector<int> > ans;
    
    void combinationSubSum(const vector<int> &candidates, int index, int target, vector<int> &curr) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }
        
        if (index >= candidates.size()) return;
        
        for (int i = index; i < candidates.size(); i ++) {
            if (candidates[i] > target) return;
            
            int cnt = target / candidates[i];
            
            for (int j = 0; j < cnt; j ++) {  // You always use int i even here...
                curr.push_back(candidates[i]);
                combinationSubSum(candidates, i + 1, target - (j + 1) * candidates[i], curr);
            }
            
            for (int j = 0; j < cnt; j ++) {
                curr.pop_back();
            }
        }
    }
    
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ans.clear();
        
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        combinationSubSum(candidates, 0, target, curr);
        return ans;
    }
};