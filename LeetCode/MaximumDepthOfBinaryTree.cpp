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
    int ans;
    void maxDepth(TreeNode *root, int depth)
    {
        if (!root){
            ans = max(ans, depth);
            return;
        }
        
        maxDepth(root->left, depth + 1);
        maxDepth(root->right, depth + 1);
    }
    
    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        ans = 0; //forgot to initialized...
        
        maxDepth(root, 0);
        
        return ans;
    }
};