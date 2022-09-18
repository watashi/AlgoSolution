/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  TreeNode* reverseOddLevels(TreeNode* root) {
    bool rev = true;
    vector<TreeNode*> v;
    v.push_back(root);
    while (v.front() != nullptr) {
      rev = !rev;
      if (rev) {
        for (int i = 0, j = (int)v.size() - 1; i < j; ++i, --j) {
          swap(v[i]->val, v[j]->val);
        }
      }
      vector<TreeNode*> w;
      for (auto p: v) {
        w.push_back(p->left);
        w.push_back(p->right);
      }
      v = std::move(w);
    }
    return root;
  }
};
