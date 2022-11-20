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
  void inorder(TreeNode* p, vector<int>& v) {
    if (p != nullptr) {
      inorder(p->left, v);
      v.push_back(p->val);
      inorder(p->right, v);
    }
  }

  vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
    vector<int> v;
    inorder(root, v);
    vector<vector<int>> ret;
    ret.reserve(queries.size());
    for (int q : queries) {
      auto it = lower_bound(v.begin(), v.end(), q);
      int y = it == v.end() ? -1 : *it;
      if (it == v.end() || *it != q) {
        --it;
      }
      int x = it < v.begin() ? -1 : *it;
      ret.push_back({ x, y });
    }
    return ret;
  }
};
