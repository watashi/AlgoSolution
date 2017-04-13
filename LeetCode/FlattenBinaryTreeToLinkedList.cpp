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

    // flatten the tree, return the root node...
    TreeNode* flattenTree(TreeNode *root, TreeNode *next) {
        if (!root) return root;
        next = flattenTree(root->right, next);
        next = flattenTree(root->left, next);

        root->right = next;
        root->left = NULL;

        return root;
    }
   
    // flatten the tree iteratively
    void flattenTreeIterative(TreeNode *root) {
        if (!root || (!root->right && !root->left)) return;

        stack<TreeNode *> stk;
        if (root->right) stk.push(root->right);
        if (root->left) stk.push(root->left);

        TreeNode *preNode = root;

        while (!stk.empty()) {
            if (stk.top()->right) stk.push(stk.top()->right);
            if (stk.top()->left) stk.push(stk.top()->left);

            preNode->left = NULL;
            preNode->right = stk.top();
            preNode = stk.top();

            stk.pop();
        }
    }

    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        flattenTree(root, NULL);
        flattenTreeIterative(root);
    }
 };
