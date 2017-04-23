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
    int findTilt(TreeNode* root) {
        int ret = 0;
        gao(root, ret);
        return ret;
    }

    int gao(TreeNode* p, int& d) {
        if (p == nullptr) {
            return 0;
        } else {
            int l = gao(p->left, d), r = gao(p->right, d);
            d += abs(r - l);
            return p->val + l + r;
        }
    }
};
