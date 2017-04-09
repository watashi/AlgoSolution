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
    int longestConsecutive(TreeNode* root) {
        int ans = 0;
        gao(root, ans);
        return ans;
    }

    pair<int, int> gao(TreeNode* p, int& ans) {
        if (p == nullptr) {
            return pair<int, int>(0, 0);
        } else {
            pair<int, int> ret(1, 1);
            auto a = gao(p->left, ans), b = gao(p->right, ans);
            bool ainc = false, adec = false, binc = false, bdec = false;
            if (p->left != nullptr) {
                ainc = p->val != INT_MAX && p->left->val == p->val + 1;
                adec = p->val != INT_MIN && p->left->val == p->val - 1;
            }
            if (p->right != nullptr) {
                binc = p->val != INT_MAX && p->right->val == p->val + 1;
                bdec = p->val != INT_MIN && p->right->val == p->val - 1;
            }
            if (ainc) ret.first = max(ret.first, a.first + 1);
            if (adec) ret.second = max(ret.second, a.second + 1);
            if (binc) ret.first = max(ret.first, b.first + 1);
            if (bdec) ret.second = max(ret.second, b.second + 1);
            ans = max(ans, max(ret.first, ret.second));
            if (ainc && bdec) ans = max(ans, a.first + 1 + b.second);
            if (adec && binc) ans = max(ans, a.second + 1 + b.first);
            return ret;
        }
    }
};
