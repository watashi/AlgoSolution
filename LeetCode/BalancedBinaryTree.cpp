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

    void dfs(TreeNode *root, int depth, int &height)
    {
        if (!root) return;
        
        if (!root->left && !root->right) {
            height = max(height, depth + 1);
        }
        
        dfs(root->left, depth + 1, height);
        dfs(root->right, depth + 1, height);
    }
    
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (!root || (!root->left && !root->right)) return true;
       
        int leftHeight = 0, rightHeight = 0;
        
        dfs(root->left, 0, leftHeight);
        dfs(root->right, 0, rightHeight);
        
        if( abs(leftHeight - rightHeight) > 1) return false;
        
        return isBalanced(root->left) && isBalanced(root->right);
        
    }
};