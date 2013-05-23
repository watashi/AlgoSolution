/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > ans;
    
    void search(TreeNode *root, int target, vector<int> &nums, int curSum) {
        if (!root) return;
        
        nums.push_back(root->val);
        
        if (!root->left && !root->right) {
            if (curSum == target - root->val) {
                ans.push_back(nums);
            }
            nums.pop_back();    //Don't forget to pop_back
            return;             //Don't forget to return
        }
        
        search(root->left, target, nums, curSum + root->val);
        search(root->right, target, nums, curSum + root->val);
        
        nums.pop_back(); //Pop_back in the end
    }
    
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ans.clear();

        vector<int> nums;
        search(root, sum, nums, 0);
        
        return ans;
    }
};