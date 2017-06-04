/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    string tree2str(TreeNode* t) {
        string ret;
        gao(t, ret);
        return ret;
    }
    
    void gao(TreeNode* t, string& s) {
        if (t != nullptr) {
            s += to_string(t->val);
            if (t->left != nullptr || t->right != nullptr) {
                s += '(';
                gao(t->left, s);
                s += ')';
                if (t->right != nullptr) {
                    s += '(';
                    gao(t->right, s);
                    s += ')';
                }
            }
        }
    }
};
