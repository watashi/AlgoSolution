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
  static pair<int64_t, int64_t> dfs(TreeNode* v, int& ret) {
    pair<int64_t, int64_t> s(v->val, 1);
    if (v->left != nullptr) {
      auto l = dfs(v->left, ret);
      s.first += l.first;
      s.second += l.second;
    }
    if (v->right != nullptr) {
      auto r = dfs(v->right, ret);
      s.first += r.first;
      s.second += r.second;
    }
    if (s.first / s.second == v->val) {
      ++ret;
    }
    return s;
  }

  int averageOfSubtree(TreeNode* root) {
    int ret = 0;
    dfs(root, ret);
    return ret;
  }
};

