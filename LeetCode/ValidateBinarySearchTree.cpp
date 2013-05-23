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

    bool isValidBSTRecursive(TreeNode *root, int &minimal, int &maximal) {
        
        if (!root) return true;
        
        if (!root->left && !root->right) {
            minimal = min(minimal, root->val);
            maximal = max(maximal, root->val);
            return true;
        }
        
        int tmpMinLeft = INT32_MAX, tmpMaxLeft = INT32_MIN;
        int tmpMinRight = INT32_MAX, tmpMaxRight = INT32_MIN;
        
        if (root->left) {
            if (isValidBSTRecursive(root->left, tmpMinLeft, tmpMaxLeft)) {
                if (root->val <= tmpMaxLeft) return false;
            } else return false  // If is invalid, return false here
        } else tmpMinLeft = root->val;
        
        if (root->right) {
            if (isValidBSTRecursive(root->right, tmpMinRight, tmpMaxRight)) {
                if (root->val >= tmpMinRight) return false;
            } else return false;   // If is invalid, return false here
        } else tmpMaxRight = root->val;
        
        minimal = min(minimal, tmpMinLeft);
        maximal = max(maximal, tmpMaxRight);
        
        return true;
    }
    
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (!root || (!root->left && !root->right)) return true;
        
        int minimal = INT32_MAX, maximal = INT32_MIN;
        
        if (isValidBSTRecursive(root, minimal, maximal)) {
            if (root->left && minimal >= root->val) return false;
            if (root->right && maximal <= root->val) return false;
            
            return true;
        }
        
        return false;
        
    }
};