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
    int target;
    
    bool isOK(TreeNode *root, int sum) {
        if (!root) return false;
        
        sum += root->val;
        //should always remember, it is leaf here: !root->left && !root->right
        if (sum == target && (!root->left && !root->right)) return true; 
        
        return isOK(root->left, sum) || isOK(root->right, sum);
    }
    
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        target = sum;
        
        return isOK(root, 0);
    }
};