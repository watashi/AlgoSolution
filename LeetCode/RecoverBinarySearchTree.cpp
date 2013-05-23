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
    TreeNode *smaller, *larger, *previous;
    
    void inorder(TreeNode *root) {
        if (!root) return;
        
        inorder(root->left);
        
        if (!previous || previous->val < root->val) previous = root;
        else {
            if (!larger) larger = previous;
            
            smaller = root;
        }
        
        inorder(root->right);
    }
    
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        smaller = larger = previous = NULL;
        inorder(root);
        
        // Remember we should swap the val, not the point itself...
        swap(smaller->val, larger->val);
    }
};